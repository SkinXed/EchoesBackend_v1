# Система Target Lock - Руководство по Интеграции с Blueprint

## Обзор

**UTargetingComponent** предоставляет систему захвата целей в стиле EVE для корабельного боя с полной поддержкой Blueprint. Это руководство объясняет, как интегрировать систему захвата с UI виджетами и игровой логикой.

## Архитектура

**Сетевая модель**: Клиент-Сервер
- **Клиент**: Инициирует запросы на захват, отображает UI
- **Сервер**: Валидирует запросы, управляет таймерами, контролирует состояние
- **Репликация**: Массив TargetLocks реплицируется клиентам для обновления UI

**Формула Захвата**: `T = k / (ScanResolution × ln(TargetSize))`
- `T` = Время захвата в секундах
- `k` = LockTimeConstant (по умолчанию: 40000)
- `ScanResolution` = Разрешение сканирования корабля (по умолчанию: 100)
- `TargetSize` = Радиус сигнатуры цели в метрах

## Настройка Компонента

### Добавление к Ship Pawn

**В Blueprint**:
1. Открыть Blueprint корабля
2. Add Component → Поиск "Targeting Component"
3. Настроить свойства в панели Details:
   - **Max Lock Range**: 2500000 (25км в см)
   - **Scan Resolution**: 100
   - **Lock Time Constant**: 40000
   - **Max Simultaneous Locks**: 5

## Blueprint API

### Функции (BlueprintCallable)

#### ServerRPC_StartLock
Запрос захвата цели (клиент вызывает, сервер выполняет).

**Параметры**:
- `Target` (Actor): Актор для захвата

**Использование**:
```
Event: Клик мыши по цели
  ↓
Get Targeting Component
  ↓
ServerRPC_StartLock (Target = Clicked Actor)
```

#### ServerRPC_CancelLock
Отменить активный захват.

**Параметры**:
- `Target` (Actor): Актор для отмены захвата

#### ServerRPC_ClearAllLocks
Очистить все активные захваты.

### Pure Функции (BlueprintPure)

Эти функции можно использовать в графах Blueprint без execution pins.

#### Common_GetLockProgress
Получить прогресс захвата для конкретной цели.

**Возвращает**: `float` (0.0 до 1.0), или -1.0 если не найдено

**Использование**:
```
Get Targeting Component
  ↓
Common_GetLockProgress (Target)
  ↓
Set Progress Bar Percent
```

#### Common_GetLockState
Получить состояние захвата для конкретной цели.

**Возвращает**: `ETargetLockState` (None, Locking, Locked, Lost)

#### Common_IsTargetLocked
Проверить, полностью ли захвачена цель.

**Возвращает**: `bool` (True если захвачена)

#### Common_GetLockedTargets
Получить все захваченные цели.

**Возвращает**: `Array<Actor>` (Все захваченные цели)

#### Common_GetAvailableLockSlots
Получить количество доступных слотов захвата.

**Возвращает**: `int32` (Оставшиеся слоты)

#### Common_IsTargetInRange
Проверить, находится ли цель в радиусе захвата.

**Возвращает**: `bool` (True если в радиусе)

#### Common_CalculateLockTime
Рассчитать требуемое время захвата цели.

**Возвращает**: `float` (Время в секундах)

## Blueprint События

### OnLockStarted
Срабатывает когда начинается захват.

**Параметры**:
- `Target` (Actor): Цель, которая захватывается

**Использование**:
```
Event OnLockStarted
  ↓
Create Lock Frame Widget (Создать виджет рамки захвата)
  ↓
Add to Viewport
```

### OnLockCompleted
Срабатывает когда захват завершён.

**Параметры**:
- `Target` (Actor): Цель, которая была захвачена

**Использование**:
```
Event OnLockCompleted
  ↓
Play Lock Sound Effect (Воспроизвести звук захвата)
  ↓
Update Lock Frame to "Locked" State
```

### OnLockLost
Срабатывает когда захват потерян (вне радиуса, цель уничтожена и т.д.).

**Параметры**:
- `Target` (Actor): Цель, которая потеряла захват

**Использование**:
```
Event OnLockLost
  ↓
Remove Lock Frame Widget (Удалить виджет рамки)
  ↓
Play Warning Sound (Воспроизвести предупреждающий звук)
```

