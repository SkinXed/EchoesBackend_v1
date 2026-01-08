using Echoes.API.Models.Entities.Universe;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    [Table("accounts")]
    public class Account
    {
        [Key]
        public Guid Id { get; set; }

        [Required]
        [MaxLength(50)]
        public string Username { get; set; } = string.Empty;

        [Required]
        [EmailAddress]
        [MaxLength(100)]
        public string Email { get; set; } = string.Empty;

        // Хэш пароля
        [MaxLength(128)]
        public byte[] PasswordHash { get; set; } = Array.Empty<byte>();

        [MaxLength(128)]
        public byte[] PasswordSalt { get; set; } = Array.Empty<byte>();

        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // Статус аккаунта
        public bool IsActive { get; set; } = true;
        public bool IsBanned { get; set; } = false;
        public bool IsAdmin { get; set; } = false;
        public bool IsDeveloper { get; set; } = false;

        // Время
        public DateTime? LastLogin { get; set; }
        public DateTime? LastLogout { get; set; }

        // Безопасность
        [MaxLength(45)]
        public string LastIP { get; set; } = string.Empty;
        public int FailedLoginAttempts { get; set; } = 0;
        public DateTime? LockedUntil { get; set; }

        // Навигационные свойства
        public virtual ICollection<Character> Characters { get; set; } = new List<Character>();
        public virtual ICollection<AccountBan> Bans { get; set; } = new List<AccountBan>();
        public virtual ICollection<AccountSession> Sessions { get; set; } = new List<AccountSession>();
    }

        [Table("account_bans")]
    public class AccountBan
    {
        [Key]
        public Guid Id { get; set; }

        [ForeignKey(nameof(Account))]
        public Guid AccountId { get; set; }

        [MaxLength(500)]
        public string Reason { get; set; } = string.Empty;

        public DateTime BannedAt { get; set; } = DateTime.UtcNow;
        public DateTime? ExpiresAt { get; set; }

        [ForeignKey(nameof(BannedBy))]
        public Guid? BannedById { get; set; }

        [MaxLength(45)]
        public string IPAddress { get; set; } = string.Empty;

        public virtual Account Account { get; set; } = null!;
        public virtual Character? BannedBy { get; set; }
    }

    [Table("account_sessions")]
    public class AccountSession 
    {
        [Key]
        public Guid Id { get; set; }

        [ForeignKey(nameof(Account))]
        public Guid AccountId { get; set; }

        [ForeignKey(nameof(Character))]
        public Guid CharacterId { get; set; }

        [Required]
        [MaxLength(500)]
        public string SessionToken { get; set; } = string.Empty;

        [MaxLength(500)]
        public string RefreshToken { get; set; } = string.Empty;

        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        public DateTime ExpiresAt { get; set; }
        public DateTime? RefreshTokenExpiresAt { get; set; }

        [MaxLength(45)]
        public string IPAddress { get; set; } = string.Empty;

        [MaxLength(500)]
        public string UserAgent { get; set; } = string.Empty;

        public bool IsActive { get; set; } = true;
        public DateTime? LastActivity { get; set; }

        public virtual Account Account { get; set; } = null!;
        public virtual Character Character { get; set; } = null!;
        
    }
}