namespace Echoes.API.Models.Enums
{
    /// <summary>
    /// Типы аккаунтов
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
    /// Типы подписки
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
    /// Роли аккаунта (флаги)
    /// </summary>
    [Flags]
    public enum AccountRole : long
    {
        None = 0,
        Player = 1L << 0,              // Базовые права игрока
        Verified = 1L << 1,            // Верифицированный аккаунт
        Premium = 1L << 2,             // Премиум аккаунт
        Creator = 1L << 3,             // Создатель контента
        Streamer = 1L << 4,            // Стример
        
        // Корпоративные роли
        CorporationMember = 1L << 10,  // Член корпорации
        CorporationOfficer = 1L << 11, // Офицер корпорации
        CorporationDirector = 1L << 12, // Директор корпорации
        CorporationCEO = 1L << 13,     // CEO корпорации
        
        // Альянс
        AllianceMember = 1L << 20,     // Член альянса
        AllianceExecutor = 1L << 21,   // Исполнитель альянса
        
        // Модерация
        Moderator = 1L << 30,          // Модератор
        GameMaster = 1L << 31,         // Гейм-мастер
        Developer = 1L << 32,          // Разработчик
        Administrator = 1L << 33,      // Администратор
        
        // Специальные
        Beta = 1L << 40,               // Бета-тестер
        EventOrganizer = 1L << 41,     // Организатор событий
        Translator = 1L << 42,         // Переводчик
        
        // Бан
        Banned = 1L << 50,             // Забанен
        Muted = 1L << 51,              // Заглушен в чате
        Restricted = 1L << 52          // Ограничен в правах
    }
}
