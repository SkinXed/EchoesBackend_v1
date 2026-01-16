using Echoes.API.Data;
using Echoes.API.Models.DTOs.Game;
using Echoes.API.Services.UniverseGeneration;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class UniverseController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<UniverseController> _logger;
        private readonly IUniverseGenerationService _universeService;
        private readonly IBackgroundGenerationService _backgroundGenerationService;

        public UniverseController(
            DatabaseContext context,
            ILogger<UniverseController> logger,
            IUniverseGenerationService universeService,
            IBackgroundGenerationService backgroundGenerationService)
        {
            _context = context;
            _logger = logger;
            _universeService = universeService;
            _backgroundGenerationService = backgroundGenerationService;
        }

        /// <summary>
        /// Получить данные карты вселенной (системы и звездные врата)
        /// </summary>
        [HttpGet("map-data")]
        [ProducesResponseType(typeof(MapDataResponse), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetMapData()
        {
            try
            {
                var mapData = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .Select(s => new MapDataDto
                    {
                        Id = s.Id,
                        Name = s.Name,
                        X = s.PositionX,
                        Y = s.PositionY,
                        Z = s.PositionZ,
                        Security = s.SecurityStatus,
                        RegionId = s.Constellation.Region.Id,
                        RegionName = s.Constellation.Region.Name,
                        ConstellationId = s.Constellation.Id,
                        ConstellationName = s.Constellation.Name,
                        StarClass = s.StarClass.ToString(),
                        HasStations = s.HasStations,
                        HasAsteroidBelts = s.HasAsteroidBelts
                    })
                    .ToListAsync();

                var stargates = await _context.Stargates
                    .Where(sg => sg.IsOperational)
                    .Select(sg => new StargateConnectionDto
                    {
                        SourceSystemId = sg.SourceSolarSystemId,
                        DestinationSystemId = sg.DestinationSolarSystemId,
                        JumpCost = sg.JumpCost
                    })
                    .ToListAsync();

                var response = new MapDataResponse
                {
                    Systems = mapData,
                    Stargates = stargates,
                    GeneratedAt = DateTime.UtcNow,
                    TotalSystems = mapData.Count
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting map data");
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Получить список всех солнечных систем с пагинацией
        /// </summary>
        [HttpGet("systems")]
        [ProducesResponseType(typeof(PaginatedResponse<SystemOverviewDto>), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetAllSystems([FromQuery] int page = 1, [FromQuery] int pageSize = 50)
        {
            try
            {
                // Валидация параметров
                if (page < 1) page = 1;
                if (pageSize < 1 || pageSize > 100) pageSize = 50;

                var totalCount = await _context.SolarSystems.CountAsync();
                
                var systems = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .OrderBy(s => s.Name)
                    .Skip((page - 1) * pageSize)
                    .Take(pageSize)
                    .Select(s => new SystemOverviewDto
                    {
                        Id = s.Id,
                        Name = s.Name,
                        Security = s.SecurityStatus,
                        Constellation = s.Constellation.Name,
                        Region = s.Constellation.Region.Name,
                        PositionX = s.PositionX,
                        PositionY = s.PositionY,
                        PositionZ = s.PositionZ,
                        PlanetCount = s.Planets.Count,
                        HasStations = s.HasStations,
                        HasAsteroidBelts = s.HasAsteroidBelts
                    })
                    .ToListAsync();

                var response = new PaginatedResponse<SystemOverviewDto>
                {
                    Items = systems,
                    Page = page,
                    PageSize = pageSize,
                    TotalCount = totalCount,
                    TotalPages = (int)Math.Ceiling(totalCount / (double)pageSize),
                    Timestamp = DateTime.UtcNow
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting all systems");
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Получить детальную информацию о солнечной системе
        /// </summary>
        [HttpGet("systems/{id:guid}")]
        [ProducesResponseType(typeof(SystemDetailResponse), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status404NotFound)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetSystem(Guid id)
        {
            try
            {
                var system = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .Include(s => s.Planets)
                    .Include(s => s.Stations)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem)
                    .FirstOrDefaultAsync(s => s.Id == id);

                if (system == null)
                {
                    return NotFound(ErrorResponse.NotFound("Solar system not found"));
                }

                var systemDetail = new SystemDetailDto
                {
                    Id = system.Id,
                    Name = system.Name,
                    SecurityStatus = system.SecurityStatus,
                    Description = system.Description,
                    Constellation = new ConstellationDto
                    {
                        Id = system.Constellation.Id,
                        Name = system.Constellation.Name
                    },
                    Region = new RegionDto
                    {
                        Id = system.Constellation.Region.Id,
                        Name = system.Constellation.Region.Name,
                        Type = system.Constellation.Region.Type.ToString()
                    },
                    StarInfo = new StarInfoDto
                    {
                        StarClass = system.StarClass.ToString(),
                        LuminosityClass = system.LuminosityClass.ToString(),
                        Temperature = system.Temperature,
                        SolarRadius = system.SolarRadius,
                        SolarMass = system.SolarMass,
                        Luminosity = system.Luminosity
                    },
                    Position = new PositionDto
                    {
                        X = system.PositionX,
                        Y = system.PositionY,
                        Z = system.PositionZ
                    },
                    Planets = system.Planets.Select(p => new PlanetOverviewDto
                    {
                        Id = p.Id,
                        Name = p.Name,
                        Type = p.Type.ToString(),
                        Radius = p.Radius,
                        OrbitDistance = p.OrbitDistance,
                        Position = new PositionDto
                        {
                            X = p.PositionX,
                            Y = p.PositionY,
                            Z = p.PositionZ
                        }
                    }).ToList(),
                    Stations = system.Stations.Select(st => new StationOverviewDto
                    {
                        Id = st.Id,
                        Name = st.Name,
                        Type = st.Type.ToString(),
                        DockingCapacity = st.DockingCapacity,
                        Services = st.Services.Split(',', StringSplitOptions.RemoveEmptyEntries).Select(s => s.Trim()).ToList()
                    }).ToList(),
                    Stargates = system.Stargates.Select(sg => new StargateDto
                    {
                        Id = sg.Id,
                        Name = sg.Name,
                        Position = new PositionDto
                        {
                            X = sg.PositionX,
                            Y = sg.PositionY,
                            Z = sg.PositionZ
                        },
                        DestinationSystem = sg.DestinationSolarSystem != null 
                            ? new StargateDestinationDto
                            {
                                Id = sg.DestinationSolarSystem.Id,
                                Name = sg.DestinationSolarSystem.Name
                            }
                            : null,
                        IsOperational = sg.IsOperational,
                        JumpCost = sg.JumpCost
                    }).ToList()
                };

                var response = new SystemDetailResponse
                {
                    Success = true,
                    System = systemDetail,
                    ObjectCounts = new SystemObjectCountsDto
                    {
                        Planets = systemDetail.Planets.Count,
                        Stations = systemDetail.Stations.Count,
                        Stargates = systemDetail.Stargates.Count
                    },
                    Timestamp = DateTime.UtcNow
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting system with id {SystemId}", id);
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Получить объекты системы для клиента UE5 (оптимизированный формат)
        /// </summary>
        [HttpGet("system/{systemId:guid}/objects")]
        [ProducesResponseType(typeof(ClientSystemObjectsResponse), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status404NotFound)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetSystemObjects(Guid systemId)
        {
            try
            {
                _logger.LogDebug("Requesting UE5 system objects for system {SystemId}", systemId);

                var system = await _context.SolarSystems
                    .Include(s => s.Planets)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem)
                    .FirstOrDefaultAsync(s => s.Id == systemId);

                if (system == null)
                    return NotFound(ErrorResponse.NotFound($"System {systemId} not found"));

                var response = new ClientSystemObjectsResponse
                {
                    Success = true,
                    System = new ClientSystemDto
                    {
                        SystemId = system.Id,
                        SystemName = system.Name,
                        SolarRadius = system.SolarRadius,
                        SolarMass = system.SolarMass,
                        Temperature = system.Temperature,
                        SecurityStatus = system.SecurityStatus,
                        Planets = system.Planets.Select(p => new ClientPlanetDto
                        {
                            Id = p.Id,
                            Name = p.Name,
                            Type = p.Type.ToString(),
                            OrbitDistance = p.OrbitDistance,
                            Radius = p.Radius,
                            PositionX = p.PositionX,
                            PositionY = p.PositionY,
                            PositionZ = p.PositionZ
                        }).ToList(),
                        Stargates = system.Stargates.Select(sg => new ClientStargateDto
                        {
                            Id = sg.Id,
                            Name = sg.Name,
                            TargetSystemId = sg.DestinationSolarSystemId,
                            TargetSystemName = sg.DestinationSolarSystem?.Name ?? "Unknown",
                            PositionX = sg.PositionX,
                            PositionY = sg.PositionY,
                            PositionZ = sg.PositionZ
                        }).ToList()
                    },
                    Timestamp = DateTime.UtcNow
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting UE5 system objects for {SystemId}", systemId);
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Получить все системы региона
        /// </summary>
        [HttpGet("region/{regionId:guid}/systems")]
        [ProducesResponseType(typeof(RegionSystemsResponse), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status404NotFound)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetSystemsByRegion(Guid regionId)
        {
            try
            {
                _logger.LogDebug("Getting systems for region {RegionId}", regionId);

                // Проверяем существует ли регион
                var regionExists = await _context.Regions.AnyAsync(r => r.Id == regionId);
                if (!regionExists)
                    return NotFound(ErrorResponse.NotFound($"Region {regionId} not found"));

                // Получаем все системы региона
                var systems = await _context.SolarSystems
                    .Where(s => s.Constellation.RegionId == regionId)
                    .Include(s => s.Planets)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem)
                    .Select(s => new RegionSystemDto
                    {
                        Id = s.Id,
                        Name = s.Name,
                        SecurityStatus = s.SecurityStatus,
                        PositionX = s.PositionX,
                        PositionY = s.PositionY,
                        PositionZ = s.PositionZ,
                        Planets = s.Planets.Select(p => new PlanetOverviewDto
                        {
                            Id = p.Id,
                            Name = p.Name,
                            Type = p.Type.ToString(),
                            Radius = p.Radius,
                            OrbitDistance = p.OrbitDistance,
                            Position = new PositionDto
                            {
                                X = p.PositionX,
                                Y = p.PositionY,
                                Z = p.PositionZ
                            }
                        }).ToList(),
                        Stargates = s.Stargates.Select(sg => new StargateOverviewDto
                        {
                            Id = sg.Id,
                            Name = sg.Name,
                            DestinationSystemId = sg.DestinationSolarSystemId,
                            Position = new PositionDto
                            {
                                X = sg.PositionX,
                                Y = sg.PositionY,
                                Z = sg.PositionZ
                            },
                            TargetSystemName = sg.DestinationSolarSystem != null
                                ? sg.DestinationSolarSystem.Name
                                : "Unknown"
                        }).ToList()
                    })
                    .ToListAsync();

                if (!systems.Any())
                    return NotFound(ErrorResponse.NotFound($"No systems found for region {regionId}"));

                var response = new RegionSystemsResponse
                {
                    Success = true,
                    RegionId = regionId,
                    Systems = systems,
                    TotalSystems = systems.Count,
                    Timestamp = DateTime.UtcNow
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting region systems for region {RegionId}", regionId);
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Поиск по вселенной (системы, планеты)
        /// </summary>
        [HttpGet("search")]
        [ProducesResponseType(typeof(SearchResponse), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status400BadRequest)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> Search([FromQuery] string query, [FromQuery] int limit = 20)
        {
            try
            {
                if (string.IsNullOrWhiteSpace(query) || query.Length < 2)
                {
                    return BadRequest(ErrorResponse.BadRequest("Search query must be at least 2 characters"));
                }

                if (limit < 1 || limit > 100)
                {
                    limit = 20;
                }

                var searchTerm = query.ToLower();

                var systems = await _context.SolarSystems
                    .Where(s => s.Name.ToLower().Contains(searchTerm))
                    .Take(limit)
                    .Select(s => new SearchResultDto
                    {
                        Id = s.Id,
                        Name = s.Name,
                        Type = "System",
                        SecurityStatus = s.SecurityStatus,
                        Region = s.Constellation.Region.Name,
                        Constellation = s.Constellation.Name
                    })
                    .ToListAsync();

                var planets = await _context.Planets
                    .Where(p => p.Name.ToLower().Contains(searchTerm))
                    .Include(p => p.SolarSystem)
                    .ThenInclude(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .Take(limit)
                    .Select(p => new SearchResultDto
                    {
                        Id = p.Id,
                        Name = p.Name,
                        Type = "Planet",
                        ParentSystem = p.SolarSystem.Name,
                        SecurityStatus = p.SolarSystem.SecurityStatus,
                        Region = p.SolarSystem.Constellation.Region.Name,
                        Constellation = p.SolarSystem.Constellation.Name
                    })
                    .ToListAsync();

                var results = systems.Concat(planets)
                    .OrderBy(r => r.Name)
                    .Take(limit)
                    .ToList();

                var response = new SearchResponse
                {
                    Success = true,
                    Query = query,
                    Results = results,
                    TotalResults = results.Count,
                    Timestamp = DateTime.UtcNow
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error searching universe for query: {Query}", query);
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Получить соседние системы (до N прыжков)
        /// </summary>
        [HttpGet("nearby/{systemId:guid}")]
        [ProducesResponseType(typeof(NearbySystemsResponse), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status404NotFound)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetNearbySystems(Guid systemId, [FromQuery] int maxJumps = 3)
        {
            try
            {
                if (maxJumps < 1 || maxJumps > 10)
                {
                    maxJumps = 3;
                }

                var centralSystem = await _context.SolarSystems
                    .Include(s => s.Stargates)
                    .FirstOrDefaultAsync(s => s.Id == systemId);

                if (centralSystem == null)
                    return NotFound(ErrorResponse.NotFound("System not found"));

                var visited = new HashSet<Guid> { systemId };
                var currentLevel = new List<Echoes.API.Models.Entities.Universe.SolarSystem> { centralSystem };
                var allNearby = new List<NearbySystemDto>();

                for (int jump = 1; jump <= maxJumps; jump++)
                {
                    var nextLevel = new List<Echoes.API.Models.Entities.Universe.SolarSystem>();

                    foreach (var system in currentLevel)
                    {
                        var connectedSystems = await _context.Stargates
                            .Where(sg => sg.SourceSolarSystemId == system.Id && sg.IsOperational)
                            .Select(sg => sg.DestinationSolarSystem)
                            .Where(s => s != null)
                            .ToListAsync();

                        foreach (var connectedSystem in connectedSystems)
                        {
                            if (connectedSystem != null && !visited.Contains(connectedSystem.Id))
                            {
                                visited.Add(connectedSystem.Id);
                                nextLevel.Add(connectedSystem);

                                allNearby.Add(new NearbySystemDto
                                {
                                    Id = connectedSystem.Id,
                                    Name = connectedSystem.Name,
                                    DistanceInJumps = jump,
                                    SecurityStatus = connectedSystem.SecurityStatus,
                                    HasStations = connectedSystem.HasStations,
                                    HasAsteroidBelts = connectedSystem.HasAsteroidBelts
                                });
                            }
                        }
                    }

                    currentLevel = nextLevel;
                }

                var response = new NearbySystemsResponse
                {
                    Success = true,
                    CentralSystem = new CentralSystemDto
                    {
                        Id = centralSystem.Id,
                        Name = centralSystem.Name,
                        SecurityStatus = centralSystem.SecurityStatus
                    },
                    NearbySystems = allNearby.OrderBy(s => s.DistanceInJumps).ThenBy(s => s.Name),
                    MaxJumps = maxJumps,
                    TotalNearby = allNearby.Count,
                    Timestamp = DateTime.UtcNow
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting nearby systems for {SystemId}", systemId);
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Запустить генерацию вселенной в фоновом режиме
        /// </summary>
        [HttpPost("generate")]
        [ProducesResponseType(typeof(GenerationResponse), StatusCodes.Status202Accepted)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status409Conflict)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GenerateUniverse(
            [FromQuery] bool force = false,
            [FromQuery] bool clearFirst = true)
        {
            try
            {
                // Проверяем, существует ли уже вселенная
                var hasExistingUniverse = await _context.SolarSystems.AnyAsync();

                if (hasExistingUniverse && !force)
                {
                    var stats = await _universeService.GetUniverseStatsAsync();
                    return Conflict(new GenerationResponse
                    {
                        Success = false,
                        Message = "Universe already exists. Use ?force=true to force regeneration.",
                        Stats = stats,
                        Timestamp = DateTime.UtcNow
                    });
                }

                // Запускаем генерацию в фоне
                var generationId = await _backgroundGenerationService.StartUniverseGenerationAsync(
                    clearFirst, 
                    force);

                var response = new GenerationResponse
                {
                    Success = true,
                    Message = "Universe generation started in background",
                    GenerationId = generationId,
                    ForceRegeneration = force,
                    ClearExisting = clearFirst,
                    Timestamp = DateTime.UtcNow
                };

                return Accepted(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error starting universe generation");
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Получить статистику вселенной
        /// </summary>
        [HttpGet("stats")]
        [ProducesResponseType(typeof(UniverseStatsResponse), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetUniverseStats()
        {
            try
            {
                var stats = await _universeService.GetUniverseStatsAsync();
                var response = new UniverseStatsResponse
                {
                    Success = true,
                    Stats = stats,
                    Timestamp = DateTime.UtcNow
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting universe stats");
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }

        /// <summary>
        /// Проверить статус генерации вселенной
        /// </summary>
        [HttpGet("generation-status/{generationId:guid}")]
        [ProducesResponseType(typeof(GenerationStatusResponse), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status404NotFound)]
        [ProducesResponseType(typeof(ErrorResponse), StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetGenerationStatus(Guid generationId)
        {
            try
            {
                var status = await _backgroundGenerationService.GetGenerationStatusAsync(generationId);
                
                if (status == null)
                    return NotFound(ErrorResponse.NotFound($"Generation with id {generationId} not found"));

                return Ok(new GenerationStatusResponse
                {
                    Success = true,
                    Status = status,
                    Timestamp = DateTime.UtcNow
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting generation status for {GenerationId}", generationId);
                return StatusCode(500, ErrorResponse.InternalServerError());
            }
        }
    }
}
