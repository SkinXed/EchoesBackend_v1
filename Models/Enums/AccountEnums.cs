namespace Nebula.Inventory.API.Models.Enums
{
    /// <summary>
    /// Тип аккаунта
    /// </summary>
    public enum AccountType : int
    {
        Free = 0,           // Бесплатный аккаунт
        Alpha = 1,          // Альфа-клоны (ограничения)
        Omega = 2,          // Омега-подписка
        Veteran = 3,        // Ветеран
        Creator = 4,        // Создатель контента
        Admin = 5,          // Администратор
        GameMaster = 6      // Гейм-мастер
    }
    
    /// <summary>
    /// Статус аккаунта
    /// </summary>
    public enum AccountStatus : int
    {
        Pending = 0,        // Ожидает подтверждения
        Active = 1,         // Активный
        Suspended = 2,      // Приостановлен
        Banned = 3,         // Забанен
        Deleted = 4,        // Удален
        Inactive = 5        // Неактивен (давно не заходил)
    }
    
    /// <summary>
    /// Типы подписок
    /// </summary>
    public enum SubscriptionType : int
    {
        None = 0,           // Нет подписки
        Monthly = 1,        // Месячная
        Quarterly = 2,      // Квартальная
        Yearly = 3,         // Годовая
        Lifetime = 4        // Пожизненная
    }
    
    /// <summary>
    /// Типы двухфакторной аутентификации
    /// </summary>
    public enum TwoFactorType : int
    {
        None = 0,           // Без 2FA
        Email = 1,          // Email код
        App = 2,            // Приложение (Google/Microsoft Authenticator)
        Sms = 3,            // SMS код
        Hardware = 4        // Аппаратный ключ
    }
    
    /// <summary>
    /// Роли аккаунта
    /// </summary>
    [Flags]
    public enum AccountRole : long
    {
        None = 0,
        Player = 1L << 0,           // Базовые права игрока
        Verified = 1L << 1,         // Верифицированный аккаунт
        Premium = 1L << 2,          // Премиум статус
        BetaTester = 1L << 3,       // Бета-тестер
        ContentCreator = 1L << 4,   // Создатель контента
        Moderator = 1L << 5,        // Модератор
        Support = 1L << 6,          // Поддержка
        Admin = 1L << 7,            // Администратор
        Developer = 1L << 8,        // Разработчик
        System = 1L << 9            // Системный аккаунт
    }
    
    /// <summary>
    /// Настройки уведомлений
    /// </summary>
    [Flags]
    public enum NotificationSettings : long
    {
        None = 0,
        EmailMarketing = 1L << 0,    // Маркетинговые рассылки
        EmailSecurity = 1L << 1,     // Уведомления безопасности
        EmailGame = 1L << 2,         // Игровые уведомления
        PushMarket = 1L << 3,        // Уведомления рынка
        PushChat = 1L << 4,          // Уведомления чата
        PushCorp = 1L << 5,          // Корпоративные уведомления
        SmsSecurity = 1L << 6,       // SMS для безопасности
        All = EmailMarketing | EmailSecurity | EmailGame | PushMarket | PushChat | PushCorp | SmsSecurity
    }
    
    /// <summary>
    /// Типы логирования активности
    /// </summary>
    public enum ActivityType : int
    {
        Login = 0,                  // Вход в аккаунт
        Logout = 1,                 // Выход из аккаунта
        FailedLogin = 2,            // Неудачная попытка входа
        PasswordChange = 3,         // Смена пароля
        EmailChange = 4,            // Смена email
        TwoFactorEnabled = 5,       // Включение 2FA
        TwoFactorDisabled = 6,      // Отключение 2FA
        SubscriptionStart = 7,      // Начало подписки
        SubscriptionEnd = 8,        // Окончание подписки
        CharacterCreate = 9,        // Создание персонажа
        CharacterDelete = 10,       // Удаление персонажа
        Purchase = 11,              // Покупка в магазине
        Ban = 12,                   // Бан аккаунта
        Unban = 13,                 // Разбан аккаунта
        SupportTicket = 14,         // Создание тикета поддержки
        ApiKeyCreate = 15,          // Создание API ключа
        ApiKeyRevoke = 16           // Отзыв API ключа
    }
    
    /// <summary>
    /// Причины бана
    /// </summary>
    public enum BanReason : int
    {
        Cheating = 0,               // Читерство
        Exploiting = 1,             // Использование багов
        Harassment = 2,             // Харассмент
        HateSpeech = 3,             // Разжигание ненависти
        RealMoneyTrading = 4,       // RMT (торговля за реальные деньги)
        AccountSharing = 5,         // Совместное использование аккаунта
        Botting = 6,                // Использование ботов
        MultipleAccounts = 7,       // Мультиаккаунтинг
        Chargeback = 8,             // Отмена платежа
        ToSViolation = 9,           // Нарушение правил
        Other = 10                  // Другое
    }
    
    /// <summary>
    /// Типы API ключей
    /// </summary>
    public enum ApiKeyType : int
    {
        Character = 0,              // Ключ для персонажа
        Corporation = 1,            // Ключ для корпорации
        Account = 2,                // Ключ для аккаунта
        Developer = 3,              // Ключ разработчика
        System = 4                  // Системный ключ
    }
    
    /// <summary>
    /// Статус API ключа
    /// </summary>
    public enum ApiKeyStatus : int
    {
        Active = 0,                 // Активен
        Expired = 1,                // Истек
        Revoked = 2,                // Отозван
        Suspended = 3               // Приостановлен
    }
}