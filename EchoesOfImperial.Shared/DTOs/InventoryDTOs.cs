namespace EchoesOfImperial.Shared.DTOs;

/// <summary>
/// Inventory item DTO for web inventory display
/// </summary>
public class InventoryItemDTO
{
    public Guid Id { get; set; } // Inventory record ID (not shop item ID!)
    public string ItemName { get; set; } = string.Empty;
    public string Category { get; set; } = string.Empty; // VIP, Credits, Equipment, etc.
    public int Quantity { get; set; }
    public string? ImageUrl { get; set; }
    public long EstimatedValue { get; set; } // Price * Quantity
    public DateTime AcquiredDate { get; set; }
    public bool IsRedeemed { get; set; }
    public DateTime? RedeemedDate { get; set; }
}

/// <summary>
/// Purchase request DTO
/// </summary>
public class PurchaseItemRequestDTO
{
    public Guid ShopItemId { get; set; }
    public int Quantity { get; set; } = 1;
}

/// <summary>
/// Redeem request DTO
/// </summary>
public class RedeemItemRequestDTO
{
    public Guid InventoryItemId { get; set; }
}

/// <summary>
/// Purchase response DTO
/// </summary>
public class PurchaseResponseDTO
{
    public bool Success { get; set; }
    public string? Message { get; set; }
    public Guid? InventoryItemId { get; set; }
}
