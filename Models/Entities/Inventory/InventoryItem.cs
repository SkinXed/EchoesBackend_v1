using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Entities.Universe;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("inventory_items")]
    public class InventoryItem 
    {
        [Key]
        public long ItemId { get; set; }

        [ForeignKey(nameof(OwnerId))]
        public Guid OwnerId { get; set; }

        public int TypeId { get; set; }
        public int Quantity { get; set; } = 1;
        public bool IsSingleton { get; set; } = false;

        // Навигационные свойства
        //public virtual Character? OwnerCharacter { get; set; }
      
    }

    
}