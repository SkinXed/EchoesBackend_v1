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
        [ForeignKey("Account")]
        public Guid AccountId { get; set; }

        [ForeignKey("Character")]
        public Guid? CharacterId { get; set; }

        /// <summary>
        /// JWT token for this session.
        /// NOTE: For production use, consider storing a hash of the token (e.g., SHA-256)
        /// instead of the raw token to prevent token theft if the database is compromised.
        /// The validation endpoint would then compare hashes rather than raw tokens.
        /// Max length of 4096 supports large JWT tokens with custom claims.
        /// </summary>
        [Required]
        [MaxLength(4096)]
        public string SessionToken { get; set; } = string.Empty;

        [Required]
        [MaxLength(4096)]
        public string RefreshToken { get; set; } = string.Empty;

        [Required]
        public DateTime CreatedAt { get; set; }

        [Required]
        public DateTime ExpiresAt { get; set; }

        [Required]
        public DateTime RefreshTokenExpiresAt { get; set; }

        /// <summary>
        /// IP address of the client.
        /// Max length of 45 supports full IPv6 addresses (e.g., 2001:0db8:85a3:0000:0000:8a2e:0370:7334).
        /// </summary>
        [MaxLength(45)]
        public string IPAddress { get; set; } = string.Empty;

        [MaxLength(500)]
        public string UserAgent { get; set; } = string.Empty;

        [Required]
        public bool IsActive { get; set; }

        [Required]
        public DateTime LastActivity { get; set; }

        // Navigation properties
        public virtual Account? Account { get; set; }

        public virtual Character? Character { get; set; }
    }
}
