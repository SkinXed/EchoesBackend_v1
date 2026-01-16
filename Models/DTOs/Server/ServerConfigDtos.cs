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
        /// List of planets in this solar system.
        /// </summary>
        public List<PlanetConfigDto> Planets { get; set; } = new List<PlanetConfigDto>();

        /// <summary>
        /// List of stargates in this solar system.
        /// </summary>
        public List<StargateConfigDto> Stargates { get; set; } = new List<StargateConfigDto>();
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
    }
}
