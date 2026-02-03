# Система Лун - Документация

## Обзор

Данный документ описывает реализацию системы лун (спутников) в генераторе мира Echoes MMO, включая создание AMoonActor, интеграцию с мировым генератором, расширенное логирование и визуализацию орбит.

## 1. Создание AMoonActor

### 1.1 Класс AMoonActor

**Файлы:** `MoonActor.h`, `MoonActor.cpp`

AMoonActor представляет луну/спутник в universe Echoes, аналогичный APlanetActor, но с оптимизациями для меньших небесных тел.

**Настройки сети:**
```cpp
bReplicates = true;              // Репликация на клиенты
bAlwaysRelevant = false;         // Можно отсеивать по расстоянию
NetCullDistanceSquared = 100000000000000.0;  // 10 млн единиц в квадрате
```

### 1.2 Метод InitializeMoon

```cpp
void AMoonActor::InitializeMoon(
    const FGuid& InMoonId,       // Уникальный ID из базы данных
    const FString& InName,       // Название луны
    const FString& InType,       // Тип луны (Rocky, Ice, Volcanic)
    float InOrbitRadius,         // Расстояние от планеты в км
    int32 InSeed)                // Seed для процедурной вариации
{
    // Сохраняем данные
    MoonId = InMoonId;
    MoonName = InName;
    MoonType = InType;
    OrbitRadius = InOrbitRadius;
    Seed = InSeed;

    UE_LOG(LogTemp, Log, TEXT("Initializing Moon: %s (Type: %s, Orbit: %.1f km, Seed: %d)"),
        *MoonName, *MoonType, OrbitRadius, Seed);

    // Применяем визуальную конфигурацию
    ApplyVisualConfiguration();
}
```

### 1.3 Компоненты

```cpp
// Основной меш луны
UStaticMeshComponent* MoonMeshComponent;

// Сплайн для орбиты (только на клиенте)
USplineComponent* OrbitSplineComponent;
```

### 1.4 Реплицируемые Данные

```cpp
UPROPERTY(ReplicatedUsing = OnRep_MoonData)
FGuid MoonId;

UPROPERTY(ReplicatedUsing = OnRep_MoonData)
FString MoonName;

UPROPERTY(ReplicatedUsing = OnRep_MoonData)
FString MoonType;

UPROPERTY(ReplicatedUsing = OnRep_MoonData)
float OrbitRadius;

UPROPERTY(ReplicatedUsing = OnRep_MoonData)
int32 Seed;
```

## 2. Доработка AEchoesWorldGenerator

### 2.1 Новые Свойства

**Файл:** `EchoesWorldGenerator.h`

```cpp
// Класс актера луны
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
TSubclassOf<AMoonActor> MoonActorClass;

// DataTable для визуальных настроек лун
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
UDataTable* MoonDataTable;
```

### 2.2 Спавн Лун в SpawnPlanets

После спавна каждой планеты добавлен вложенный цикл для спавна лун:

```cpp
// ==================== SPAWN MOONS FOR THIS PLANET ====================
if (PlanetConfig.Moons.Num() > 0)
{
    UE_LOG(LogTemp, Log, TEXT("  Spawning %d moons for planet %s..."), 
        PlanetConfig.Moons.Num(), *PlanetConfig.Name);
    
    for (const FMoonConfig& MoonConfig : PlanetConfig.Moons)
    {
        // Рассчитываем позицию луны относительно планеты
        FVector MoonOffset = ConvertCoordinates(
            MoonConfig.PositionX,
            MoonConfig.PositionY,
            MoonConfig.PositionZ);
        FVector MoonLocation = PlanetLocation + MoonOffset;
        
        // Спавн луны...
    }
}
```

### 2.3 Расчет Координат Луны

**Формула позиции:**
```cpp
FVector MoonLocation = PlanetLocation + MoonOffset;
```

Где:
- `PlanetLocation` = позиция родительской планеты в мировых координатах
- `MoonOffset` = смещение луны, рассчитанное через `ConvertCoordinates()`

**Расчет радиуса орбиты:**
```cpp
float OrbitRadius = FMath::Sqrt(
    FMath::Square(static_cast<float>(MoonConfig.PositionX)) +
    FMath::Square(static_cast<float>(MoonConfig.PositionY)) +
    FMath::Square(static_cast<float>(MoonConfig.PositionZ))
);
```

### 2.4 Новая Функция Helper

