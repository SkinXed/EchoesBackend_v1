using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Represents an active user session with JWT tokens.
    /// Tracks login sessions, tokens, and activity for security and session management.
    /// </summary>
    [Table("AccountSessions")]
    public class AccountSession
    {
        [Key]
        public Guid Id { get; set; }

        [Required]
        public Guid AccountId { get; set; }

        public Guid? CharacterId { get; set; }

        /// <summary>
        /// JWT token for this session.
        /// NOTE: For production use, consider storing a hash of the token (e.g., SHA-256)
        /// instead of the raw token to prevent token theft if the database is compromised.
        /// The validation endpoint would then compare hashes rather than raw tokens.
        /// </summary>
        [Required]
        [MaxLength(1024)]
        public string SessionToken { get; set; } = string.Empty;

        [Required]
        [MaxLength(1024)]
        public string RefreshToken { get; set; } = string.Empty;

        [Required]
        public DateTime CreatedAt { get; set; }

        [Required]
        public DateTime ExpiresAt { get; set; }

        [Required]
        public DateTime RefreshTokenExpiresAt { get; set; }

        [MaxLength(50)]
        public string IPAddress { get; set; } = string.Empty;

        [MaxLength(500)]
        public string UserAgent { get; set; } = string.Empty;

        [Required]
        public bool IsActive { get; set; }

        [Required]
        public DateTime LastActivity { get; set; }

        // Navigation properties
        [ForeignKey("AccountId")]
        public virtual Account? Account { get; set; }

        [ForeignKey("CharacterId")]
        public virtual Character? Character { get; set; }
    }
}
