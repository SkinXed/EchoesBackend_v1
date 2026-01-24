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

            Account? adminAccount = null;

            try
            {
                adminAccount = await _context.Accounts.FirstOrDefaultAsync(a => a.Email == adminEmail);
            }
            catch (Exception ex)
            {
                // Likely schema mismatch between model and database (column/table names).
                _logger.LogWarning(ex, "Unable to query Accounts table to check for admin user. Skipping admin creation.\nPossible causes: database schema does not match the current EF model.\nDetails: {Message}", ex.Message);
            }

            if (adminAccount == null)
            {
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
                        PasswordHash = passwordHash,
                        PasswordSalt = passwordSalt,
                        AccountStatus = AccountStatus.Active,
                        AccountType = AccountType.Admin,
                        Roles = AccountRole.Admin | AccountRole.Player, // Admin + Player roles
                        IsEmailVerified = true,
                        EmailVerifiedAt = DateTime.UtcNow
                    };

                    try
                    {
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
                    catch (Exception ex)
                    {
                        _logger.LogWarning(ex, "Failed to insert admin account or character. Skipping admin creation to avoid startup failure.");
                    }
                }
            }
            else
            {
                _logger.LogInformation($"✓ Admin user already exists: {adminEmail}");

                // Ensure admin has admin role
                try
                {
                    if (!adminAccount.Roles.HasFlag(AccountRole.Admin))
                    {
                        adminAccount.Roles |= AccountRole.Admin;
                        await _context.SaveChangesAsync();
                        _logger.LogInformation("✅ Admin role assigned to existing admin user");
                    }
                }
                catch (Exception ex)
                {
                    _logger.LogWarning(ex, "Failed to update existing admin user roles. Continuing startup.");
                }
            }

            // Seed shop items if they don't exist
            var shopItemCount = 0;
            try
            {
                shopItemCount = await _context.ShopItems.CountAsync();
            }
            catch (Exception ex)
            {
                _logger.LogWarning(ex, "Unable to access ShopItems table. Skipping shop seeding.");
            }

            if (shopItemCount == 0)
            {
                _logger.LogInformation("🛒 Seeding shop items...");

                var shopItems = new List<ShopItem>
                {
                    // Equipment Category
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Frigate Hull - Imperial Vanguard",
                        Description = "A lightweight, fast frigate hull perfect for reconnaissance and quick strike missions. Features advanced targeting systems and enhanced shield capacity. Ideal for new pilots looking to make their mark in the galaxy.",
                        Price = 500000,
                        Category = ShopItemCategory.Equipment,
                        ImageUrl = "https://example.com/images/frigate-hull.jpg",
                        IsActive = true
                    },
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Plasma Cannon MK-VII",
                        Description = "High-energy plasma weapon system capable of devastating damage at medium range. Utilizes advanced plasma containment technology to deliver massive firepower. Warning: High power consumption.",
                        Price = 1200000,
                        Category = ShopItemCategory.Equipment,
                        ImageUrl = "https://example.com/images/plasma-cannon.jpg",
                        IsActive = true
                    },
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Repair Nanites (Advanced)",
                        Description = "Self-replicating nanobots that can repair ship hull damage in real-time. Advanced formula provides 50% faster repair rates than standard nanites. Essential for long-duration missions in hostile territory.",
                        Price = 350000,
                        Category = ShopItemCategory.Consumables,
                        ImageUrl = "https://example.com/images/repair-nanites.jpg",
                        IsActive = true
                    },
                    
                    // Credits Category
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Credit Package - Starter",
                        Description = "Instant credit package for new pilots. Get 100,000 credits immediately credited to your account. Perfect for purchasing your first upgrades and equipment.",
                        Price = 100, // Real money price (e.g., $1.00)
                        Category = ShopItemCategory.Credits,
                        ImageUrl = "https://example.com/images/credits-starter.jpg",
                        IsActive = true
                    },
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Credit Package - Professional",
                        Description = "Professional pilot credit package. Receive 500,000 credits instantly. Best value for experienced pilots looking to expand their fleet.",
                        Price = 500, // Real money price (e.g., $5.00)
                        Category = ShopItemCategory.Credits,
                        ImageUrl = "https://example.com/images/credits-professional.jpg",
                        IsActive = true
                    },
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "Credit Package - Admiral",
                        Description = "Elite admiral credit package. Massive 2,000,000 credits package for serious commanders. Includes 10% bonus credits. Build your empire with this premium package.",
                        Price = 2000, // Real money price (e.g., $20.00)
                        Category = ShopItemCategory.Credits,
                        ImageUrl = "https://example.com/images/credits-admiral.jpg",
                        IsActive = true
                    },
                    
                    // VIP Status Category
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "VIP Status - Bronze (30 Days)",
                        Description = "Bronze VIP membership for 30 days. Benefits: +10% credit earnings, priority customer support, exclusive Bronze badge, access to VIP chat channel.",
                        Price = 500, // Real money price (e.g., $5.00)
                        Category = ShopItemCategory.VipStatus,
                        ImageUrl = "https://example.com/images/vip-bronze.jpg",
                        IsActive = true
                    },
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "VIP Status - Silver (30 Days)",
                        Description = "Silver VIP membership for 30 days. Benefits: +20% credit earnings, +10% experience boost, priority customer support, exclusive Silver badge, access to VIP lounge, 2 free ship respawns per day.",
                        Price = 1000, // Real money price (e.g., $10.00)
                        Category = ShopItemCategory.VipStatus,
                        ImageUrl = "https://example.com/images/vip-silver.jpg",
                        IsActive = true
                    },
                    new ShopItem
                    {
                        Id = Guid.NewGuid(),
                        Name = "VIP Status - Gold (30 Days)",
                        Description = "Gold VIP membership for 30 days. Benefits: +30% credit earnings, +20% experience boost, 24/7 priority support, exclusive Gold badge, VIP lounge access, 5 free ship respawns per day, early access to new features, special gold ship skin.",
                        Price = 2000, // Real money price (e.g., $20.00)
                        Category = ShopItemCategory.VipStatus,
                        ImageUrl = "https://example.com/images/vip-gold.jpg",
                        IsActive = true
                    }
                };

                try
                {
                    _context.ShopItems.AddRange(shopItems);
                    await _context.SaveChangesAsync();
                    _logger.LogInformation($"✅ Added {shopItems.Count} shop items");
                }
                catch (Exception ex)
                {
                    _logger.LogWarning(ex, "Failed to seed shop items. Continuing startup.");
                }
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
            // Do not rethrow to avoid crashing the application during startup when schema mismatches occur.
        }
    }

    private void CreatePasswordHash(string password, out byte[] passwordHash, out byte[] passwordSalt)
    {
        using var hmac = new HMACSHA512();
        passwordSalt = hmac.Key;
        passwordHash = hmac.ComputeHash(Encoding.UTF8.GetBytes(password));
    }
}
