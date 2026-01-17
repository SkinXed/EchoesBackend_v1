using System;
using System.Collections.Generic;

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Request DTO for getting server configuration.
    /// Used by game servers to request their operational configuration.
    /// </summary>
    public class ServerConfigRequestDto
    {
        /// <summary>
        /// Unique identifier for the server instance requesting configuration.
        /// </summary>
        public string InstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Type of server: "DedicatedSystem" or "RegionalCluster".
        /// </summary>
        public string ServerType { get; set; } = string.Empty;

        /// <summary>
        /// Solar System ID for dedicated system servers.
        /// Required when ServerType is "DedicatedSystem".
        /// </summary>
        public string? SolarSystemId { get; set; }

        /// <summary>
        /// Region ID for regional cluster servers.
        /// Required when ServerType is "RegionalCluster".
        /// </summary>
        public Guid? RegionId { get; set; }

        /// <summary>
        /// Cluster ID for regional cluster servers.
        /// Required when ServerType is "RegionalCluster".
        /// </summary>
        public string? ClusterId { get; set; }

        /// <summary>
        /// Geographic region code (e.g., "EU", "US", "ASIA").
        /// </summary>
        public string? GeoRegion { get; set; }
    }

    /// <summary>
    /// Response DTO containing server configuration.
    /// Wraps the configuration in a "Config" property as expected by UE5.
    /// </summary>
    public class ServerConfigResponseDto
    {
        /// <summary>
        /// Configuration data for the game server system.
        /// </summary>
        public ServerSystemConfigDto Config { get; set; } = new ServerSystemConfigDto();
    }

    /// <summary>
    /// Solar system configuration details.
    /// Contains all data needed to initialize a game server instance.
    /// </summary>
    public class ServerSystemConfigDto
    {
        /// <summary>
        /// Unique identifier of the solar system.
        /// </summary>
        public Guid SystemId { get; set; }

        /// <summary>
        /// Name of the solar system.
        /// </summary>
        public string SystemName { get; set; } = string.Empty;

        /// <summary>
        /// Radius of the primary star (relative to solar radius).
        /// </summary>
        public float SolarRadius { get; set; }

        /// <summary>
        /// Mass of the primary star (relative to solar mass).
        /// </summary>
        public float SolarMass { get; set; }

        /// <summary>
        /// Temperature of the primary star in Kelvin.
        /// </summary>
        public float Temperature { get; set; }

        /// <summary>
        /// Luminosity of the primary star (relative to solar luminosity).
        /// </summary>
        public float Luminosity { get; set; }

        /// <summary>
        /// Security status of the solar system (-1.0 to 1.0).
        /// </summary>
        public float SecurityStatus { get; set; }

        /// <summary>
        /// Constellation ID this system belongs to.
        /// </summary>
        public Guid ConstellationId { get; set; }

        /// <summary>
        /// Name of the constellation.
        /// </summary>
        public string ConstellationName { get; set; } = string.Empty;

        /// <summary>
        /// Region ID this system belongs to.
        /// </summary>
        public Guid? RegionId { get; set; }

        /// <summary>
        /// Name of the region.
        /// </summary>
        public string RegionName { get; set; } = string.Empty;

        /// <summary>
        /// X coordinate of the solar system in the universe.
        /// </summary>
        public long PositionX { get; set; }

        /// <summary>
        /// Y coordinate of the solar system in the universe.
        /// </summary>
        public long PositionY { get; set; }

        /// <summary>
        /// Z coordinate of the solar system in the universe.
        /// </summary>
        public long PositionZ { get; set; }

        /// <summary>
        /// List of planets in this solar system.
        /// </summary>
        public List<PlanetConfigDto> Planets { get; set; } = new List<PlanetConfigDto>();

        /// <summary>
        /// List of stargates in this solar system.
        /// </summary>
        public List<StargateConfigDto> Stargates { get; set; } = new List<StargateConfigDto>();

        /// <summary>
        /// List of stations in this solar system.
        /// </summary>
        public List<StationConfigDto> Stations { get; set; } = new List<StationConfigDto>();

        /// <summary>
        /// List of asteroid belts in this solar system.
        /// </summary>
        public List<AsteroidBeltConfigDto> AsteroidBelts { get; set; } = new List<AsteroidBeltConfigDto>();
    }

    /// <summary>
    /// Planet configuration data.
    /// </summary>
    public class PlanetConfigDto
    {
        /// <summary>
        /// Unique identifier of the planet.
        /// </summary>
        public Guid Id { get; set; }

        /// <summary>
        /// Name of the planet.
        /// </summary>
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// Type of the planet (e.g., "Terrestrial", "Gas Giant").
        /// </summary>
        public string Type { get; set; } = string.Empty;

        /// <summary>
        /// Distance from the star (orbit distance).
        /// </summary>
        public float OrbitDistance { get; set; }

        /// <summary>
        /// Radius of the planet in kilometers.
        /// </summary>
        public float Radius { get; set; }

        /// <summary>
        /// X coordinate of the planet position in the solar system.
        /// </summary>
        public long PositionX { get; set; }

        /// <summary>
        /// Y coordinate of the planet position in the solar system.
        /// </summary>
        public long PositionY { get; set; }

        /// <summary>
        /// Z coordinate of the planet position in the solar system.
        /// </summary>
        public long PositionZ { get; set; }

        /// <summary>
        /// List of moons orbiting this planet.
        /// </summary>
        public List<MoonConfigDto> Moons { get; set; } = new List<MoonConfigDto>();

        /// <summary>
        /// List of resources available on this planet.
        /// </summary>
        public List<ResourceConfigDto> Resources { get; set; } = new List<ResourceConfigDto>();
    }

    /// <summary>
    /// Stargate configuration data.
    /// </summary>
    public class StargateConfigDto
    {
        /// <summary>
        /// Unique identifier of the stargate.
        /// </summary>
        public Guid Id { get; set; }

        /// <summary>
        /// Name of the stargate.
        /// </summary>
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// Target solar system ID (destination).
        /// </summary>
        public Guid? TargetSystemId { get; set; }

        /// <summary>
        /// Name of the target solar system.
        /// </summary>
        public string TargetSystemName { get; set; } = string.Empty;

        /// <summary>
        /// X coordinate of the stargate position in the solar system.
        /// </summary>
        public float PositionX { get; set; }

        /// <summary>
        /// Y coordinate of the stargate position in the solar system.
        /// </summary>
        public float PositionY { get; set; }

        /// <summary>
        /// Z coordinate of the stargate position in the solar system.
        /// </summary>
        public float PositionZ { get; set; }

        /// <summary>
        /// Indicates whether the stargate is operational.
        /// </summary>
        public bool IsOperational { get; set; }
    }

    /// <summary>
    /// Moon configuration data.
    /// </summary>
    public class MoonConfigDto
    {
        /// <summary>
        /// Unique identifier of the moon.
        /// </summary>
        public Guid Id { get; set; }

        /// <summary>
        /// Name of the moon.
        /// </summary>
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// Radius of the moon in kilometers.
        /// </summary>
        public long Radius { get; set; }

        /// <summary>
        /// X coordinate of the moon position.
        /// </summary>
        public long PositionX { get; set; }

        /// <summary>
        /// Y coordinate of the moon position.
        /// </summary>
        public long PositionY { get; set; }

        /// <summary>
        /// Z coordinate of the moon position.
        /// </summary>
        public long PositionZ { get; set; }
    }

    /// <summary>
    /// Resource configuration data.
    /// </summary>
    public class ResourceConfigDto
    {
        /// <summary>
        /// Unique identifier of the resource.
        /// </summary>
        public Guid Id { get; set; }

        /// <summary>
        /// Type of the resource (e.g., "Iron", "Gold", "Uranium").
        /// </summary>
        public string ResourceType { get; set; } = string.Empty;

        /// <summary>
        /// Quantity of the resource available.
        /// </summary>
        public int Quantity { get; set; }

        /// <summary>
        /// Richness/quality of the resource (0.0 to 1.0).
        /// </summary>
        public float Richness { get; set; }
    }

    /// <summary>
    /// Station configuration data.
    /// </summary>
    public class StationConfigDto
    {
        /// <summary>
        /// Unique identifier of the station.
        /// </summary>
        public Guid Id { get; set; }

        /// <summary>
        /// Name of the station.
        /// </summary>
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// X coordinate of the station position in the solar system.
        /// </summary>
        public long PositionX { get; set; }

        /// <summary>
        /// Y coordinate of the station position in the solar system.
        /// </summary>
        public long PositionY { get; set; }

        /// <summary>
        /// Z coordinate of the station position in the solar system.
        /// </summary>
        public long PositionZ { get; set; }

        /// <summary>
        /// Type of the station (e.g., TradingHub, MilitaryBase).
        /// </summary>
        public string StationType { get; set; } = string.Empty;
    }

    /// <summary>
    /// Asteroid belt configuration data.
    /// </summary>
    public class AsteroidBeltConfigDto
    {
        /// <summary>
        /// Unique identifier of the asteroid belt.
        /// </summary>
        public Guid Id { get; set; }

        /// <summary>
        /// Name of the asteroid belt.
        /// </summary>
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// X coordinate of the asteroid belt position in the solar system.
        /// </summary>
        public long PositionX { get; set; }

        /// <summary>
        /// Y coordinate of the asteroid belt position in the solar system.
        /// </summary>
        public long PositionY { get; set; }

        /// <summary>
        /// Z coordinate of the asteroid belt position in the solar system.
        /// </summary>
        public long PositionZ { get; set; }

        /// <summary>
        /// List of resources available in this asteroid belt.
        /// </summary>
        public List<ResourceConfigDto> Resources { get; set; } = new List<ResourceConfigDto>();
    }

    /// <summary>
    /// Regional cluster configuration data.
    /// Contains all systems within a region for multi-system servers.
    /// </summary>
    public class ServerRegionalClusterConfigDto
    {
        /// <summary>
        /// Unique identifier of the region.
        /// </summary>
        public Guid RegionId { get; set; }

        /// <summary>
        /// Name of the region.
        /// </summary>
        public string RegionName { get; set; } = string.Empty;

        /// <summary>
        /// Region code identifier.
        /// </summary>
        public string RegionCode { get; set; } = string.Empty;

        /// <summary>
        /// Average security status across the region.
        /// </summary>
        public float AverageSecurity { get; set; }

        /// <summary>
        /// Number of constellations in this region.
        /// </summary>
        public int ConstellationCount { get; set; }

        /// <summary>
        /// Number of solar systems in this region.
        /// </summary>
        public int SystemCount { get; set; }

        /// <summary>
        /// Total number of planets across all systems in the region.
        /// </summary>
        public int TotalPlanets { get; set; }

        /// <summary>
        /// Total number of stargates across all systems in the region.
        /// </summary>
        public int TotalStargates { get; set; }

        /// <summary>
        /// Total number of stations across all systems in the region.
        /// </summary>
        public int TotalStations { get; set; }

        /// <summary>
        /// List of all solar systems in this region.
        /// </summary>
        public List<ServerSystemConfigDto> Systems { get; set; } = new List<ServerSystemConfigDto>();

        /// <summary>
        /// Configuration wrapper for serialization.
        /// </summary>
        public ServerRegionalClusterConfigDto? Config { get; set; }
    }
}