### OnLockProgress
Срабатывает каждый тик во время захвата с обновлением прогресса.

**Параметры**:
- `Target` (Actor): Цель, которая захватывается
- `Progress` (float): Прогресс от 0.0 до 1.0

**Использование**:
```
Event OnLockProgress
  ↓
Update Progress Bar (Обновить полосу прогресса)
  ↓
Update Lock Frame Animation (Обновить анимацию рамки)
```

## Реализация UI Виджета

### Виджет Рамки Захвата (Lock Frame Widget)

**Назначение**: Отображение прогресса захвата на цели с анимированной рамкой.

#### Структура Виджета
```
Canvas Panel
├─ Lock Frame Image (Рамка)
├─ Progress Ring (Материал с параметром прогресса)
├─ Target Name (Текстовый блок - имя цели)
├─ Lock Status (Текстовый блок: "Захват..." или "Захвачено")
└─ Distance (Текстовый блок - дистанция)
```

#### Blueprint Реализация

**1. Переменные Виджета**:
```
- TargetActor (Actor) - Цель
- TargetingComponent (Targeting Component) - Компонент захвата
- LockProgress (Float): 0.0 до 1.0 - Прогресс
- IsLocked (Bool) - Захвачена ли
```

**2. Event Construct**:
```
Event Construct
  ↓
Get Owning Player Pawn
  ↓
Get Component By Class (Targeting Component)
  ↓
Store in Variable (Сохранить в переменную)
  ↓
Bind Events (Привязать события):
  - OnLockStarted → Update UI
  - OnLockCompleted → Set Locked State
  - OnLockLost → Remove Widget
  - OnLockProgress → Update Progress
```

**3. Event Tick**:
```
Event Tick
  ↓
Is Valid? (TargetActor)
  ↓ Yes
Project World to Screen (TargetActor Location)
  ↓
Set Widget Position (Screen Position)
  ↓
Get Lock Progress (TargetActor)
  ↓
Update Progress Ring Material Parameter
  ↓
Update Lock Status Text
```

**4. Функция UpdateProgress**:
```
Function: UpdateProgress
  ↓
Get Lock Progress (Target)
  ↓
Branch: Progress >= 1.0?
  ↓ Yes: Set Status Text = "ЗАХВАЧЕНО"
  ↓      Set Frame Color = Зелёный
  ↓      Play Lock Complete Animation
  ↓
  ↓ No:  Set Status Text = "ЗАХВАТ..."
         Set Frame Color = Жёлтый
         Update Progress Ring (0.0 до 1.0)
```

### Материал Рамки Захвата

**Параметры Материала**:
- `Progress` (Scalar): 0.0 до 1.0 для кругового прогресса
- `Color` (Vector): Цвет рамки (Жёлтый для захвата, Зелёный для захваченного)
- `Thickness` (Scalar): Толщина линии рамки

**Логика Материала**:
```
UV Coordinates
  ↓
Radial Gradient (От центра к краю)
  ↓
Compare: Угол < (Progress × 360°)
  ↓
Mask for Progress Ring (Маска для кольца прогресса)
  ↓
Multiply by Color
```

## Примеры Использования

### Пример 1: Базовый Захват по Клику

**PlayerController Blueprint**:
```
Event: Mouse Left Click (Клик левой кнопкой)
  ↓
Line Trace by Channel (From Camera)
  ↓
Did Hit?
  ↓ Yes
Get Hit Actor
  ↓
Get Targeting Component (From Player Pawn)
  ↓
Is Target In Range? (Hit Actor)
  ↓ Yes
Get Available Lock Slots > 0?
  ↓ Yes
ServerRPC_StartLock (Hit Actor)
  ↓
Create Lock Frame Widget
  ↓
Add to Viewport
```

### Пример 2: Захват Всех Целей в Радиусе

**Blueprint Function**: `LockAllHostiles`
```
Get Targeting Component
  ↓
Get All Actors of Class (Enemy Ships - Вражеские корабли)
  ↓
For Each Enemy:
  ↓
  Is Target In Range? (Enemy)
  ↓ Yes
  Get Available Lock Slots > 0?
  ↓ Yes
  ServerRPC_StartLock (Enemy)
```

### Пример 3: Отображение Полосы Прогресса

