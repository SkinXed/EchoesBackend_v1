using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Кошелек персонажа
    /// </summary>
    [Table("character_wallets")]
    public class CharacterWallet
    {
        [Key]
        [Column("wallet_id")]
        public Guid WalletId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("character_id")]
        public Guid CharacterId { get; set; }
        
        [Required]
        [Column("currency_type")]
        public CurrencyType CurrencyType { get; set; }
        
        [Required]
        [Column("balance")]
        public decimal Balance { get; set; } = 0;
        
        [Column("balance_updated_at")]
        public DateTime BalanceUpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Для ISK дополнительная информация
        [Column("wallet_name")]
        public string? WalletName { get; set; }
        
        [Column("division")]
        public int? Division { get; set; }
        
        [Column("is_primary")]
        public bool IsPrimary { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("CharacterId")]
        public virtual Character Character { get; set; } = null!;
        
        public virtual ICollection<WalletTransaction> Transactions { get; set; } = new List<WalletTransaction>();
        
        // Методы
        public bool Deposit(decimal amount, string? description = null)
        {
            if (amount <= 0)
                return false;
                
            Balance += amount;
            BalanceUpdatedAt = DateTime.UtcNow;
            
            // Записываем транзакцию
            Transactions.Add(new WalletTransaction
            {
                WalletId = WalletId,
                TransactionType = WalletTransactionType.Deposit,
                Amount = amount,
                NewBalance = Balance,
                Description = description,
                CreatedAt = DateTime.UtcNow
            });
            
            return true;
        }
        
        public bool Withdraw(decimal amount, string? description = null)
        {
            if (amount <= 0 || amount > Balance)
                return false;
                
            Balance -= amount;
            BalanceUpdatedAt = DateTime.UtcNow;
            
            // Записываем транзакцию
            Transactions.Add(new WalletTransaction
            {
                WalletId = WalletId,
                TransactionType = WalletTransactionType.Withdrawal,
                Amount = amount,
                NewBalance = Balance,
                Description = description,
                CreatedAt = DateTime.UtcNow
            });
            
            return true;
        }
        
        public bool TransferTo(CharacterWallet targetWallet, decimal amount, string? description = null)
        {
            if (amount <= 0 || amount > Balance || targetWallet == null)
                return false;
                
            // Validate same currency type
            if (CurrencyType != targetWallet.CurrencyType)
                return false;
                
            if (Withdraw(amount, $"Transfer to {targetWallet.WalletName}: {description}"))
            {
                return targetWallet.Deposit(amount, $"Transfer from {WalletName}: {description}");
            }
            
            return false;
        }
    }
}
