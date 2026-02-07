# Система HUD в стиле EVE - Руководство по Blueprint

## Обзор

**EchoesMainHUD** - система интерфейса для EVE-like MMO с двумя режимами: **В Ангаре** (станция) и **В Космосе** (навигация/бой). Система использует событийно-ориентированные обновления без функции Tick.

## Архитектура

### Иерархия Виджетов

```
EchoesMainHUD (Корневой виджет)
├─ ModeSwitcher (WidgetSwitcher)
│  ├─ [Индекс 0] HangarHUD (Ангар)
│  │  ├─ Fitting Panel (Фитинг)
│  │  ├─ Inventory Panel (Инвентарь)
│  │  ├─ Social Panel (Социальная панель)
│  │  └─ Station Services (Услуги станции)
│  └─ [Индекс 1] SpaceHUD (Космос)
│     ├─ Navigation Panel (Навигация)
│     ├─ Target Panel (Цели)
│     ├─ Overview Panel (Обзор)
│     └─ Ship Status Panel (Статус корабля)
├─ Постоянные элементы
│  ├─ Shield/Armor/Hull Bars (Щит/Броня/Корпус)
│  └─ Speed/Target Count (Скорость/Кол-во целей)
```

## Создание HUD в Blueprint

### Шаг 1: Создание Widget Blueprint

1. **Content Browser** → Правый клик → **User Interface** → **Widget Blueprint**
2. Имя: `WBP_MainHUD`
3. Родительский класс: `EchoesMainHUD` (C++)

### Шаг 2: Структура в UMG Designer

**Добавить виджеты**:

```
Canvas Panel (Root)
├─ Widget Switcher "ModeSwitcher"
│  ├─ [Слот 0] User Widget "HangarHUD" (WBP_HangarHUD)
│  └─ [Слот 1] User Widget "SpaceHUD" (WBP_SpaceHUD)
├─ Vertical Box "ShipStatusContainer" (Низ экрана)
│  ├─ Progress Bar "ShieldBar" (Зелёный)
│  ├─ Progress Bar "ArmorBar" (Оранжевый)
│  └─ Progress Bar "HullBar" (Красный)
└─ Horizontal Box "InfoContainer" (Верх экрана)
   ├─ Text Block "SpeedText"
   └─ Text Block "TargetCountText"
```

**Важно**: Все виджеты должны иметь флаг **Is Variable = True** для привязки в C++.

### Шаг 3: Привязка Виджетов

В панели **Details** для каждого виджета:

| Виджет | Variable Name | Bind Widget |
|--------|--------------|-------------|
| Widget Switcher | ModeSwitcher | ✅ |
| User Widget (Ангар) | HangarHUD | ✅ |
| User Widget (Космос) | SpaceHUD | ✅ |
| Progress Bar (Щит) | ShieldBar | ✅ (Optional) |
| Progress Bar (Броня) | ArmorBar | ✅ (Optional) |
| Progress Bar (Корпус) | HullBar | ✅ (Optional) |
| Text Block (Скорость) | SpeedText | ✅ (Optional) |
| Text Block (Цели) | TargetCountText | ✅ (Optional) |

**BindWidget vs BindWidgetOptional**:
- `BindWidget`: Обязательный виджет (ошибка если отсутствует)
- `BindWidgetOptional`: Необязательный виджет

## Логика Переключения Состояний

### Event Graph Blueprint

#### Инициализация

```
Event Construct
  ↓
Parent: Construct
  ↓
Set Initial State → SetGameState(InHangar)
  ↓
Bind Custom Events
```

#### Событие: Docking (Стыковка)

```
Custom Event: OnDockingComplete
  ↓
Self → SetGameState
  - New State: InHangar
  ↓
Play Animation (Docking Sequence)
  ↓
Show Station Menu Widget
```

#### Событие: Undocking (Расстыковка)

```
Custom Event: OnUndockingComplete
  ↓
Self → SetGameState
  - New State: InSpace
  ↓
Play Animation (Undock Sequence)
  ↓
Enable Flight Controls
```

#### Событие: OnGameStateChanged

```
Event OnGameStateChanged (NewState)
  ↓
Branch: NewState == InSpace?
  ↓ Yes
  │ Enable Space Controls
  │ ↓
  │ Show Navigation Panel
  │ ↓
  │ Start Space Music
  │
  ↓ No (InHangar)
    Disable Space Controls
    ↓
    Show Station Services
    ↓
    Start Hangar Music
```

## Создание Подвиджетов

### HangarHUD Widget (WBP_HangarHUD)

