using Echoes.API.Models;
using System.Text.Json;
using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Entities.GameServer;
using Echoes.API.Models.Entities.Universe;
using Echoes.API.Models.Entities.Inventory;
using Echoes.API.Models.Entities.Shop;
using Echoes.API.Models.Enums;
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
        public DbSet<CharacterContract> CharacterContracts { get; set; }
        public DbSet<CharacterWallet> CharacterWallets { get; set; }
        public DbSet<WalletTransaction> WalletTransactions { get; set; }
        public DbSet<Faction> Factions { get; set; }
        public DbSet<SkillGroupEntity> SkillGroups { get; set; }
        public DbSet<Skill> Skills { get; set; }
        public DbSet<CharacterSkillEnhanced> CharacterSkillsEnhanced { get; set; }

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

        // Inventory entities
        public DbSet<ItemCategory> ItemCategories { get; set; }
        public DbSet<Echoes.API.Models.Entities.Inventory.ItemGroup> ItemGroups { get; set; }
        public DbSet<ItemTypeEntity> ItemTypesInventory { get; set; }
        public DbSet<Ship> Ships { get; set; }
        public DbSet<Module> Modules { get; set; }
        public DbSet<Container> Containers { get; set; }
        public DbSet<Asset> Assets { get; set; }
        public DbSet<ShipFitting> ShipFittings { get; set; }
        public DbSet<FittedModule> FittedModules { get; set; }
        public DbSet<AssetLog> AssetLogs { get; set; }
        public DbSet<PlayerInventoryItem> PlayerInventoryItems { get; set; }
        
        // Ship instance entities for movement system
        public DbSet<ShipInstance> ShipInstances { get; set; }
        public DbSet<ShipInstanceModule> ShipInstanceModules { get; set; }
        
        // Shop entities
        public DbSet<ShopItem> ShopItems { get; set; }
        
        // Configuration entities
        public DbSet<Models.Config.RaceConfig> RaceConfigs { get; set; }

        // News entities
        public DbSet<Echoes.API.Models.Entities.News.NewsPost> NewsPosts { get; set; }
        
        // Wiki entities
        public DbSet<Echoes.API.Models.Entities.Wiki.WikiPage> WikiPages { get; set; }


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

            // Character -> CharacterContracts (one-to-many for issued contracts)
            modelBuilder.Entity<Character>()
                .HasMany(c => c.IssuedContracts)
                .WithOne(cc => cc.Issuer)
                .HasForeignKey(cc => cc.IssuerId)
                .OnDelete(DeleteBehavior.Restrict);

            // CharacterContract -> Assignee (many-to-one, optional)
            modelBuilder.Entity<CharacterContract>()
                .HasOne(cc => cc.Assignee)
                .WithMany()
                .HasForeignKey(cc => cc.AssigneeId)
                .OnDelete(DeleteBehavior.Restrict);

            // CharacterContract -> Acceptor (many-to-one, optional)
            modelBuilder.Entity<CharacterContract>()
                .HasOne(cc => cc.Acceptor)
                .WithMany()
                .HasForeignKey(cc => cc.AcceptorId)
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
// Account table name is defined by the [Table("accounts")] attribute on the entity.
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
                .Property(a => a.AccountStatus)
                .HasDefaultValue(AccountStatus.Active);

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

            // ==============================================
            // INVENTORY ENTITIES
            // ==============================================

            // ItemCategory configuration
            modelBuilder.Entity<ItemCategory>(entity =>
            {
                entity.HasKey(e => e.CategoryId);
                entity.HasIndex(e => e.Name).IsUnique();
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");
            });

            // ItemGroup configuration
            modelBuilder.Entity<Echoes.API.Models.Entities.Inventory.ItemGroup>(entity =>
            {
                entity.HasKey(e => e.GroupId);
                entity.HasIndex(e => e.Name).IsUnique();
                entity.HasIndex(e => e.CategoryId);
                entity.Property(e => e.VolumeMultiplier).HasPrecision(5, 2);
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.Category)
                    .WithMany(c => c.ItemGroups)
                    .HasForeignKey(e => e.CategoryId)
                    .OnDelete(DeleteBehavior.Restrict);
            });

            // ItemTypeEntity configuration
            modelBuilder.Entity<ItemTypeEntity>(entity =>
            {
                entity.HasKey(e => e.TypeId);
                entity.HasIndex(e => e.GroupId);
                entity.HasIndex(e => e.Name);
                entity.Property(e => e.BaseVolume).HasPrecision(12, 4);
                entity.Property(e => e.PackagedVolume).HasPrecision(12, 4);
                entity.Property(e => e.Mass).HasPrecision(12, 4);
                entity.Property(e => e.Capacity).HasPrecision(12, 4);
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");
                entity.Property(e => e.UpdatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.Group)
                    .WithMany(g => g.ItemTypes)
                    .HasForeignKey(e => e.GroupId)
                    .OnDelete(DeleteBehavior.Restrict);
            });

            // Ship configuration
            modelBuilder.Entity<Ship>(entity =>
            {
                entity.HasKey(e => e.ShipTypeId);
                entity.HasIndex(e => e.Race);
                entity.Property(e => e.BaseCpu).HasPrecision(10, 2);
                entity.Property(e => e.BasePowergrid).HasPrecision(10, 2);
                entity.Property(e => e.BaseCapacitor).HasPrecision(10, 2);
                entity.Property(e => e.BaseShieldHp).HasPrecision(12, 2);
                entity.Property(e => e.BaseArmorHp).HasPrecision(12, 2);
                entity.Property(e => e.BaseStructureHp).HasPrecision(12, 2);
                entity.Property(e => e.BaseSpeed).HasPrecision(10, 2);
                entity.Property(e => e.BaseAgility).HasPrecision(10, 4);
                entity.Property(e => e.BaseSignatureRadius).HasPrecision(10, 2);
                entity.Property(e => e.BaseCargoCapacity).HasPrecision(12, 2);
                entity.Property(e => e.ShieldResistanceEm).HasPrecision(5, 3);
                entity.Property(e => e.ShieldResistanceThermal).HasPrecision(5, 3);
                entity.Property(e => e.ShieldResistanceKinetic).HasPrecision(5, 3);
                entity.Property(e => e.ShieldResistanceExplosive).HasPrecision(5, 3);
                entity.Property(e => e.ArmorResistanceEm).HasPrecision(5, 3);
                entity.Property(e => e.ArmorResistanceThermal).HasPrecision(5, 3);
                entity.Property(e => e.ArmorResistanceKinetic).HasPrecision(5, 3);
                entity.Property(e => e.ArmorResistanceExplosive).HasPrecision(5, 3);
                entity.Property(e => e.StructureResistanceEm).HasPrecision(5, 3);
                entity.Property(e => e.StructureResistanceThermal).HasPrecision(5, 3);
                entity.Property(e => e.StructureResistanceKinetic).HasPrecision(5, 3);
                entity.Property(e => e.StructureResistanceExplosive).HasPrecision(5, 3);
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");
                entity.Property(e => e.UpdatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.ItemType)
                    .WithOne(it => it.Ship)
                    .HasForeignKey<Ship>(e => e.ShipTypeId)
                    .OnDelete(DeleteBehavior.Cascade);
            });

            // Module configuration
            modelBuilder.Entity<Module>(entity =>
            {
                entity.HasKey(e => e.ModuleTypeId);
                entity.HasIndex(e => e.SlotType);
                entity.Property(e => e.RequiredCpu).HasPrecision(10, 2);
                entity.Property(e => e.RequiredPowergrid).HasPrecision(10, 2);
                entity.Property(e => e.RequiredCapacitor).HasPrecision(10, 2);
                entity.Property(e => e.ActivationCost).HasPrecision(10, 2);
                entity.Property(e => e.ActivationDuration).HasPrecision(10, 2);
                entity.Property(e => e.CooldownTime).HasPrecision(10, 2);
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");
                entity.Property(e => e.UpdatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.ItemType)
                    .WithOne(it => it.Module)
                    .HasForeignKey<Module>(e => e.ModuleTypeId)
                    .OnDelete(DeleteBehavior.Cascade);
            });

            // Container configuration
            modelBuilder.Entity<Container>(entity =>
            {
                entity.HasKey(e => e.ContainerId);
                entity.HasIndex(e => e.OwnerId);
                entity.HasIndex(e => e.ParentContainerId);
                entity.HasIndex(e => e.ContainerType);
                entity.Property(e => e.MaxVolume).HasPrecision(15, 4);
                entity.Property(e => e.UsedVolume).HasPrecision(15, 4);
                entity.Property(e => e.LocationX).HasPrecision(20, 4);
                entity.Property(e => e.LocationY).HasPrecision(20, 4);
                entity.Property(e => e.LocationZ).HasPrecision(20, 4);
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");
                entity.Property(e => e.UpdatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.ParentContainer)
                    .WithMany(c => c.ChildContainers)
                    .HasForeignKey(e => e.ParentContainerId)
                    .OnDelete(DeleteBehavior.Restrict);
            });

            // Asset configuration
            modelBuilder.Entity<Asset>(entity =>
            {
                entity.HasKey(e => e.AssetId);
                entity.HasIndex(e => e.LocationId);
                entity.HasIndex(e => e.OwnerId);
                entity.HasIndex(e => new { e.LocationId, e.LocationFlag });
                entity.HasIndex(e => e.TypeId);
                entity.HasIndex(e => new { e.OwnerId, e.LocationId });
                entity.HasIndex(e => e.IsOnline).HasFilter("is_online = true");
                entity.HasIndex(e => e.IsSingleton).HasFilter("is_singleton = true");
                entity.HasIndex(e => e.IsBpc).HasFilter("is_bpc = true");
                entity.Property(e => e.Damage).HasPrecision(5, 2);
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");
                entity.Property(e => e.UpdatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.ItemType)
                    .WithMany(it => it.Assets)
                    .HasForeignKey(e => e.TypeId)
                    .OnDelete(DeleteBehavior.Restrict);

                entity.HasOne(e => e.Location)
                    .WithMany(c => c.Assets)
                    .HasForeignKey(e => e.LocationId)
                    .OnDelete(DeleteBehavior.Restrict);
            });

            // ShipFitting configuration
            modelBuilder.Entity<ShipFitting>(entity =>
            {
                entity.HasKey(e => e.FittingId);
                entity.HasIndex(e => e.ShipAssetId);
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");
                entity.Property(e => e.UpdatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.ShipAsset)
                    .WithMany()
                    .HasForeignKey(e => e.ShipAssetId)
                    .OnDelete(DeleteBehavior.Cascade);
            });

            // FittedModule configuration
            modelBuilder.Entity<FittedModule>(entity =>
            {
                entity.HasKey(e => e.FittedModuleId);
                entity.HasIndex(e => e.FittingId);
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.Fitting)
                    .WithMany(f => f.FittedModules)
                    .HasForeignKey(e => e.FittingId)
                    .OnDelete(DeleteBehavior.Cascade);

                entity.HasOne(e => e.ModuleAsset)
                    .WithMany()
                    .HasForeignKey(e => e.ModuleAssetId)
                    .OnDelete(DeleteBehavior.Restrict);

                entity.HasOne(e => e.AmmoType)
                    .WithMany()
                    .HasForeignKey(e => e.AmmoTypeId)
                    .OnDelete(DeleteBehavior.Restrict);
            });

            // AssetLog configuration
            modelBuilder.Entity<AssetLog>(entity =>
            {
                entity.HasKey(e => e.LogId);
                entity.HasIndex(e => e.AssetId);
                entity.HasIndex(e => e.CreatedAt).IsDescending();
                entity.Property(e => e.CreatedAt).HasDefaultValueSql("NOW()");

                entity.HasOne(e => e.Asset)
                    .WithMany(a => a.AssetLogs)
                    .HasForeignKey(e => e.AssetId)
                    .OnDelete(DeleteBehavior.SetNull);
            });

            // ==============================================
            // FACTION AND SKILL GROUP ENTITIES
            // ==============================================

            // Faction configuration
            modelBuilder.Entity<Faction>(entity =>
            {
                entity.ToTable("factions");
                entity.HasKey(e => e.FactionId);
                entity.HasIndex(e => e.Name).IsUnique();
            });

            // SkillGroup configuration
            modelBuilder.Entity<SkillGroupEntity>(entity =>
            {
                entity.ToTable("skill_groups");
                entity.HasKey(e => e.SkillGroupId);
                entity.HasIndex(e => e.Name).IsUnique();
            });

            // Skill configuration
            modelBuilder.Entity<Skill>(entity =>
            {
                entity.ToTable("skills");
                entity.HasKey(e => e.SkillId);
                entity.HasIndex(e => e.SkillGroupId);
                
                entity.HasOne(e => e.SkillGroup)
                    .WithMany(sg => sg.Skills)
                    .HasForeignKey(e => e.SkillGroupId)
                    .OnDelete(DeleteBehavior.Restrict);
            });

            // Character -> Faction relationship
            modelBuilder.Entity<Character>()
                .HasOne(c => c.Faction)
                .WithMany(f => f.Characters)
                .HasForeignKey(c => c.FactionId)
                .OnDelete(DeleteBehavior.Restrict);

            modelBuilder.Entity<Character>()
                .HasIndex(c => c.FactionId);

            // CharacterSkillEnhanced configuration
            modelBuilder.Entity<CharacterSkillEnhanced>(entity =>
            {
                entity.ToTable("character_skills_enhanced");
                entity.HasKey(e => e.CharacterSkillId);
                
                // Unique constraint on (CharacterId, SkillId)
                entity.HasIndex(e => new { e.CharacterId, e.SkillId }).IsUnique();
                
                // Index for active training queries
                entity.HasIndex(e => new { e.IsActive, e.TrainingFinishedAt });
                
                // Relationships
                entity.HasOne(e => e.Character)
                    .WithMany(c => c.SkillsEnhanced)
                    .HasForeignKey(e => e.CharacterId)
                    .OnDelete(DeleteBehavior.Cascade);
                
                entity.HasOne(e => e.Skill)
                    .WithMany(s => s.CharacterSkills)
                    .HasForeignKey(e => e.SkillId)
                    .OnDelete(DeleteBehavior.Restrict);
            });

            // ==============================================
            // SEED DATA
            // ==============================================

            var seedTime = new DateTime(2026, 2, 5, 0, 0, 0, DateTimeKind.Utc);

            // Faction seeds
            modelBuilder.Entity<Faction>().HasData(
                new Faction { FactionId = 1, Name = "Arden", ConfigJson = "{}", Description = "Arden faction", CreatedAt = seedTime, UpdatedAt = seedTime },
                new Faction { FactionId = 2, Name = "Nova", ConfigJson = "{}", Description = "Nova faction", CreatedAt = seedTime, UpdatedAt = seedTime },
                new Faction { FactionId = 3, Name = "Solaris", ConfigJson = "{}", Description = "Solaris faction", CreatedAt = seedTime, UpdatedAt = seedTime },
                new Faction { FactionId = 4, Name = "Valerion", ConfigJson = "{}", Description = "Valerion faction", CreatedAt = seedTime, UpdatedAt = seedTime }
            );

            // SkillGroup seeds
            modelBuilder.Entity<SkillGroupEntity>().HasData(
                new SkillGroupEntity { SkillGroupId = 1, Name = "Gunnery", Description = "Gunnery skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 2, Name = "Missiles", Description = "Missile skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 3, Name = "Drones", Description = "Drone skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 4, Name = "Navigation", Description = "Navigation skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 5, Name = "Targeting", Description = "Targeting skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 6, Name = "Engineering", Description = "Engineering skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 7, Name = "Electronics", Description = "Electronics skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 8, Name = "Mechanics", Description = "Mechanics skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 9, Name = "Shield", Description = "Shield skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 10, Name = "Armor", Description = "Armor skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 11, Name = "SpaceshipCommand", Description = "Spaceship Command skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 12, Name = "Frigate", Description = "Frigate skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 13, Name = "Cruiser", Description = "Cruiser skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 14, Name = "Battleship", Description = "Battleship skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime },
                new SkillGroupEntity { SkillGroupId = 15, Name = "Industrial", Description = "Industrial skills", ConfigJson = "{}", CreatedAt = seedTime, UpdatedAt = seedTime }
            );
        }
    }
}