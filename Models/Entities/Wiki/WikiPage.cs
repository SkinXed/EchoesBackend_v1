using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Wiki
{
    /// <summary>
    /// Entity for storing Wiki pages
    /// </summary>
    [Table("wiki_pages")]
    public class WikiPage
    {
        [Key]
        [Column("wiki_page_id")]
        public Guid WikiPageId { get; set; } = Guid.NewGuid();

        [Required]
        [MaxLength(100)]
        [Column("section_name")]
        public string SectionName { get; set; } = string.Empty;

        [Required]
        [MaxLength(200)]
        [Column("title")]
        public string Title { get; set; } = string.Empty;

        [Required]
        [Column("content_html")]
        public string ContentHtml { get; set; } = string.Empty;

        [Required]
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime? UpdatedAt { get; set; }

        [Required]
        [Column("created_by_id")]
        public Guid CreatedById { get; set; }

        [MaxLength(100)]
        [Column("created_by_name")]
        public string CreatedByName { get; set; } = string.Empty;

        [Column("last_updated_by_id")]
        public Guid? LastUpdatedById { get; set; }

        [MaxLength(100)]
        [Column("last_updated_by")]
        public string? LastUpdatedBy { get; set; }

        [Column("is_published")]
        public bool IsPublished { get; set; } = true;

        // Navigation properties
        [ForeignKey("CreatedById")]
        public virtual Character.Account? Creator { get; set; }

        [ForeignKey("LastUpdatedById")]
        public virtual Character.Account? LastEditor { get; set; }
    }
}
