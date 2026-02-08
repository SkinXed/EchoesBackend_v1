using Echoes.API.Controllers;
using Echoes.API.Data;
using Echoes.API.Health;
using Echoes.API.Models.Config;
using Echoes.API.Services;
using Echoes.API.Services.Auth;
using Echoes.API.Services.UniverseGeneration;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authentication.Google;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.RateLimiting;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using Microsoft.OpenApi.Models;
using System.Net;
using System.Text;
using System.Threading.RateLimiting;

var contentRoot = Directory.GetCurrentDirectory();

// Prefer serving the Blazor client wwwroot during local development if available
var potentialClientWww = Path.GetFullPath(Path.Combine(contentRoot, "..", "EchoesOfImperial.Client", "wwwroot"));
string webRootPath;
if (Directory.Exists(potentialClientWww))
{
    webRootPath = potentialClientWww;
    Console.WriteLine($"📡 Serving Blazor client from: {webRootPath}");
}
else
{
    webRootPath = Path.Combine(contentRoot, "api-webroot");
    Directory.CreateDirectory(webRootPath);
    Console.WriteLine($"📁 Using fallback webroot: {webRootPath}");
}

var builder = WebApplication.CreateBuilder(new WebApplicationOptions
{
    Args = args,
    ContentRootPath = contentRoot,
    WebRootPath = webRootPath
});

// ==============================================
// 0. KESTREL CONFIGURATION (Must be before building app)
// ==============================================
// Helper method to get port from environment or config
static int GetPortFromEnvironment(string envVar, int defaultValue)
{
    var envValue = Environment.GetEnvironmentVariable(envVar);
    return int.TryParse(envValue, out var port) ? port : defaultValue;
}

// Get port configuration with fallback to environment variables
var httpPort = builder.Configuration.GetValue<int?>("Server:Port") 
    ?? GetPortFromEnvironment("HTTP_PORT", 5116);

var httpsPort = builder.Configuration.GetValue<int?>("Server:HttpsPort")
    ?? GetPortFromEnvironment("HTTPS_PORT", 5115);

builder.WebHost.ConfigureKestrel(options =>
{
    // Configure HTTP endpoint
    options.Listen(IPAddress.Loopback, httpPort);
    Console.WriteLine($"🌐 Configuring HTTP on port {httpPort}");
    
    // Configure HTTPS endpoint
    options.Listen(IPAddress.Loopback, httpsPort, listenOptions =>
    {
        listenOptions.UseHttps(); // Use appropriate certificate if needed
    });
    Console.WriteLine($"🔒 Configuring HTTPS on port {httpsPort}");
});

// ==============================================
// 1. CONFIGURATION
// ==============================================
builder.Configuration
    .SetBasePath(Directory.GetCurrentDirectory())
    .AddJsonFile("appsettings.json", optional: false, reloadOnChange: true)
    .AddJsonFile($"appsettings.{builder.Environment.EnvironmentName}.json", optional: true)
    .AddEnvironmentVariables();

// ==============================================
// 2. LOGGING
// ==============================================
builder.Logging.ClearProviders();
builder.Logging.AddConsole();
builder.Logging.AddDebug();
builder.Logging.SetMinimumLevel(builder.Environment.IsDevelopment() ? LogLevel.Information : LogLevel.Warning);
builder.Services.AddScoped<IGameServerService, GameServerService>();

// ==============================================
// 3. ADD SERVICES
// ==============================================
var services = builder.Services;

// 3.1. Entity Framework with PostgreSQL
var connectionString = builder.Configuration.GetConnectionString("DefaultConnection");

