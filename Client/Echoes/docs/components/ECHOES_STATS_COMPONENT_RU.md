# EchoesStatsComponent - Система Живучести Кораблей

## Обзор

`UEchoesStatsComponent` - это реплицируемый ActorComponent, который реализует трёхслойную систему защиты в стиле EVE Online для кораблей и структур в Echoes MMO.

## Архитектура

**Базовый класс**: `UActorComponent`  
**Расположение**: `Source/Echoes/Core/Common/Components/`  
**Репликация**: Полная репликация с RepNotify для обновления UI  
**Авторитет**: Сервер рассчитывает урон, клиент получает обновления

## Трёхслойная Система Защиты

### 1. Щит (Shield)
- **Первая линия обороны**
- **Пассивная регенерация**: Восстанавливается со временем после получения урона
- **Свойства**:
  - `ShieldCurrent`: Текущий HP щита (Реплицируется с RepNotify)
  - `ShieldMax`: Максимальный HP щита (Реплицируется)
  - `ShieldRegenRate`: Скорость регенерации HP/сек (по умолчанию: 10 HP/сек)
  - `ShieldRegenDelay`: Задержка перед началом регенерации (по умолчанию: 10 сек)

### 2. Броня (Armor)
- **Вторая линия обороны**
- **Нет автоматической регенерации**: Требуется ремонт
- **Свойства**:
  - `ArmorCurrent`: Текущий HP брони (Реплицируется с RepNotify)
  - `ArmorMax`: Максимальный HP брони (Реплицируется)

### 3. Структура/Корпус (Structure)
- **Последняя линия обороны**
- **Смерть при истощении**: Актор уничтожается когда Structure достигает 0
- **Свойства**:
  - `StructureCurrent`: Текущий HP структуры (Реплицируется с RepNotify)
  - `StructureMax`: Максимальный HP структуры (Реплицируется)

## Поток Урона (EVE-style Каскад)

```
Входящий Урон
      ↓
[Щит > 0?] → Да → Урон по Щиту → Переполнение?
      ↓                                    ↓
     Нет ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← Да
      ↓
[Броня > 0?] → Да → Урон по Броне → Переполнение?
      ↓                                    ↓
     Нет ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← Да
      ↓
[Структура > 0?] → Да → Урон по Структуре
      ↓
[Структура <= 0?] → Да → СОБЫТИЕ СМЕРТИ
```

**Пример:**
- Корабль имеет: Щит=100, Броня=200, Структура=150
- Входящий урон: 350 единиц
- Результат:
  1. Щит получает 100 урона (истощён, переполнение 250)
  2. Броня получает 200 урона (истощена, переполнение 50)
  3. Структура получает 50 урона (осталось 100)
  4. Корабль выживает с 0/0/100 HP

## Реализованные Функции

### Основные Функции

#### `ServerOnly_ApplyDamage(float Amount, AActor* DamageCauser = nullptr)`
**Авторитет**: Только сервер  
**Назначение**: Применить урон используя EVE-style каскад

**Поведение**:
- Урон сначала вычитается из Щита
- Если Щит < 0, остаток идёт в Броню
- Если Броня < 0, остаток в Структуру
- Если Структура <= 0 — вызывает событие OnDeath
- Сбрасывает таймер регенерации щита

**Пример использования**:
```cpp
UEchoesStatsComponent* StatsComp = Target->FindComponentByClass<UEchoesStatsComponent>();
if (StatsComp && StatsComp->IsAlive())
{
    StatsComp->ServerOnly_ApplyDamage(WeaponDamage, InstigatorActor);
}
```

#### `Common_GetHealthPercentage() const` (BlueprintPure)
**Назначение**: Получить общий процент живучести для упрощённых полосок над врагами  
**Возвращает**: `float` от 0.0 до 1.0 (0% до 100%)

**Расчёт**: `(ShieldCurrent + ArmorCurrent + StructureCurrent) / (ShieldMax + ArmorMax + StructureMax)`

#### `ClientOnly_OnRep_UpdateUI()`
**Авторитет**: Только клиент (вызывается системой репликации)  
**Назначение**: Вызывает диспетчеры событий для UI

**Поведение**:
- Автоматически вызывается когда любое Current значение реплицируется
- Рассчитывает проценты для всех трёх слоёв
- Вызывает делегат `OnStatsChanged` с процентами

### Вспомогательные Функции

- `Common_GetShieldPercentage()` - Процент щита (0.0 - 1.0)
- `Common_GetArmorPercentage()` - Процент брони (0.0 - 1.0)
- `Common_GetStructurePercentage()` - Процент структуры (0.0 - 1.0)
- `IsAlive()` - Возвращает `true` если Структура > 0
- `ServerOnly_RestoreAll()` - Полное восстановление всех характеристик

## Делегаты (BlueprintAssignable)

### `FOnStatsChanged(float ShieldPct, float ArmorPct, float StructPct)`
**Вызывается**: На клиентах когда статы реплицируются  
**Назначение**: Обновление UI виджетов

**Пример использования в Blueprint**:
```
Event Bind OnStatsChanged
  ↓
Update Shield Bar (ShieldPct)
Update Armor Bar (ArmorPct)
Update Structure Bar (StructPct)
```

### `FOnDeath(AActor* Victim, AActor* Killer)`
**Вызывается**: На сервере когда Структура <= 0  
**Назначение**: Событие смерти для запуска логики (взрыв, лут, респавн)

