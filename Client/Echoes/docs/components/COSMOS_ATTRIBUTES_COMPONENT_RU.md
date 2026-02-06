# CosmosAttributesComponent - Система Урона с Резистами

## Обзор

`UCosmosAttributesComponent` - это продвинутый реплицируемый ActorComponent, который реализует трёхслойную систему защиты в стиле EVE Online с резистами для каждого типа урона. Это production-ready боевая система с продвинутой механикой поглощения урона.

## Архитектура

**Базовый класс**: `UActorComponent`  
**Расположение**: `Source/Echoes/Core/Common/Components/`  
**Зависимости**: `EchoesCoreTypes.h` (типы урона и структура защитного слоя)  
**Репликация**: Полная репликация с RepNotify для обновления UI  
**Авторитет**: Сервер рассчитывает урон, клиенты получают обновления

## Система Типов Урона

### ECosmosDamageType Enum

Пять типов урона с разными характеристиками:

| Тип | Описание | Типичное использование |
|-----|----------|------------------------|
| **EM** | Электромагнитный | Энергетическое оружие, обычно сильно против щитов |
| **Thermal** | Тепловой | Лазеры, плазма, обычно сильно против брони |
| **Kinetic** | Кинетический | Рельсотроны, автопушки, физический удар |
| **Explosive** | Взрывной | Ракеты, бомбы, урон по площади |
| **Omni** | Чистый урон | Специальное оружие, проходит ВСЕ резисты |

### Поглощение на Основе Резистов

**Формула**: `ПоглощённыйУрон = СырьёвойУрон × (1.0 - Резист)`

**Примеры**:
- 100 урона с 0.5 (50%) резистом = 50 урона получено
- 100 урона с 0.75 (75%) резистом = 25 урона получено
- 100 урона с 0.0 (0%) резистом = 100 урона получено
- 100 Omni урона = 100 урона получено (проходит резисты)

## Структура Защитного Слоя

### FCosmosDefenseLayer

Каждый слой (Shield, Armor, Structure) содержит:

**Hit Points (Очки здоровья)**:
- `Current`: Текущий HP
- `Max`: Максимальный HP

**Резисты** (0.0 до 1.0):
- `ResistEM`: Резист EM урона
- `ResistThermal`: Резист теплового урона
- `ResistKinetic`: Резист кинетического урона
- `ResistExplosive`: Резист взрывного урона

**Вспомогательные функции**:
- `GetResistance(ECosmosDamageType)`: Получить резист для типа урона
- `CalculateMitigatedDamage(float, ECosmosDamageType)`: Рассчитать урон после поглощения
- `GetPercentage()`: Получить процент HP (0.0 до 1.0)
- `IsDepleted()`: Проверить, истощён ли слой
- `Restore()`: Восстановить до максимального HP

## Трёхслойная Система Защиты

### 1. Слой Щита (Shield)
**Свойства**:
- Первая линия обороны
- Может иметь высокий EM резист, низкий против других типов
- Типичный фрегат: 500-1500 HP

**Пример профиля резистов** (Caldari):
```cpp
Shield.ResistEM = 0.5f;        // 50% EM резист
Shield.ResistThermal = 0.2f;   // 20% Thermal резист
Shield.ResistKinetic = 0.4f;   // 40% Kinetic резист
Shield.ResistExplosive = 0.5f; // 50% Explosive резист
```

### 2. Слой Брони (Armor)
**Свойства**:
- Вторая линия обороны
- Другой профиль резистов чем у щита
- Типичный фрегат: 300-800 HP

**Пример профиля резистов** (Amarr):
```cpp
Armor.ResistEM = 0.5f;         // 50% EM резист
Armor.ResistThermal = 0.35f;   // 35% Thermal резист
Armor.ResistKinetic = 0.25f;   // 25% Kinetic резист
Armor.ResistExplosive = 0.1f;  // 10% Explosive резист
```

### 3. Слой Структуры (Structure/Hull)
**Свойства**:
- Последняя линия обороны (корпус)
- Смерть при истощении
- Обычно самые низкие резисты
- Типичный фрегат: 400-600 HP

**Пример профиля резистов** (Стандартный):
```cpp
Structure.ResistEM = 0.0f;        // 0% EM резист
Structure.ResistThermal = 0.0f;   // 0% Thermal резист
Structure.ResistKinetic = 0.0f;   // 0% Kinetic резист
Structure.ResistExplosive = 0.0f; // 0% Explosive резист
```