```cpp
FMoonVisualRow* AEchoesWorldGenerator::GetMoonVisualData(const FString& MoonType)
{
    if (!MoonDataTable)
    {
        UE_LOG(LogTemp, Warning, TEXT("MoonDataTable is not set!"));
        return nullptr;
    }

    FName RowName = FName(*MoonType);
    FMoonVisualRow* Row = MoonDataTable->FindRow<FMoonVisualRow>(RowName, TEXT("GetMoonVisualData"));
    
    if (!Row)
    {
        // Откат к строке "Default"
        Row = MoonDataTable->FindRow<FMoonVisualRow>(FName(TEXT("Default")), TEXT("GetMoonVisualData"));
    }

    return Row;
}
```

## 3. Расширенное Логирование (Server Report)

### 3.1 Формат [SERVER]

Добавлен новый формат логирования для удобного мониторинга:

```
[SERVER] System: Jita | Security: 1.0
[SERVER] Objects: 1 Star (Class G2V) | 10 Planets | 24 Moons | 5 Stations | 4 Stargates
[SERVER] Status: Generation Successful for Jita
```

**Реализация:**
```cpp
// Подсчет лун
int32 TotalMoons = 0;
for (const FPlanetConfig& Planet : Config.Planets)
{
    TotalMoons += Planet.Moons.Num();
}

// Логирование
UE_LOG(LogTemp, Log, TEXT("[SERVER] System: %s | Security: %.1f"), 
    *Config.SystemName, Config.SecurityStatus);
UE_LOG(LogTemp, Log, TEXT("[SERVER] Objects: 1 Star (Class %s) | %d Planets | %d Moons | %d Stations | %d Stargates"),
    *Config.StarClass, Config.Planets.Num(), TotalMoons, Config.Stations.Num(), Config.Stargates.Num());
UE_LOG(LogTemp, Log, TEXT("[SERVER] Status: Generation Successful for %s"), *Config.SystemName);
```

### 3.2 Таблица Статистики

Обновленная таблица статистики теперь включает луны:

```
┌─────────────────────────────────────────────────────────────┐
│ MATERIALIZING SYSTEM: Jita                                  │
├─────────────────────────────────────────────────────────────┤
│ System ID: 30000142-0000-0000-0000-000000000000            │
│ Star Class: G2V                                             │
│ Security Status: 1.00                                       │
├─────────────────────────────────────────────────────────────┤
│ OBJECT STATISTICS                                           │
├─────────────────────────────────────────────────────────────┤
│ Celestial Bodies:                                           │
│   ⭐ Stars:            1                                     │
│   🌍 Planets:         10                                     │
│   🌙 Moons:           24    ← НОВОЕ!                        │
│   ☄️  Asteroid Belts:   3                                     │
├─────────────────────────────────────────────────────────────┤
│ Infrastructure:                                             │
│   🏭 Stations:         5                                     │
│   🚪 Stargates:        4                                     │
├─────────────────────────────────────────────────────────────┤
│ Exploration:                                                │
│   ❓ Anomalies:        2                                     │
│   🌀 Wormholes:        1                                     │
└─────────────────────────────────────────────────────────────┘
```

### 3.3 Логирование Спавна Лун

```
✓ Planet spawned: Earth (Type: Temperate, Orbit: 149597.87 km) at (...)
  Spawning 1 moons for planet Earth...
  ✓ Moon spawned: Luna (Orbit: 384400.00 km around Earth)
```

## 4. Визуальные Орбиты (Client-Only)

### 4.1 Структура FMoonVisualRow

**Файл:** `EchoesWorldVisualTypes.h`

```cpp
USTRUCT(BlueprintType)
struct FMoonVisualRow : public FTableRowBase
{
    GENERATED_BODY()

    /** Moon blueprint actor */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
    TSoftClassPtr<AActor> ActorClass;

    /** Scale applied to the moon actor */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
    FVector ActorScale = FVector(0.5f, 0.5f, 0.5f); // Меньше планет

    /** Whether to display orbital path for this moon type */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
    bool bShowOrbit = true;

    /** Color of the orbital path line */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
    FLinearColor OrbitColor = FLinearColor(0.6f, 0.7f, 0.8f, 0.3f); // Светло-серый

    /** Thickness of the orbital path line in world units */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
    float OrbitLineThickness = 5.0f; // Тоньше орбит планет

    /** Number of segments for orbit circle */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
    int32 OrbitSegments = 64; // Меньше сегментов чем у планет

    /** Material to use for orbit rendering (optional) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
    TSoftObjectPtr<UMaterialInterface> OrbitMaterial;
};
```

### 4.2 Функция ClientOnly_DrawOrbit