if (string.IsNullOrEmpty(connectionString))
{
    // Use InMemory for development
    Console.WriteLine("⚠️ Using InMemory database (connection string not specified)");
    services.AddDbContext<DatabaseContext>(options =>
        options.UseInMemoryDatabase("EchoesTestDB"));
}
else
{
    services.AddDbContext<DatabaseContext>(options =>
    {
        options.UseNpgsql(connectionString, npgsqlOptions =>
        {
            npgsqlOptions.EnableRetryOnFailure(5, TimeSpan.FromSeconds(30), null);
            npgsqlOptions.MigrationsAssembly(typeof(Program).Assembly.GetName().Name);
        });

        // Note: prefer using `.AsSplitQuery()` on individual queries. Global UseQuerySplittingBehavior caused build issues in this environment, so it's omitted.

        // Включаем sensitive logging только когда это явно разрешено в конфигурации (и только в dev)
        var enableSensitive = builder.Environment.IsDevelopment()
                            && builder.Configuration.GetValue<bool>("Logging:EnableSensitiveDataLogging", false);

        if (enableSensitive)
        {
            options.EnableSensitiveDataLogging();
            options.EnableDetailedErrors();
            options.LogTo(Console.WriteLine, LogLevel.Information);
        }
    });
}

// 3.2. Configuration
services.Configure<UniverseConfig>(
    builder.Configuration.GetSection("Universe"));

// 3.3. JWT Authentication
var jwtSecret = builder.Configuration["Jwt:Secret"] ?? "YourSuperSecretKeyForJWTTokenGeneration1234567890!";
var authenticationBuilder = services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
    .AddJwtBearer(options =>
    {
        options.TokenValidationParameters = new TokenValidationParameters
        {
            ValidateIssuer = true,
            ValidateAudience = true,
            ValidateLifetime = true,
            ValidateIssuerSigningKey = true,
            ValidIssuer = builder.Configuration["Jwt:Issuer"] ?? "EchoesAPI",
            ValidAudience = builder.Configuration["Jwt:Audience"] ?? "EchoesClient",
            IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(jwtSecret)),
            ClockSkew = TimeSpan.Zero
        };
    });

// Add Google authentication only if credentials are configured
var googleClientId = builder.Configuration["Google:ClientId"];
var googleClientSecret = builder.Configuration["Google:ClientSecret"];
if (!string.IsNullOrEmpty(googleClientId) && !string.IsNullOrEmpty(googleClientSecret))
{
    authenticationBuilder.AddGoogle(options =>
    {
        options.ClientId = googleClientId;
        options.ClientSecret = googleClientSecret;
    });
    Console.WriteLine("✅ Google OAuth authentication enabled");
}
else
{
    Console.WriteLine("⚠️ Google OAuth not configured - skipping Google authentication");
}

// 3.4. Register services
services.AddScoped<IUniverseGenerator, UniverseGenerator>();
services.AddScoped<IUniverseGenerationService, UniverseGenerationService>();
services.AddSingleton<IBackgroundGenerationService, BackgroundGenerationService>();
services.AddScoped<IJwtTokenService, JwtTokenService>();
services.AddScoped<IAuthService, AuthService>();
services.AddScoped<Echoes.API.Services.Email.IEmailService, Echoes.API.Services.Email.EmailService>();
services.AddScoped<ITwoFactorAuthService, TwoFactorAuthService>();
services.AddScoped<IGoogleAuthService, GoogleAuthService>();
services.AddScoped<IDbInitializer, DbInitializer>();

// 3.4.1. Inventory services
services.AddScoped<Echoes.API.Services.Inventory.IInventoryService, Echoes.API.Services.Inventory.InventoryService>();
services.AddScoped<Echoes.API.Services.Inventory.IContainerService, Echoes.API.Services.Inventory.ContainerService>();
services.AddScoped<Echoes.API.Services.Inventory.IInventoryOperationsService, Echoes.API.Services.Inventory.InventoryOperationsService>();

// 3.4.2. Ship services
services.AddScoped<Echoes.API.Services.Ship.IShipFittingService, Echoes.API.Services.Ship.ShipFittingService>();

// 3.4.3. Training services
services.AddScoped<TrainingService>();
services.AddHostedService<TrainingWorker>();
// 3.4.3. Repositories
services.AddScoped<Echoes.API.Data.Repositories.FittingRepository>();

// 3.4.4. Market services
services.AddScoped<Echoes.API.Services.Market.IMarketService, Echoes.API.Services.Market.MarketService>();

