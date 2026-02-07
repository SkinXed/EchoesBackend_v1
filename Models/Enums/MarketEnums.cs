namespace Echoes.API.Models.Enums
{
    /// <summary>
    /// Статус рыночного ордера
    /// </summary>
    public enum MarketOrderStatus : int
    {
        Active = 0,
        Fulfilled = 1,
        Cancelled = 2,
        Expired = 3
    }
}
