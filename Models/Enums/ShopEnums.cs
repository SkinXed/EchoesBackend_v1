namespace Echoes.API.Models.Enums;

/// <summary>
/// Shop item categories
/// </summary>
public enum ShopItemCategory : int
{
    Equipment = 0,      // Ships, weapons, modules
    Credits = 1,        // Credit packages
    VipStatus = 2,      // VIP membership/subscriptions
    Consumables = 3,    // Repair kits, boosters, etc.
    Cosmetic = 4        // Skins, decorations
}