**Lock Frame Widget Blueprint**:
```
Event OnLockProgress (Target, Progress)
  ↓
Set Progress Bar Percent (Progress)
  ↓
Format Text: "{0}%" (Progress × 100)
  ↓
Set Text Block Text
  ↓
Update Material Parameter "Progress" (Progress)
```

### Пример 4: Отмена Захвата по Правому Клику

**PlayerController Blueprint**:
```
Event: Mouse Right Click (Правый клик)
  ↓
Line Trace by Channel (From Camera)
  ↓
Did Hit?
  ↓ Yes
Get Hit Actor
  ↓
Get Targeting Component
  ↓
Is Target Locked? (Hit Actor)
  ↓ Yes
ServerRPC_CancelLock (Hit Actor)
  ↓
Remove Lock Frame Widget (Удалить виджет)
```

### Пример 5: Автоотмена Захватов Вне Радиуса

**Ship Pawn Blueprint** (Event Tick):
```
Event Tick
  ↓
Get Targeting Component
  ↓
Get Locked Targets
  ↓
For Each Target:
  ↓
  Is Target In Range? (Target)
  ↓ No
  ServerRPC_CancelLock (Target)
  ↓
  Display Warning: "Захват потерян - Вне радиуса"
```

## Визуальные Стили Рамки Захвата

### Стиль 1: EVE Online
- Круглая вращающаяся рамка
- Кольцо прогресса заполняется по часовой стрелке
- Жёлтый во время захвата, зелёный когда захвачено
- Имя цели и дистанция в центре

### Стиль 2: X-Wing
- Квадратные скобки по углам
- Скобки анимируются внутрь во время захвата
- Индикатор упреждения цели
- Тон захвата увеличивается по частоте

### Стиль 3: Современная Научная Фантастика
- Шестиугольная рамка
- Голографический материал
- Анимация линий сканирования
- Эффект глитча во время захвата

## Оптимизация Производительности

### Советы по Оптимизации

1. **Пулинг Виджетов**: Переиспользовать виджеты рамок вместо создания/уничтожения
2. **Частота Обновления**: Обновлять UI на 30 FPS вместо 60 FPS для рамок захвата
3. **Проверки Дистанции**: Обновлять только видимые рамки захвата (на экране)
4. **Material Instances**: Использовать динамические экземпляры материалов для колец прогресса
5. **Throttling Событий**: Ограничивать события OnLockProgress для уменьшения обновлений виджетов

## Требования Выполнены ✅

### Технические Требования ✅
- ✅ Класс: `UTargetingComponent` (ActorComponent)
- ✅ Крепится к AEPawn (кораблю)
- ✅ Сетевая модель: Клиент инициирует, сервер контролирует таймер и валидацию
- ✅ Префиксы: `ServerRPC_` для запросов, `ClientRPC_` для уведомлений, `Common_` для расчётов

### Логика ✅
- ✅ Метод `ServerRPC_StartLock(AActor* Target)`: Проверяет дистанцию и SignatureRadius цели
- ✅ Таймер: Время захвата рассчитывается по формуле: `T = k / (ScanResolution × ln(TargetSize))`
- ✅ Списки: `TArray<FTargetLockEntry>` (структура с Actor, Progress и State)

### Blueprint Integration ✅
- ✅ Custom Events: `OnLockStarted`, `OnLockCompleted`, `OnLockLost`, `OnLockProgress` для UI
- ✅ Pure функции получения прогресса захвата
- ✅ Полная документация по интеграции с виджетами

### Безопасность ✅
- ✅ Никакой прямой записи в БД
- ✅ Только логика внутри UE Server
- ✅ Серверная авторитетность

## Отладка

### Типичные Проблемы

**Проблема**: Рамка захвата не появляется  
**Решение**: Проверить, что событие OnLockStarted привязано и виджет добавлен на viewport

**Проблема**: Прогресс не обновляется  
**Решение**: Убедиться, что событие OnLockProgress привязано и обновляет параметр материала

**Проблема**: Захват завершается мгновенно  
**Решение**: Проверить значения LockTimeConstant и ScanResolution

**Проблема**: Не могу захватить цель  
**Решение**: Проверить, что цель в радиусе (MaxLockRange) и посмотреть логи для ошибок

---

**Статус**: ✅ Реализовано  
**Последнее Обновление**: 2026-02-06  
**Зависимости**: UTargetingComponent, Blueprint UI Framework