// 3.4.5. Combat services
services.AddScoped<Echoes.API.Services.Combat.IKillmailService, Echoes.API.Services.Combat.KillmailService>();

// 3.5. Controllers
services.AddControllers()
    .AddJsonOptions(options =>
    {
        // CRITICAL: Use null (PascalCase) to match UE5 C++ USTRUCT property names
        // DO NOT use CamelCase as it breaks UE5 JSON parsing!
        options.JsonSerializerOptions.PropertyNamingPolicy = null; // PascalCase (default)
        options.JsonSerializerOptions.WriteIndented = true;
        options.JsonSerializerOptions.ReferenceHandler = System.Text.Json.Serialization.ReferenceHandler.IgnoreCycles;
        options.JsonSerializerOptions.DefaultIgnoreCondition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull;
    });

// 3.6. CORS
services.AddCors(options =>
{
    options.AddPolicy("AllowAll", policy =>
    {
        policy.AllowAnyOrigin()
              .AllowAnyMethod()
              .AllowAnyHeader()
              .WithExposedHeaders("Content-Disposition", "X-Pagination");
    });

    options.AddPolicy("AllowUE5", policy =>
    {
        policy.WithOrigins(
                "http://localhost:8080",    // UE5 Dev Server
                "http://127.0.0.1:8080",    // UE5 Local
                "https://*.unrealengine.com" // UE5 Web
            )
            .AllowAnyMethod()
            .AllowAnyHeader()
            .AllowCredentials();
    });
});

// 3.7. Memory Caching for Inventory
services.AddMemoryCache(options =>
{
    options.SizeLimit = 1024 * 1024 * 100; // 100 MB
});

// 3.8. Response Caching
services.AddResponseCaching();

// 3.9. Rate Limiting
services.AddRateLimiter(options =>
{
    options.AddFixedWindowLimiter("search-limit", limiterOptions =>
    {
        limiterOptions.PermitLimit = 30;
        limiterOptions.Window = TimeSpan.FromMinutes(1);
        limiterOptions.QueueProcessingOrder = System.Threading.RateLimiting.QueueProcessingOrder.OldestFirst;
        limiterOptions.QueueLimit = 5;
    });
});

// 3.10. Swagger/OpenAPI
services.AddEndpointsApiExplorer();
services.AddSwaggerGen(c =>
{
    c.SwaggerDoc("v1", new OpenApiInfo
    {
        Title = "Echoes Universe API",
        Version = "v1",
        Description = "Game Backend API",
        Contact = new OpenApiContact
        {
            Name = "Echoes Development Team",
            Email = "dev@echoes-game.com",
            Url = new Uri("https://echoes-game.com")
        },
        License = new OpenApiLicense
        {
            Name = "MIT License",
            Url = new Uri("https://opensource.org/licenses/MIT")
        }
    });

    // Fix duplicate schema names by using full type names
    // This is needed because we have multiple InventoryItemDTO classes in different namespaces:
    // - Echoes.API.Models.DTOs.Inventory.InventoryItemDTO (in-game inventory)
    // - EchoesOfImperial.Shared.DTOs.InventoryItemDTO (web shop inventory)
    // Using FullName ensures Swagger can differentiate them
    c.CustomSchemaIds(type => type.FullName);

    // Add JWT support to Swagger
    c.AddSecurityDefinition("Bearer", new OpenApiSecurityScheme
    {
        Description = "JWT Authorization header using the Bearer scheme.\n\nEnter 'Bearer' [space] and then your token.\n\nExample: 'Bearer 12345abcdef'",
        Name = "Authorization",
        In = ParameterLocation.Header,
        Type = SecuritySchemeType.ApiKey,
        Scheme = "Bearer"
    });

    c.AddSecurityRequirement(new OpenApiSecurityRequirement
    {
        {
            new OpenApiSecurityScheme
            {
                Reference = new OpenApiReference
                {
                    Type = ReferenceType.SecurityScheme,
                    Id = "Bearer"
                }
            },
            Array.Empty<string>()
        }
    });

    // Include XML comments if available
    var xmlFile = $"{System.Reflection.Assembly.GetExecutingAssembly().GetName().Name}.xml";
    var xmlPath = Path.Combine(AppContext.BaseDirectory, xmlFile);
    if (File.Exists(xmlPath))
    {
        c.IncludeXmlComments(xmlPath);
    }
});

