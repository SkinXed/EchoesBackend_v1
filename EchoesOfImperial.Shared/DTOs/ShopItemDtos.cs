using System.ComponentModel.DataAnnotations;

namespace EchoesOfImperial.Shared.DTOs;

/// <summary>
/// DTO for shop item data transfer
/// </summary>
public class ShopItemDto
{
    public Guid Id { get; set; }
    
    [Required(ErrorMessage = "Name is required")]
    [StringLength(200, ErrorMessage = "Name cannot exceed 200 characters")]
    public string Name { get; set; } = string.Empty;
    
    [Required(ErrorMessage = "Description is required")]
    [StringLength(1000, ErrorMessage = "Description cannot exceed 1000 characters")]
    public string Description { get; set; } = string.Empty;
    
    [Required(ErrorMessage = "Price is required")]
    [Range(0, long.MaxValue, ErrorMessage = "Price must be positive")]
    public long Price { get; set; }
    
    [Url(ErrorMessage = "Invalid URL format")]
    [StringLength(500, ErrorMessage = "Image URL cannot exceed 500 characters")]
    public string? ImageUrl { get; set; }
    
    [Required(ErrorMessage = "Category is required")]
    public string Category { get; set; } = string.Empty;
    
    public bool IsActive { get; set; } = true;
    
    public DateTime CreatedAt { get; set; }
}

/// <summary>
/// DTO for creating or updating a shop item
/// </summary>
public class ShopItemCreateDto
{
    [Required(ErrorMessage = "Name is required")]
    [StringLength(200, ErrorMessage = "Name cannot exceed 200 characters")]
    public string Name { get; set; } = string.Empty;
    
    [Required(ErrorMessage = "Description is required")]
    [StringLength(1000, ErrorMessage = "Description cannot exceed 1000 characters")]
    public string Description { get; set; } = string.Empty;
    
    [Required(ErrorMessage = "Price is required")]
    [Range(0, long.MaxValue, ErrorMessage = "Price must be positive")]
    public long Price { get; set; }
    
    [Url(ErrorMessage = "Invalid URL format")]
    [StringLength(500, ErrorMessage = "Image URL cannot exceed 500 characters")]
    public string? ImageUrl { get; set; }
    
    [Required(ErrorMessage = "Category is required")]
    public string Category { get; set; } = string.Empty;
}

/// <summary>
/// DTO for shop purchase request
/// </summary>
public class ShopPurchaseDto
{
    [Required]
    public Guid ItemId { get; set; }
    
    [Range(1, int.MaxValue, ErrorMessage = "Quantity must be at least 1")]
    public int Quantity { get; set; } = 1;
}
