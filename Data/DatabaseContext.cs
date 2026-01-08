using Echoes.API.Models;
using System.Text.Json;
using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Entities.GameServer;
using Echoes.API.Models.Entities.Universe;
using Echoes.Server.Models.Entities.Universe;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Data
{
    public class DatabaseContext : DbContext
    {
        public DatabaseContext(DbContextOptions<DatabaseContext> options) : base(options)
        {
        }
       

        // Character entities
        public DbSet<Account> Accounts { get; set; }
        public DbSet<Character> Characters { get; set; }
        public DbSet<CharacterLocation> CharacterLocations { get; set; }
        public DbSet<AccountSession> AccountSessions { get; set; }

        // Universe entities
        public DbSet<Region> Regions { get; set; }
        public DbSet<Constellation> Constellations { get; set; }
        public DbSet<Anomaly> Anomalies { get; set; }
        public DbSet<Wormhole> Wormholes { get; set; }
        public DbSet<SolarSystem> SolarSystems { get; set; }
        public DbSet<Planet> Planets { get; set; }
        public DbSet<Moon> Moons { get; set; }
        public DbSet<Station> Stations { get; set; }
        public DbSet<Stargate> Stargates { get; set; }
        public DbSet<AsteroidBelt> AsteroidBelts { get; set; }
        public DbSet<PlanetResource> PlanetResources { get; set; }
        // Game server entities
        public DbSet<GameServerNode> GameServers { get; set; }
        // Universe generation configuration
        public DbSet<UniverseGenerationConfig> UniverseGenerationConfigs { get; set; }


        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            // =========================================================================
            // ВАЖНО: Явно игнорируем все неподходящие типы в самом начале
            // =========================================================================
            modelBuilder.Ignore<AnomalyConfig>();
            modelBuilder.Ignore<AnomalyConfig>();
            modelBuilder.Ignore<WormholeConfig>();

            // Также явно игнорируем любые другие классы конфигурации
            // modelBuilder.Ignore<YourOtherConfigClass>();

            // =========================================================================
            // Теперь настраиваем сущности
            // =========================================================================

            // UniverseGenerationConfig - ЯВНО указываем ключ
            modelBuilder.Entity<UniverseGenerationConfig>(entity =>
            {
                // Явно указываем первичный ключ
                entity.HasKey(e => e.Id);

                // Настраиваем JSON свойства
                entity.Property(e => e.Anomalies)
                    .HasColumnType("jsonb")
                    .HasConversion(
                        v => JsonSerializer.Serialize(v, new JsonSerializerOptions()),
                        v => JsonSerializer.Deserialize<AnomalyConfig>(v, new JsonSerializerOptions()) ?? new AnomalyConfig()
                    );
                modelBuilder.Ignore<WormholeConfig>();
                entity.Property(e => e.Wormholes)
                    .HasColumnType("jsonb")
                    .HasConversion(
                        v => JsonSerializer.Serialize(v, new JsonSerializerOptions()),
                        v => JsonSerializer.Deserialize<WormholeConfig>(v, new JsonSerializerOptions()) ?? new WormholeConfig()
                    );
            });


        // ==============================================
        // CHARACTER ENTITIES
        // ==============================================

        // Account -> Characters (one-to-many)
        modelBuilder.Entity<Account>()
                .HasMany(a => a.Characters)
                .WithOne(c => c.Account)
                .HasForeignKey(c => c.AccountId)
                .OnDelete(DeleteBehavior.Cascade);

            // Account -> AccountSessions (one-to-many)
            modelBuilder.Entity<Account>()
                .HasMany(a => a.Sessions)
                .WithOne(s => s.Account)
                .HasForeignKey(s => s.AccountId)
                .OnDelete(DeleteBehavior.Cascade);

            // Character -> CharacterLocation (one-to-one)
            modelBuilder.Entity<Character>()
                .HasOne(c => c.CurrentLocation)
                .WithOne(cl => cl.Character)
                .HasForeignKey<CharacterLocation>(cl => cl.CharacterId)
                .OnDelete(DeleteBehavior.Cascade);

            // CharacterLocation -> SolarSystem (many-to-one)
            modelBuilder.Entity<CharacterLocation>()
                .HasOne(cl => cl.SolarSystem)
                .WithMany()
                .HasForeignKey(cl => cl.SolarSystemId)
                .OnDelete(DeleteBehavior.Restrict);

            // CharacterLocation -> Station (many-to-one, optional)
            modelBuilder.Entity<CharacterLocation>()
                .HasOne(cl => cl.Station)
                .WithMany()
                .HasForeignKey(cl => cl.StationId)
                .OnDelete(DeleteBehavior.Restrict);

            // ==============================================
            // UNIVERSE ENTITIES
            // ==============================================

            // Region -> Constellations (one-to-many)
            modelBuilder.Entity<Region>()
                .HasMany(r => r.Constellations)
                .WithOne(c => c.Region)
                .HasForeignKey(c => c.RegionId)
                .OnDelete(DeleteBehavior.Cascade);

            // Constellation -> SolarSystems (one-to-many)
            modelBuilder.Entity<Constellation>()
                .HasMany(c => c.SolarSystems)
                .WithOne(s => s.Constellation)
                .HasForeignKey(s => s.ConstellationId)
                .OnDelete(DeleteBehavior.Cascade);

            // SolarSystem -> Planets (one-to-many)
            modelBuilder.Entity<SolarSystem>()
                .HasMany(s => s.Planets)
                .WithOne(p => p.SolarSystem)
                .HasForeignKey(p => p.SolarSystemId)
                .OnDelete(DeleteBehavior.Cascade);

            // SolarSystem -> Stations (one-to-many)
            modelBuilder.Entity<SolarSystem>()
                .HasMany(s => s.Stations)
                .WithOne(st => st.SolarSystem)
                .HasForeignKey(st => st.SolarSystemId)
                .OnDelete(DeleteBehavior.Cascade);

            // SolarSystem -> AsteroidBelts (one-to-many)
            modelBuilder.Entity<SolarSystem>()
                .HasMany(s => s.AsteroidBelts)
                .WithOne(ab => ab.SolarSystem)
                .HasForeignKey(ab => ab.SolarSystemId)
                .OnDelete(DeleteBehavior.Cascade);

            // Planet -> Moons (one-to-many)
            modelBuilder.Entity<Planet>()
                .HasMany(p => p.Moons)
                .WithOne(m => m.Planet)
                .HasForeignKey(m => m.PlanetId)
                .OnDelete(DeleteBehavior.Cascade);

            // Planet -> Resources (one-to-many)
            modelBuilder.Entity<Planet>()
                .HasMany(p => p.Resources)
                .WithOne(pr => pr.Planet)
                .HasForeignKey(pr => pr.PlanetId)
                .OnDelete(DeleteBehavior.Cascade);

            // Moon -> Resources (one-to-many)
            modelBuilder.Entity<Moon>()
                .HasMany(m => m.Resources)
                .WithOne(pr => pr.Moon)
                .HasForeignKey(pr => pr.MoonId)
                .OnDelete(DeleteBehavior.Cascade);

            // AsteroidBelt -> Resources (one-to-many)
            modelBuilder.Entity<AsteroidBelt>()
                .HasMany(ab => ab.Resources)
                .WithOne(pr => pr.AsteroidBelt)
                .HasForeignKey(pr => pr.AsteroidBeltId)
                .OnDelete(DeleteBehavior.Cascade);

            // ==============================================
            // STARGATE RELATIONSHIPS
            // ==============================================

            // SolarSystem -> Stargates (as source)
            modelBuilder.Entity<SolarSystem>()
                .HasMany(s => s.Stargates)
                .WithOne(sg => sg.SourceSolarSystem)
                .HasForeignKey(sg => sg.SourceSolarSystemId)
                .OnDelete(DeleteBehavior.Cascade);

            // Stargate -> Destination SolarSystem
            modelBuilder.Entity<Stargate>()
                .HasOne(sg => sg.DestinationSolarSystem)
                .WithMany()
                .HasForeignKey(sg => sg.DestinationSolarSystemId)
                .OnDelete(DeleteBehavior.Restrict);

            // ==============================================
            // CONSTRAINTS
            // ==============================================

            // Security status precision
            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.SecurityStatus)
                .HasPrecision(3, 2);

            modelBuilder.Entity<Region>()
                .Property(r => r.AverageSecurity)
                .HasPrecision(3, 2);

            modelBuilder.Entity<Constellation>()
                .Property(c => c.AverageSecurity)
                .HasPrecision(3, 2);

            // Temperature constraints
            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.Temperature)
                .HasPrecision(7, 2);

            // Radius constraints
            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.SolarRadius)
                .HasPrecision(10, 4);

            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.SolarMass)
                .HasPrecision(10, 4);

            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.Luminosity)
                .HasPrecision(15, 4);

            // Position constraints (big integers for space coordinates)
            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.PositionX)
                .HasColumnType("bigint");

            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.PositionY)
                .HasColumnType("bigint");

            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.PositionZ)
                .HasColumnType("bigint");

            // ==============================================
            // INDEXES FOR PERFORMANCE
            // ==============================================

            // Character indexes
            modelBuilder.Entity<Character>()
                .HasIndex(c => c.Name)
                .IsUnique();

            modelBuilder.Entity<Character>()
                .HasIndex(c => c.AccountId);

            // Account indexes
            modelBuilder.Entity<Account>()
                .HasIndex(a => a.Email)
                .IsUnique();

            modelBuilder.Entity<Account>()
                .HasIndex(a => a.Username)
                .IsUnique();

            // Universe indexes
            modelBuilder.Entity<Region>()
                .HasIndex(r => r.Name)
                .IsUnique();

            modelBuilder.Entity<Constellation>()
                .HasIndex(c => c.Name)
                .IsUnique();

            modelBuilder.Entity<SolarSystem>()
                .HasIndex(s => s.Name)
                .IsUnique();

            modelBuilder.Entity<SolarSystem>()
                .HasIndex(s => s.SecurityStatus);

            modelBuilder.Entity<SolarSystem>()
                .HasIndex(s => s.ConstellationId);

            // Spatial index for position searches (PostgreSQL specific)
            modelBuilder.Entity<SolarSystem>()
                .HasIndex(s => new { s.PositionX, s.PositionY, s.PositionZ });

            // Stargate indexes
            modelBuilder.Entity<Stargate>()
                .HasIndex(sg => sg.SourceSolarSystemId);

            modelBuilder.Entity<Stargate>()
                .HasIndex(sg => sg.DestinationSolarSystemId);

            // Character location indexes
            modelBuilder.Entity<CharacterLocation>()
                .HasIndex(cl => cl.CharacterId)
                .IsUnique();

            modelBuilder.Entity<CharacterLocation>()
                .HasIndex(cl => cl.SolarSystemId);

            modelBuilder.Entity<SolarSystem>(entity =>
            {
                entity.HasKey(e => e.Id);
                entity.Property(e => e.Id).ValueGeneratedNever();
                entity.HasIndex(e => e.Name).IsUnique();

                // Связи
                entity.HasMany(e => e.Planets)
                    .WithOne(p => p.SolarSystem)
                    .HasForeignKey(p => p.SolarSystemId)
                    .OnDelete(DeleteBehavior.Cascade);

                // Исправлено: используем правильную навигацию SourceSolarSystem
                entity.HasMany(e => e.Stargates)
                    .WithOne(sg => sg.SourceSolarSystem)
                    .HasForeignKey(sg => sg.SourceSolarSystemId)
                    .OnDelete(DeleteBehavior.Cascade);

                entity.HasMany(e => e.Anomalies)
                    .WithOne(a => a.SolarSystem)
                    .HasForeignKey(a => a.SolarSystemId)
                    .OnDelete(DeleteBehavior.Cascade);

                entity.HasMany(e => e.SourceWormholes)
                    .WithOne(w => w.SourceSystem)
                    .HasForeignKey(w => w.SourceSystemId)
                    .OnDelete(DeleteBehavior.Restrict);

                entity.HasMany(e => e.TargetWormholes)
                    .WithOne(w => w.TargetSystem)
                    .HasForeignKey(w => w.TargetSystemId)
                    .OnDelete(DeleteBehavior.Restrict);
            });

            // Конфигурация Anomaly
            modelBuilder.Entity<Anomaly>(entity =>
            {
                entity.HasKey(e => e.Id);
                entity.Property(e => e.Id).ValueGeneratedNever();
                entity.ToTable("Anomalies");
                // Индексы для производительности
                entity.HasIndex(e => e.SolarSystemId);
                entity.HasIndex(e => e.Type);
                entity.HasIndex(e => e.Difficulty);
                entity.HasIndex(e => e.ExpiresAt);
                entity.HasIndex(e => e.Signature).IsUnique();

                // Конвертация enum в string
                entity.Property(e => e.Type)
                    .HasConversion<string>();

                entity.Property(e => e.Difficulty)
                    .HasConversion<string>();
            });

            // Конфигурация Wormhole
            modelBuilder.Entity<Wormhole>(entity =>
            {
                entity.HasKey(e => e.Id);
                entity.Property(e => e.Id).ValueGeneratedNever();

                // Индексы
                entity.HasIndex(e => e.SourceSystemId);
                entity.HasIndex(e => e.TargetSystemId);
                entity.HasIndex(e => e.ExpiresAt);
                entity.HasIndex(e => e.Signature).IsUnique();
                entity.HasIndex(e => e.PairedWormholeId);

                // Конвертация enum
                entity.Property(e => e.Class)
                    .HasConversion<string>();

                entity.Property(e => e.MaxShipSize)
                    .HasConversion<string>();

                // Само-ссылка для парных вормхолов
                entity.HasOne(e => e.PairedWormhole)
                    .WithOne()
                    .HasForeignKey<Wormhole>(e => e.PairedWormholeId)
                    .OnDelete(DeleteBehavior.SetNull);
            });

            // Настройка точности для decimal полей
            modelBuilder.Entity<Wormhole>()
                .Property(e => e.MaxMass)
                .HasPrecision(18, 2);

            modelBuilder.Entity<Wormhole>()
                .Property(e => e.RemainingMass)
                .HasPrecision(18, 2);

            modelBuilder.Entity<Wormhole>()
                .Property(e => e.Stability)
                .HasPrecision(3, 2);

