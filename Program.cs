using Echoes.API.Controllers;
using Echoes.API.Data;
using Echoes.API.Health;
using Echoes.API.Models.Config;
using Echoes.API.Services;
using Echoes.API.Services.Auth;
using Echoes.API.Services.UniverseGeneration;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using Microsoft.OpenApi.Models;
using System.Text;

var builder = WebApplication.CreateBuilder(args);

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
        options.UseNpgsql(connectionString,
            npgsqlOptions =>
            {
                npgsqlOptions.EnableRetryOnFailure(
                    maxRetryCount: 5,
                    maxRetryDelay: TimeSpan.FromSeconds(30),
                    errorCodesToAdd: null);
                npgsqlOptions.MigrationsAssembly(typeof(Program).Assembly.GetName().Name);
               
            });

        if (builder.Environment.IsDevelopment())
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
services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
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

// 3.4. Register services
services.AddScoped<IUniverseGenerator, UniverseGenerator>();
services.AddScoped<IJwtTokenService, JwtTokenService>();

// 3.5. Controllers
services.AddControllers()
    .AddJsonOptions(options =>
    {
        options.JsonSerializerOptions.PropertyNamingPolicy = System.Text.Json.JsonNamingPolicy.CamelCase;
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

// 3.7. Swagger/OpenAPI
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

// 3.8. Health Checks
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
}

// 4.2. Middleware pipeline
//app.UseHttpsRedirection();
app.UseStaticFiles();
app.UseRouting();
app.UseCors("AllowAll");
app.UseAuthentication();
app.UseAuthorization();

// 4.3. Health check endpoint
app.MapGet("/", () => Results.Json(new
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
            var detailedStatsTask = (Task)method.Invoke(universeGenerator, null);
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
    catch (Exception ex)
    {
        // Игнорируем ошибки детальной статистики
        Console.WriteLine($"⚠️ Detailed statistics unavailable: {ex.Message}");
    }
}