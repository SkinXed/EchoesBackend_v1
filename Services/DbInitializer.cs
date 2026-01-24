using Echoes.API.Data;
using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Entities.Shop;
using Echoes.API.Models.Enums;
using Microsoft.EntityFrameworkCore;
using System.Security.Cryptography;
using System.Text;

namespace Echoes.API.Services;

public interface IDbInitializer
{
    Task InitializeAsync();
}

public class DbInitializer : IDbInitializer
{
    private readonly DatabaseContext _context;
    private readonly IConfiguration _configuration;
    private readonly ILogger<DbInitializer> _logger;

    public DbInitializer(DatabaseContext context, IConfiguration configuration, ILogger<DbInitializer> logger)
    {
        _context = context;
        _configuration = configuration;
        _logger = logger;
    }

    public async Task InitializeAsync()
    {
        try
        {
            _logger.LogInformation("🔄 Initializing database roles and admin user...");

            // Check and create admin user if not exists
            var adminEmail = _configuration["Admin:Email"] ?? "admin@echoes.com";
            var adminPassword = _configuration["Admin:Password"] ?? "Admin123!";
            var adminUsername = _configuration["Admin:Username"] ?? "admin";

            var adminAccount = await _context.Accounts.FirstOrDefaultAsync(a => a.Email == adminEmail);

            if (adminAccount == null)
            {
                _logger.LogInformation($"👤 Creating admin user: {adminEmail}");

                // Create admin account
                CreatePasswordHash(adminPassword, out byte[] passwordHash, out byte[] passwordSalt);

                adminAccount = new Account
                {
                    AccountId = Guid.NewGuid(),
                    Email = adminEmail,
                    Username = adminUsername,
                    DisplayName = "System Administrator",
                    Nickname = "Admin",
                    PasswordHash = Convert.ToBase64String(passwordHash),
                    PasswordSalt = Convert.ToBase64String(passwordSalt),
                    AccountStatus = AccountStatus.Active,
                    AccountType = AccountType.Admin,
                    Roles = AccountRole.Admin | AccountRole.Player, // Admin + Player roles
                    IsEmailVerified = true,
                    EmailVerifiedAt = DateTime.UtcNow
                };

                _context.Accounts.Add(adminAccount);

                // Create default character for admin
                var adminCharacter = new Character
                {
                    Id = Guid.NewGuid(),
                    AccountId = adminAccount.AccountId,
                    Name = "Administrator",
                    IsMain = true,
                    WalletBalance = 999999999,
                    SecurityStatus = 10.0f,
                    CloneExpiration = DateTime.UtcNow.AddYears(10)
                };

                _context.Characters.Add(adminCharacter);

                await _context.SaveChangesAsync();
                _logger.LogInformation($"✅ Admin user created: {adminEmail}");
            }
            else
            {
                _logger.LogInformation($"✓ Admin user already exists: {adminEmail}");

                // Ensure admin has admin role
                if (!adminAccount.Roles.HasFlag(AccountRole.Admin))
                {
                    adminAccount.Roles |= AccountRole.Admin;
                    await _context.SaveChangesAsync();
                    _logger.LogInformation("✅ Admin role assigned to existing admin user");
                }
            }

            // Seed shop items if they don't exist
            var shopItemCount = await _context.ShopItems.CountAsync();
            if (shopItemCount == 0)
            {
                _logger.LogInformation("🛒 Seeding shop items...");

                var shopItems = new List<ShopItem>
                {
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Frigate Hull - Imperial Vanguard",
                        Description = "A lightweight, fast frigate hull perfect for reconnaissance and quick strike missions. Features advanced targeting systems and enhanced shield capacity. Ideal for new pilots looking to make their mark in the galaxy.",
                        Price = 500000,
                        ImageUrl = "https://example.com/images/frigate-hull.jpg",
                        IsActive = true
                    },
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Plasma Cannon MK-VII",
                        Description = "High-energy plasma weapon system capable of devastating damage at medium range. Utilizes advanced plasma containment technology to deliver massive firepower. Warning: High power consumption.",
                        Price = 1200000,
                        ImageUrl = "https://example.com/images/plasma-cannon.jpg",
                        IsActive = true
                    },
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Repair Nanites (Advanced)",
                        Description = "Self-replicating nanobots that can repair ship hull damage in real-time. Advanced formula provides 50% faster repair rates than standard nanites. Essential for long-duration missions in hostile territory.",
                        Price = 350000,
                        ImageUrl = "https://example.com/images/repair-nanites.jpg",
                        IsActive = true
                    }
                };

                _context.ShopItems.AddRange(shopItems);
                await _context.SaveChangesAsync();
                _logger.LogInformation($"✅ Added {shopItems.Count} shop items");
            }
            else
            {
                _logger.LogInformation($"✓ Shop items already exist ({shopItemCount} items)");
            }

            _logger.LogInformation("✅ Database initialization complete");
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "❌ Error during database initialization");
            throw;
        }
    }

    private void CreatePasswordHash(string password, out byte[] passwordHash, out byte[] passwordSalt)
    {
        using var hmac = new HMACSHA512();
        passwordSalt = hmac.Key;
        passwordHash = hmac.ComputeHash(Encoding.UTF8.GetBytes(password));
    }
}
