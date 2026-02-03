using System.ComponentModel.DataAnnotations;

namespace EchoesOfImperial.Shared.DTOs;

/// <summary>
/// DTO for creating a new news post
/// </summary>
public class NewsPostCreateDto
{
    [Required(ErrorMessage = "Title is required")]
    [StringLength(200, ErrorMessage = "Title cannot exceed 200 characters")]
    public string Title { get; set; } = string.Empty;

    [Required(ErrorMessage = "Content is required")]
    [StringLength(10000, ErrorMessage = "Content cannot exceed 10000 characters")]
    public string Content { get; set; } = string.Empty;

    [Url(ErrorMessage = "Invalid URL format")]
    [StringLength(500, ErrorMessage = "Image URL cannot exceed 500 characters")]
    public string? ImageUrl { get; set; }
}

/// <summary>
/// DTO for news post response
/// </summary>
public class NewsPostDto
{
    public Guid Id { get; set; }
    public string Title { get; set; } = string.Empty;
    public string Content { get; set; } = string.Empty;
    public string? ImageUrl { get; set; }
    public DateTime CreatedAt { get; set; }
    public string AuthorName { get; set; } = string.Empty;
}
