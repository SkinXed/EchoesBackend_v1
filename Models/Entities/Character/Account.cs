using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Основная информация об аккаунте
    /// </summary>
    [Table("accounts")]
    public class Account
    {
        [Key]
        [Column("account_id")]
        public Guid AccountId { get; set; } = Guid.NewGuid();
        
        [Required]
        [EmailAddress]
        [Column("email")]
        public string Email { get; set; } = string.Empty;
        
        [Required]
        [Column("username")]
        public string Username { get; set; } = string.Empty;
        
        [Column("display_name")]
        public string? DisplayName { get; set; }
        
        [Required]
        [Column("password_hash")]
        public string PasswordHash { get; set; } = string.Empty;
        
        [Required]
        [Column("password_salt")]
        public string PasswordSalt { get; set; } = string.Empty;
        
        [Column("phone_number")]
        public string? PhoneNumber { get; set; }
        
        [Required]
        [Column("account_type")]
        public AccountType AccountType { get; set; } = AccountType.Free;
        
        [Required]
        [Column("account_status")]
        public AccountStatus AccountStatus { get; set; } = AccountStatus.Pending;
        
        [Required]
        [Column("roles")]
        public AccountRole Roles { get; set; } = AccountRole.Player;
        
        [Column("subscription_type")]
        public SubscriptionType SubscriptionType { get; set; } = SubscriptionType.None;
        
        [Column("subscription_start")]
        public DateTime? SubscriptionStart { get; set; }
        
        [Column("subscription_end")]
        public DateTime? SubscriptionEnd { get; set; }
        
        [Column("trial_ends_at")]
        public DateTime? TrialEndsAt { get; set; }
        
        // Двухфакторная аутентификация
        [Column("two_factor_type")]
        public TwoFactorType TwoFactorType { get; set; } = TwoFactorType.None;
        
        [Column("two_factor_secret")]
        public string? TwoFactorSecret { get; set; }
        
        [Column("two_factor_recovery_codes")]
        public string? TwoFactorRecoveryCodesJson { get; set; }
        
        [Column("is_email_verified")]
        public bool IsEmailVerified { get; set; }
        
        [Column("email_verified_at")]
        public DateTime? EmailVerifiedAt { get; set; }
        
        [Column("email_verification_token")]
        public string? EmailVerificationToken { get; set; }
        
        [Column("phone_verified_at")]
        public DateTime? PhoneVerifiedAt { get; set; }
        
        // Безопасность
        [Column("failed_login_attempts")]
        public int FailedLoginAttempts { get; set; }
        
        [Column("locked_until")]
        public DateTime? LockedUntil { get; set; }
        
        [Column("last_login")]
        public DateTime? LastLogin { get; set; }
        
        [Column("last_login_ip")]
        public string? LastLoginIp { get; set; }
        
        [Column("last_active")]
        public DateTime? LastActive { get; set; }
        
        [Column("password_changed_at")]
        public DateTime PasswordChangedAt { get; set; } = DateTime.UtcNow;
        
        [Column("password_reset_token")]
        public string? PasswordResetToken { get; set; }
        
        [Column("password_reset_expires")]
        public DateTime? PasswordResetExpires { get; set; }
        
        // Настройки
        [Column("notification_settings")]
        public NotificationSettings NotificationSettings { get; set; } = NotificationSettings.All;
        
        [Column("language")]
        public string Language { get; set; } = "en-US";
        
        [Column("timezone")]
        public string Timezone { get; set; } = "UTC";
        
        [Column("country_code")]
        public string? CountryCode { get; set; }
        
        [Column("referral_code")]
        public string ReferralCode { get; set; } = Guid.NewGuid().ToString("N")[..8].ToUpper();
        
        [Column("referred_by")]
        public string? ReferredBy { get; set; }
        
        // Статистика
        [Column("total_play_time")]
        public long TotalPlayTimeSeconds { get; set; }
        
        [Column("total_characters")]
        public int TotalCharacters { get; set; }
        
        [Column("total_spent")]
        public decimal TotalSpent { get; set; }
        
        [Column("total_referrals")]
        public int TotalReferrals { get; set; }
        
        // Метаданные
        [Column("metadata")]
        public string MetadataJson { get; set; } = string.Empty;
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        public virtual ICollection<Character> Characters { get; set; } = new List<Character>();
        public virtual ICollection<AccountSession> Sessions { get; set; } = new List<AccountSession>();
        public virtual ICollection<AccountActivity> Activities { get; set; } = new List<AccountActivity>();
        public virtual ICollection<AccountBan> Bans { get; set; } = new List<AccountBan>();
        public virtual ICollection<ApiKey> ApiKeys { get; set; } = new List<ApiKey>();
        public virtual ICollection<SupportTicket> SupportTickets { get; set; } = new List<SupportTicket>();
        
        // Дополнительное свойство для совместимости с кодом
        [NotMapped]
        public Guid Id
        {
            get => AccountId;
            set => AccountId = value;
        }
        
        // Методы
        [NotMapped]
        public Dictionary<string, object> Metadata
        {
            get => string.IsNullOrEmpty(MetadataJson) ? 
                new Dictionary<string, object>() : 
                System.Text.Json.JsonSerializer.Deserialize<Dictionary<string, object>>(MetadataJson)!;
            set => MetadataJson = System.Text.Json.JsonSerializer.Serialize(value);
        }
        
        [NotMapped]
        public List<string> TwoFactorRecoveryCodes
        {
            get => string.IsNullOrEmpty(TwoFactorRecoveryCodesJson) ? 
                new List<string>() : 
                System.Text.Json.JsonSerializer.Deserialize<List<string>>(TwoFactorRecoveryCodesJson)!;
            set => TwoFactorRecoveryCodesJson = System.Text.Json.JsonSerializer.Serialize(value);
        }
        
        public bool HasRole(AccountRole role)
        {
            return (Roles & role) == role;
        }
        
        public void AddRole(AccountRole role)
        {
            Roles |= role;
        }
        
        public void RemoveRole(AccountRole role)
        {
            Roles &= ~role;
        }
        
        public bool IsSubscribed()
        {
            return SubscriptionType != SubscriptionType.None && 
                   (!SubscriptionEnd.HasValue || SubscriptionEnd.Value > DateTime.UtcNow);
        }
        
        public bool IsOnTrial()
        {
            return TrialEndsAt.HasValue && TrialEndsAt.Value > DateTime.UtcNow;
        }
        
        public bool IsActive()
        {
            return AccountStatus == AccountStatus.Active && 
                   !IsLocked() && 
                   IsEmailVerified;
        }
        
        public bool IsLocked()
        {
            return LockedUntil.HasValue && LockedUntil.Value > DateTime.UtcNow;
        }
        
        public bool IsPasswordExpired()
        {
            // Пароль истекает через 90 дней
            return PasswordChangedAt.AddDays(90) < DateTime.UtcNow;
        }
        
        public bool ShouldEnableTwoFactor()
        {
            // Требование 2FA для определенных ролей и подписок
            return HasRole(AccountRole.Admin) || 
                   HasRole(AccountRole.Moderator) || 
                   SubscriptionType == SubscriptionType.Omega;
        }
        
        public void LockAccount(int minutes = 15)
        {
            LockedUntil = DateTime.UtcNow.AddMinutes(minutes);
            FailedLoginAttempts = 0;
        }
        
        public void UnlockAccount()
        {
            LockedUntil = null;
            FailedLoginAttempts = 0;
        }
        
        public void RecordFailedLogin()
        {
            FailedLoginAttempts++;
            
            if (FailedLoginAttempts >= 5)
            {
                LockAccount();
            }
        }
        
        public void RecordSuccessfulLogin(string ipAddress)
        {
            LastLogin = DateTime.UtcNow;
            LastLoginIp = ipAddress;
            LastActive = DateTime.UtcNow;
            FailedLoginAttempts = 0;
            LockedUntil = null;
        }
        
        public TimeSpan GetSubscriptionRemaining()
        {
            if (!SubscriptionEnd.HasValue || !IsSubscribed())
                return TimeSpan.Zero;
                
            return SubscriptionEnd.Value - DateTime.UtcNow;
        }
        
        public TimeSpan GetTrialRemaining()
        {
            if (!TrialEndsAt.HasValue || !IsOnTrial())
                return TimeSpan.Zero;
                
            return TrialEndsAt.Value - DateTime.UtcNow;
        }
    }
    
    /// <summary>
    /// Активность аккаунта (логи)
    /// </summary>
    [Table("account_activities")]
    public class AccountActivity
    {
        [Key]
        [Column("activity_id")]
        public long ActivityId { get; set; }
        
        [Required]
        [Column("account_id")]
        public Guid AccountId { get; set; }
        
        [Required]
        [Column("activity_type")]
        public ActivityType ActivityType { get; set; }
        
        [Column("ip_address")]
        public string? IpAddress { get; set; }
        
        [Column("user_agent")]
        public string? UserAgent { get; set; }
        
        [Column("location")]
        public string? LocationJson { get; set; }
        
        [Column("details")]
        public string? DetailsJson { get; set; }
        
        [Column("is_suspicious")]
        public bool IsSuspicious { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("AccountId")]
        public virtual Account Account { get; set; } = null!;
        
        // Методы
        public class LocationData
        {
            public string? Country { get; set; }
            public string? Region { get; set; }
            public string? City { get; set; }
            public double? Latitude { get; set; }
            public double? Longitude { get; set; }
        }
        
        [NotMapped]
        public LocationData? Location
        {
            get => string.IsNullOrEmpty(LocationJson) ? 
                null : 
                System.Text.Json.JsonSerializer.Deserialize<LocationData>(LocationJson);
            set => LocationJson = value == null ? null : System.Text.Json.JsonSerializer.Serialize(value);
        }
        
        [NotMapped]
        public Dictionary<string, object> Details
        {
            get => string.IsNullOrEmpty(DetailsJson) ? 
                new Dictionary<string, object>() : 
                System.Text.Json.JsonSerializer.Deserialize<Dictionary<string, object>>(DetailsJson)!;
            set => DetailsJson = System.Text.Json.JsonSerializer.Serialize(value);
        }
    }
    
    /// <summary>
    /// Баны аккаунта
    /// </summary>
    [Table("account_bans")]
    public class AccountBan
    {
        [Key]
        [Column("ban_id")]
        public Guid BanId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("account_id")]
        public Guid AccountId { get; set; }
        
        [Column("banned_by")]
        public Guid? BannedBy { get; set; } // AccountId модератора
        
        [Required]
        [Column("reason")]
        public BanReason Reason { get; set; }
        
        [Column("reason_text")]
        public string ReasonText { get; set; } = string.Empty;
        
        [Required]
        [Column("start_date")]
        public DateTime StartDate { get; set; } = DateTime.UtcNow;
        
        [Column("end_date")]
        public DateTime? EndDate { get; set; }
        
        [Column("is_permanent")]
        public bool IsPermanent { get; set; }
        
        [Column("appeal_allowed")]
        public bool AppealAllowed { get; set; } = true;
        
        [Column("appeal_status")]
        public AppealStatus AppealStatus { get; set; } = AppealStatus.None;
        
        [Column("appeal_text")]
        public string? AppealText { get; set; }
        
        [Column("appeal_reviewed_by")]
        public Guid? AppealReviewedBy { get; set; }
        
        [Column("appeal_reviewed_at")]
        public DateTime? AppealReviewedAt { get; set; }
        
        [Column("appeal_response")]
        public string? AppealResponse { get; set; }
        
        [Column("evidence")]
        public string? EvidenceJson { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("AccountId")]
        public virtual Account Account { get; set; } = null!;
        
        // Методы
        public bool IsActive()
        {
            if (IsPermanent)
                return true;
                
            return !EndDate.HasValue || EndDate.Value > DateTime.UtcNow;
        }
        
        public TimeSpan GetRemainingTime()
        {
            if (IsPermanent || !EndDate.HasValue)
                return TimeSpan.MaxValue;
                
            return EndDate.Value - DateTime.UtcNow;
        }
        
        public bool CanAppeal()
        {
            return AppealAllowed && 
                   AppealStatus == AppealStatus.None && 
                   IsActive();
        }
    }
    
    public enum AppealStatus
    {
        None = 0,
        Pending = 1,
        Approved = 2,
        Denied = 3
    }
    
    /// <summary>
    /// API ключи
    /// </summary>
    [Table("api_keys")]
    public class ApiKey
    {
        [Key]
        [Column("api_key_id")]
        public Guid ApiKeyId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("account_id")]
        public Guid AccountId { get; set; }
        
        [Required]
        [Column("key_name")]
        public string KeyName { get; set; } = string.Empty;
        
        [Required]
        [Column("api_key")]
        public string KeyValue { get; set; } = Guid.NewGuid().ToString("N") + Guid.NewGuid().ToString("N");
        
        [Required]
        [Column("key_type")]
        public ApiKeyType KeyType { get; set; }
        
        [Required]
        [Column("key_status")]
        public ApiKeyStatus KeyStatus { get; set; } = ApiKeyStatus.Active;
        
        [Column("character_id")]
        public Guid? CharacterId { get; set; }
        
        [Column("corporation_id")]
        public Guid? CorporationId { get; set; }
        
        [Column("permissions")]
        public string PermissionsJson { get; set; } = string.Empty;
        
        [Column("last_used")]
        public DateTime? LastUsed { get; set; }
        
        [Column("expires_at")]
        public DateTime? ExpiresAt { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("AccountId")]
        public virtual Account Account { get; set; } = null!;
        
        // Методы
        [NotMapped]
        public Dictionary<string, bool> Permissions
        {
            get => string.IsNullOrEmpty(PermissionsJson) ? 
                new Dictionary<string, bool>() : 
                System.Text.Json.JsonSerializer.Deserialize<Dictionary<string, bool>>(PermissionsJson)!;
            set => PermissionsJson = System.Text.Json.JsonSerializer.Serialize(value);
        }
        
        public bool IsValid()
        {
            return KeyStatus == ApiKeyStatus.Active && 
                   (!ExpiresAt.HasValue || ExpiresAt.Value > DateTime.UtcNow);
        }
        
        public bool HasPermission(string permission)
        {
            return Permissions.TryGetValue(permission, out var hasPermission) && hasPermission;
        }
        
        public void Use()
        {
            LastUsed = DateTime.UtcNow;
        }
        
        public void Revoke()
        {
            KeyStatus = ApiKeyStatus.Revoked;
            UpdatedAt = DateTime.UtcNow;
        }
    }
    
    /// <summary>
    /// Тикеты поддержки
    /// </summary>
    [Table("support_tickets")]
    public class SupportTicket
    {
        [Key]
        [Column("ticket_id")]
        public Guid TicketId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("account_id")]
        public Guid AccountId { get; set; }
        
        [Required]
        [Column("ticket_type")]
        public TicketType TicketType { get; set; }
        
        [Required]
        [Column("subject")]
        public string Subject { get; set; } = string.Empty;
        
        [Column("description")]
        public string Description { get; set; } = string.Empty;
        
        [Required]
        [Column("status")]
        public TicketStatus Status { get; set; } = TicketStatus.Open;
        
        [Column("priority")]
        public TicketPriority Priority { get; set; } = TicketPriority.Medium;
        
        [Column("assigned_to")]
        public Guid? AssignedTo { get; set; }
        
        [Column("category")]
        public string Category { get; set; } = string.Empty;
        
        [Column("metadata")]
        public string MetadataJson { get; set; } = string.Empty;
        
        [Column("closed_at")]
        public DateTime? ClosedAt { get; set; }
        
        [Column("closed_by")]
        public Guid? ClosedBy { get; set; }
        
        [Column("closure_reason")]
        public string? ClosureReason { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("AccountId")]
        public virtual Account Account { get; set; } = null!;
        public virtual ICollection<TicketMessage> Messages { get; set; } = new List<TicketMessage>();
        public virtual ICollection<TicketAttachment> Attachments { get; set; } = new List<TicketAttachment>();
    }
    
    public enum TicketType
    {
        Bug = 0,
        Account = 1,
        Billing = 2,
        Gameplay = 3,
        Technical = 4,
        Appeal = 5,
        Suggestion = 6,
        Other = 7
    }
    
    public enum TicketStatus
    {
        Open = 0,
        InProgress = 1,
        Waiting = 2,
        Resolved = 3,
        Closed = 4
    }
    
    public enum TicketPriority
    {
        Low = 0,
        Medium = 1,
        High = 2,
        Critical = 3
    }
    
    [Table("ticket_messages")]
    public class TicketMessage
    {
        [Key]
        [Column("message_id")]
        public Guid MessageId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("ticket_id")]
        public Guid TicketId { get; set; }
        
        [Required]
        [Column("account_id")]
        public Guid AccountId { get; set; }
        
        [Required]
        [Column("message")]
        public string Message { get; set; } = string.Empty;
        
        [Column("is_internal")]
        public bool IsInternal { get; set; }
        
        [Column("read_by_support")]
        public bool ReadBySupport { get; set; }
        
        [Column("read_by_user")]
        public bool ReadByUser { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("TicketId")]
        public virtual SupportTicket Ticket { get; set; } = null!;
        
        [ForeignKey("AccountId")]
        public virtual Account Account { get; set; } = null!;
    }
    
    [Table("ticket_attachments")]
    public class TicketAttachment
    {
        [Key]
        [Column("attachment_id")]
        public Guid AttachmentId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("ticket_id")]
        public Guid TicketId { get; set; }
        
        [Column("message_id")]
        public Guid? MessageId { get; set; }
        
        [Required]
        [Column("file_name")]
        public string FileName { get; set; } = string.Empty;
        
        [Required]
        [Column("file_path")]
        public string FilePath { get; set; } = string.Empty;
        
        [Column("file_size")]
        public long FileSize { get; set; }
        
        [Column("mime_type")]
        public string MimeType { get; set; } = string.Empty;
        
        [Column("uploaded_by")]
        public Guid UploadedBy { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("TicketId")]
        public virtual SupportTicket Ticket { get; set; } = null!;
        
        [ForeignKey("MessageId")]
        public virtual TicketMessage? Message { get; set; }
    }

    /// <summary>
    /// Сессии аккаунта для аутентификации
    /// </summary>
    [Table("account_sessions")]
    public class AccountSession
    {
        [Key]
        [Column("id")]
        public Guid Id { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("account_id")]
        public Guid AccountId { get; set; }
        
        [Column("character_id")]
        public Guid? CharacterId { get; set; }
        
        [Required]
        [Column("session_token")]
        public string SessionToken { get; set; } = string.Empty;
        
        [Required]
        [Column("refresh_token")]
        public string RefreshToken { get; set; } = string.Empty;
        
        [Column("ip_address")]
        public string? IPAddress { get; set; }
        
        [Column("user_agent")]
        public string? UserAgent { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("expires_at")]
        public DateTime ExpiresAt { get; set; }
        
        [Column("refresh_token_expires_at")]
        public DateTime RefreshTokenExpiresAt { get; set; }
        
        [Column("last_activity")]
        public DateTime? LastActivity { get; set; }
        
        [Column("is_revoked")]
        public bool IsRevoked { get; set; } = false;
        
        // Навигационные свойства
        [ForeignKey("AccountId")]
        public virtual Account Account { get; set; } = null!;
        
        public bool IsExpired()
        {
            return ExpiresAt < DateTime.UtcNow || IsRevoked;
        }
        
        public bool IsRefreshTokenExpired()
        {
            return RefreshTokenExpiresAt < DateTime.UtcNow || IsRevoked;
        }
    }
}