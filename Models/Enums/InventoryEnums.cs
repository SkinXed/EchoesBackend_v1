namespace Echoes.API.Models.Enums
{
    /// <summary>
    /// Inventory location flags for items in containers
    /// </summary>
    public enum InventoryFlag : int
    {
        Cargo = 0,
        DroneBay = 1,
        FighterBay = 2,
        FighterTube = 3,
        
        HighSlot1 = 10,
        HighSlot2 = 11,
        HighSlot3 = 12,
        HighSlot4 = 13,
        HighSlot5 = 14,
        HighSlot6 = 15,
        HighSlot7 = 16,
        HighSlot8 = 17,
        
        MediumSlot1 = 20,
        MediumSlot2 = 21,
        MediumSlot3 = 22,
        MediumSlot4 = 23,
        MediumSlot5 = 24,
        MediumSlot6 = 25,
        MediumSlot7 = 26,
        MediumSlot8 = 27,
        
        LowSlot1 = 30,
        LowSlot2 = 31,
        LowSlot3 = 32,
        LowSlot4 = 33,
        LowSlot5 = 34,
        LowSlot6 = 35,
        LowSlot7 = 36,
        LowSlot8 = 37,
        
        RigSlot1 = 40,
        RigSlot2 = 41,
        RigSlot3 = 42,
        RigSlot4 = 43,
        RigSlot5 = 44,
        
        StationHangar = 100,
        CorpHangar1 = 101,
        CorpHangar2 = 102,
        CorpHangar3 = 103,
        CorpHangar4 = 104,
        CorpHangar5 = 105,
        CorpHangar6 = 106,
        CorpHangar7 = 107,
        
        AssetSafety = 200,
        Impounded = 300
    }
    
    /// <summary>
    /// Ship slot types for module fitting
    /// </summary>
    public enum ShipSlotType : int
    {
        HighSlot = 0,
        MediumSlot = 1,
        LowSlot = 2,
        RigSlot = 3,
        SubSystem = 4,
        DroneSlot = 5,
        FighterSlot = 6,
        SpecialSlot = 7
    }
    
    /// <summary>
    /// Module categories for classification
    /// </summary>
    public enum ModuleCategory : int
    {
        Weapon = 0,
        Shield = 1,
        Armor = 2,
        Propulsion = 3,
        Electronics = 4,
        Engineering = 5,
        Drone = 6,
        Special = 7,
        Rig = 8,
        Subsystem = 9
    }
    
    /// <summary>
    /// Ship stat types for attribute identification
    /// </summary>
    public enum ShipStatType : int
    {
        CPU = 0,
        PowerGrid = 1,
        Capacitor = 2,
        
        ShieldHP = 10,
        ShieldRecharge = 11,
        ShieldResistanceEM = 12,
        ShieldResistanceThermal = 13,
        ShieldResistanceKinetic = 14,
        ShieldResistanceExplosive = 15,
        
        ArmorHP = 20,
        ArmorRepair = 21,
        ArmorResistanceEM = 22,
        ArmorResistanceThermal = 23,
        ArmorResistanceKinetic = 24,
        ArmorResistanceExplosive = 25,
        
        StructureHP = 30,
        StructureResistanceEM = 31,
        StructureResistanceThermal = 32,
        StructureResistanceKinetic = 33,
        StructureResistanceExplosive = 34,
        
        Speed = 40,
        Agility = 41,
        SignatureRadius = 50,
        
        DamageMultiplier = 60,
        RateOfFire = 61,
        TrackingSpeed = 62,
        OptimalRange = 63,
        FalloffRange = 64,
        
        CargoCapacity = 70,
        DroneBayCapacity = 71,
        DroneBandwidth = 72
    }
}
