using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.Entities.News;
using EchoesOfImperial.Shared.DTOs;
using System.Security.Claims;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class NewsController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<NewsController> _logger;

        public NewsController(DatabaseContext context, ILogger<NewsController> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Get all published news posts (public endpoint)
        /// </summary>
        [HttpGet]
        [AllowAnonymous]
        public async Task<ActionResult<List<NewsPostDto>>> GetNews()
        {
            try
            {
                var news = await _context.NewsPosts
                    .Where(n => n.IsPublished)
                    .OrderByDescending(n => n.CreatedAt)
                    .Select(n => new NewsPostDto
                    {
                        Id = n.NewsPostId,
                        Title = n.Title,
                        Content = n.Content,
                        ImageUrl = n.ImageUrl,
                        CreatedAt = n.CreatedAt,
                        AuthorName = n.AuthorName
                    })
                    .ToListAsync();

                return Ok(news);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error fetching news posts");
                return StatusCode(500, new { error = "Failed to fetch news posts" });
            }
        }

        /// <summary>
        /// Create a new news post (Admin only)
        /// </summary>
        [HttpPost]
        [Authorize(Roles = "Admin")]
        public async Task<ActionResult<NewsPostDto>> CreateNews([FromBody] NewsPostCreateDto request)
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

                // Create news post
                var newsPost = new NewsPost
                {
                    NewsPostId = Guid.NewGuid(),
                    Title = request.Title,
                    Content = request.Content,
                    ImageUrl = request.ImageUrl,
                    AuthorId = userId,
                    AuthorName = userName,
                    CreatedAt = DateTime.UtcNow,
                    IsPublished = true
                };

                _context.NewsPosts.Add(newsPost);
                await _context.SaveChangesAsync();

                _logger.LogInformation("[ADMIN] {UserName} created news post: {Title}", userName, newsPost.Title);

                var result = new NewsPostDto
                {
                    Id = newsPost.NewsPostId,
                    Title = newsPost.Title,
                    Content = newsPost.Content,
                    ImageUrl = newsPost.ImageUrl,
                    CreatedAt = newsPost.CreatedAt,
                    AuthorName = newsPost.AuthorName
                };

                return CreatedAtAction(nameof(GetNews), new { id = newsPost.NewsPostId }, result);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error creating news post");
                return StatusCode(500, new { error = "Failed to create news post" });
            }
        }

        /// <summary>
        /// Delete a news post (Admin only)
        /// </summary>
        [HttpDelete("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<ActionResult> DeleteNews(Guid id)
        {
            try
            {
                var userName = User.FindFirst(ClaimTypes.Name)?.Value ?? User.FindFirst("username")?.Value ?? "Admin";

                var newsPost = await _context.NewsPosts.FindAsync(id);
                if (newsPost == null)
                {
                    return NotFound(new { error = "News post not found" });
                }

                _context.NewsPosts.Remove(newsPost);
                await _context.SaveChangesAsync();

                _logger.LogInformation("[ADMIN] {UserName} deleted news post: {Title}", userName, newsPost.Title);

                return Ok(new { message = "News post deleted successfully" });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error deleting news post with ID: {Id}", id);
                return StatusCode(500, new { error = "Failed to delete news post" });
            }
        }
    }
}
