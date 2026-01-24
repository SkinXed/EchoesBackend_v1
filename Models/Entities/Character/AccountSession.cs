using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Сессия аккаунта для отслеживания активных входов
    /// </summary>
    [Table("AccountSessions")]
    public class AccountSession
    {
        [Key]
        public Guid Id { get; set; } = Guid.NewGuid();

        [Required]
        public Guid AccountId { get; set; }

        [Required]
        public Guid CharacterId { get; set; }

        [Required]
        [MaxLength(500)]
        public string SessionToken { get; set; } = string.Empty;

        [Required]
        [MaxLength(500)]
        public string RefreshToken { get; set; } = string.Empty;

        [Required]
        [MaxLength(45)]
        public string IPAddress { get; set; } = string.Empty;

        [Required]
        [MaxLength(500)]
        public string UserAgent { get; set; } = string.Empty;

        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        public DateTime ExpiresAt { get; set; }

        public DateTime? RefreshTokenExpiresAt { get; set; }

        public DateTime? LastActivity { get; set; }

        public bool IsActive { get; set; } = true;

        // Navigation properties
        [ForeignKey("AccountId")]
        public virtual Account Account { get; set; } = null!;

        [ForeignKey("CharacterId")]
        public virtual Character Character { get; set; } = null!;
    }
}