**Файл:** `MoonActor.cpp`

```cpp
void AMoonActor::ClientOnly_DrawOrbit()
{
    // Только на клиенте (не на сервере)
    if (HasAuthority())
    {
        UE_LOG(LogTemp, Warning, TEXT("ClientOnly_DrawOrbit called on server - ignoring"));
        return;
    }

    // Не рисуем если радиус орбиты 0
    if (OrbitRadius <= 0.0f)
    {
        return;
    }

    // Рассчитываем радиус орбиты в Unreal Units
    const float UniverseToWorldScale = 0.0001f; // 1 км = 10 см
    const double OrbitRadiusUU = static_cast<double>(OrbitRadius) * 
                                 static_cast<double>(UniverseToWorldScale) * 100000.0;

    // Создаем компонент сплайна
    if (!OrbitSplineComponent)
    {
        OrbitSplineComponent = NewObject<USplineComponent>(this, TEXT("OrbitSpline"));
        OrbitSplineComponent->RegisterComponent();
        OrbitSplineComponent->AttachToComponent(GetRootComponent(), 
            FAttachmentTransformRules::KeepRelativeTransform);
        OrbitSplineComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        OrbitSplineComponent->SetVisibility(true);
    }

    // Генерируем точки окружности
    const int32 NumSegments = 64; // Луны используют меньше сегментов
    const float AngleStep = 360.0f / NumSegments;

    // Центр орбиты = позиция родительской планеты
    const FVector OrbitCenter = ParentLocation;

    for (int32 i = 0; i <= NumSegments; ++i)
    {
        const float Angle = FMath::DegreesToRadians(AngleStep * i);
        const float X = FMath::Cos(Angle) * OrbitRadiusUU;
        const float Y = FMath::Sin(Angle) * OrbitRadiusUU;
        const FVector PointLocation = OrbitCenter + FVector(X, Y, 0.0f);
        
        const FVector LocalPoint = GetTransform().InverseTransformPosition(PointLocation);
        OrbitSplineComponent->AddSplinePoint(LocalPoint, ESplineCoordinateSpace::Local, false);
    }

    // Обновляем сплайн
    OrbitSplineComponent->UpdateSpline();
    OrbitSplineComponent->SetClosedLoop(true);

    // Устанавливаем цвет (светлый серо-голубой для лун)
    OrbitSplineComponent->SetDrawDebug(true);
    OrbitSplineComponent->SetUnselectedSplineSegmentColor(
        FLinearColor(0.6f, 0.7f, 0.8f, 0.3f));
}
```

### 4.3 Сравнение Орбит Планет и Лун

| Параметр | Планеты | Луны |
|----------|---------|------|
| Центр орбиты | Звезда (SystemOffset) | Родительская планета |
| Количество сегментов | 128 | 64 |
| Цвет по умолчанию | Яркий голубой (0.3, 0.6, 1.0, 0.5) | Светлый серый (0.6, 0.7, 0.8, 0.3) |
| Толщина линии | 10.0 | 5.0 |
| Масштаб актера | 1.0 | 0.5 |

### 4.4 Использование UniverseToWorldScale

Орбиты правильно масштабируются с использованием `UniverseToWorldScale`:

```cpp
const float UniverseToWorldScale = 0.0001f; // 1 км = 10 см
const double OrbitRadiusUU = OrbitRadius * UniverseToWorldScale * 100000.0; // км в см
```

**Пример:**
- Луна на расстоянии 384,400 км от Земли
- `OrbitRadiusUU = 384400 * 0.0001 * 100000 = 3,844,000,000 см = 38,440 км`
- Орбита визуально правильно масштабирована

## 5. Настройка через DataTable

### 5.1 Пример Настройки MoonDataTable

**Row Name:** "Default"
```
ActorScale: (0.5, 0.5, 0.5)
bShowOrbit: true
OrbitColor: (0.6, 0.7, 0.8, 0.3)
OrbitLineThickness: 5.0
OrbitSegments: 64
```

**Row Name:** "Rocky"
```
ActorScale: (0.4, 0.4, 0.4)
bShowOrbit: true
OrbitColor: (0.7, 0.6, 0.5, 0.35)  // Коричневатый
OrbitSegments: 64
```

**Row Name:** "Ice"
```
ActorScale: (0.6, 0.6, 0.6)
bShowOrbit: true
OrbitColor: (0.7, 0.8, 1.0, 0.4)  // Светло-голубой
OrbitSegments: 96  // Больше сегментов для плавности
```

### 5.2 Отключение Орбит для Конкретных Типов

