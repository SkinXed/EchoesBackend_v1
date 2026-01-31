using Echoes.API.Models.Config;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Data.SeedData
{
    public static class RaceConfigSeedData
    {
        /// <summary>
        /// Seed race configuration data
        /// Must be called after universe generation when stations exist
        /// </summary>
        public static async Task SeedRaceConfigs(DatabaseContext context)
        {
            // Check if race configs already exist
            if (await context.RaceConfigs.AnyAsync())
            {
                Console.WriteLine("⏩ Race configs already exist, skipping seed");
                return;
            }

            Console.WriteLine("🌟 Seeding race configuration data...");

            // Note: These are placeholder GUIDs
            // In a real scenario, these should be populated after universe generation
            // or updated to match actual station IDs from the database

            var raceConfigs = new List<RaceConfig>
            {
                new RaceConfig
                {
                    RaceId = 1,
                    RaceName = "Caldari",
                    Description = "The Caldari State is ruled by several megacorporations. Ruthless, efficient, and technologically advanced.",
                    RaceBonuses = "• +5% Shield HP\n• +5% Hybrid Turret damage\n• Strong in electronic warfare",
                    StartingSystemId = Guid.Empty, // Will be set by DbInitializer
                    StartingStationId = Guid.Empty, // Will be set by DbInitializer
                    DefaultShipTypeId = 670, // Caldari Rookie Ship (Ibis)
                    StartingSkillPoints = 50000,
                    StartingISK = 5000000,
                    CreatedAt = DateTime.UtcNow,
                    UpdatedAt = DateTime.UtcNow
                },
                new RaceConfig
                {
                    RaceId = 2,
                    RaceName = "Gallente",
                    Description = "The Gallente Federation is a democracy that values freedom and individual rights above all else.",
                    RaceBonuses = "• +5% Armor HP\n• +5% Drone damage and hitpoints\n• +10% Scan resolution",
                    StartingSystemId = Guid.Empty, // Will be set by DbInitializer
                    StartingStationId = Guid.Empty, // Will be set by DbInitializer
                    DefaultShipTypeId = 606, // Gallente Rookie Ship (Velator)
                    StartingSkillPoints = 50000,
                    StartingISK = 5000000,
                    CreatedAt = DateTime.UtcNow,
                    UpdatedAt = DateTime.UtcNow
                },
                new RaceConfig
                {
                    RaceId = 3,
                    RaceName = "Amarr",
                    Description = "The Amarr Empire is the largest and oldest of the four major empires. Religious and traditionalist.",
                    RaceBonuses = "• +5% Armor HP\n• +5% Energy weapon damage\n• +10% Capacitor capacity",
                    StartingSystemId = Guid.Empty, // Will be set by DbInitializer
                    StartingStationId = Guid.Empty, // Will be set by DbInitializer
                    DefaultShipTypeId = 596, // Amarr Rookie Ship (Impairor)
                    StartingSkillPoints = 50000,
                    StartingISK = 5000000,
                    CreatedAt = DateTime.UtcNow,
                    UpdatedAt = DateTime.UtcNow
                },
                new RaceConfig
                {
                    RaceId = 4,
                    RaceName = "Minmatar",
                    Description = "The Minmatar Republic was formed over a century ago. Tribal and resilient people.",
                    RaceBonuses = "• +5% Shield HP\n• +5% Projectile weapon damage\n• +10% Ship velocity",
                    StartingSystemId = Guid.Empty, // Will be set by DbInitializer
                    StartingStationId = Guid.Empty, // Will be set by DbInitializer
                    DefaultShipTypeId = 588, // Minmatar Rookie Ship (Reaper)
                    StartingSkillPoints = 50000,
                    StartingISK = 5000000,
                    CreatedAt = DateTime.UtcNow,
                    UpdatedAt = DateTime.UtcNow
                }
            };

            context.RaceConfigs.AddRange(raceConfigs);
            await context.SaveChangesAsync();

            Console.WriteLine($"✅ Seeded {raceConfigs.Count} race configurations");
        }

        /// <summary>
        /// Update race configs with actual station IDs after universe generation
        /// </summary>
        public static async Task UpdateRaceConfigsWithStations(DatabaseContext context)
        {
            Console.WriteLine("🔧 Updating race configs with actual station IDs...");

            // Helper method to find high-security stations
            async Task<Station?> FindHighSecurityStation(int skipCount)
            {
                return await context.Stations
                    .Include(s => s.SolarSystem)
                    .ThenInclude(ss => ss.Constellation)
                    .ThenInclude(c => c.Region)
                    .Where(s => s.SolarSystem.SecurityStatus >= 0.9 && 
                               s.Type == Models.Enums.StationType.TradingHub)
                    .OrderBy(s => Guid.NewGuid()) // Note: This is inefficient but simple for seeding
                    .Skip(skipCount)
                    .FirstOrDefaultAsync();
            }

            // Find high-security starting stations for each race
            var caldariStation = await FindHighSecurityStation(0);
            var gallenteStation = await FindHighSecurityStation(1);
            var amarrStation = await FindHighSecurityStation(2);
            var minmatarStation = await FindHighSecurityStation(3);

            // Update race configs
            var raceConfigs = await context.RaceConfigs.ToListAsync();
            
            foreach (var config in raceConfigs)
            {
                var station = config.RaceId switch
                {
                    1 => caldariStation,
                    2 => gallenteStation,
                    3 => amarrStation,
                    4 => minmatarStation,
                    _ => null
                };

                if (station != null)
                {
                    config.StartingStationId = station.Id;
                    config.StartingSystemId = station.SolarSystemId;
                    config.UpdatedAt = DateTime.UtcNow;
                    
                    Console.WriteLine($"  ✅ {config.RaceName}: {station.Name} in {station.SolarSystem.Name}");
                }
                else
                {
                    Console.WriteLine($"  ⚠️ {config.RaceName}: No suitable station found");
                }
            }

            await context.SaveChangesAsync();
            Console.WriteLine("✅ Race configs updated with station IDs");
        }
    }
}
