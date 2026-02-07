using Echoes.API.Data;
using Echoes.API.Models.DTOs.Market;
using Echoes.API.Services.Market;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Security.Claims;

namespace Echoes.API.Controllers
{
    /// <summary>
    /// Контроллер рыночной системы (EVE-style Market)
    /// Все операции требуют X-Server-Secret для серверной аутентификации
    /// </summary>
    [Authorize]
    [ApiController]
    [Route("api/[controller]")]
    public class MarketController : ControllerBase
    {
        private readonly IMarketService _marketService;
        private readonly ILogger<MarketController> _logger;
        private readonly IConfiguration _configuration;
        private readonly DatabaseContext _context;

        public MarketController(
            IMarketService marketService,
            ILogger<MarketController> logger,
            IConfiguration configuration,
            DatabaseContext context)
        {
            _marketService = marketService;
            _logger = logger;
            _configuration = configuration;
            _context = context;
        }

        /// <summary>
        /// Validates the X-Server-Secret header for server-to-server authentication
        /// </summary>
        private bool ValidateServerSecret()
        {
            if (!Request.Headers.TryGetValue("X-Server-Secret", out var headerSecret))
                return false;

            var configuredSecret = _configuration["ServerSecret"] ?? "default-server-secret-change-me";
            return string.Equals(headerSecret, configuredSecret, StringComparison.Ordinal);
        }

        /// <summary>
        /// Validates that the given characterId belongs to the authenticated user's account
        /// </summary>
        private async Task<bool> ValidateCharacterOwnershipAsync(Guid characterId)
        {
            var accountIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value;
            if (string.IsNullOrEmpty(accountIdClaim) || !Guid.TryParse(accountIdClaim, out var accountId))
                return false;

            return await _context.Characters
                .AnyAsync(c => c.Id == characterId && c.AccountId == accountId);
        }

        /// <summary>
        /// Получить стакан ордеров на товар в регионе (order book)
        /// </summary>
        /// <param name="regionId">ID региона</param>
        /// <param name="itemId">ID шаблона предмета</param>
        [HttpGet("region/{regionId}/{itemId:int}")]
        [ProducesResponseType(typeof(MarketOrderBookDto), StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        public async Task<ActionResult<MarketOrderBookDto>> GetRegionOrders(Guid regionId, int itemId)
        {
            if (!ValidateServerSecret())
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });

            try
            {
                var orderBook = await _marketService.GetRegionOrdersAsync(regionId, itemId);
                return Ok(orderBook);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting region orders for region {RegionId}, item {ItemId}",
                    regionId, itemId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Создать новый рыночный ордер (Buy или Sell)
        /// Списывает broker fee и залог (escrow для Buy) у игрока
        /// </summary>
        [HttpPost("orders")]
        [ProducesResponseType(typeof(CreateOrderResultDto), StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        public async Task<ActionResult<CreateOrderResultDto>> CreateOrder([FromBody] CreateOrderRequest request)
        {
            if (!ValidateServerSecret())
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });

            if (!await ValidateCharacterOwnershipAsync(request.CharacterId))
                return Unauthorized(new { error = "Character does not belong to the authenticated user" });

            try
            {
                var result = await _marketService.CreateOrderAsync(request);
                return Ok(result);
            }
            catch (ArgumentException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error creating market order for character {CharacterId}", request.CharacterId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Исполнить сделку по существующему ордеру (покупка/продажа)
        /// Использует Database Transaction (Serializable) для предотвращения double-spend
        /// </summary>
        [HttpPost("execute")]
        [ProducesResponseType(typeof(ExecuteTradeResultDto), StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        public async Task<ActionResult<ExecuteTradeResultDto>> ExecuteTrade([FromBody] ExecuteTradeRequest request)
        {
            if (!ValidateServerSecret())
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });

            if (!await ValidateCharacterOwnershipAsync(request.CharacterId))
                return Unauthorized(new { error = "Character does not belong to the authenticated user" });

            try
            {
                var result = await _marketService.ExecuteTradeAsync(request);
                return Ok(result);
            }
            catch (ArgumentException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error executing trade for order {OrderId}", request.OrderId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Получить все ордера персонажа
        /// </summary>
        [HttpGet("orders/{characterId}")]
        [ProducesResponseType(typeof(List<MarketOrderDto>), StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        public async Task<ActionResult<List<MarketOrderDto>>> GetCharacterOrders(Guid characterId)
        {
            if (!ValidateServerSecret())
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });

            if (!await ValidateCharacterOwnershipAsync(characterId))
                return Unauthorized(new { error = "Character does not belong to the authenticated user" });

            try
            {
                var orders = await _marketService.GetCharacterOrdersAsync(characterId);
                return Ok(orders);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting orders for character {CharacterId}", characterId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Рассчитать налоги для предполагаемой сделки
        /// </summary>
        [HttpGet("taxes")]
        [ProducesResponseType(typeof(TaxInfoDto), StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        public ActionResult<TaxInfoDto> GetTaxInfo([FromQuery] decimal price, [FromQuery] int quantity)
        {
            if (!ValidateServerSecret())
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });

            if (price <= 0 || quantity <= 0)
                return BadRequest(new { error = "Price and quantity must be greater than zero" });

            var taxInfo = _marketService.CalculateTaxes(price, quantity);
            return Ok(taxInfo);
        }
    }
}
