using System.ComponentModel.DataAnnotations;

namespace EchoesOfImperial.Shared.DTOs;

/// <summary>
/// DTO for creating or updating a wiki page
/// </summary>
public class WikiPageUpdateDto
{
    [Required(ErrorMessage = "Section name is required")]
    [StringLength(100, ErrorMessage = "Section name cannot exceed 100 characters")]
    public string SectionName { get; set; } = string.Empty;

    [Required(ErrorMessage = "Title is required")]
    [StringLength(200, ErrorMessage = "Title cannot exceed 200 characters")]
    public string Title { get; set; } = string.Empty;

    [Required(ErrorMessage = "Content is required")]
    public string ContentHtml { get; set; } = string.Empty;
}

/// <summary>
/// DTO for wiki page response
/// </summary>
public class WikiPageDto
{
    public Guid Id { get; set; }
    public string SectionName { get; set; } = string.Empty;
    public string Title { get; set; } = string.Empty;
    public string ContentHtml { get; set; } = string.Empty;
    public DateTime CreatedAt { get; set; }
    public DateTime? UpdatedAt { get; set; }
    public string CreatedByName { get; set; } = string.Empty;
    public string? LastUpdatedBy { get; set; }
}
