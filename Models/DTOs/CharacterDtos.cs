using System;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.DTOs
{
    /// <summary>
    /// DTO for character data response (mirrors UE5 FCharacterData)
    /// </summary>
    public class CharacterDataDto
    {
        public Guid CharacterId { get; set; }
        public string Name { get; set; } = string.Empty;
        public Guid AccountId { get; set; }
        public long WalletBalance { get; set; }
        public float SecurityStatus { get; set; }
        public long? CurrentShipId { get; set; }
        public Guid? CorporationId { get; set; }
        public int RaceId { get; set; }
        public int TotalSkillPoints { get; set; }
        public int UnallocatedSkillPoints { get; set; }
        public bool IsOnline { get; set; }
        public bool IsDocked { get; set; }
        public bool InWarp { get; set; }
        public DateTime? LastLogin { get; set; }
    }

    // DTO для отображения персонажа
    public class CharacterDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public DateTime CreatedAt { get; set; }
        public long WalletBalance { get; set; }
        public float SecurityStatus { get; set; }
        public Guid? CorporationId { get; set; }
        public string? CorporationName { get; set; }
        public bool IsMain { get; set; }
        public LocationDto? Location { get; set; }
        public ShipDto? ActiveShip { get; set; }
        public int SkillPoints { get; set; }
        public int TotalSkills { get; set; }
        public int MaxTrainedSkill { get; set; }
    }

    // DTO для локации
    public class LocationDto
    {
        public Guid? SolarSystemId { get; set; }
        public Guid? StationId { get; set; }
        public double PositionX { get; set; }
        public double PositionY { get; set; }
        public double PositionZ { get; set; }
        public LocationType LocationType { get; set; }
        public DateTime UpdatedAt { get; set; }
    }

    // DTO для корабля
    public class ShipDto
    {
        public long ItemId { get; set; }
        public int TypeId { get; set; }
        public string ShipName { get; set; } = string.Empty;
        public string TypeName { get; set; } = string.Empty;
        public bool IsActiveShip { get; set; }
        public List<FittedModuleDto> FittedModules { get; set; } = new();
        public List<CargoItemDto> Cargo { get; set; } = new();
    }

    // DTO для модуля
    public class FittedModuleDto
    {
        public Guid ModuleId { get; set; }
        public int TypeId { get; set; }
        public string TypeName { get; set; } = string.Empty;
        public string SlotType { get; set; } = string.Empty;
        public bool IsOnline { get; set; }
    }

    // DTO для предмета в грузе
    public class CargoItemDto
    {
        public long ItemId { get; set; }
        public int TypeId { get; set; }
        public int Quantity { get; set; }
    }

    // DTO для навыка персонажа
    public class CharacterSkillDto
    {
        public int SkillId { get; set; }
        public int Level { get; set; }
        public bool IsActive { get; set; }
        public DateTime? TrainingStart { get; set; }
        public DateTime? TrainingEnd { get; set; }
        public string? SkillName { get; set; }
        public string? Description { get; set; }
        public float TrainingTimeMultiplier { get; set; }
    }

    // DTO для кошелька
    public class WalletDto
    {
        public long Balance { get; set; }
        public DateTime LastUpdated { get; set; }
        public List<TransactionDto> Transactions { get; set; } = new();
    }

    // DTO для транзакции
    public class TransactionDto
    {
        public Guid Id { get; set; }
        public string Type { get; set; } = string.Empty;
        public long Amount { get; set; }
        public string Description { get; set; } = string.Empty;
        public DateTime Timestamp { get; set; }
        public string? OtherParty { get; set; }
    }

    // DTO для запроса смены активного корабля
    public class SetActiveShipRequest
    {
        public long ShipItemId { get; set; }
    }

    // DTO для запроса тренировки навыка
    public class TrainSkillRequest
    {
        public int SkillId { get; set; }
        public int TargetLevel { get; set; } = 1;
    }

    /// <summary>
    /// Request DTO for creating a new character
    /// </summary>
    public class CreateCharacterRequest
    {
        public string Name { get; set; } = string.Empty;
        public string Race { get; set; } = "Caldari"; // Caldari, Gallente, Amarr, Minmatar
        public int PortraitId { get; set; } = 1;
    }
}