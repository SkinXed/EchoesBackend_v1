# Echoes of Imperial - Critical Fix Log

> **History of Major Bug Fixes and Solutions**  
> Documentation of critical issues, root causes, and resolutions

**Version:** 2.0  
**Last Updated:** 2026-02-03  
**Purpose:** Track critical fixes to prevent regression and educate developers

---

## Table of Contents

1. [PostgreSQL Schema Errors](#postgresql-schema-errors)
2. [GUID Serialization Issues](#guid-serialization-issues)
3. [Foreign Key Constraint Violations](#foreign-key-constraint-violations)
4. [World Generation Race Conditions](#world-generation-race-conditions)
5. [Authentication & JWT Issues](#authentication--jwt-issues)
6. [Performance & Memory Issues](#performance--memory-issues)

---

## PostgreSQL Schema Errors

### Error 42P01: Relation Does Not Exist

**Date:** 2026-01-15  
**Severity:** 🔴 Critical  
**Impact:** API crashes on startup, database queries fail

#### Symptoms
```
Npgsql.PostgresException (0x80004005): 42P01: relation "characters" does not exist
   at Npgsql.NpgsqlConnector.ReadMessage(Boolean async, DataRowLoadingMode dataRowLoadingMode, Boolean readingNotifications, Boolean isReadingPrependedMessage)
```

#### Root Cause
1. Database migrations not applied
2. Migration files exist but `dotnet ef database update` not run
3. Database was reset but migrations not rerun

#### Solution
```bash
# 1. Check current migration status
dotnet ef migrations list

# 2. Apply all pending migrations
dotnet ef database update

# 3. Verify tables exist
psql -d echoes_database -c "\dt"
```

#### Prevention
- Add migration check to startup
- Document deployment process
- Include migration status in health check endpoint

```csharp
// Startup.cs - Check migrations on startup
public void Configure(IApplicationBuilder app, DatabaseContext context)
{
    // Apply migrations automatically (use with caution in production)
    context.Database.Migrate();
    
    // OR check if migrations are pending
    if (context.Database.GetPendingMigrations().Any())
    {
        throw new InvalidOperationException(
            "Database migrations pending! Run 'dotnet ef database update'"
        );
    }
}
```

---

### Error 42P01: Table Name Case Sensitivity

**Date:** 2026-01-18  
**Severity:** 🟡 Medium  
**Impact:** Queries fail with "relation not found"

#### Symptoms
```sql
-- This fails:
SELECT * FROM Characters WHERE id = '...';
-- Error: relation "Characters" does not exist

-- But this works:
SELECT * FROM characters WHERE id = '...';
```

#### Root Cause
PostgreSQL converts unquoted table names to lowercase. Entity Framework generates:
- Table name: `characters` (lowercase)
- Query: `SELECT * FROM Characters` (capitalized)

PostgreSQL interprets `Characters` as `characters`, which matches, but if table was created with quotes as `"Characters"`, it fails.

#### Solution
**Option 1:** Always use lowercase (RECOMMENDED)
```csharp
[Table("characters")]
public class Character { }
```

**Option 2:** Use quotes in migration (NOT RECOMMENDED)
```csharp
modelBuilder.Entity<Character>()
    .ToTable("\"Characters\"");  // Forces case-sensitive
```

**Fix Applied:** All Entity Framework models updated to use lowercase table names.

---

## GUID Serialization Issues

### Issue: GUID Format Mismatch Between C# and UE5

**Date:** 2026-01-20  
**Severity:** 🔴 Critical  
**Impact:** API responses fail to deserialize in UE5, breaking all communication

#### Symptoms

**C# API Response:**
```json
{
  "id": "550e8400-e29b-41d4-a716-446655440000",
  "name": "Pilot Alpha"
}
```

**UE5 Deserialization:**
```cpp
// UE5 expects:
{
  "id": "550E8400E29B41D4A716446655440000",  // No hyphens, uppercase
  "name": "Pilot Alpha"
}

// Actual result:
FString Id = "";  // Deserialization fails, empty string
```

#### Root Cause

| Platform | Format | Example |
|----------|--------|---------|
| C# .NET | Lowercase with hyphens | `550e8400-e29b-41d4-a716-446655440000` |
| UE5 C++ | Uppercase without hyphens | `550E8400E29B41D4A716446655440000` |
| JavaScript | Lowercase with hyphens | `550e8400-e29b-41d4-a716-446655440000` |

**Problem:** UE5 JSON deserializer doesn't recognize hyphened GUIDs.

#### Solution: GUID as String

**Backend Change:**
```csharp
// OLD (causing issues):
public class CharacterDataDto
{
    public Guid Id { get; set; }  // ❌ Serializes as "550e8400-..."
}

// NEW (works everywhere):
public class CharacterDataDto
{
    public string Id { get; set; }  // ✅ Serializes as string
}

// Mapping:
var dto = new CharacterDataDto
{
    Id = character.Id.ToString()  // Convert Guid → string
};
```

**UE5 Change:**
```cpp
// OLD (doesn't work):
USTRUCT()
struct FEchoesCharacter
{
    UPROPERTY()
    FGuid CharacterId;  // ❌ Fails to deserialize
};

// NEW (works):
USTRUCT()
struct FEchoesCharacter
{
    UPROPERTY()
    FString CharacterId;  // ✅ Works as string
};
```

#### Database Impact
Database still uses native `UUID` type (efficient storage):
```sql
CREATE TABLE characters (
    id UUID PRIMARY KEY DEFAULT gen_random_uuid(),  -- Still UUID
    ...
);
```

#### Conversion Layer
```csharp
// API receives string from UE5
[HttpGet("{id}")]
public async Task<IActionResult> GetCharacter(string id)
{
    // Parse string → Guid for database query
    if (!Guid.TryParse(id, out Guid characterId))
    {
        return BadRequest("Invalid character ID format");
    }
    
    var character = await _context.Characters.FindAsync(characterId);
    // ...
}
```

#### Benefits
✅ Cross-platform compatibility (C#, UE5, JavaScript)  
✅ Human-readable in logs and debugging  
✅ Copy-paste friendly  
✅ Database still uses efficient UUID type

---

## Foreign Key Constraint Violations

### Error 23503: Foreign Key Violation on Delete

**Date:** 2026-01-22  
**Severity:** 🟡 Medium  
**Impact:** Cannot delete accounts/characters, cascade deletes fail

#### Symptoms
```
Npgsql.PostgresException: 23503: update or delete on table "accounts" 
violates foreign key constraint "FK_characters_accounts_account_id" 
on table "characters"
```

#### Root Cause
Missing `ON DELETE CASCADE` in foreign key definitions.

**Original Migration:**
```csharp
modelBuilder.Entity<Character>()
    .HasOne(c => c.Account)
    .WithMany(a => a.Characters)
    .HasForeignKey(c => c.AccountId);
    // Missing: OnDelete behavior
```

#### Solution
Add explicit cascade behavior:

```csharp
modelBuilder.Entity<Character>()
    .HasOne(c => c.Account)
    .WithMany(a => a.Characters)
    .HasForeignKey(c => c.AccountId)
    .OnDelete(DeleteBehavior.Cascade);  // ✅ Added
```

**Generated SQL:**
```sql
ALTER TABLE characters
ADD CONSTRAINT FK_characters_accounts_account_id
FOREIGN KEY (account_id)
REFERENCES accounts(id)
ON DELETE CASCADE;  -- ✅ This line
```

#### Delete Behavior Matrix

| Parent | Child | Behavior | Reason |
|--------|-------|----------|--------|
| accounts | characters | CASCADE | Delete characters with account |
| characters | assets | CASCADE | Delete items with character |
| characters | character_locations | CASCADE | Delete location with character |
| solar_systems | planets | CASCADE | Universe regeneration |
| stations | character_locations | SET NULL | Don't delete characters if station removed |
| shop_items | player_inventory_items | RESTRICT | Can't delete purchased item |

---

### Error 23505: Unique Constraint Violation

**Date:** 2026-01-25  
**Severity:** 🟡 Medium  
**Impact:** Duplicate data prevents inserts

#### Symptoms
```
Npgsql.PostgresException: 23505: duplicate key value violates unique 
constraint "IX_accounts_username"
```

#### Root Cause
Attempting to create account with existing username.

#### Solution
```csharp
[HttpPost("register")]
public async Task<IActionResult> Register(RegisterRequest request)
{
    // Check if username exists
    if (await _context.Accounts.AnyAsync(a => a.Username == request.Username))
    {
        return BadRequest(new { error = "Username already taken" });
    }
    
    // Check if email exists
    if (await _context.Accounts.AnyAsync(a => a.Email == request.Email))
    {
        return BadRequest(new { error = "Email already registered" });
    }
    
    // Proceed with registration
    // ...
}
```

---

## World Generation Race Conditions

### Issue: WorldGenerator Missing Configuration

**Date:** 2026-01-28  
**Severity:** 🔴 Critical  
**Impact:** Universe doesn't generate, players spawn in void

#### Symptoms
- Server starts successfully
- Registers with backend API
- Receives universe configuration
- WorldGenerator spawned but doesn't generate objects
- No error messages in logs

#### Root Cause
**Race Condition** in delegate subscription:

```
Timeline:
T+0ms:   Server starts
T+50ms:  ServerManagementSubsystem initializes
T+100ms: HTTP request sent to backend
T+200ms: Backend responds with config
T+201ms: OnServerConfigReceived.Broadcast() called
T+300ms: WorldGenerator spawns
T+301ms: WorldGenerator::BeginPlay() subscribes to delegate
```

**Problem:** Delegate broadcast at T+201ms happened before subscription at T+301ms!

#### Solution
Check for cached config after subscription:

```cpp
// WorldGenerator::BeginPlay()
void AEchoesWorldGenerator::BeginPlay()
{
    Super::BeginPlay();
    
    // Subscribe to delegate
    ServerManagementSubsystem->OnServerConfigReceived.AddDynamic(
        this, &AEchoesWorldGenerator::OnServerConfigReceived
    );
    
    // ✅ FIX: Check if config already arrived
    if (ServerManagementSubsystem->IsServerRegistered() && 
        ServerManagementSubsystem->HasCachedConfig())
    {
        UE_LOG(LogEchoes, Log, TEXT("Config already cached - generating immediately"));
        
        if (ServerManagementSubsystem->IsRegionalCluster())
        {
            const FServerRegionalClusterConfig& Config = 
                ServerManagementSubsystem->GetRegionalConfig();
            OnRegionalClusterConfigReceived(Config);
        }
        else
        {
            const FServerSystemConfig& Config = 
                ServerManagementSubsystem->GetSystemConfig();
            OnServerConfigReceived(Config);
        }
    }
}
```

#### Prevention
- Cache all async responses in subsystems
- Provide `HasCachedData()` and `GetCachedData()` methods
- Check cache after delegate subscription
- Log both broadcast and subscription events

---

## Authentication & JWT Issues

### Issue: JWT Token Expiration Not Handled

**Date:** 2026-01-30  
**Severity:** 🟡 Medium  
**Impact:** Users logged out unexpectedly, API calls fail

#### Symptoms
```
HTTP 401 Unauthorized
{
  "error": "Token expired"
}
```

#### Root Cause
JWT tokens expire after configured time (default: 24 hours). Client doesn't refresh token automatically.

#### Solution
Implement token refresh flow:

```csharp
// Backend: Add refresh token endpoint
[HttpPost("refresh")]
public async Task<IActionResult> RefreshToken(RefreshTokenRequest request)
{
    // Validate refresh token
    var session = await _context.AccountSessions
        .FirstOrDefaultAsync(s => s.RefreshToken == request.RefreshToken 
                                && s.ExpiresAt > DateTime.UtcNow);
    
    if (session == null)
    {
        return Unauthorized(new { error = "Invalid or expired refresh token" });
    }
    
    // Generate new JWT
    var newToken = _jwtService.GenerateToken(session.AccountId);
    
    return Ok(new { token = newToken });
}
```

**Client: Auto-refresh on 401**
```csharp
// HttpClient interceptor
public class TokenRefreshHandler : DelegatingHandler
{
    protected override async Task<HttpResponseMessage> SendAsync(
        HttpRequestMessage request, 
        CancellationToken cancellationToken)
    {
        var response = await base.SendAsync(request, cancellationToken);
        
        if (response.StatusCode == HttpStatusCode.Unauthorized)
        {
            // Try to refresh token
            var newToken = await RefreshTokenAsync();
            if (newToken != null)
            {
                // Retry original request with new token
                request.Headers.Authorization = 
                    new AuthenticationHeaderValue("Bearer", newToken);
                response = await base.SendAsync(request, cancellationToken);
            }
        }
        
        return response;
    }
}
```

---

### Issue: Admin Role Not Recognized

**Date:** 2026-02-01  
**Severity:** 🟡 Medium  
**Impact:** Admin endpoints return 403 Forbidden

#### Symptoms
Admin user can't access admin endpoints despite having `is_admin = true` in database.

#### Root Cause
JWT token doesn't include role claim:

```csharp
// OLD (missing role):
var claims = new[]
{
    new Claim(ClaimTypes.NameIdentifier, character.Id.ToString()),
    new Claim(ClaimTypes.Email, account.Email)
    // ❌ Missing role claim
};
```

#### Solution
```csharp
// NEW (includes role):
var claims = new List<Claim>
{
    new Claim(ClaimTypes.NameIdentifier, character.Id.ToString()),
    new Claim(ClaimTypes.Email, account.Email),
    new Claim(ClaimTypes.Role, account.IsAdmin ? "Admin" : "Pilot")  // ✅ Added
};

if (account.IsAdmin)
{
    claims.Add(new Claim("IsAdmin", "true"));
}
```

**Verify in Controller:**
```csharp
[Authorize(Roles = "Admin")]
[HttpPost]
public IActionResult AdminOnlyAction()
{
    // This now works for admins
}
```

---

## Performance & Memory Issues

### Issue: Memory Leak in HTTP Requests

**Date:** 2026-02-02  
**Severity:** 🟡 Medium  
**Impact:** Server memory grows over time, eventually crashes

#### Symptoms
- Memory usage increases 100MB per hour
- Garbage collection doesn't reclaim memory
- Server crashes after 24-48 hours

#### Root Cause
HTTP clients not disposed properly:

```csharp
// ❌ BAD: Creates new HttpClient every call
public async Task<string> FetchData()
{
    var client = new HttpClient();  // Memory leak!
    var response = await client.GetStringAsync("https://api.example.com");
    return response;
    // HttpClient not disposed - socket remains open
}
```

#### Solution
Use IHttpClientFactory:

```csharp
// ✅ GOOD: Reuse HttpClient via factory
public class MyService
{
    private readonly IHttpClientFactory _httpClientFactory;
    
    public MyService(IHttpClientFactory httpClientFactory)
    {
        _httpClientFactory = httpClientFactory;
    }
    
    public async Task<string> FetchData()
    {
        var client = _httpClientFactory.CreateClient();
        var response = await client.GetStringAsync("https://api.example.com");
        return response;
        // Factory manages lifecycle - no leak
    }
}

// Startup.cs registration:
services.AddHttpClient();
```

---

### Issue: N+1 Query Problem

**Date:** 2026-02-03  
**Severity:** 🟡 Medium  
**Impact:** Slow API responses, database overload

#### Symptoms
```
GET /api/character/profile takes 5+ seconds
Database shows 100+ queries per request
```

#### Root Cause
Lazy loading causes N+1 queries:

```csharp
// ❌ BAD: Causes N+1 queries
var characters = await _context.Characters.ToListAsync();  // 1 query
foreach (var character in characters)
{
    var location = character.CharacterLocation;  // N queries (one per character!)
    // ...
}
```

#### Solution
Use eager loading with `.Include()`:

```csharp
// ✅ GOOD: Single query with JOIN
var characters = await _context.Characters
    .Include(c => c.CharacterLocation)  // JOIN in single query
    .Include(c => c.ActiveShip)
    .ToListAsync();

foreach (var character in characters)
{
    var location = character.CharacterLocation;  // No additional query
    // ...
}
```

**Performance Impact:**
- Before: 101 queries, 5000ms
- After: 1 query, 50ms
- **100x faster!**

---

## Lessons Learned

### Best Practices from Fixes

1. **Database Migrations**
   - Always check migration status on startup
   - Include migration status in health check
   - Document deployment procedures

2. **Cross-Platform Compatibility**
   - Use strings for GUIDs in DTOs
   - Test serialization with all clients (C#, C++, JavaScript)
   - Document data formats

3. **Foreign Keys**
   - Explicitly define ON DELETE behavior
   - Document cascade rules
   - Test deletion flows

4. **Async/Delegates**
   - Cache async responses in subsystems
   - Check cache after subscribing to delegates
   - Log both broadcast and subscription

5. **Authentication**
   - Include all required claims in JWT
   - Implement token refresh
   - Handle 401 responses gracefully

6. **Performance**
   - Use IHttpClientFactory for HTTP clients
   - Use `.Include()` for eager loading
   - Monitor database query counts
   - Profile memory usage regularly

---

## Testing Checklist

Before deploying:
- [ ] Run all database migrations
- [ ] Test GUID serialization in UE5 client
- [ ] Test account deletion (cascade)
- [ ] Test world generation multiple times (race condition)
- [ ] Test admin endpoints with admin JWT
- [ ] Load test API endpoints (N+1 queries)
- [ ] Monitor memory usage for 1 hour
- [ ] Test token expiration and refresh

---

## Conclusion

This fix log documents critical issues encountered during development of Echoes of Imperial. By documenting root causes and solutions, we:

✅ Prevent regression of fixed bugs  
✅ Educate new developers on common pitfalls  
✅ Build institutional knowledge  
✅ Improve code quality over time

**Remember:** Every bug is a learning opportunity. Document, fix, test, and move forward.

**Related Documentation:**
- [ARCHITECTURE.md](ARCHITECTURE.md) - System architecture
- [DATABASE_SCHEMA.md](DATABASE_SCHEMA.md) - Database structure
- [API_DOCUMENTATION.md](API_DOCUMENTATION.md) - API reference
- [UE5_INTEGRATION.md](UE5_INTEGRATION.md) - UE5 server integration