// ==============================================
// TABLE NAMES AND SCHEMA
// ==============================================

// Все таблицы будут в схеме "public" по умолчанию
// Можно сгруппировать по модулям
modelBuilder.Entity<Account>().ToTable("Accounts");
            modelBuilder.Entity<Character>().ToTable("Characters");
            modelBuilder.Entity<CharacterLocation>().ToTable("CharacterLocations");
            modelBuilder.Entity<AccountSession>().ToTable("AccountSessions");

            modelBuilder.Entity<Region>().ToTable("Regions");
            modelBuilder.Entity<Constellation>().ToTable("Constellations");
            modelBuilder.Entity<SolarSystem>().ToTable("SolarSystems");
            modelBuilder.Entity<Planet>().ToTable("Planets");
            modelBuilder.Entity<Moon>().ToTable("Moons");
            modelBuilder.Entity<Station>().ToTable("Stations");
            modelBuilder.Entity<Stargate>().ToTable("Stargates");
            modelBuilder.Entity<AsteroidBelt>().ToTable("AsteroidBelts");
            modelBuilder.Entity<PlanetResource>().ToTable("PlanetResources");

            // ==============================================
            // DEFAULT VALUES
            // ==============================================

            modelBuilder.Entity<Account>()
                .Property(a => a.CreatedAt)
                .HasDefaultValueSql("NOW()");

            modelBuilder.Entity<Account>()
                .Property(a => a.IsActive)
                .HasDefaultValue(true);

            modelBuilder.Entity<Character>()
                .Property(c => c.CreatedAt)
                .HasDefaultValueSql("NOW()");

            modelBuilder.Entity<Character>()
                .Property(c => c.LastLogin)
                .HasDefaultValueSql("NOW()");

            modelBuilder.Entity<CharacterLocation>()
                .Property(cl => cl.LastUpdate)
                .HasDefaultValueSql("NOW()");

            modelBuilder.Entity<Region>()
                .Property(r => r.CreatedAt)
                .HasDefaultValueSql("NOW()");

            modelBuilder.Entity<SolarSystem>()
                .Property(s => s.CreatedAt)
                .HasDefaultValueSql("NOW()");

            modelBuilder.Entity<Stargate>()
                .Property(sg => sg.IsOperational)
                .HasDefaultValue(true);
        }
    }
}