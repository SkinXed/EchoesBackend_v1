using Echoes.API.Data;
using Echoes.API.Models.Entities.Inventory;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Data.SeedData
{
    public static class InventorySeedData
    {
        public static async Task SeedInventoryDataAsync(DatabaseContext context)
        {
            // Check if data already exists
            if (await context.ItemCategories.AnyAsync())
            {
                return; // Data already seeded
            }

            // Seed Categories
            var categories = new List<ItemCategory>
            {
                new() { Name = "Корабли", Description = "Пилотируемые космические корабли", IconName = "ship" },
                new() { Name = "Модули", Description = "Оборудование для установки на корабли", IconName = "module" },
                new() { Name = "Боеприпасы", Description = "Расходные материалы для оружия", IconName = "ammo" },
                new() { Name = "Дроны", Description = "Автономные летательные аппараты", IconName = "drone" },
                new() { Name = "Минералы", Description = "Добываемые ресурсы", IconName = "mineral" }
            };

            context.ItemCategories.AddRange(categories);
            await context.SaveChangesAsync();

            // Seed Groups
            var groups = new List<ItemGroup>
            {
                new() { Name = "Фрегаты", CategoryId = categories[0].CategoryId },
                new() { Name = "Крейсеры", CategoryId = categories[0].CategoryId },
                new() { Name = "Лазерные орудия", CategoryId = categories[1].CategoryId },
                new() { Name = "Ракетные установки", CategoryId = categories[1].CategoryId },
                new() { Name = "Щиты", CategoryId = categories[1].CategoryId },
                new() { Name = "Броня", CategoryId = categories[1].CategoryId },
                new() { Name = "Лазерные кристаллы", CategoryId = categories[2].CategoryId },
                new() { Name = "Ракеты", CategoryId = categories[2].CategoryId },
                new() { Name = "Боевые дроны", CategoryId = categories[3].CategoryId },
                new() { Name = "Основные минералы", CategoryId = categories[4].CategoryId }
            };

            context.ItemGroups.AddRange(groups);
            await context.SaveChangesAsync();

            // Seed Item Types
            var itemTypes = new List<ItemTypeEntity>
            {
                // Ships
                new()
                {
                    Name = "Фрегат \"Скорпион\"",
                    Description = "Многоцелевой фрегат",
                    GroupId = groups[0].GroupId,
                    BaseVolume = 2500.0m,
                    PackagedVolume = 25000.0m,
                    IsStackable = false,
                    MaxStackSize = 1,
                    Mass = 1000000.0m
                },
                new()
                {
                    Name = "Крейсер \"Титаник\"",
                    Description = "Тяжелый крейсер",
                    GroupId = groups[1].GroupId,
                    BaseVolume = 10000.0m,
                    PackagedVolume = 50000.0m,
                    IsStackable = false,
                    MaxStackSize = 1,
                    Mass = 12000000.0m
                },
                // Modules
                new()
                {
                    Name = "Лазерный излучатель \"Факел\"",
                    Description = "Малокалиберный лазер",
                    GroupId = groups[2].GroupId,
                    BaseVolume = 5.0m,
                    PackagedVolume = 25.0m,
                    IsStackable = false,
                    MaxStackSize = 1
                },
                new()
                {
                    Name = "Ракетная установка \"Ураган\"",
                    Description = "Противокорабельная ракетная установка",
                    GroupId = groups[3].GroupId,
                    BaseVolume = 15.0m,
                    PackagedVolume = 75.0m,
                    IsStackable = false,
                    MaxStackSize = 1
                },
                new()
                {
                    Name = "Генератор щита \"Атлас\"",
                    Description = "Щит класса I",
                    GroupId = groups[4].GroupId,
                    BaseVolume = 20.0m,
                    PackagedVolume = 100.0m,
                    IsStackable = false,
                    MaxStackSize = 1
                },
                new()
                {
                    Name = "Бронепластины \"Вулканит\"",
                    Description = "Тяжелая броня",
                    GroupId = groups[5].GroupId,
                    BaseVolume = 200.0m,
                    PackagedVolume = 1000.0m,
                    IsStackable = false,
                    MaxStackSize = 1
                },
                // Ammo
                new()
                {
                    Name = "Кристалл \"Инфракрасный M\"",
                    Description = "Кристалл среднего калибра",
                    GroupId = groups[6].GroupId,
                    BaseVolume = 0.1m,
                    PackagedVolume = 0.5m,
                    IsStackable = true,
                    MaxStackSize = 10000
                },
                new()
                {
                    Name = "Ракета \"Призрак\"",
                    Description = "Ракета ближнего боя",
                    GroupId = groups[7].GroupId,
                    BaseVolume = 0.5m,
                    PackagedVolume = 2.5m,
                    IsStackable = true,
                    MaxStackSize = 1000
                },
                // Drones
                new()
                {
                    Name = "Дрон \"Шершень I\"",
                    Description = "Легкий боевой дрон",
                    GroupId = groups[8].GroupId,
                    BaseVolume = 5.0m,
                    PackagedVolume = 25.0m,
                    IsStackable = true,
                    MaxStackSize = 50
                },
                // Minerals
                new()
                {
                    Name = "Тритоний",
                    Description = "Основной строительный минерал",
                    GroupId = groups[9].GroupId,
                    BaseVolume = 0.01m,
                    PackagedVolume = 0.01m,
                    IsStackable = true,
                    MaxStackSize = 10000000
                },
                new()
                {
                    Name = "Пираксий",
                    Description = "Используется в производстве",
                    GroupId = groups[9].GroupId,
                    BaseVolume = 0.01m,
                    PackagedVolume = 0.01m,
                    IsStackable = true,
                    MaxStackSize = 10000000
                }
            };

            context.ItemTypesInventory.AddRange(itemTypes);
            await context.SaveChangesAsync();

            // Seed Ships
            var ships = new List<Ship>
            {
                new()
                {
                    ShipTypeId = itemTypes[0].TypeId,
                    Name = "Фрегат \"Скорпион\"",
                    Description = "Многоцелевой фрегат",
                    ShipSize = "Frigate",
                    Race = "Gallente",
                    HighSlots = 4,
                    MediumSlots = 3,
                    LowSlots = 3,
                    RigSlots = 2,
                    BaseCpu = 150.0m,
                    BasePowergrid = 40.0m,
                    BaseShieldHp = 500.0m,
                    BaseArmorHp = 600.0m,
                    BaseSpeed = 280.0m,
                    BaseCargoCapacity = 200.0m
                },
                new()
                {
                    ShipTypeId = itemTypes[1].TypeId,
                    Name = "Крейсер \"Титаник\"",
                    Description = "Тяжелый крейсер",
                    ShipSize = "Cruiser",
                    Race = "Minmatar",
                    HighSlots = 6,
                    MediumSlots = 4,
                    LowSlots = 4,
                    RigSlots = 3,
                    BaseCpu = 400.0m,
                    BasePowergrid = 120.0m,
                    BaseShieldHp = 2000.0m,
                    BaseArmorHp = 2500.0m,
                    BaseSpeed = 180.0m,
                    BaseCargoCapacity = 500.0m
                }
            };

            context.Ships.AddRange(ships);
            await context.SaveChangesAsync();

            // Seed Modules
            var modules = new List<Module>
            {
                new()
                {
                    ModuleTypeId = itemTypes[2].TypeId,
                    Name = "Лазерный излучатель \"Факел\"",
                    ModuleCategory = 0, // Weapon
                    SlotType = 0, // High
                    RequiredCpu = 25.0m,
                    RequiredPowergrid = 40.0m,
                    ModuleEffects = "{\"damage\": 15.0, \"rate_of_fire\": 3.0}"
                },
                new()
                {
                    ModuleTypeId = itemTypes[3].TypeId,
                    Name = "Ракетная установка \"Ураган\"",
                    ModuleCategory = 0, // Weapon
                    SlotType = 0, // High
                    RequiredCpu = 30.0m,
                    RequiredPowergrid = 50.0m,
                    ModuleEffects = "{\"damage\": 45.0, \"rate_of_fire\": 5.0}"
                },
                new()
                {
                    ModuleTypeId = itemTypes[4].TypeId,
                    Name = "Генератор щита \"Атлас\"",
                    ModuleCategory = 1, // Shield
                    SlotType = 1, // Medium
                    RequiredCpu = 15.0m,
                    RequiredPowergrid = 20.0m,
                    ModuleEffects = "{\"shield_hp\": 200.0, \"shield_recharge\": 2.0}"
                },
                new()
                {
                    ModuleTypeId = itemTypes[5].TypeId,
                    Name = "Бронепластины \"Вулканит\"",
                    ModuleCategory = 2, // Armor
                    SlotType = 2, // Low
                    RequiredCpu = 10.0m,
                    RequiredPowergrid = 0.0m,
                    ModuleEffects = "{\"armor_hp\": 300.0}"
                }
            };

            context.Modules.AddRange(modules);
            await context.SaveChangesAsync();

            Console.WriteLine("✅ Inventory seed data created successfully!");
        }
    }
}