**Структура**:
```
Canvas Panel
├─ Horizontal Box (Main Layout)
│  ├─ Vertical Box "FittingPanel" (Слева)
│  │  ├─ Text "Ship Fitting"
│  │  ├─ Grid Panel (Слоты модулей 8x3)
│  │  └─ Button "Save Fitting"
│  ├─ Vertical Box "InventoryPanel" (Центр)
│  │  ├─ Text "Cargo Hold"
│  │  ├─ Scroll Box (Список предметов)
│  │  └─ Text "Capacity: 500/1000 m³"
│  └─ Vertical Box "SocialPanel" (Справа)
│     ├─ Text "Corporation"
│     ├─ List View (Члены корпорации)
│     └─ Text Block "Fleet Status"
└─ Overlay "StationServices" (Низ)
   ├─ Button "Market"
   ├─ Button "Repair"
   └─ Button "Reprocess"
```

**Event Graph**:
```
Event OnEnterHangar (From Parent)
  ↓
Load Ship Fitting Data
  ↓
Refresh Inventory
  ↓
Update Corporation Info
  ↓
Set Visibility → Visible
```

### SpaceHUD Widget (WBP_SpaceHUD)

**Структура**:
```
Canvas Panel
├─ Vertical Box "NavigationPanel" (Слева)
│  ├─ Button "Autopilot"
│  ├─ Text "Destination: Jita"
│  └─ Button "Jump"
├─ Vertical Box "TargetPanel" (Справа)
│  ├─ Text "Target: Enemy Frigate"
│  ├─ Progress Bar "Target Shield"
│  ├─ Progress Bar "Target Armor"
│  ├─ Progress Bar "Target Hull"
│  └─ Text "Distance: 15.5 km"
├─ Vertical Box "OverviewPanel" (Центр-Низ)
│  ├─ Text "Overview"
│  ├─ List View (Nearby Ships)
│  └─ Combo Box "Filter"
└─ Invalidation Box "ShipStatusPanel"
   └─ (Shield/Armor/Hull bars from parent)
```

**Event Graph**:
```
Event OnEnterSpace (From Parent)
  ↓
Initialize Navigation System
  ↓
Load Overview Filters
  ↓
Clear Target List
  ↓
Set Visibility → Visible
  ↓
Start Scanning Timer
```

## Обновление Данных Корабля

### Метод 1: Событийно-Ориентированный

```
Event OnShipStatusUpdated (ShipData)
  ↓
Break FCommon_ShipDataStruct
  ↓
Update Shield Bar
  - Percent: ShieldCurrent / ShieldMax
  - Color: Common_GetHealthBarColor(Percent)
  ↓
Update Armor Bar
  - Percent: ArmorCurrent / ArmorMax
  - Color: Common_GetHealthBarColor(Percent)
  ↓
Update Hull Bar
  - Percent: StructureCurrent / StructureMax
  - Color: Common_GetHealthBarColor(Percent)
  ↓
Update Speed Text
  - Text: Common_FormatSpeed(Speed)
```

### Метод 2: Периодический Таймер

Уже реализован в C++ - обновление каждые 0.1 секунды.

**Настройка в Blueprint**:
```
Event Construct
  ↓
Set Ship Status Update Rate = 0.1
  - Значение: 0.1 (10 раз в секунду)
  - Значение: 0.2 (5 раз в секунду, меньше нагрузка)
```

## Расчет Упреждения Цели

### Pure Function: Common_GetTargetLeadIndicator

**Использование в Blueprint**:

```
Event Tick (Only for targeting reticle)
  ↓
Get Current Target Actor
  ↓
Is Valid?
  ↓ Yes
  Common_GetTargetLeadIndicator
    - Target Actor: CurrentTarget
    - Projectile Speed: 50000.0 (см/с)
  ↓
  Returns: FVector (Lead Position)
  ↓
  Project World to Screen (Lead Position)
  ↓
  Returns: FVector2D (Screen Position)
  ↓
  Set Render Translation (Targeting Reticle Widget)
    - Translation: Screen Position
```

**Результат**: Прицельная метка указывает куда стрелять для попадания в движущуюся цель.

## Цветовая Индикация Здоровья

### Common_GetHealthBarColor

**Логика**:
```
Percentage > 50% → Зелёный (0, 1, 0)
Percentage 25-50% → Жёлтый (1, 1, 0)
Percentage < 25% → Красный (1, 0, 0)
```

