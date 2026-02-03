using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.News
{
    /// <summary>
    /// Entity for storing news posts/edicts
    /// </summary>
    [Table("news_posts")]
    public class NewsPost
    {
        [Key]
        [Column("news_post_id")]
        public Guid NewsPostId { get; set; } = Guid.NewGuid();

        [Required]
        [MaxLength(200)]
        [Column("title")]
        public string Title { get; set; } = string.Empty;

        [Required]
        [Column("content")]
        public string Content { get; set; } = string.Empty;

        [MaxLength(500)]
        [Column("image_url")]
        public string? ImageUrl { get; set; }

        [Required]
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime? UpdatedAt { get; set; }

        [Required]
        [Column("author_id")]
        public Guid AuthorId { get; set; }

        [Required]
        [MaxLength(100)]
        [Column("author_name")]
        public string AuthorName { get; set; } = string.Empty;

        [Column("is_published")]
        public bool IsPublished { get; set; } = true;

        // Navigation property
        [ForeignKey("AuthorId")]
        public virtual Character.Account? Author { get; set; }
    }
}