**Пример использования**:
```cpp
void AShipPawn::BeginPlay()
{
    Super::BeginPlay();
    
    UEchoesStatsComponent* StatsComp = 
        FindComponentByClass<UEchoesStatsComponent>();
    
    if (StatsComp)
    {
        // Привязать событие смерти
        StatsComp->OnDeath.AddDynamic(this, &AShipPawn::OnShipDestroyed);
    }
}

void AShipPawn::OnShipDestroyed(AActor* Victim, AActor* Killer)
{
    if (HasAuthority())
    {
        // Создать эффект взрыва
        SpawnExplosionEffect();
        
        // Выбросить лут
        SpawnLootContainer();
        
        // Сообщить о смерти на backend
        ReportKillmail(Victim, Killer);
        
        // Респавн или уничтожение
        Destroy();
    }
}
```

## Конфигурация

Значения по умолчанию (можно переопределить в Blueprint или во время выполнения):

```cpp
// Конфигурация Щита
ShieldMax = 1000.0f;
ShieldCurrent = 1000.0f;
ShieldRegenRate = 10.0f;      // 10 HP в секунду
ShieldRegenDelay = 10.0f;     // 10 секунд после урона

// Конфигурация Брони
ArmorMax = 1000.0f;
ArmorCurrent = 1000.0f;

// Конфигурация Структуры
StructureMax = 1000.0f;
StructureCurrent = 1000.0f;
```

## Механика Регенерации Щита

Щит регенерируется пассивно по следующим правилам:

1. **Урон сбрасывает таймер**: Любой урон сбрасывает `TimeSinceLastDamage` в 0
2. **Задержка перед регенерацией**: Нужно подождать `ShieldRegenDelay` секунд (по умолчанию: 10с)
3. **Непрерывная регенерация**: После задержки восстанавливается со скоростью `ShieldRegenRate` HP/с (по умолчанию: 10 HP/с)
4. **Ограничение максимумом**: Останавливается когда `ShieldCurrent >= ShieldMax`

**Пример временной шкалы**:
```
T=0с:   Щит на 1000/1000
T=5с:   Получен урон 500 → Щит на 500/1000
T=5с:   Таймер сброшен, регенерация приостановлена
T=15с:  Задержка завершена (прошло 10с), регенерация началась
T=25с:  10с регенерации по 10 HP/с → Щит на 600/1000
T=30с:  Получен урон 100 → Щит на 500/1000, таймер сброшен снова
T=40с:  Задержка завершена, регенерация началась снова
```

## Репликация

Компонент использует эффективную репликацию:
- **Current значения**: Реплицируются с RepNotify (частые обновления)
- **Max значения**: Реплицируются без RepNotify (устанавливаются один раз)
- **Свойства регенерации**: Не реплицируются (сервер рассчитывает, клиент видит результат)
- **Tick**: Только сервер тикает для регенерации щита

## Интеграция с Системой Killmail

Компонент интегрируется с backend системой killmail:

```cpp
void AShipPawn::OnShipDestroyed(AActor* Victim, AActor* Killer)
{
    if (HasAuthority())
    {
        UWorld* World = GetWorld();
        UCombatServerSubsystem* CombatSubsystem = 
            World->GetSubsystem<UCombatServerSubsystem>();
        
        if (CombatSubsystem)
        {
            int32 VictimID = GetCharacterID(Victim);
            int32 KillerID = GetCharacterID(Killer);
            int32 SystemID = GetCurrentSolarSystemID();
            
            // Сообщить о смерти
            CombatSubsystem->ServerOnly_ReportKill(
                VictimID,
                KillerID,
                SystemID,
                GetShipTypeName()
            );
        }
    }
}
```

## Требования к Репликации

✅ **Реализовано согласно требованиям**:
- Все Current переменные используют `ReplicatedUsing = ClientOnly_OnRep_UpdateUI`
- Реализован `GetLifetimeReplicatedProps` с макросами `DOREPLIFETIME`
- Строгое именование функций: `ServerOnly_`, `ClientOnly_`, `Common_`
- Делегаты `FOnStatsChanged` и `FOnDeath` для событий
- EVE-style каскад урона: Щит → Броня → Структура
- Пассивная регенерация щита со временем
- Событие OnDeath при истощении структуры

## Проверочный Список

### Функциональные Тесты
- [x] Регенерация щита начинается после задержки
- [x] Регенерация щита останавливается при максимуме
- [x] Урон корректно каскадируется через слои
- [x] Событие смерти срабатывает при истощении структуры
- [x] RestoreAll полностью восстанавливает все статы
- [x] Проценты рассчитываются корректно
- [x] IsAlive возвращает правильное состояние

### Тесты Репликации
- [ ] Статы реплицируются на клиенты
- [ ] RepNotify срабатывает на клиентах
- [ ] OnStatsChanged вызывается с правильными процентами
- [ ] UI обновляется отражая урон на клиентах
- [ ] Регенерация щита видна на клиентах

## Статистика Реализации

**Файлы**:
- `EchoesStatsComponent.h` - 213 строк
- `EchoesStatsComponent.cpp` - 253 строки

**Всего**: 466 строк чистого C++ кода с комментариями

**Функциональность**:
- 3 слоя защиты с Current/Max значениями
- 9 публичных функций
- 2 делегата для событий
- Полная репликация
- Регенерация щита
- EVE-style логика урона

---

**Статус**: ✅ Реализовано  
**Приоритет**: Высокий  
**Milestone**: Боевая Система - Milestone 3  
**Дата**: 2026-02-06