## Каскад Урона с Резистами

### Как Урон Проходит Через Слои

```
Входящий Урон (100 Thermal)
      ↓
[Щит: 50 HP, 20% Thermal резист]
  → Поглощённый: 100 × (1.0 - 0.2) = 80 урона
  → Щит получает 50 урона (истощён)
  → Переполнение: 30 урона
      ↓
[Броня: 200 HP, 35% Thermal резист]
  → Поглощённый: 30 × (1.0 - 0.35) = 19.5 урона
  → Броня получает 19.5 урона
  → Броня: 180.5 HP осталось
      ↓
Результат: Корабль выживает с 0/180.5/400 HP
```

## Основные Функции

### `ServerOnly_ApplyDamage(float RawDamage, ECosmosDamageType DmgType, AActor* Instigator)`

**Авторитет**: Только сервер  
**Возвращает**: `bool` - True если урон был применён

**Параметры**:
- `RawDamage`: Сырьевой урон до поглощения резистами
- `DmgType`: Тип урона (EM, Thermal, Kinetic, Explosive, Omni)
- `Instigator`: Актор, причинивший урон (для атрибуции килла)

**Поведение**:
1. Валидация авторитета сервера и состояния актора
2. Рассчёт поглощённого урона для слоя Щита
3. Применение к Щиту, расчёт переполнения
4. Если переполнение > 0, расчёт поглощённого урона для Брони (с резистами Брони)
5. Применение к Броне, расчёт переполнения
6. Если переполнение > 0, расчёт поглощённого урона для Структуры (с резистами Структуры)
7. Применение к Структуре
8. Если Структура <= 0, вызов события OnDeath

**Пример**:
```cpp
UCosmosAttributesComponent* AttrComp = 
    Target->FindComponentByClass<UCosmosAttributesComponent>();

if (AttrComp && AttrComp->IsAlive())
{
    // Применить 100 теплового урона
    AttrComp->ServerOnly_ApplyDamage(100.0f, ECosmosDamageType::Thermal, WeaponOwner);
}
```

### `ServerOnly_SetLayerResistances(int32 LayerIndex, float EM, float Thermal, float Kinetic, float Explosive)`

**Авторитет**: Только сервер  
**Назначение**: Установить резисты для конкретного слоя во время выполнения

**Параметры**:
- `LayerIndex`: 0=Щит, 1=Броня, 2=Структура
- `EM`, `Thermal`, `Kinetic`, `Explosive`: Значения резистов (0.0 до 1.0)

**Пример**:
```cpp
// Установить резисты щита на профиль Caldari
AttrComp->ServerOnly_SetLayerResistances(0, 0.5f, 0.2f, 0.4f, 0.5f);

// Установить резисты брони на профиль Amarr
AttrComp->ServerOnly_SetLayerResistances(1, 0.5f, 0.35f, 0.25f, 0.1f);
```

## Функции Получения Данных

Все геттеры `BlueprintPure` и работают на сервере и клиенте:

- `Common_GetShieldPct()`: Процент щита (0.0 до 1.0)
- `Common_GetArmorPct()`: Процент брони (0.0 до 1.0)
- `Common_GetHullPct()`: Процент структуры (0.0 до 1.0)
- `Common_GetOverallHealthPct()`: Общий процент здоровья (все слои вместе)
- `IsAlive()`: True если Структура > 0

## Делегаты

### `FOnAttributesChanged` (BlueprintAssignable)

**Сигнатура**: `void ()`  
**Вызывается**: На клиентах когда любой реплицированный атрибут изменяется  
**Назначение**: Обновление UI виджетов

### `FOnCosmosDeath` (BlueprintAssignable)

**Сигнатура**: `void (AActor* Victim, AActor* Killer)`  
**Вызывается**: На сервере когда Структура истощается  
**Назначение**: Запуск логики смерти

## Примеры Конфигурации

### Фрегат Caldari (Щитовой танк)

