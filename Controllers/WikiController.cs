using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.Entities.Wiki;
using EchoesOfImperial.Shared.DTOs;
using System.Security.Claims;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class WikiController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<WikiController> _logger;

        public WikiController(DatabaseContext context, ILogger<WikiController> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Get all published wiki pages (public endpoint)
        /// </summary>
        [HttpGet]
        [AllowAnonymous]
        public async Task<ActionResult<List<WikiPageDto>>> GetWikiPages()
        {
            try
            {
                var pages = await _context.WikiPages
                    .Where(w => w.IsPublished)
                    .OrderBy(w => w.SectionName)
                    .ThenBy(w => w.Title)
                    .Select(w => new WikiPageDto
                    {
                        Id = w.WikiPageId,
                        SectionName = w.SectionName,
                        Title = w.Title,
                        ContentHtml = w.ContentHtml,
                        CreatedAt = w.CreatedAt,
                        UpdatedAt = w.UpdatedAt,
                        CreatedByName = w.CreatedByName,
                        LastUpdatedBy = w.LastUpdatedBy
                    })
                    .ToListAsync();

                return Ok(pages);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error fetching wiki pages");
                return StatusCode(500, new { error = "Failed to fetch wiki pages" });
            }
        }

        /// <summary>
        /// Get a single wiki page by ID (public endpoint)
        /// </summary>
        [HttpGet("{id}")]
        [AllowAnonymous]
        public async Task<ActionResult<WikiPageDto>> GetWikiPage(Guid id)
        {
            try
            {
                var page = await _context.WikiPages
                    .Where(w => w.WikiPageId == id && w.IsPublished)
                    .Select(w => new WikiPageDto
                    {
                        Id = w.WikiPageId,
                        SectionName = w.SectionName,
                        Title = w.Title,
                        ContentHtml = w.ContentHtml,
                        CreatedAt = w.CreatedAt,
                        UpdatedAt = w.UpdatedAt,
                        CreatedByName = w.CreatedByName,
                        LastUpdatedBy = w.LastUpdatedBy
                    })
                    .FirstOrDefaultAsync();

                if (page == null)
                {
                    return NotFound(new { error = "Wiki page not found" });
                }

                return Ok(page);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error fetching wiki page with ID: {Id}", id);
                return StatusCode(500, new { error = "Failed to fetch wiki page" });
            }
        }

        /// <summary>
        /// Update a wiki page (Admin only)
        /// </summary>
        [HttpPut("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<ActionResult<WikiPageDto>> UpdateWikiPage(Guid id, [FromBody] WikiPageUpdateDto request)
        {
            try
            {
                // Get user ID and username from JWT claims
                var userIdClaim = User.FindFirst("sub")?.Value ?? User.FindFirst(ClaimTypes.NameIdentifier)?.Value;
                var userName = User.FindFirst(ClaimTypes.Name)?.Value ?? User.FindFirst("username")?.Value ?? "Admin";

                if (string.IsNullOrEmpty(userIdClaim) || !Guid.TryParse(userIdClaim, out Guid userId))
                {
                    return Unauthorized(new { error = "Invalid user token" });
                }

                var page = await _context.WikiPages.FindAsync(id);
                if (page == null)
                {
                    return NotFound(new { error = "Wiki page not found" });
                }

                // Update page properties
                page.SectionName = request.SectionName;
                page.Title = request.Title;
                page.ContentHtml = request.ContentHtml;
                page.UpdatedAt = DateTime.UtcNow;
                page.LastUpdatedById = userId;
                page.LastUpdatedBy = userName;

                await _context.SaveChangesAsync();

                _logger.LogInformation("[ADMIN] {UserName} updated Wiki page: {Title}", userName, page.Title);

                var result = new WikiPageDto
                {
                    Id = page.WikiPageId,
                    SectionName = page.SectionName,
                    Title = page.Title,
                    ContentHtml = page.ContentHtml,
                    CreatedAt = page.CreatedAt,
                    UpdatedAt = page.UpdatedAt,
                    CreatedByName = page.CreatedByName,
                    LastUpdatedBy = page.LastUpdatedBy
                };

                return Ok(result);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error updating wiki page with ID: {Id}", id);
                return StatusCode(500, new { error = "Failed to update wiki page" });
            }
        }

        /// <summary>
        /// Create a new wiki page (Admin only)
        /// </summary>
        [HttpPost]
        [Authorize(Roles = "Admin")]
        public async Task<ActionResult<WikiPageDto>> CreateWikiPage([FromBody] WikiPageUpdateDto request)
        {
            try
            {
                // Get user ID and username from JWT claims
                var userIdClaim = User.FindFirst("sub")?.Value ?? User.FindFirst(ClaimTypes.NameIdentifier)?.Value;
                var userName = User.FindFirst(ClaimTypes.Name)?.Value ?? User.FindFirst("username")?.Value ?? "Admin";

                if (string.IsNullOrEmpty(userIdClaim) || !Guid.TryParse(userIdClaim, out Guid userId))
                {
                    return Unauthorized(new { error = "Invalid user token" });
                }

                var page = new WikiPage
                {
                    WikiPageId = Guid.NewGuid(),
                    SectionName = request.SectionName,
                    Title = request.Title,
                    ContentHtml = request.ContentHtml,
                    CreatedById = userId,
                    CreatedByName = userName,
                    CreatedAt = DateTime.UtcNow,
                    IsPublished = true
                };

                _context.WikiPages.Add(page);
                await _context.SaveChangesAsync();

                _logger.LogInformation("[ADMIN] {UserName} created Wiki page: {Title}", userName, page.Title);

                var result = new WikiPageDto
                {
                    Id = page.WikiPageId,
                    SectionName = page.SectionName,
                    Title = page.Title,
                    ContentHtml = page.ContentHtml,
                    CreatedAt = page.CreatedAt,
                    UpdatedAt = page.UpdatedAt,
                    CreatedByName = page.CreatedByName,
                    LastUpdatedBy = page.LastUpdatedBy
                };

                return CreatedAtAction(nameof(GetWikiPage), new { id = page.WikiPageId }, result);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error creating wiki page");
                return StatusCode(500, new { error = "Failed to create wiki page" });
            }
        }
    }
}
