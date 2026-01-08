using Echoes.API.Models.Entities.Universe;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("item_types")]
    public class ItemType 
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.None)] // ID задаем вручную (из EVE базы)
        public int Id { get; set; }

        [MaxLength(200)]
        public string Name { get; set; } = string.Empty;

        public string Description { get; set; } = string.Empty;

        public double Mass { get; set; }
        public double Volume { get; set; }
        public double Capacity { get; set; }
        public int GroupId { get; set; }
        public int CategoryId { get; set; } 
    }
   
}