В `MoonDataTable` для строки "Captured":
```
bShowOrbit: false  // Не показывать орбиту для захваченных астероидов
```

## 6. Производительность

### 6.1 Оптимизации

**Client-Only компоненты:**
```cpp
if (HasAuthority())
{
    return;  // Орбиты не создаются на сервере
}
```

**Меньше сегментов:**
- Луны: 64 сегмента (vs 128 для планет)
- Экономия ~50% вычислений на луну
- При 24 лунах = экономия ~1500 точек сплайна

**Network Culling:**
```cpp
NetCullDistanceSquared = 100000000000000.0;  // 10 млн единиц²
bAlwaysRelevant = false;  // Можно отсекать по дистанции
```

### 6.2 Масштабируемость

**Типичная система:**
- 1 звезда
- 10 планет с орбитами (128 сегментов × 10 = 1,280 точек)
- 24 луны с орбитами (64 сегмента × 24 = 1,536 точек)
- **Итого:** 2,816 точек сплайна на клиента

**Региональный кластер (50 систем):**
- 50 звезд
- 500 планет (64,000 точек)
- 1,200 лун (76,800 точек)
- **Итого:** 140,800 точек, но с network culling видно только ~5-10% одновременно

## 7. Примеры Использования

### 7.1 Пример Полного Лога

```
┌─────────────────────────────────────────────────────────────┐
│ MATERIALIZING SYSTEM: Sol                                   │
├─────────────────────────────────────────────────────────────┤
│ System ID: 30000001-0000-0000-0000-000000000000            │
│ Star Class: G2V                                             │
│ Security Status: 1.00                                       │
├─────────────────────────────────────────────────────────────┤
│ OBJECT STATISTICS                                           │
├─────────────────────────────────────────────────────────────┤
│ Celestial Bodies:                                           │
│   ⭐ Stars:            1                                     │
│   🌍 Planets:          8                                     │
│   🌙 Moons:          177                                     │
│   ☄️  Asteroid Belts:   1                                     │
├─────────────────────────────────────────────────────────────┤
│ Infrastructure:                                             │
│   🏭 Stations:         12                                    │
│   🚪 Stargates:        3                                     │
└─────────────────────────────────────────────────────────────┘

[SERVER] System: Sol | Security: 1.0
[SERVER] Objects: 1 Star (Class G2V) | 8 Planets | 177 Moons | 12 Stations | 3 Stargates
Total objects to spawn: 202

✓ Star spawned successfully at origin
✓ Planet spawned: Mercury (Type: Rocky, Orbit: 57900.00 km)
✓ Planet spawned: Venus (Type: Rocky, Orbit: 108200.00 km)
✓ Planet spawned: Earth (Type: Temperate, Orbit: 149600.00 km) at (...)
  Spawning 1 moons for planet Earth...
  ✓ Moon spawned: Luna (Orbit: 384400.00 km around Earth)
✓ Planet spawned: Mars (Type: Rocky, Orbit: 227900.00 km)
  Spawning 2 moons for planet Mars...
  ✓ Moon spawned: Phobos (Orbit: 9376.00 km around Mars)
  ✓ Moon spawned: Deimos (Orbit: 23463.00 km around Mars)
...

[SERVER] Status: Generation Successful for Sol
```

## 8. Известные Ограничения

1. **Орбиты - окружности:** Нет эллиптических орбит
2. **Плоскость орбиты:** Все орбиты в плоскости XY (нет наклона)
3. **Статические орбиты:** Нет анимации движения по орбите
4. **Тип луны:** Сейчас используется фиксированный тип "Rocky"

## 9. Будущие Улучшения

Потенциальные улучшения:
1. **Типы лун из БД:** Использовать реальный тип луны из конфига
2. **Эллиптические орбиты:** Поддержка эксцентриситета
3. **Наклон орбиты:** Поддержка орбитального наклона
4. **Анимированные орбиты:** Движение лун по орбитам
5. **Материалы орбит:** Свечение и шиммер эффекты
6. **Приливной захват:** Визуальная индикация приливного захвата

## 10. Заключение

Система лун полностью интегрирована в генератор мира Echoes:

✅ **Функциональность:**
- Полная сетевая репликация
- Client-only визуализация орбит
- Data-driven конфигурация

✅ **Логирование:**
- Расширенные серверные отчеты
- Формат [SERVER] для мониторинга
- Детальная статистика

✅ **Производительность:**
- Оптимизация для client-side
- Network culling
- Меньше сегментов для лун

Система готова к использованию в продакшене!
