using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Market
{
    /// <summary>
    /// Рыночный ордер (Buy/Sell) в стиле EVE Online
    /// </summary>
    [Table("market_orders")]
    public class MarketOrder
    {
        [Key]
        [Column("id")]
        public Guid Id { get; set; } = Guid.NewGuid();

        [Required]
        [Column("character_id")]
        public Guid CharacterId { get; set; }

        /// <summary>
        /// ID шаблона предмета (ItemTypeId)
        /// </summary>
        [Required]
        [Column("item_id")]
        public int ItemId { get; set; }

        /// <summary>
        /// true = Buy Order, false = Sell Order
        /// </summary>
        [Required]
        [Column("is_buy_order")]
        public bool IsBuyOrder { get; set; }

        [Required]
        [Column("price")]
        public decimal Price { get; set; }

        [Required]
        [Column("quantity")]
        public int Quantity { get; set; }

        /// <summary>
        /// Оставшееся количество (уменьшается при частичном исполнении)
        /// </summary>
        [Required]
        [Column("remaining_quantity")]
        public int RemainingQuantity { get; set; }

        [Required]
        [Column("station_id")]
        public Guid StationId { get; set; }

        /// <summary>
        /// ID региона для быстрой фильтрации
        /// </summary>
        [Required]
        [Column("region_id")]
        public Guid RegionId { get; set; }

        /// <summary>
        /// Длительность ордера в днях
        /// </summary>
        [Required]
        [Column("duration")]
        public int Duration { get; set; } = 90;

        [Required]
        [Column("status")]
        public MarketOrderStatus Status { get; set; } = MarketOrderStatus.Active;

        /// <summary>
        /// Broker Fee уплаченный при создании ордера
        /// </summary>
        [Column("broker_fee")]
        public decimal BrokerFee { get; set; }

        [Required]
        [Column("issued_at")]
        public DateTime IssuedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime? UpdatedAt { get; set; }

        // Навигационные свойства
        [ForeignKey("CharacterId")]
        public virtual Character.Character Character { get; set; } = null!;

        [ForeignKey("StationId")]
        public virtual Universe.Station Station { get; set; } = null!;

        [ForeignKey("RegionId")]
        public virtual Universe.Region Region { get; set; } = null!;
    }
}
