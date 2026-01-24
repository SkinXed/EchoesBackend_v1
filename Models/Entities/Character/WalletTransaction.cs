using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Транзакции кошелька
    /// </summary>
    [Table("wallet_transactions")]
    public class WalletTransaction
    {
        [Key]
        [Column("transaction_id")]
        public long TransactionId { get; set; }
        
        [Required]
        [Column("wallet_id")]
        public Guid WalletId { get; set; }
        
        [Required]
        [Column("transaction_type")]
        public WalletTransactionType TransactionType { get; set; }
        
        [Required]
        [Column("amount")]
        public decimal Amount { get; set; }
        
        [Required]
        [Column("new_balance")]
        public decimal NewBalance { get; set; }
        
        [Column("description")]
        public string? Description { get; set; }
        
        [Column("reference_id")]
        public Guid? ReferenceId { get; set; } // ID связанной сущности
        
        [Column("reference_type")]
        public string? ReferenceType { get; set; } // Тип связанной сущности
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; }
        
        // Навигационные свойства
        [ForeignKey("WalletId")]
        public virtual CharacterWallet Wallet { get; set; } = null!;
    }
}
