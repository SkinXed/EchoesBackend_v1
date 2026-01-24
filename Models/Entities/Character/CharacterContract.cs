using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Контракты персонажа
    /// </summary>
    [Table("character_contracts")]
    public class CharacterContract
    {
        [Key]
        [Column("contract_id")]
        public Guid ContractId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("issuer_id")]
        public Guid IssuerId { get; set; }
        
        [Column("assignee_id")]
        public Guid? AssigneeId { get; set; }
        
        [Column("acceptor_id")]
        public Guid? AcceptorId { get; set; }
        
        [Required]
        [Column("contract_type")]
        public ContractType ContractType { get; set; }
        
        [Required]
        [Column("status")]
        public ContractStatus Status { get; set; }
        
        [Column("title")]
        public string Title { get; set; } = string.Empty;
        
        [Column("description")]
        public string? Description { get; set; }
        
        [Column("price")]
        public decimal Price { get; set; }
        
        [Column("reward")]
        public decimal? Reward { get; set; }
        
        [Column("collateral")]
        public decimal? Collateral { get; set; }
        
        [Column("volume")]
        public decimal Volume { get; set; }
        
        [Column("items")]
        public string ItemsJson { get; set; } = string.Empty; // List<ContractItem>
        
        [Column("start_location_id")]
        public Guid? StartLocationId { get; set; }
        
        [Column("end_location_id")]
        public Guid? EndLocationId { get; set; }
        
        [Column("date_issued")]
        public DateTime DateIssued { get; set; } = DateTime.UtcNow;
        
        [Column("date_expired")]
        public DateTime DateExpired { get; set; }
        
        [Column("date_accepted")]
        public DateTime? DateAccepted { get; set; }
        
        [Column("date_completed")]
        public DateTime? DateCompleted { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("IssuerId")]
        public virtual Character Issuer { get; set; } = null!;
        
        [ForeignKey("AssigneeId")]
        public virtual Character? Assignee { get; set; }
        
        [ForeignKey("AcceptorId")]
        public virtual Character? Acceptor { get; set; }
        
        // Методы
        [NotMapped]
        public List<ContractItem> Items
        {
            get => string.IsNullOrEmpty(ItemsJson) ? 
                new List<ContractItem>() : 
                System.Text.Json.JsonSerializer.Deserialize<List<ContractItem>>(ItemsJson)!;
            set => ItemsJson = System.Text.Json.JsonSerializer.Serialize(value);
        }
    }
    
    /// <summary>
    /// Предмет в контракте
    /// </summary>
    public class ContractItem
    {
        public Guid AssetId { get; set; }
        public int TypeId { get; set; }
        public long Quantity { get; set; }
        public bool IsIncluded { get; set; }
        public bool IsForSale { get; set; }
    }
}