// 3.11. Health Checks
services.AddHealthChecks()
    .AddCheck<DatabaseHealthCheck>("Database");

// Добавляем поддержку статических файлов (для wwwroot предупреждения)



var app = builder.Build();

// ==============================================
// 4. CONFIGURE HTTP PIPELINE
// ==============================================

// 4.1. Development
if (app.Environment.IsDevelopment())
{
    app.UseDeveloperExceptionPage();

    app.UseSwagger();
    app.UseSwaggerUI(c =>
    {
        c.SwaggerEndpoint("/swagger/v1/swagger.json", "Echoes Universe API v1");
        c.RoutePrefix = "swagger";
        c.DocumentTitle = "Echoes Universe API Documentation";
        c.EnableDeepLinking();
        c.DisplayOperationId();
        c.DisplayRequestDuration();
    });
}
else
{
    // Production
    app.UseExceptionHandler("/error");
    app.UseHsts();
    
    // In production, also enable Swagger but protect it
    app.UseSwagger();
    app.UseSwaggerUI(c =>
    {
        c.SwaggerEndpoint("/swagger/v1/swagger.json", "Echoes Universe API v1");
        c.RoutePrefix = "swagger";
        c.DocumentTitle = "Echoes Universe API Documentation";
    });
}

// 4.2. Middleware pipeline
//app.UseHttpsRedirection();
webRootPath = app.Environment.WebRootPath;
if (Directory.Exists(webRootPath))
{
    app.UseBlazorFrameworkFiles();
    app.UseStaticFiles();
}

app.UseRouting();
app.UseResponseCaching(); // Должен быть до UseAuthorization
app.UseCors("AllowAll");
app.UseAuthentication();
app.UseAuthorization();

// 4.2.1. Swagger security middleware - Admin only
app.Use(async (context, next) =>
{
    if (context.Request.Path.StartsWithSegments("/swagger"))
    {
        // Check if user is authenticated
        if (!context.User.Identity?.IsAuthenticated ?? true)
        {
            context.Response.StatusCode = 403;
            await context.Response.WriteAsync("Forbidden: Authentication required to access Swagger");
            return;
        }

        // Check if user has Admin role
        var rolesClaimValue = context.User.FindFirst("Roles")?.Value;
        if (string.IsNullOrEmpty(rolesClaimValue))
        {
            context.Response.StatusCode = 403;
            await context.Response.WriteAsync("Forbidden: Admin role required to access Swagger");
            return;
        }

        // Parse roles (AccountRole is a Flags enum stored as long)
        if (long.TryParse(rolesClaimValue, out long roles))
        {
            var accountRole = (Echoes.API.Models.Enums.AccountRole)roles;
            if (!accountRole.HasFlag(Echoes.API.Models.Enums.AccountRole.Admin))
            {
                context.Response.StatusCode = 403;
                await context.Response.WriteAsync("Forbidden: Admin role required to access Swagger");
                return;
            }
        }
        else
        {
            context.Response.StatusCode = 403;
            await context.Response.WriteAsync("Forbidden: Invalid role information");
            return;
        }
    }

    await next();
});

app.UseRateLimiter(); // Должен быть после UseAuthorization

// 4.3. Health check endpoint
app.MapGet("/api/status", () => Results.Json(new
{
    status = "online",
    service = "Echoes Universe API",
    version = "1.0.0",
    timestamp = DateTime.UtcNow,
    documentation = $"{app.Urls.FirstOrDefault()}/swagger",
    database = "PostgreSQL"
}));

