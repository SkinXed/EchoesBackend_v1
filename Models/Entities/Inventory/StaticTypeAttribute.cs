using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("static_type_attributes")]
    public class StaticTypeAttribute
    {
        [Key]
        public int Id { get; set; } // Первичный ключ

        public int TypeId { get; set; }      // ID типа предмета
        public int AttributeId { get; set; } // ID атрибута (например, масса, мощность)
        public float Value { get; set; }     // Значение атрибута

        // Навигационное свойство (опционально)
      
       
    }
}