**Использование**:
```
Get Shield Percentage
  ↓
Common_GetHealthBarColor (Percentage)
  ↓
Set Fill Color and Opacity (Shield Bar)
  - Color: Result
```

## Форматирование Значений

### Common_FormatSpeed

**Вход**: Скорость в см/с  
**Выход**: "125.5 m/s"

```
Get Velocity → Size
  ↓
Common_FormatSpeed (Size)
  ↓
Set Text (Speed Text Block)
  - Text: Result
```

### Common_FormatDistance

**Вход**: Расстояние в см  
**Выход**: 
- "450 m" (< 1000м)
- "2.5 km" (≥ 1000м)

```
Get Distance To Actor (Target)
  ↓
Common_FormatDistance (Distance)
  ↓
Set Text (Distance Text Block)
  - Text: Result
```

## Оптимизация UI

### Invalidation Box

**Что это**: Контейнер, который кэширует отрисовку и обновляет только при изменении содержимого.

**Когда использовать**:
- Статичные элементы (имя корабля, иконки)
- Редко изменяемые панели (фитинг)
- Большие списки (инвентарь)

**Пример**:
```
Invalidation Box "StaticShipInfo"
├─ Text "Ship Name" (не меняется часто)
├─ Image "Ship Icon"
└─ Text "Ship Type"

Event OnShipChanged
  ↓
Update Ship Name/Icon/Type
  ↓
Invalidate Cache (StaticShipInfo)
```

### Отключение Tick

**По умолчанию**: Tick отключён в C++.

**Если нужен Tick для виджета** (например, для анимаций):
```
Event Construct
  ↓
Set Tick Frequency
  - Frequency: 0.1 (только 10 раз в секунду)
```

**Но лучше**: Использовать **Widget Animation** или **Timeline** вместо Tick.

## Интеграция с PlayerController

### Создание HUD

```
APlayerController Blueprint

Event BeginPlay
  ↓
Create Widget
  - Class: WBP_MainHUD
  - Owning Player: Self
  ↓
Add to Viewport
  - ZOrder: 0
  ↓
Promote to Variable → HUDWidget
```

### Обработка Docking

```
Custom Event: RequestDock
  ↓
Server RPC → ServerDock
  ↓ (На сервере)
  Validate Docking Conditions
  ↓ (Если успешно)
  Multicast RPC → OnDocked
  ↓ (На всех клиентах)
  HUDWidget → SetGameState(InHangar)
  ↓
  Disable Movement Input
  ↓
  Play Docking Animation
```

### Обработка Undocking

```
Custom Event: RequestUndock
  ↓
Server RPC → ServerUndock
  ↓ (На сервере)
  Validate Undocking Conditions
  ↓ (Если успешно)
  Multicast RPC → OnUndocked
  ↓ (На всех клиентах)
  HUDWidget → SetGameState(InSpace)
  ↓
  Enable Movement Input
  ↓
  Play Undocking Animation
```

## Реализация IShipStateInterface

### В Blueprint Ship Pawn

**1. Добавить Interface**:
- Class Settings → Implemented Interfaces → Add → ShipStateInterface

**2. Реализовать GetShipData**:
```
Event GetShipData (Returns: FCommon_ShipDataStruct)
  ↓
Make FCommon_ShipDataStruct
  ↓
Get Component (EchoesStatsComponent)
  ↓
Break Component
  - Shield Current → ShieldCurrent
  - Shield Max → ShieldMax
  - Armor Current → ArmorCurrent
  - Armor Max → ArmorMax
  - Structure Current → StructureCurrent
  - Structure Max → StructureMax
  ↓
Get Velocity → Velocity
  ↓
Get Velocity Size → Divide 100 → Speed (м/с)
  ↓
Get Actor Location → Location
  ↓
Get Actor Rotation → Rotation
  ↓
Get Name → ShipName
  ↓
Return → FCommon_ShipDataStruct
```

**3. Реализовать IsShipAlive**:
```
Event IsShipAlive (Returns: bool)
  ↓
Get Component (EchoesStatsComponent)
  ↓
Get StructureCurrent
  ↓
Greater Than 0
  ↓
Return → bool
```

**4. Реализовать GetCurrentTarget**:
```
Event GetCurrentTarget (Returns: Actor)
  ↓
Get Component (TargetingComponent)
  ↓
Common_GetLockedTargets
  ↓
Get (Index 0)
  ↓
Return → Actor (or null)
```

## Пример: Полный HUD Blueprint

### Переменные