app.MapGet("/api/handshake", async (DatabaseContext db) =>
{
    // Считаем онлайн (можно упростить до 0, если база пустая)
    int onlineCount = 0;
    try
    {
        onlineCount = await db.GameServers
            .Where(s => s.Status == Echoes.API.Models.Entities.GameServer.ServerStatus.Ready)
            .SumAsync(s => s.OnlinePlayers);
    }
    catch { }

    return Results.Ok(new
    {
        ServerVersion = "0.1.0",
        MinClientVersion = "0.1.0", // Версия, ниже которой клиент не пустит
        OnlinePlayers = onlineCount,
        Region = "EU",
        ServerTime = DateTime.UtcNow,
        bIsOnline = true
    });
});

app.MapGet("/health", async (DatabaseContext dbContext) =>
{
    try
    {
        // Check database connection
        var canConnect = await dbContext.Database.CanConnectAsync();

        return Results.Json(new
        {
            status = canConnect ? "healthy" : "degraded",
            timestamp = DateTime.UtcNow,
            service = "Echoes Universe API",
            database = canConnect ? "connected" : "disconnected",
            universe = new
            {
                regions = await dbContext.Regions.CountAsync(),
                systems = await dbContext.SolarSystems.CountAsync()
                // Removed players count
            }
        });
    }
    catch (Exception ex)
    {
        return Results.Json(new
        {
            status = "unhealthy",
            timestamp = DateTime.UtcNow,
            error = ex.Message,
            database = "error"
        }, statusCode: 503);


    }

});

// 4.4. Error handling endpoint
app.Map("/error", () => Results.Problem("An error occurred on the server"));

// 4.5. Main routes
app.MapControllers();

// 4.6. Fallback to Blazor app for client-side routing
if (Directory.Exists(webRootPath))
{
    // Serve Blazor static files and ensure SPA fallback for any non-file path (e.g., /wiki)
    app.UseBlazorFrameworkFiles();
    app.UseStaticFiles();

    // Map a catch-all fallback so client-side routes like /wiki return index.html
    app.MapFallbackToFile("{*path:nonfile}", "index.html");
}
else
{
    // If no webroot, keep previous behavior
    app.MapFallbackToFile("index.html");
}

