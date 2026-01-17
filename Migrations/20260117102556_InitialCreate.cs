using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class InitialCreate : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Accounts",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Username = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    Email = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    PasswordHash = table.Column<byte[]>(type: "bytea", maxLength: 128, nullable: false),
                    PasswordSalt = table.Column<byte[]>(type: "bytea", maxLength: 128, nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false, defaultValue: true),
                    IsBanned = table.Column<bool>(type: "boolean", nullable: false),
                    IsAdmin = table.Column<bool>(type: "boolean", nullable: false),
                    IsDeveloper = table.Column<bool>(type: "boolean", nullable: false),
                    LastLogin = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    LastLogout = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    LastIP = table.Column<string>(type: "character varying(45)", maxLength: 45, nullable: false),
                    FailedLoginAttempts = table.Column<int>(type: "integer", nullable: false),
                    LockedUntil = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Accounts", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "universe_generation_configs",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    ConfigName = table.Column<string>(type: "character varying(255)", maxLength: 255, nullable: false),
                    Description = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    ConfigJson = table.Column<string>(type: "jsonb", nullable: false),
                    UniverseSeed = table.Column<string>(type: "text", nullable: true),
                    UseSeedBasedGeneration = table.Column<bool>(type: "boolean", nullable: false),
                    SeedVersion = table.Column<int>(type: "integer", nullable: false),
                    GeneratorVersion = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    IsPreset = table.Column<bool>(type: "boolean", nullable: false),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false),
                    Tags = table.Column<string>(type: "text", nullable: true),
                    RegionCount = table.Column<int>(type: "integer", nullable: false),
                    SystemCount = table.Column<int>(type: "integer", nullable: false),
                    PlanetCount = table.Column<int>(type: "integer", nullable: false),
                    Anomalies = table.Column<string>(type: "jsonb", nullable: false),
                    Wormholes = table.Column<string>(type: "jsonb", nullable: false),
                    RandomSeed = table.Column<int>(type: "integer", nullable: false),
                    PresetType = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: true),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    LastUsedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    UsageCount = table.Column<int>(type: "integer", nullable: false),
                    GenerationTimeMs = table.Column<long>(type: "bigint", nullable: true),
                    GenerationStats = table.Column<string>(type: "text", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_universe_generation_configs", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "Regions",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    RegionCode = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    Type = table.Column<int>(type: "integer", nullable: false),
                    AverageSecurity = table.Column<float>(type: "real", precision: 3, scale: 2, nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    Description = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    UniverseGenerationConfigId = table.Column<Guid>(type: "uuid", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Regions", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Regions_universe_generation_configs_UniverseGenerationConfi~",
                        column: x => x.UniverseGenerationConfigId,
                        principalTable: "universe_generation_configs",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateTable(
                name: "Constellations",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    RegionId = table.Column<Guid>(type: "uuid", nullable: false),
                    AverageSecurity = table.Column<float>(type: "real", precision: 3, scale: 2, nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Constellations", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Constellations_Regions_RegionId",
                        column: x => x.RegionId,
                        principalTable: "Regions",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "SolarSystems",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    ConstellationId = table.Column<Guid>(type: "uuid", nullable: false),
                    SecurityStatus = table.Column<float>(type: "real", precision: 3, scale: 2, nullable: false),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    StarClass = table.Column<int>(type: "integer", nullable: false),
                    LuminosityClass = table.Column<int>(type: "integer", nullable: false),
                    TemperatureClass = table.Column<int>(type: "integer", nullable: false),
                    Temperature = table.Column<int>(type: "integer", precision: 7, scale: 2, nullable: false),
                    SolarRadius = table.Column<float>(type: "real", precision: 10, scale: 4, nullable: false),
                    SolarMass = table.Column<float>(type: "real", precision: 10, scale: 4, nullable: false),
                    Luminosity = table.Column<float>(type: "real", precision: 15, scale: 4, nullable: false),
                    NumberOfStars = table.Column<int>(type: "integer", nullable: false),
                    Radius = table.Column<long>(type: "bigint", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    HasAsteroidBelts = table.Column<bool>(type: "boolean", nullable: false),
                    HasStations = table.Column<bool>(type: "boolean", nullable: false),
                    Description = table.Column<string>(type: "character varying(1000)", maxLength: 1000, nullable: false),
                    RegionId = table.Column<Guid>(type: "uuid", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    UpdatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_SolarSystems", x => x.Id);
                    table.ForeignKey(
                        name: "FK_SolarSystems_Constellations_ConstellationId",
                        column: x => x.ConstellationId,
                        principalTable: "Constellations",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Anomalies",
                columns: table => new
                {
                    id = table.Column<Guid>(type: "uuid", nullable: false),
                    solar_system_id = table.Column<Guid>(type: "uuid", nullable: false),
                    type = table.Column<string>(type: "text", nullable: false),
                    difficulty = table.Column<string>(type: "text", nullable: false),
                    name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    description = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    position_x = table.Column<long>(type: "bigint", nullable: false),
                    position_y = table.Column<long>(type: "bigint", nullable: false),
                    position_z = table.Column<long>(type: "bigint", nullable: false),
                    radius = table.Column<double>(type: "double precision", nullable: false),
                    expires_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    signature = table.Column<string>(type: "character varying(20)", maxLength: 20, nullable: false),
                    durability = table.Column<double>(type: "double precision", nullable: false),
                    current_durability = table.Column<double>(type: "double precision", nullable: false),
                    scan_strength = table.Column<int>(type: "integer", nullable: false),
                    reward_data = table.Column<string>(type: "text", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Anomalies", x => x.id);
                    table.ForeignKey(
                        name: "FK_Anomalies_SolarSystems_solar_system_id",
                        column: x => x.solar_system_id,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "AsteroidBelts",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    Radius = table.Column<long>(type: "bigint", nullable: false),
                    Density = table.Column<float>(type: "real", nullable: false),
                    AsteroidCount = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_AsteroidBelts", x => x.Id);
                    table.ForeignKey(
                        name: "FK_AsteroidBelts_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "game_servers",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    InstanceId = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    PublicIP = table.Column<string>(type: "character varying(45)", maxLength: 45, nullable: false),
                    GamePort = table.Column<int>(type: "integer", nullable: false),
                    WebPort = table.Column<int>(type: "integer", nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: true),
                    RegionId = table.Column<Guid>(type: "uuid", nullable: true),
                    Status = table.Column<int>(type: "integer", nullable: false),
                    OnlinePlayers = table.Column<int>(type: "integer", nullable: false),
                    MaxPlayers = table.Column<int>(type: "integer", nullable: false),
                    CPUUsage = table.Column<float>(type: "real", nullable: false),
                    MemoryUsageMB = table.Column<long>(type: "bigint", nullable: false),
                    NetworkInKbps = table.Column<float>(type: "real", nullable: false),
                    NetworkOutKbps = table.Column<float>(type: "real", nullable: false),
                    LastHeartbeat = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    GeoRegion = table.Column<string>(type: "character varying(10)", maxLength: 10, nullable: false),
                    GameVersion = table.Column<string>(type: "character varying(20)", maxLength: 20, nullable: false),
                    Hostname = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: true),
                    StartupArguments = table.Column<string>(type: "text", nullable: true),
                    ServerTags = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: true),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    UpdatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_game_servers", x => x.Id);
                    table.ForeignKey(
                        name: "FK_game_servers_Regions_RegionId",
                        column: x => x.RegionId,
                        principalTable: "Regions",
                        principalColumn: "Id");
                    table.ForeignKey(
                        name: "FK_game_servers_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateTable(
                name: "Planets",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    Type = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    Radius = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    OrbitDistance = table.Column<long>(type: "bigint", nullable: false),
                    OrbitPeriod = table.Column<long>(type: "bigint", nullable: false),
                    HasAtmosphere = table.Column<bool>(type: "boolean", nullable: false),
                    AtmosphereType = table.Column<int>(type: "integer", nullable: false),
                    Temperature = table.Column<int>(type: "integer", nullable: false),
                    Gravity = table.Column<float>(type: "real", nullable: false),
                    HasMoons = table.Column<bool>(type: "boolean", nullable: false),
                    MoonCount = table.Column<int>(type: "integer", nullable: false),
                    IsColonizable = table.Column<bool>(type: "boolean", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    Description = table.Column<string>(type: "character varying(1000)", maxLength: 1000, nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    Mass = table.Column<double>(type: "double precision", nullable: false),
                    HasRings = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Planets", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Planets_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Stargates",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    SourceSolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    DestinationSolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    IsOperational = table.Column<bool>(type: "boolean", nullable: false, defaultValue: true),
                    JumpCost = table.Column<int>(type: "integer", nullable: false),
                    Model = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Stargates", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Stargates_SolarSystems_DestinationSolarSystemId",
                        column: x => x.DestinationSolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Stargates_SolarSystems_SourceSolarSystemId",
                        column: x => x.SourceSolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Stations",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    Type = table.Column<int>(type: "integer", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    DockingCapacity = table.Column<int>(type: "integer", nullable: false),
                    IsOperational = table.Column<bool>(type: "boolean", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    Services = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Stations", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Stations_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "wormholes",
                columns: table => new
                {
                    id = table.Column<Guid>(type: "uuid", nullable: false),
                    source_system_id = table.Column<Guid>(type: "uuid", nullable: false),
                    target_system_id = table.Column<Guid>(type: "uuid", nullable: false),
                    name = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    @class = table.Column<string>(name: "class", type: "text", nullable: false),
                    max_mass = table.Column<double>(type: "double precision", precision: 18, scale: 2, nullable: false),
                    remaining_mass = table.Column<double>(type: "double precision", precision: 18, scale: 2, nullable: false),
                    max_ship_size = table.Column<string>(type: "text", nullable: false),
                    expires_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    position_x = table.Column<long>(type: "bigint", nullable: false),
                    position_y = table.Column<long>(type: "bigint", nullable: false),
                    position_z = table.Column<long>(type: "bigint", nullable: false),
                    radius = table.Column<double>(type: "double precision", nullable: false),
                    stability = table.Column<double>(type: "double precision", precision: 3, scale: 2, nullable: false),
                    signature = table.Column<string>(type: "character varying(20)", maxLength: 20, nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    last_used_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    total_passes = table.Column<int>(type: "integer", nullable: false),
                    paired_wormhole_id = table.Column<Guid>(type: "uuid", nullable: true),
                    is_exit_only = table.Column<bool>(type: "boolean", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_wormholes", x => x.id);
                    table.ForeignKey(
                        name: "FK_wormholes_SolarSystems_source_system_id",
                        column: x => x.source_system_id,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_wormholes_SolarSystems_target_system_id",
                        column: x => x.target_system_id,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_wormholes_wormholes_paired_wormhole_id",
                        column: x => x.paired_wormhole_id,
                        principalTable: "wormholes",
                        principalColumn: "id",
                        onDelete: ReferentialAction.SetNull);
                });

            migrationBuilder.CreateTable(
                name: "Moons",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    PlanetId = table.Column<Guid>(type: "uuid", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    Radius = table.Column<long>(type: "bigint", nullable: false),
                    OrbitDistance = table.Column<long>(type: "bigint", nullable: false),
                    OrbitPeriod = table.Column<long>(type: "bigint", nullable: false),
                    HasResources = table.Column<bool>(type: "boolean", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Moons", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Moons_Planets_PlanetId",
                        column: x => x.PlanetId,
                        principalTable: "Planets",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "PlanetResources",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    PlanetId = table.Column<Guid>(type: "uuid", nullable: true),
                    MoonId = table.Column<Guid>(type: "uuid", nullable: true),
                    AsteroidBeltId = table.Column<Guid>(type: "uuid", nullable: true),
                    ResourceType = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    Quantity = table.Column<int>(type: "integer", nullable: false),
                    Quality = table.Column<float>(type: "real", nullable: false),
                    LastHarvested = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_PlanetResources", x => x.Id);
                    table.ForeignKey(
                        name: "FK_PlanetResources_AsteroidBelts_AsteroidBeltId",
                        column: x => x.AsteroidBeltId,
                        principalTable: "AsteroidBelts",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_PlanetResources_Moons_MoonId",
                        column: x => x.MoonId,
                        principalTable: "Moons",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_PlanetResources_Planets_PlanetId",
                        column: x => x.PlanetId,
                        principalTable: "Planets",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "account_bans",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    AccountId = table.Column<Guid>(type: "uuid", nullable: false),
                    Reason = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    BannedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    ExpiresAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    BannedById = table.Column<Guid>(type: "uuid", nullable: true),
                    IPAddress = table.Column<string>(type: "character varying(45)", maxLength: 45, nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_account_bans", x => x.Id);
                    table.ForeignKey(
                        name: "FK_account_bans_Accounts_AccountId",
                        column: x => x.AccountId,
                        principalTable: "Accounts",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "AccountSessions",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    AccountId = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    SessionToken = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    RefreshToken = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    ExpiresAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    RefreshTokenExpiresAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    IPAddress = table.Column<string>(type: "character varying(45)", maxLength: 45, nullable: false),
                    UserAgent = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false),
                    LastActivity = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_AccountSessions", x => x.Id);
                    table.ForeignKey(
                        name: "FK_AccountSessions_Accounts_AccountId",
                        column: x => x.AccountId,
                        principalTable: "Accounts",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "character_implants",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    Slot = table.Column<int>(type: "integer", nullable: false),
                    TypeId = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_implants", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "character_skills",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    SkillId = table.Column<int>(type: "integer", nullable: false),
                    Level = table.Column<int>(type: "integer", nullable: false),
                    Skillpoints = table.Column<int>(type: "integer", nullable: false),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false),
                    TrainingStart = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    TrainingEnd = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_skills", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "character_standings",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    TargetId = table.Column<int>(type: "integer", nullable: false),
                    TargetType = table.Column<string>(type: "text", nullable: false),
                    Standing = table.Column<float>(type: "real", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_standings", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "CharacterLocations",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: true),
                    PositionX = table.Column<double>(type: "double precision", nullable: false),
                    PositionY = table.Column<double>(type: "double precision", nullable: false),
                    PositionZ = table.Column<double>(type: "double precision", nullable: false),
                    RotationX = table.Column<float>(type: "real", nullable: false),
                    RotationY = table.Column<float>(type: "real", nullable: false),
                    RotationZ = table.Column<float>(type: "real", nullable: false),
                    RotationW = table.Column<float>(type: "real", nullable: false),
                    VelocityX = table.Column<float>(type: "real", nullable: false),
                    VelocityY = table.Column<float>(type: "real", nullable: false),
                    VelocityZ = table.Column<float>(type: "real", nullable: false),
                    StationId = table.Column<Guid>(type: "uuid", nullable: true),
                    ShipItemId = table.Column<long>(type: "bigint", nullable: true),
                    IsDocked = table.Column<bool>(type: "boolean", nullable: false),
                    InWarp = table.Column<bool>(type: "boolean", nullable: false),
                    IsCloaked = table.Column<bool>(type: "boolean", nullable: false),
                    WarpEndTime = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    LocationType = table.Column<int>(type: "integer", nullable: false),
                    LastUpdate = table.Column<DateTime>(type: "timestamp with time zone", nullable: true, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_CharacterLocations", x => x.Id);
                    table.ForeignKey(
                        name: "FK_CharacterLocations_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_CharacterLocations_Stations_StationId",
                        column: x => x.StationId,
                        principalTable: "Stations",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "Characters",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    AccountId = table.Column<Guid>(type: "uuid", nullable: false),
                    WalletBalance = table.Column<long>(type: "bigint", nullable: false),
                    SecurityStatus = table.Column<float>(type: "real", nullable: false),
                    CloneExpiration = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    CorporationId = table.Column<Guid>(type: "uuid", nullable: true),
                    CorporationRole = table.Column<long>(type: "bigint", nullable: false),
                    RaceId = table.Column<int>(type: "integer", nullable: false),
                    BloodlineId = table.Column<int>(type: "integer", nullable: false),
                    AncestryId = table.Column<int>(type: "integer", nullable: false),
                    TotalSkillPoints = table.Column<int>(type: "integer", nullable: false),
                    UnallocatedSkillPoints = table.Column<int>(type: "integer", nullable: false),
                    SkillTrainingEnd = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    ActiveShipItemId = table.Column<long>(type: "bigint", nullable: true),
                    SettingsJson = table.Column<string>(type: "text", nullable: false),
                    IsMain = table.Column<bool>(type: "boolean", nullable: false),
                    IsOnline = table.Column<bool>(type: "boolean", nullable: false),
                    IsDocked = table.Column<bool>(type: "boolean", nullable: false),
                    InWarp = table.Column<bool>(type: "boolean", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    LastLogin = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Characters", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Characters_Accounts_AccountId",
                        column: x => x.AccountId,
                        principalTable: "Accounts",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "inventory_items",
                columns: table => new
                {
                    ItemId = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    OwnerId = table.Column<Guid>(type: "uuid", nullable: false),
                    TypeId = table.Column<int>(type: "integer", nullable: false),
                    Quantity = table.Column<int>(type: "integer", nullable: false),
                    IsSingleton = table.Column<bool>(type: "boolean", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_inventory_items", x => x.ItemId);
                    table.ForeignKey(
                        name: "FK_inventory_items_Characters_CharacterId",
                        column: x => x.CharacterId,
                        principalTable: "Characters",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateIndex(
                name: "IX_account_bans_AccountId",
                table: "account_bans",
                column: "AccountId");

            migrationBuilder.CreateIndex(
                name: "IX_account_bans_BannedById",
                table: "account_bans",
                column: "BannedById");

            migrationBuilder.CreateIndex(
                name: "IX_Accounts_Email",
                table: "Accounts",
                column: "Email",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Accounts_Username",
                table: "Accounts",
                column: "Username",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_AccountSessions_AccountId",
                table: "AccountSessions",
                column: "AccountId");

            migrationBuilder.CreateIndex(
                name: "IX_AccountSessions_CharacterId",
                table: "AccountSessions",
                column: "CharacterId");

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_difficulty",
                table: "Anomalies",
                column: "difficulty");

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_expires_at",
                table: "Anomalies",
                column: "expires_at");

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_signature",
                table: "Anomalies",
                column: "signature",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_solar_system_id",
                table: "Anomalies",
                column: "solar_system_id");

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_type",
                table: "Anomalies",
                column: "type");

            migrationBuilder.CreateIndex(
                name: "IX_AsteroidBelts_SolarSystemId",
                table: "AsteroidBelts",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_character_implants_CharacterId",
                table: "character_implants",
                column: "CharacterId");

            migrationBuilder.CreateIndex(
                name: "IX_character_skills_CharacterId",
                table: "character_skills",
                column: "CharacterId");

            migrationBuilder.CreateIndex(
                name: "IX_character_standings_CharacterId",
                table: "character_standings",
                column: "CharacterId");

            migrationBuilder.CreateIndex(
                name: "IX_CharacterLocations_CharacterId",
                table: "CharacterLocations",
                column: "CharacterId",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_CharacterLocations_ShipItemId",
                table: "CharacterLocations",
                column: "ShipItemId");

            migrationBuilder.CreateIndex(
                name: "IX_CharacterLocations_SolarSystemId",
                table: "CharacterLocations",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_CharacterLocations_StationId",
                table: "CharacterLocations",
                column: "StationId");

            migrationBuilder.CreateIndex(
                name: "IX_Characters_AccountId",
                table: "Characters",
                column: "AccountId");

            migrationBuilder.CreateIndex(
                name: "IX_Characters_ActiveShipItemId",
                table: "Characters",
                column: "ActiveShipItemId");

            migrationBuilder.CreateIndex(
                name: "IX_Characters_Name",
                table: "Characters",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Constellations_Name",
                table: "Constellations",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Constellations_RegionId",
                table: "Constellations",
                column: "RegionId");

            migrationBuilder.CreateIndex(
                name: "IX_game_servers_RegionId",
                table: "game_servers",
                column: "RegionId");

            migrationBuilder.CreateIndex(
                name: "IX_game_servers_SolarSystemId",
                table: "game_servers",
                column: "SolarSystemId",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_inventory_items_CharacterId",
                table: "inventory_items",
                column: "CharacterId");

            migrationBuilder.CreateIndex(
                name: "IX_Moons_PlanetId",
                table: "Moons",
                column: "PlanetId");

            migrationBuilder.CreateIndex(
                name: "IX_PlanetResources_AsteroidBeltId",
                table: "PlanetResources",
                column: "AsteroidBeltId");

            migrationBuilder.CreateIndex(
                name: "IX_PlanetResources_MoonId",
                table: "PlanetResources",
                column: "MoonId");

            migrationBuilder.CreateIndex(
                name: "IX_PlanetResources_PlanetId",
                table: "PlanetResources",
                column: "PlanetId");

            migrationBuilder.CreateIndex(
                name: "IX_Planets_SolarSystemId",
                table: "Planets",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_Regions_Name",
                table: "Regions",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Regions_UniverseGenerationConfigId",
                table: "Regions",
                column: "UniverseGenerationConfigId");

            migrationBuilder.CreateIndex(
                name: "IX_SolarSystems_ConstellationId",
                table: "SolarSystems",
                column: "ConstellationId");

            migrationBuilder.CreateIndex(
                name: "IX_SolarSystems_Name",
                table: "SolarSystems",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_SolarSystems_PositionX_PositionY_PositionZ",
                table: "SolarSystems",
                columns: new[] { "PositionX", "PositionY", "PositionZ" });

            migrationBuilder.CreateIndex(
                name: "IX_SolarSystems_SecurityStatus",
                table: "SolarSystems",
                column: "SecurityStatus");

            migrationBuilder.CreateIndex(
                name: "IX_Stargates_DestinationSolarSystemId",
                table: "Stargates",
                column: "DestinationSolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_Stargates_SourceSolarSystemId",
                table: "Stargates",
                column: "SourceSolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_Stations_SolarSystemId",
                table: "Stations",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_expires_at",
                table: "wormholes",
                column: "expires_at");

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_paired_wormhole_id",
                table: "wormholes",
                column: "paired_wormhole_id",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_signature",
                table: "wormholes",
                column: "signature",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_source_system_id",
                table: "wormholes",
                column: "source_system_id");

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_target_system_id",
                table: "wormholes",
                column: "target_system_id");

            migrationBuilder.AddForeignKey(
                name: "FK_account_bans_Characters_BannedById",
                table: "account_bans",
                column: "BannedById",
                principalTable: "Characters",
                principalColumn: "Id");

            migrationBuilder.AddForeignKey(
                name: "FK_AccountSessions_Characters_CharacterId",
                table: "AccountSessions",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_implants_Characters_CharacterId",
                table: "character_implants",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_skills_Characters_CharacterId",
                table: "character_skills",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_standings_Characters_CharacterId",
                table: "character_standings",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_CharacterLocations_Characters_CharacterId",
                table: "CharacterLocations",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_CharacterLocations_inventory_items_ShipItemId",
                table: "CharacterLocations",
                column: "ShipItemId",
                principalTable: "inventory_items",
                principalColumn: "ItemId");

            migrationBuilder.AddForeignKey(
                name: "FK_Characters_inventory_items_ActiveShipItemId",
                table: "Characters",
                column: "ActiveShipItemId",
                principalTable: "inventory_items",
                principalColumn: "ItemId");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Characters_Accounts_AccountId",
                table: "Characters");

            migrationBuilder.DropForeignKey(
                name: "FK_inventory_items_Characters_CharacterId",
                table: "inventory_items");

            migrationBuilder.DropTable(
                name: "account_bans");

            migrationBuilder.DropTable(
                name: "AccountSessions");

            migrationBuilder.DropTable(
                name: "Anomalies");

            migrationBuilder.DropTable(
                name: "character_implants");

            migrationBuilder.DropTable(
                name: "character_skills");

            migrationBuilder.DropTable(
                name: "character_standings");

            migrationBuilder.DropTable(
                name: "CharacterLocations");

            migrationBuilder.DropTable(
                name: "game_servers");

            migrationBuilder.DropTable(
                name: "PlanetResources");

            migrationBuilder.DropTable(
                name: "Stargates");

            migrationBuilder.DropTable(
                name: "wormholes");

            migrationBuilder.DropTable(
                name: "Stations");

            migrationBuilder.DropTable(
                name: "AsteroidBelts");

            migrationBuilder.DropTable(
                name: "Moons");

            migrationBuilder.DropTable(
                name: "Planets");

            migrationBuilder.DropTable(
                name: "SolarSystems");

            migrationBuilder.DropTable(
                name: "Constellations");

            migrationBuilder.DropTable(
                name: "Regions");

            migrationBuilder.DropTable(
                name: "universe_generation_configs");

            migrationBuilder.DropTable(
                name: "Accounts");

            migrationBuilder.DropTable(
                name: "Characters");

            migrationBuilder.DropTable(
                name: "inventory_items");
        }
    }
}
