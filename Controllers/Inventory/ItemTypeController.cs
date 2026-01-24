using Echoes.API.Data;
using Echoes.API.Models.DTOs.Inventory;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers.Inventory
{
    [ApiController]
    [Route("api/[controller]")]
    [AllowAnonymous]
    public class ItemTypeController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<ItemTypeController> _logger;

        public ItemTypeController(DatabaseContext context, ILogger<ItemTypeController> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Get all item categories
        /// </summary>
        [HttpGet("categories")]
        public async Task<ActionResult<List<object>>> GetCategories()
        {
            var categories = await _context.ItemCategories
                .Select(c => new { c.CategoryId, c.Name, c.Description, c.IconName })
                .ToListAsync();

            return Ok(categories);
        }

        /// <summary>
        /// Get item groups in a category
        /// </summary>
        [HttpGet("categories/{categoryId}/groups")]
        public async Task<ActionResult<List<object>>> GetGroupsByCategory(int categoryId)
        {
            var groups = await _context.ItemGroups
                .Where(g => g.CategoryId == categoryId)
                .Select(g => new { g.GroupId, g.Name, g.VolumeMultiplier })
                .ToListAsync();

            return Ok(groups);
        }

        /// <summary>
        /// Get item type by ID
        /// </summary>
        [HttpGet("{typeId}")]
        public async Task<ActionResult<ItemTypeDto>> GetItemType(int typeId)
        {
            var itemType = await _context.ItemTypesInventory
                .Include(it => it.Group)
                .ThenInclude(g => g!.Category)
                .FirstOrDefaultAsync(it => it.TypeId == typeId);

            if (itemType == null)
            {
                return NotFound();
            }

            var dto = new ItemTypeDto
            {
                TypeId = itemType.TypeId,
                Name = itemType.Name,
                Description = itemType.Description,
                GroupId = itemType.GroupId,
                GroupName = itemType.Group?.Name,
                BaseVolume = itemType.BaseVolume,
                PackagedVolume = itemType.PackagedVolume,
                IsStackable = itemType.IsStackable,
                MaxStackSize = itemType.MaxStackSize,
                Mass = itemType.Mass,
                Capacity = itemType.Capacity,
                MetaLevel = itemType.MetaLevel,
                TechLevel = itemType.TechLevel
            };

            return Ok(dto);
        }

        /// <summary>
        /// Search item types
        /// </summary>
        [HttpGet("search")]
        public async Task<ActionResult<List<ItemTypeDto>>> SearchItemTypes(
            [FromQuery] string? name = null,
            [FromQuery] int? groupId = null,
            [FromQuery] int? categoryId = null,
            [FromQuery] int page = 1,
            [FromQuery] int pageSize = 50)
        {
            var query = _context.ItemTypesInventory
                .Include(it => it.Group)
                .ThenInclude(g => g!.Category)
                .AsQueryable();

            if (!string.IsNullOrEmpty(name))
            {
                query = query.Where(it => it.Name.Contains(name));
            }

            if (groupId.HasValue)
            {
                query = query.Where(it => it.GroupId == groupId.Value);
            }

            if (categoryId.HasValue)
            {
                query = query.Where(it => it.Group != null && it.Group.CategoryId == categoryId.Value);
            }

            var totalCount = await query.CountAsync();
            var items = await query
                .Skip((page - 1) * pageSize)
                .Take(pageSize)
                .ToListAsync();

            var dtos = items.Select(it => new ItemTypeDto
            {
                TypeId = it.TypeId,
                Name = it.Name,
                Description = it.Description,
                GroupId = it.GroupId,
                GroupName = it.Group?.Name,
                BaseVolume = it.BaseVolume,
                PackagedVolume = it.PackagedVolume,
                IsStackable = it.IsStackable,
                MaxStackSize = it.MaxStackSize,
                Mass = it.Mass,
                Capacity = it.Capacity,
                MetaLevel = it.MetaLevel,
                TechLevel = it.TechLevel
            }).ToList();

            Response.Headers["X-Total-Count"] = totalCount.ToString();
            Response.Headers["X-Page"] = page.ToString();
            Response.Headers["X-Page-Size"] = pageSize.ToString();

            return Ok(dtos);
        }

        /// <summary>
        /// Get ship types
        /// </summary>
        [HttpGet("ships")]
        public async Task<ActionResult<List<ShipTypeDto>>> GetShipTypes([FromQuery] string? race = null)
        {
            var query = _context.Ships
                .Include(s => s.ItemType)
                .ThenInclude(it => it.Group)
                .AsQueryable();

            if (!string.IsNullOrEmpty(race))
            {
                query = query.Where(s => s.Race == race);
            }

            var ships = await query.ToListAsync();

            var dtos = ships.Select(s => new ShipTypeDto
            {
                TypeId = s.ShipTypeId,
                Name = s.Name,
                Description = s.Description,
                ShipSize = s.ShipSize,
                Race = s.Race,
                HighSlots = s.HighSlots,
                MediumSlots = s.MediumSlots,
                LowSlots = s.LowSlots,
                RigSlots = s.RigSlots,
                BaseCpu = s.BaseCpu,
                BasePowergrid = s.BasePowergrid,
                BaseCargoCapacity = s.BaseCargoCapacity,
                BaseShieldHp = s.BaseShieldHp,
                BaseArmorHp = s.BaseArmorHp,
                BaseStructureHp = s.BaseStructureHp,
                BaseVolume = s.ItemType.BaseVolume,
                PackagedVolume = s.ItemType.PackagedVolume,
                Mass = s.ItemType.Mass,
                MetaLevel = s.ItemType.MetaLevel,
                TechLevel = s.TechLevel
            }).ToList();

            return Ok(dtos);
        }

        /// <summary>
        /// Get module types
        /// </summary>
        [HttpGet("modules")]
        public async Task<ActionResult<List<ModuleTypeDto>>> GetModuleTypes(
            [FromQuery] int? slotType = null,
            [FromQuery] int? moduleCategory = null)
        {
            var query = _context.Modules
                .Include(m => m.ItemType)
                .AsQueryable();

            if (slotType.HasValue)
            {
                query = query.Where(m => m.SlotType == slotType.Value);
            }

            if (moduleCategory.HasValue)
            {
                query = query.Where(m => m.ModuleCategory == moduleCategory.Value);
            }

            var modules = await query.ToListAsync();

            var dtos = modules.Select(m => new ModuleTypeDto
            {
                TypeId = m.ModuleTypeId,
                Name = m.Name,
                Description = m.Description,
                ModuleCategory = m.ModuleCategory,
                SlotType = m.SlotType,
                RequiredCpu = m.RequiredCpu,
                RequiredPowergrid = m.RequiredPowergrid,
                ActivationCost = m.ActivationCost,
                ActivationDuration = m.ActivationDuration,
                BaseVolume = m.ItemType.BaseVolume,
                PackagedVolume = m.ItemType.PackagedVolume,
                Mass = m.ItemType.Mass,
                MetaLevel = m.MetaLevel,
                TechLevel = m.TechLevel
            }).ToList();

            return Ok(dtos);
        }
    }
}