// ==============================================
// 5. DATABASE AND UNIVERSE INITIALIZATION
// ==============================================
using (var scope = app.Services.CreateScope())
{
    var context = scope.ServiceProvider.GetRequiredService<DatabaseContext>();
    var universeGenerator = scope.ServiceProvider.GetRequiredService<IUniverseGenerator>();
    var config = scope.ServiceProvider.GetRequiredService<Microsoft.Extensions.Options.IOptions<UniverseConfig>>();
    var logger = scope.ServiceProvider.GetRequiredService<ILogger<Program>>();
    var configuration = scope.ServiceProvider.GetRequiredService<IConfiguration>();
    var dbInitializer = scope.ServiceProvider.GetRequiredService<IDbInitializer>();

    try
    {
        Console.WriteLine("🚀 INITIALIZING ECHOES UNIVERSE");
        Console.WriteLine("=".PadRight(60, '='));

        // Apply migrations
        Console.WriteLine("🔄 Checking/creating database...");
        try
        {
            // Применяем миграции (это также создаст базу, если её нет)
            Console.WriteLine("🔄 Applying migrations...");
            await context.Database.MigrateAsync();
            Console.WriteLine("✅ Database migrated successfully");
        }

        
        catch (Exception ex)
        {
            Console.WriteLine($"⚠️ Database issue: {ex.Message}");
            // Продолжаем работу в режиме InMemory или выходим
        }

        // Check connection
        Console.WriteLine("🔌 Testing database connection...");
        var canConnect = await context.Database.CanConnectAsync();
        if (!canConnect)
        {
            throw new Exception("Failed to connect to database");
        }
        Console.WriteLine("✅ Database connection established");

        // Initialize roles and admin user
        await dbInitializer.InitializeAsync();

        // Check if data already exists
        var hasData = await context.SolarSystems.AnyAsync();

        bool generateUniverseOnStartup = configuration.GetValue<bool>("Game:GenerateUniverseOnStartup", true);
        string universePreset = configuration["Game:UniversePreset"] ?? "Medium";
        bool forceRegenerate = configuration.GetValue<bool>("Game:ForceRegenerate", false);

        if (!hasData || forceRegenerate)
        {
            if (forceRegenerate && hasData)
            {
                Console.WriteLine("🔄 Forced universe regeneration...");
                await universeGenerator.ClearUniverseAsync();
            }

            if (generateUniverseOnStartup)
            {
                Console.WriteLine($"🔧 Universe configuration:");
                Console.WriteLine($"   • Regions: {config.Value.RegionCount}");
                Console.WriteLine($"   • Constellations: {config.Value.MinConstellationsPerRegion}-{config.Value.MaxConstellationsPerRegion} per region");
                Console.WriteLine($"   • Systems: {config.Value.MinSystemsPerConstellation}-{config.Value.MaxSystemsPerConstellation} per constellation");
                Console.WriteLine($"   • Planets: {config.Value.MinPlanetsPerSystem}-{config.Value.MaxPlanetsPerSystem} per system");
                Console.WriteLine($"   • Preset: {universePreset}");
                Console.WriteLine();

                Console.WriteLine("🌌 Generating universe...");
                Console.WriteLine("   This may take some time...");
                Console.WriteLine();

                var stopwatch = System.Diagnostics.Stopwatch.StartNew();

                await universeGenerator.GenerateUniverseFromConfigAsync(config.Value);

                stopwatch.Stop();

                var stats = await universeGenerator.GetUniverseStatsAsync();

                Console.WriteLine($"✅ Universe created in {stopwatch.Elapsed.TotalSeconds:F1} seconds!");
                Console.WriteLine();

                Console.WriteLine("📊 UNIVERSE STATISTICS:");
                Console.WriteLine($"   ┌──────────────────────┬──────────┐");
                Console.WriteLine($"   │ Entity               │ Count    │");
                Console.WriteLine($"   ├──────────────────────┼──────────┤");
                Console.WriteLine($"   │ Regions              │ {stats.Regions,8} │");
                Console.WriteLine($"   │ Constellations       │ {stats.Constellations,8} │");
                Console.WriteLine($"   │ Solar Systems        │ {stats.SolarSystems,8} │");
                Console.WriteLine($"   │ Planets              │ {stats.Planets,8} │");
                Console.WriteLine($"   │ Stations             │ {stats.Stations,8} │");
                Console.WriteLine($"   │ Stargates            │ {stats.Stargates,8} │");
                Console.WriteLine($"   │ Asteroid Belts       │ {stats.AsteroidBelts,8} │");
                Console.WriteLine($"   │ Anomalies            │ {stats.Anomalies,8} │");
                Console.WriteLine($"   │ Wormholes            │ {stats.Wormholes,8} │");
                Console.WriteLine($"   └──────────────────────┴──────────┘");
                Console.WriteLine();

                // Estimated capacity
                int estimatedPlayers = stats.SolarSystems * 100;
                Console.WriteLine($"👥 Estimated capacity: {estimatedPlayers:N0} players");
                Console.WriteLine();

                // Детальная статистика
                await PrintDetailedStatsAsync(universeGenerator);
            }
            else
            {
                Console.WriteLine("⏸️  Universe generation disabled in settings");
                Console.WriteLine("📝 Creating test universe...");
                await universeGenerator.GenerateTestUniverseAsync();
                Console.WriteLine("✅ Test universe created");

                var stats = await universeGenerator.GetUniverseStatsAsync();
                Console.WriteLine("📊 TEST UNIVERSE STATISTICS:");
                Console.WriteLine($"   ┌──────────────────────┬──────────┐");
                Console.WriteLine($"   │ Entity               │ Count    │");
                Console.WriteLine($"   ├──────────────────────┼──────────┤");
                Console.WriteLine($"   │ Regions              │ {stats.Regions,8} │");
                Console.WriteLine($"   │ Constellations       │ {stats.Constellations,8} │");
                Console.WriteLine($"   │ Solar Systems        │ {stats.SolarSystems,8} │");
                Console.WriteLine($"   │ Planets              │ {stats.Planets,8} │");
                Console.WriteLine($"   │ Stations             │ {stats.Stations,8} │");
                Console.WriteLine($"   │ Stargates            │ {stats.Stargates,8} │");
                Console.WriteLine($"   │ Asteroid Belts       │ {stats.AsteroidBelts,8} │");
                Console.WriteLine($"   │ Anomalies            │ {stats.Anomalies,8} │");
                Console.WriteLine($"   │ Wormholes            │ {stats.Wormholes,8} │");
                Console.WriteLine($"   └──────────────────────┴──────────┘");
                Console.WriteLine();

                // Детальная статистика
                await PrintDetailedStatsAsync(universeGenerator);
            }
        }
        else
        {
            var stats = await universeGenerator.GetUniverseStatsAsync();

            Console.WriteLine("📊 EXISTING UNIVERSE STATISTICS:");
            Console.WriteLine($"   ┌──────────────────────┬──────────┐");
            Console.WriteLine($"   │ Entity               │ Count    │");
            Console.WriteLine($"   ├──────────────────────┼──────────┤");
            Console.WriteLine($"   │ Regions              │ {stats.Regions,8} │");
            Console.WriteLine($"   │ Constellations       │ {stats.Constellations,8} │");
            Console.WriteLine($"   │ Solar Systems        │ {stats.SolarSystems,8} │");
            Console.WriteLine($"   │ Planets              │ {stats.Planets,8} │");
            Console.WriteLine($"   │ Stations             │ {stats.Stations,8} │");
            Console.WriteLine($"   │ Stargates            │ {stats.Stargates,8} │");
            Console.WriteLine($"   │ Asteroid Belts       │ {stats.AsteroidBelts,8} │");
            Console.WriteLine($"   │ Anomalies            │ {stats.Anomalies,8} │");
            Console.WriteLine($"   │ Wormholes            │ {stats.Wormholes,8} │");
            Console.WriteLine($"   └──────────────────────┴──────────┘");
            Console.WriteLine();

            // Детальная статистика
            await PrintDetailedStatsAsync(universeGenerator);
        }
    }
    catch (Exception ex)
    {
        logger.LogError(ex, "❌ Initialization error");
        Console.WriteLine($"❌ Error: {ex.Message}");

        if (ex.InnerException != null)
        {
            Console.WriteLine($"   Details: {ex.InnerException.Message}");
        }

        Console.WriteLine();
        Console.WriteLine("💡 Check:");
        Console.WriteLine("   1. Is PostgreSQL server running?");
        Console.WriteLine("   2. Is the connection string correct in appsettings.json?");
        Console.WriteLine("   3. Does the 'EchoesUniverse' database exist?");
        Console.WriteLine();
    }
}

