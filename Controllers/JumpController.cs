using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Caching.Memory;
using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Universe;

namespace Echoes.API.Controllers
{
    /// <summary>
    /// Jump Controller - Handles interstellar jump system
    /// Manages jump tickets for secure server-to-server transitions
    /// </summary>
    [ApiController]
    [Route("api/jump")]
    public class JumpController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<JumpController> _logger;
        private readonly IConfiguration _configuration;
        private readonly IMemoryCache _cache;

        // Default ticket expiration time (5 minutes)
        private static readonly TimeSpan TicketExpiration = TimeSpan.FromMinutes(5);

        public JumpController(
            DatabaseContext context,
            ILogger<JumpController> logger,
            IConfiguration configuration,
            IMemoryCache cache)
        {
            _context = context;
            _logger = logger;
            _configuration = configuration;
            _cache = cache;
        }

        /// <summary>
        /// Request a jump ticket for transitioning between systems
        /// POST /api/jump/request
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpPost("request")]
        public async Task<ActionResult<JumpResponseDto>> RequestJump([FromBody] JumpRequestDto request)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("Jump request received without X-Server-Secret header for character {CharacterId}", request.CharacterId);
                    return Unauthorized(new JumpResponseDto
                    {
                        Success = false,
                        Message = "Missing X-Server-Secret header",
                        DenialReason = "Authentication required"
                    });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["Server:Secret"] ?? "UE5-Server-Secret-Change-Me-In-Production";
                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("Invalid X-Server-Secret for jump request - character {CharacterId}", request.CharacterId);
                    return Unauthorized(new JumpResponseDto
                    {
                        Success = false,
                        Message = "Invalid server secret",
                        DenialReason = "Authentication failed"
                    });
                }

                // Validate character exists
                var character = await _context.Characters
                    .Include(c => c.Pilot)
                    .FirstOrDefaultAsync(c => c.Id == request.CharacterId);

                if (character == null)
                {
                    _logger.LogWarning("Jump request for non-existent character {CharacterId}", request.CharacterId);
                    return NotFound(new JumpResponseDto
                    {
                        Success = false,
                        Message = "Character not found",
                        DenialReason = "Invalid character"
                    });
                }

                // Check if character already has a pending jump ticket
                var existingTicketKey = $"jump_ticket_char_{request.CharacterId}";
                if (_cache.TryGetValue(existingTicketKey, out JumpTicket? existingTicket) && existingTicket != null)
                {
                    if (existingTicket.Status == JumpTicketStatus.Pending && existingTicket.ExpiresAt > DateTime.UtcNow)
                    {
                        _logger.LogWarning("Character {CharacterId} already has a pending jump ticket", request.CharacterId);
                        return BadRequest(new JumpResponseDto
                        {
                            Success = false,
                            Message = "Jump already in progress",
                            DenialReason = "Character has pending jump ticket"
                        });
                    }
                }

                // Validate stargate exists and is operational
                var stargate = await _context.Stargates
                    .Include(sg => sg.DestinationSolarSystem)
                    .FirstOrDefaultAsync(sg => sg.Id == request.StargateId);

                if (stargate == null)
                {
                    _logger.LogWarning("Jump request for non-existent stargate {StargateId}", request.StargateId);
                    return NotFound(new JumpResponseDto
                    {
                        Success = false,
                        Message = "Stargate not found",
                        DenialReason = "Invalid stargate"
                    });
                }

                if (!stargate.IsOperational)
                {
                    _logger.LogWarning("Jump request for non-operational stargate {StargateId}", request.StargateId);
                    return BadRequest(new JumpResponseDto
                    {
                        Success = false,
                        Message = "Stargate is not operational",
                        DenialReason = "Stargate offline"
                    });
                }

                // Validate destination system matches stargate configuration
                if (stargate.DestinationSolarSystemId != request.DestinationSystemId)
                {
                    _logger.LogWarning("Jump request destination mismatch - stargate: {StargateDestination}, request: {RequestDestination}",
                        stargate.DestinationSolarSystemId, request.DestinationSystemId);
                    return BadRequest(new JumpResponseDto
                    {
                        Success = false,
                        Message = "Destination system mismatch",
                        DenialReason = "Invalid destination"
                    });
                }

                // Validate destination system exists
                var destinationSystem = await _context.SolarSystems
                    .FirstOrDefaultAsync(s => s.Id == request.DestinationSystemId);

                if (destinationSystem == null)
                {
                    _logger.LogWarning("Jump request for non-existent destination system {SystemId}", request.DestinationSystemId);
                    return NotFound(new JumpResponseDto
                    {
                        Success = false,
                        Message = "Destination system not found",
                        DenialReason = "Invalid destination system"
                    });
                }

                // TODO: Add checks for combat/aggression status
                // This would require combat system integration
                // For now, we assume the UE server handles this before making the request

                // Generate jump ticket
                var ticketId = Guid.NewGuid().ToString();
                var now = DateTime.UtcNow;
                var expiresAt = now.Add(TicketExpiration);

                var ticket = new JumpTicket
                {
                    TicketId = ticketId,
                    CharacterId = request.CharacterId,
                    SourceSystemId = request.SourceSystemId,
                    DestinationSystemId = request.DestinationSystemId,
                    StargateId = request.StargateId,
                    IssuedAt = now,
                    ExpiresAt = expiresAt,
                    Status = JumpTicketStatus.Pending
                };

                // Store ticket in cache with expiration
                var cacheKey = $"jump_ticket_{ticketId}";
                var cacheOptions = new MemoryCacheEntryOptions()
                    .SetAbsoluteExpiration(TicketExpiration)
                    .SetPriority(CacheItemPriority.High);

                _cache.Set(cacheKey, ticket, cacheOptions);

                // Also store by character ID for duplicate detection
                _cache.Set(existingTicketKey, ticket, cacheOptions);

                _logger.LogInformation("Jump ticket {TicketId} issued for character {CharacterId} from {SourceSystem} to {DestSystem}",
                    ticketId, request.CharacterId, request.SourceSystemId, request.DestinationSystemId);

                // Get destination server address (in production, this would be from a server registry)
                // For now, we'll use a placeholder or configuration value
                var destinationServerAddress = _configuration[$"ServerAddresses:{request.DestinationSystemId}"]
                    ?? "127.0.0.1:7777"; // Default fallback

                return Ok(new JumpResponseDto
                {
                    Success = true,
                    TicketId = ticketId,
                    DestinationServerAddress = destinationServerAddress,
                    DestinationSystem = new DestinationSystemInfo
                    {
                        SystemId = destinationSystem.Id,
                        SystemName = destinationSystem.Name,
                        SecurityStatus = destinationSystem.SecurityStatus
                    },
                    ExpiresAt = expiresAt,
                    Message = "Jump ticket issued successfully"
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error processing jump request for character {CharacterId}", request.CharacterId);
                return StatusCode(500, new JumpResponseDto
                {
                    Success = false,
                    Message = "Internal server error",
                    DenialReason = "Server error"
                });
            }
        }

        /// <summary>
        /// Redeem/validate a jump ticket on destination server
        /// POST /api/jump/redeem
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpPost("redeem")]
        public async Task<ActionResult<RedeemTicketResponseDto>> RedeemTicket([FromBody] RedeemTicketRequestDto request)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("Ticket redemption received without X-Server-Secret header");
                    return Unauthorized(new RedeemTicketResponseDto
                    {
                        Valid = false,
                        Message = "Missing X-Server-Secret header",
                        InvalidReason = "Authentication required"
                    });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["Server:Secret"] ?? "UE5-Server-Secret-Change-Me-In-Production";
                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("Invalid X-Server-Secret for ticket redemption");
                    return Unauthorized(new RedeemTicketResponseDto
                    {
                        Valid = false,
                        Message = "Invalid server secret",
                        InvalidReason = "Authentication failed"
                    });
                }

                // Retrieve ticket from cache
                var cacheKey = $"jump_ticket_{request.TicketId}";
                if (!_cache.TryGetValue(cacheKey, out JumpTicket? ticket) || ticket == null)
                {
                    _logger.LogWarning("Attempted to redeem non-existent or expired ticket {TicketId}", request.TicketId);
                    return BadRequest(new RedeemTicketResponseDto
                    {
                        Valid = false,
                        Message = "Ticket not found or expired",
                        InvalidReason = "Invalid or expired ticket"
                    });
                }

                // Validate ticket hasn't been redeemed
                if (ticket.Status == JumpTicketStatus.Redeemed)
                {
                    _logger.LogWarning("Attempted to reuse already redeemed ticket {TicketId}", request.TicketId);
                    return BadRequest(new RedeemTicketResponseDto
                    {
                        Valid = false,
                        Message = "Ticket already redeemed",
                        InvalidReason = "Ticket was already used"
                    });
                }

                // Validate ticket hasn't expired
                if (ticket.ExpiresAt <= DateTime.UtcNow)
                {
                    _logger.LogWarning("Attempted to redeem expired ticket {TicketId}", request.TicketId);
                    return BadRequest(new RedeemTicketResponseDto
                    {
                        Valid = false,
                        Message = "Ticket expired",
                        InvalidReason = "Ticket expiration time passed"
                    });
                }

                // Validate character ID matches
                if (ticket.CharacterId != request.CharacterId)
                {
                    _logger.LogWarning("Character ID mismatch for ticket {TicketId} - ticket: {TicketCharId}, request: {RequestCharId}",
                        request.TicketId, ticket.CharacterId, request.CharacterId);
                    return BadRequest(new RedeemTicketResponseDto
                    {
                        Valid = false,
                        Message = "Character ID mismatch",
                        InvalidReason = "Ticket character doesn't match"
                    });
                }

                // Validate destination system matches
                if (ticket.DestinationSystemId != request.SystemId)
                {
                    _logger.LogWarning("System ID mismatch for ticket {TicketId} - ticket: {TicketSystemId}, request: {RequestSystemId}",
                        request.TicketId, ticket.DestinationSystemId, request.SystemId);
                    return BadRequest(new RedeemTicketResponseDto
                    {
                        Valid = false,
                        Message = "Destination system mismatch",
                        InvalidReason = "Wrong destination system"
                    });
                }

                // Validate character exists
                var character = await _context.Characters.FindAsync(request.CharacterId);
                if (character == null)
                {
                    _logger.LogWarning("Ticket redemption for non-existent character {CharacterId}", request.CharacterId);
                    return NotFound(new RedeemTicketResponseDto
                    {
                        Valid = false,
                        Message = "Character not found",
                        InvalidReason = "Invalid character"
                    });
                }

                // Mark ticket as redeemed
                ticket.Status = JumpTicketStatus.Redeemed;
                ticket.RedeemedAt = DateTime.UtcNow;

                // Update ticket in cache (keep it for audit trail)
                var cacheOptions = new MemoryCacheEntryOptions()
                    .SetAbsoluteExpiration(TimeSpan.FromMinutes(15)) // Keep redeemed tickets for 15 minutes
                    .SetPriority(CacheItemPriority.Low);
                _cache.Set(cacheKey, ticket, cacheOptions);

                // Remove from character-specific cache
                _cache.Remove($"jump_ticket_char_{request.CharacterId}");

                _logger.LogInformation("Jump ticket {TicketId} successfully redeemed for character {CharacterId} in system {SystemId}",
                    request.TicketId, request.CharacterId, request.SystemId);

                return Ok(new RedeemTicketResponseDto
                {
                    Valid = true,
                    CharacterId = ticket.CharacterId,
                    DestinationSystemId = ticket.DestinationSystemId,
                    SourceSystemId = ticket.SourceSystemId,
                    Message = "Ticket validated successfully"
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error redeeming jump ticket {TicketId}", request.TicketId);
                return StatusCode(500, new RedeemTicketResponseDto
                {
                    Valid = false,
                    Message = "Internal server error",
                    InvalidReason = "Server error"
                });
            }
        }

        /// <summary>
        /// Get jump ticket status (optional, for debugging)
        /// GET /api/jump/ticket/{ticketId}
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpGet("ticket/{ticketId}")]
        public IActionResult GetTicketStatus(string ticketId)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                var expectedSecret = _configuration["Server:Secret"] ?? "UE5-Server-Secret-Change-Me-In-Production";
                if (serverSecret != expectedSecret)
                {
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                // Retrieve ticket from cache
                var cacheKey = $"jump_ticket_{ticketId}";
                if (!_cache.TryGetValue(cacheKey, out JumpTicket? ticket) || ticket == null)
                {
                    return NotFound(new { message = "Ticket not found" });
                }

                return Ok(new
                {
                    ticketId = ticket.TicketId,
                    characterId = ticket.CharacterId,
                    sourceSystemId = ticket.SourceSystemId,
                    destinationSystemId = ticket.DestinationSystemId,
                    status = ticket.Status.ToString(),
                    issuedAt = ticket.IssuedAt,
                    expiresAt = ticket.ExpiresAt,
                    redeemedAt = ticket.RedeemedAt,
                    isExpired = ticket.ExpiresAt <= DateTime.UtcNow
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting ticket status for {TicketId}", ticketId);
                return StatusCode(500, new { message = "Internal server error" });
            }
        }
    }
}