```cpp
// Высокий HP щита, хорошие EM/Explosive резисты щита
AttrComp->Shield.Max = 1200.0f;
AttrComp->Shield.Current = 1200.0f;
AttrComp->Shield.ResistEM = 0.5f;
AttrComp->Shield.ResistThermal = 0.2f;
AttrComp->Shield.ResistKinetic = 0.4f;
AttrComp->Shield.ResistExplosive = 0.5f;

// Низкая броня
AttrComp->Armor.Max = 400.0f;
AttrComp->Armor.Current = 400.0f;

// Стандартная структура
AttrComp->Structure.Max = 500.0f;
AttrComp->Structure.Current = 500.0f;
```

### Фрегат Amarr (Броневой танк)

```cpp
// Умеренный щит
AttrComp->Shield.Max = 600.0f;
AttrComp->Shield.Current = 600.0f;

// Высокий HP брони, хорошие EM/Thermal резисты брони
AttrComp->Armor.Max = 1000.0f;
AttrComp->Armor.Current = 1000.0f;
AttrComp->Armor.ResistEM = 0.5f;
AttrComp->Armor.ResistThermal = 0.35f;
AttrComp->Armor.ResistKinetic = 0.25f;
AttrComp->Armor.ResistExplosive = 0.1f;

// Стандартная структура
AttrComp->Structure.Max = 500.0f;
AttrComp->Structure.Current = 500.0f;
```

## Статистика Физики

Компонент также хранит атрибуты физики:

```cpp
// Масса в килограммах (влияет на ускорение)
AttrComp->Mass = 1250000.0f; // 1,250 тонн

// Модификатор инерции (влияет на повороты)
AttrComp->InertiaModifier = 1.2f;

// Вместимость груза в кубометрах
AttrComp->CargoCapacity = 400.0f; // 400 м³
```

## Сравнение с EchoesStatsComponent

| Функция | EchoesStatsComponent | CosmosAttributesComponent |
|---------|---------------------|---------------------------|
| Типы урона | Нет (единый) | 5 типов с резистами |
| Резисты | Нет | Да (на слой, на тип) |
| Поглощение урона | Нет | Да (на основе резистов) |
| Регенерация щита | Да (пассивная) | Нет (нужно добавлять отдельно) |
| Сложность | Простая | Продвинутая |
| Использование | Базовый бой | Production EVE-подобный бой |

**Рекомендация**: Используйте `CosmosAttributesComponent` для production систем, требующих продвинутой механики урона. Используйте `EchoesStatsComponent` для простых игровых режимов или как пример для обучения.

## Требования Выполнены ✅

- ✅ Файл `EchoesCoreTypes.h` создан
- ✅ Enum `ECosmosDamageType` с 5 типами урона
- ✅ Struct `FCosmosDefenseLayer` с Current/Max и 4 резистами
- ✅ Хелпер-функция `GetResistance(ECosmosDamageType Type)`
- ✅ Файлы `CosmosAttributesComponent.h` и `.cpp` созданы
- ✅ Наследование от `UActorComponent`
- ✅ Три переменные `FCosmosDefenseLayer`: Shield, Armor, Structure
- ✅ Все используют `ReplicatedUsing = ClientOnly_OnRep_Stats`
- ✅ Physics Stats: Mass, InertiaModifier, CargoCapacity (реплицированы)
- ✅ Функция `ServerOnly_ApplyDamage` с правильной математикой поглощения
- ✅ Функция `ClientOnly_OnRep_Stats` вызывает диспетчер
- ✅ Геттеры: `Common_GetShieldPct()`, `Common_GetArmorPct()`, `Common_GetHullPct()`
- ✅ Использован `DOREPLIFETIME` для всех переменных
- ✅ Код чистый, готовый к Production
- ✅ Правильная математика поглощения урона (Mitigation)

## Статистика Реализации

**Файлы**:
- `EchoesCoreTypes.h` - 163 строки (типы данных)
- `CosmosAttributesComponent.h` - 263 строки (заголовок)
- `CosmosAttributesComponent.cpp` - 356 строк (реализация)

**Всего**: 782 строки production-ready C++ кода

**Функциональность**:
- 5 типов урона с enum
- 3 защитных слоя с 4 резистами каждый
- Полная система поглощения урона
- 7 публичных функций
- 2 делегата для событий
- Полная репликация

---

**Статус**: ✅ Реализовано  
**Приоритет**: Высокий  
**Milestone**: Боевая Система - Milestone 3  
**Дата**: 2026-02-06