// ==============================================
// 6. DIAGNOSTICS (опционально)
// ==============================================
using (var scope = app.Services.CreateScope())
{
    try
    {
        var context = scope.ServiceProvider.GetRequiredService<DatabaseContext>();
        var model = context.Model;
        Console.WriteLine($"🔍 Model created successfully with {model.GetEntityTypes().Count()} entities");

        // Выводим все сущности для диагностики
        foreach (var entityType in model.GetEntityTypes())
        {
            Console.WriteLine($"   • {entityType.Name} -> {entityType.ClrType.FullName}");
        }
    }
    catch (Exception ex)
    {
        Console.WriteLine($"⚠️ Diagnostic error: {ex.Message}");
    }
}

// ==============================================
// 7. STARTUP INFORMATION
// ==============================================
Console.WriteLine("=".PadRight(60, '='));
Console.WriteLine("🚀 SERVER STARTED");
Console.WriteLine("=".PadRight(60, '='));

var urls = app.Urls.ToList();
foreach (var url in urls)
{
    Console.WriteLine($"🌐 URL: {url}");
}

Console.WriteLine();
Console.WriteLine("🎮 MAIN COMMANDS:");
Console.WriteLine($"   • Swagger UI: {app.Urls.FirstOrDefault()}/swagger");
Console.WriteLine($"   • Health Check: {app.Urls.FirstOrDefault()}/health");
Console.WriteLine($"   • Status: {app.Urls.FirstOrDefault()}/");
Console.WriteLine();