```
Variable Name         | Type                      | Category
---------------------|---------------------------|----------
HUDWidget            | EchoesMainHUD            | UI
CurrentState         | EGameState               | State
ShipPawn             | Pawn (Ship)              | Ship
LastUpdateTime       | Float                    | Internal
```

### Event Construct

```
Event Construct
  ↓
Parent: Construct
  ↓
Get Owning Player Pawn → Cast to Ship Pawn
  ↓
Store in ShipPawn Variable
  ↓
Set Initial State
  - SetGameState(InHangar)
  ↓
Bind Event OnGameStateChanged
  - AddDynamic → HandleStateChange
  ↓
Bind Event OnShipStatusUpdated
  - AddDynamic → HandleShipStatusUpdate
```

### Event HandleStateChange

```
Event HandleStateChange (NewState)
  ↓
Set CurrentState = NewState
  ↓
Branch: NewState == InSpace?
  ↓ Yes
  │ Print String "Entering Space Mode"
  │ ↓
  │ Enable Flight Controls
  │ ↓
  │ Show Space UI Elements
  │ ↓
  │ Hide Hangar UI Elements
  │ ↓
  │ Play Space Music
  │
  ↓ No (InHangar)
    Print String "Entering Hangar Mode"
    ↓
    Disable Flight Controls
    ↓
    Show Hangar UI Elements
    ↓
    Hide Space UI Elements
    ↓
    Play Hangar Music
```

### Event HandleShipStatusUpdate

```
Event HandleShipStatusUpdate (ShipData)
  ↓
Break FCommon_ShipDataStruct
  ↓
Update UI Elements
  - Shield Bar Percent = GetShieldPercentage()
  - Armor Bar Percent = GetArmorPercentage()
  - Hull Bar Percent = GetStructurePercentage()
  ↓
Update Text Displays
  - Shield Text = Format("{0}/{1}", ShieldCurrent, ShieldMax)
  - Armor Text = Format("{0}/{1}", ArmorCurrent, ArmorMax)
  - Hull Text = Format("{0}/{1}", StructureCurrent, StructureMax)
  ↓
Update Colors
  - Shield Color = Common_GetHealthBarColor(ShieldPct)
  - Armor Color = Common_GetHealthBarColor(ArmorPct)
  - Hull Color = Common_GetHealthBarColor(HullPct)
```

## Отладка

### Проблема: Widget Switcher не переключается

**Проверка**:
1. ModeSwitcher привязан? (BindWidget)
2. Индексы правильные? (0 = Ангар, 1 = Космос)
3. Дочерние виджеты существуют?

**Debug**:
```
Event SetGameState
  ↓
Print String
  - Text: Format("Switching to: {0}", NewState)
  ↓
If ModeSwitcher IsValid
  ↓ Yes
  Print String "ModeSwitcher OK"
  ↓
  Get Active Widget Index
  ↓
  Print String
    - Text: Format("Current Index: {0}", Index)
```

### Проблема: Данные корабля не обновляются

**Проверка**:
1. Ship реализует IShipStateInterface?
2. Компонент EchoesStatsComponent существует?
3. События привязаны?

**Debug**:
```
Event Construct
  ↓
Get Player Ship
  ↓
Does Implement Interface? (ShipStateInterface)
  ↓
Print String
  - Text: Format("Has Interface: {0}", Result)
  ↓
If True
  GetShipData
  ↓
  Print String
    - Text: Format("Shield: {0}/{1}", ShieldCurrent, ShieldMax)
```

### Проблема: Производительность

**Проверка**:
1. Tick отключён?
2. ShipStatusUpdateRate не слишком малый?
3. Invalidation Box используется?

**Измерение**:
```
Console Commands:
- stat game
- stat ui
- stat unitgraph
```

## Советы по Производительности

### 1. Отключить Tick для виджетов
```
Class Defaults
  ↓
Tick
  - Can Ever Tick: False
```

### 2. Использовать Widget Animation
```
Add Animation (In UMG)
  - Name: FadeIn
  - Duration: 0.5s
  - Track: Opacity (0 → 1)

Event OnEnterSpace
  ↓
Play Animation (FadeIn)
```

### 3. Переиспользовать виджеты
```
Object Pool Pattern:
- Create 10 widgets at start
- Show/Hide instead of Create/Destroy
```

### 4. Ограничить частоту обновлений
```
Set Ship Status Update Rate
  - 0.1s = 10 Hz (Default)
  - 0.2s = 5 Hz (Экономия CPU)
```

---

**Статус**: ✅ Готово к Production  
**Версия**: 1.0  
**Последнее Обновление**: 2026-02-06