Console.WriteLine("🔧 UNIVERSE MANAGEMENT:");
Console.WriteLine($"   • Test universe: POST {app.Urls.FirstOrDefault()}/api/universe/generate-test");
Console.WriteLine($"   • Full universe: POST {app.Urls.FirstOrDefault()}/api/universe/generate-eve");
Console.WriteLine($"   • Statistics: GET {app.Urls.FirstOrDefault()}/api/universe/stats");
Console.WriteLine($"   • Clear: POST {app.Urls.FirstOrDefault()}/api/universe/clear");
Console.WriteLine();

Console.WriteLine("👤 AUTHENTICATION:");
Console.WriteLine($"   • Register: POST {app.Urls.FirstOrDefault()}/api/auth/register");
Console.WriteLine($"   • Login: POST {app.Urls.FirstOrDefault()}/api/auth/login");
Console.WriteLine();

Console.WriteLine("=".PadRight(60, '='));
Console.WriteLine("✅ READY FOR GAME!");
Console.WriteLine("=".PadRight(60, '='));
Console.WriteLine();

// ==============================================
// 8. SERVER START
// ==============================================
try
{
    await app.RunAsync();
}
catch (Exception ex)
{
    Console.WriteLine($"❌ Critical error starting server: {ex.Message}");
    Console.WriteLine(ex.StackTrace);
    throw;
}

// ==============================================
// HELPER METHODS
// ==============================================

async Task PrintDetailedStatsAsync(IUniverseGenerator universeGenerator)
{
    try
    {
        // Проверяем, есть ли метод GetDetailedUniverseStatsAsync
        var method = universeGenerator.GetType().GetMethod("GetDetailedUniverseStatsAsync");
        if (method != null)
        {
            var detailedStatsTask = (Task?)method.Invoke(universeGenerator, null);
            if (detailedStatsTask != null)
            {
                await detailedStatsTask;

                // Получаем результат через отражение
                var detailedStats = detailedStatsTask.GetType().GetProperty("Result")?.GetValue(detailedStatsTask);

                if (detailedStats != null)
                {
                    // Проверяем свойства через отражение
                    var anomalyTypesProp = detailedStats.GetType().GetProperty("AnomalyTypes");
                    if (anomalyTypesProp != null)
                    {
                        var anomalyTypes = anomalyTypesProp.GetValue(detailedStats) as System.Collections.IEnumerable;
                        if (anomalyTypes != null && anomalyTypes.Cast<object>().Any())
                        {
                            Console.WriteLine("📈 ANOMALY TYPES:");
                            foreach (dynamic type in anomalyTypes)
                            {
                                Console.WriteLine($"   • {type.Type}: {type.Count}");
                            }
                            Console.WriteLine();
                        }
                    }

                    var wormholeClassesProp = detailedStats.GetType().GetProperty("WormholeClasses");
                    if (wormholeClassesProp != null)
                    {
                        var wormholeClasses = wormholeClassesProp.GetValue(detailedStats) as System.Collections.IEnumerable;
                        if (wormholeClasses != null && wormholeClasses.Cast<object>().Any())
                        {
                            Console.WriteLine("🌀 WORMHOLE CLASSES:");
                            foreach (dynamic whClass in wormholeClasses)
                            {
                                Console.WriteLine($"   • {whClass.Type}: {whClass.Count}");
                            }
                            Console.WriteLine();
                        }
                    }
                }
            }
        }
    }
    catch (Exception ex)
    {
        // Игнорируем ошибки детальной статистики
        Console.WriteLine($"⚠️ Detailed statistics unavailable: {ex.Message}");
    }
}

builder.WebHost.UseContentRoot(Path.GetDirectoryName(typeof(Program).Assembly.Location)!);