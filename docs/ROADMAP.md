# Echoes of Imperial - Development Roadmap

> **Future Development Strategy & Recommendations**  
> Scalability, performance, and feature enhancements

**Version:** 2.0  
**Last Updated:** 2026-02-03  
**Planning Horizon:** 6-12 months

---

## Table of Contents

1. [Current State Assessment](#current-state-assessment)
2. [Scalability & Performance](#scalability--performance)
3. [Feature Enhancements](#feature-enhancements)
4. [Technical Debt & Refactoring](#technical-debt--refactoring)
5. [DevOps & Infrastructure](#devops--infrastructure)
6. [Security & Compliance](#security--compliance)
7. [Implementation Priority](#implementation-priority)

---

## Current State Assessment

### What's Working Well ✅

**Architecture:**
- 4-layer architecture (PostgreSQL → API → UE5 → Clients)
- Clean separation of concerns
- RESTful API design
- JWT authentication

**Backend:**
- 90+ API endpoints
- 50+ database tables
- ACID transactions for economy
- Entity Framework migrations

**Game Server:**
- Server registration system
- Dynamic world generation (72 objects)
- Personal hangar instances
- Server-authoritative gameplay

**Web Dashboard:**
- Blazor WebAssembly frontend
- Character profile viewer
- Imperial Store (shop)
- Wiki & news systems

### Areas for Improvement 🔧

**Performance:**
- No caching layer (Redis)
- Synchronous API calls from UE5
- No real-time updates (polling only)
- Database connection pooling could be optimized

**Scalability:**
- Single database server (SPOF)
- No load balancing for API
- No CDN for static assets
- Limited horizontal scaling

**Features:**
- No player-to-player trading
- No corporation/alliance system
- No market orders (only instant shop purchases)
- No contract system

**Monitoring:**
- Limited logging infrastructure
- No centralized error tracking
- No performance metrics dashboard
- Manual server health checks

---

## Scalability & Performance

### Priority 1: Implement SignalR for Real-Time Updates 🚀

**Problem:**
Currently, clients poll the API for updates:
- Wallet balance: Poll every 5 seconds
- News feed: Poll every 30 seconds
- Shop inventory: Poll on page load

**Impact:**
- Unnecessary network traffic
- Delayed updates (5-30 second lag)
- Increased server load
- Poor user experience

**Solution: SignalR WebSocket Hub**

#### Architecture

```
┌─────────────────────────────────────────────────┐
│  Blazor Client                                  │
│  ┌───────────────────────────────────────────┐ │
│  │  SignalR Client                           │ │
│  │  • Auto-reconnect                         │ │
│  │  • Subscribe to channels                  │ │
│  │  • Receive live updates                   │ │
│  └───────────────────────────────────────────┘ │
└──────────────────┬──────────────────────────────┘
                   │ WebSocket (wss://)
                   ▼
┌─────────────────────────────────────────────────┐
│  ASP.NET Core API                               │
│  ┌───────────────────────────────────────────┐ │
│  │  SignalR Hub                              │ │
│  │  • WalletHub                              │ │
│  │  • NewsHub                                │ │
│  │  • MarketHub                              │ │
│  │  • ChatHub (future)                       │ │
│  └───────────────────────────────────────────┘ │
└─────────────────────────────────────────────────┘
```

#### Implementation

**1. Backend: Create SignalR Hub**

```csharp
// Hubs/WalletHub.cs
public class WalletHub : Hub
{
    public async Task SubscribeToWallet(string characterId)
    {
        await Groups.AddToGroupAsync(Context.ConnectionId, $"wallet_{characterId}");
    }
    
    public async Task UnsubscribeFromWallet(string characterId)
    {
        await Groups.RemoveFromGroupAsync(Context.ConnectionId, $"wallet_{characterId}");
    }
}

// Service to notify wallet changes
public class WalletNotificationService
{
    private readonly IHubContext<WalletHub> _hubContext;
    
    public async Task NotifyBalanceChange(string characterId, long newBalance)
    {
        await _hubContext.Clients.Group($"wallet_{characterId}")
            .SendAsync("BalanceUpdated", new { balance = newBalance });
    }
}

// In ShopController after purchase:
await _walletNotificationService.NotifyBalanceChange(characterId, character.WalletBalance);
```

**2. Frontend: Connect to SignalR**

```csharp
// Blazor component
@inject NavigationManager Navigation
@inject IAuthService AuthService

@code {
    private HubConnection hubConnection;
    
    protected override async Task OnInitializedAsync()
    {
        // Create connection
        hubConnection = new HubConnectionBuilder()
            .WithUrl(Navigation.ToAbsoluteUri("/hubs/wallet"), options =>
            {
                options.AccessTokenProvider = () => Task.FromResult(AuthService.Token);
            })
            .WithAutomaticReconnect()
            .Build();
        
        // Subscribe to balance updates
        hubConnection.On<WalletUpdateDto>("BalanceUpdated", (update) =>
        {
            currentBalance = update.Balance;
            StateHasChanged();  // Update UI
        });
        
        // Start connection
        await hubConnection.StartAsync();
        
        // Subscribe to character's wallet
        await hubConnection.SendAsync("SubscribeToWallet", characterId);
    }
}
```

#### Benefits

✅ **Real-time updates** - Instant wallet/news/market updates  
✅ **Reduced server load** - No polling, 90% less API calls  
✅ **Better UX** - Immediate feedback on purchases  
✅ **Scalable** - SignalR handles 10,000+ concurrent connections  
✅ **Bi-directional** - Server can push updates to clients

#### Use Cases

1. **Wallet Balance**: Update instantly after purchase
2. **News Feed**: Push new edicts as they're published
3. **Market Prices**: Real-time price updates
4. **Corporation Chat**: In-game messaging (future)
5. **Fleet Invitations**: Real-time invite notifications
6. **Trade Requests**: Player-to-player trading

**Estimated Effort:** 2-3 weeks  
**Priority:** HIGH

---

### Priority 2: Implement Redis Caching Layer 🚀

**Problem:**
Frequently accessed data is queried from PostgreSQL every time:
- Universe data (planets, systems) - rarely changes
- Item types (ships, modules) - static
- Shop catalog - changes infrequently

**Impact:**
- High database load
- Slow response times (100-200ms per query)
- Unnecessary compute

**Solution: Redis Cache**

#### Architecture

```
┌─────────────────────────────────────────────────┐
│  API Request                                    │
└──────────────────┬──────────────────────────────┘
                   ▼
          ┌────────────────┐
          │  Check Redis   │
          └────────┬───────┘
                   │
        ┌──────────┴──────────┐
        │                     │
        ▼                     ▼
    ┌───────┐           ┌──────────┐
    │ Cache │           │ Cache    │
    │ Hit   │           │ Miss     │
    └───┬───┘           └────┬─────┘
        │                    │
        │                    ▼
        │            ┌─────────────────┐
        │            │ Query PostgreSQL│
        │            └────────┬────────┘
        │                     │
        │                     ▼
        │            ┌─────────────────┐
        │            │  Store in Redis │
        │            └────────┬────────┘
        │                     │
        └─────────────────────┘
                   ▼
          ┌────────────────┐
          │  Return Data   │
          └────────────────┘
```

#### Implementation

**1. Install Redis**

```bash
# Docker
docker run -d -p 6379:6379 redis:latest

# Or install locally
# Windows: https://github.com/microsoftarchive/redis/releases
# Linux: apt install redis-server
```

**2. Add NuGet Package**

```bash
dotnet add package StackExchange.Redis
dotnet add package Microsoft.Extensions.Caching.StackExchangeRedis
```

**3. Configure in Startup**

```csharp
// Program.cs
builder.Services.AddStackExchangeRedisCache(options =>
{
    options.Configuration = builder.Configuration.GetConnectionString("Redis");
    options.InstanceName = "EchoesCache_";
});

// appsettings.json
{
  "ConnectionStrings": {
    "Redis": "localhost:6379"
  }
}
```

**4. Create Cache Service**

```csharp
public interface ICacheService
{
    Task<T> GetOrSetAsync<T>(string key, Func<Task<T>> factory, TimeSpan expiration);
    Task<T> GetAsync<T>(string key);
    Task SetAsync<T>(string key, T value, TimeSpan expiration);
    Task RemoveAsync(string key);
}

public class RedisCacheService : ICacheService
{
    private readonly IDistributedCache _cache;
    
    public async Task<T> GetOrSetAsync<T>(string key, Func<Task<T>> factory, TimeSpan expiration)
    {
        // Try to get from cache
        var cached = await GetAsync<T>(key);
        if (cached != null) return cached;
        
        // Cache miss - call factory
        var value = await factory();
        
        // Store in cache
        await SetAsync(key, value, expiration);
        
        return value;
    }
    
    public async Task<T> GetAsync<T>(string key)
    {
        var data = await _cache.GetStringAsync(key);
        if (data == null) return default;
        return JsonSerializer.Deserialize<T>(data);
    }
    
    public async Task SetAsync<T>(string key, T value, TimeSpan expiration)
    {
        var json = JsonSerializer.Serialize(value);
        await _cache.SetStringAsync(key, json, new DistributedCacheEntryOptions
        {
            AbsoluteExpirationRelativeToNow = expiration
        });
    }
    
    public async Task RemoveAsync(string key)
    {
        await _cache.RemoveAsync(key);
    }
}
```

**5. Use in Controllers**

```csharp
[HttpGet("systems")]
public async Task<IActionResult> GetSolarSystems()
{
    // Cache for 1 hour (universe data rarely changes)
    var systems = await _cacheService.GetOrSetAsync(
        "universe:systems",
        async () => await _context.SolarSystems
            .Include(s => s.Constellation)
            .Include(s => s.Region)
            .ToListAsync(),
        TimeSpan.FromHours(1)
    );
    
    return Ok(systems);
}

[HttpGet("itemtype/{typeId}")]
public async Task<IActionResult> GetItemType(int typeId)
{
    // Cache for 24 hours (item types are static)
    var itemType = await _cacheService.GetOrSetAsync(
        $"itemtype:{typeId}",
        async () => await _context.ItemTypesInventory.FindAsync(typeId),
        TimeSpan.FromHours(24)
    );
    
    return Ok(itemType);
}
```

**6. Cache Invalidation**

```csharp
// When item type is updated (admin action)
[HttpPut("itemtype/{typeId}")]
[Authorize(Roles = "Admin")]
public async Task<IActionResult> UpdateItemType(int typeId, ItemTypeDto dto)
{
    // Update in database
    var itemType = await _context.ItemTypesInventory.FindAsync(typeId);
    // ... update properties
    await _context.SaveChangesAsync();
    
    // Invalidate cache
    await _cacheService.RemoveAsync($"itemtype:{typeId}");
    
    return Ok();
}
```

#### Cache Strategy by Data Type

| Data Type | Cache Duration | Invalidation |
|-----------|----------------|--------------|
| **Universe Data** | 1 hour | Admin regeneration |
| **Item Types** | 24 hours | Admin update |
| **Shop Catalog** | 5 minutes | Admin add/edit/delete |
| **Character Profile** | 1 minute | On any character update |
| **News Feed** | 5 minutes | Admin post/delete |

#### Benefits

✅ **10x faster responses** - 10ms from cache vs 100ms from database  
✅ **Reduced database load** - 80% fewer queries  
✅ **Horizontal scaling** - Shared cache across API servers  
✅ **Cost savings** - Smaller database instance needed

**Estimated Effort:** 1-2 weeks  
**Priority:** HIGH

---

### Priority 3: Database Read Replicas

**Problem:**
Single PostgreSQL instance handles all reads and writes. High read load impacts write performance.

**Solution:**
- **Primary DB**: Handles all writes
- **Read Replicas (2+)**: Handle all read-only queries

**Benefits:**
- Distribute read load across multiple servers
- Faster read queries
- Better write performance on primary
- High availability (failover to replica)

**Estimated Effort:** 1 week  
**Priority:** MEDIUM

---

### Priority 4: API Load Balancing

**Problem:**
Single API server instance. No horizontal scaling.

**Solution:**

```
┌─────────────────────────────────────────────┐
│  Nginx Load Balancer                        │
│  (Round-robin or Least Connections)         │
└──────────────┬──────────────────────────────┘
               │
    ┌──────────┼──────────┐
    │          │          │
    ▼          ▼          ▼
┌───────┐  ┌───────┐  ┌───────┐
│ API-1 │  │ API-2 │  │ API-3 │
└───┬───┘  └───┬───┘  └───┬───┘
    │          │          │
    └──────────┼──────────┘
               ▼
       ┌────────────────┐
       │   PostgreSQL   │
       │   + Redis      │
       └────────────────┘
```

**Benefits:**
- Handle 3x more requests
- Zero-downtime deployments
- Automatic failover

**Estimated Effort:** 3 days  
**Priority:** MEDIUM

---

## Feature Enhancements

### Priority 1: Player-to-Player Trading

**Description:**
Allow players to trade items and credits directly.

**Implementation:**
1. Create `trades` table
2. Add `/api/trade` endpoints
3. Implement trade UI in Blazor
4. Add trade notifications (SignalR)

**Estimated Effort:** 2 weeks

---

### Priority 2: Corporation System

**Description:**
Players can form corporations with shared hangars and wallets.

**Tables:**
- `corporations`
- `corporation_members`
- `corporation_roles`
- `corporation_hangars`

**Features:**
- Create/join/leave corporation
- Corporation hierarchy (CEO, Directors, Members)
- Shared hangar (corporation assets)
- Corporation wallet
- Corporation chat

**Estimated Effort:** 4 weeks

---

### Priority 3: Market Orders

**Description:**
Buy/sell orders instead of instant shop purchases.

**Features:**
- Post sell orders (price, quantity, duration)
- Post buy orders
- Order matching system
- Market history graphs
- Regional markets

**Estimated Effort:** 3 weeks

---

### Priority 4: Manufacturing & Research

**Description:**
Craft items from blueprints and materials.

**Features:**
- Blueprint system
- Material requirements
- Manufacturing time
- Research (improve blueprint efficiency)
- Invention (create tech 2 items)

**Estimated Effort:** 6 weeks

---

## Technical Debt & Refactoring

### Priority 1: Migrate to Minimal APIs

**Current:** Traditional controller-based APIs  
**Target:** Minimal APIs (.NET 8 feature)

**Benefits:**
- Less boilerplate code
- Better performance
- Easier testing

**Effort:** 2 weeks

---

### Priority 2: Add Comprehensive Unit Tests

**Current:** No unit tests  
**Target:** 80% code coverage

**Tools:**
- xUnit for test framework
- Moq for mocking
- FluentAssertions for readable tests

**Effort:** 4 weeks (ongoing)

---

### Priority 3: Implement CQRS Pattern

**Current:** Single models for read and write  
**Target:** Separate command and query models

**Benefits:**
- Optimized read models
- Clear separation of concerns
- Easier to scale reads separately

**Effort:** 6 weeks

---

## DevOps & Infrastructure

### Priority 1: Continuous Integration/Deployment

**Tools:**
- GitHub Actions for CI/CD
- Docker containers
- Kubernetes for orchestration

**Pipeline:**
```
Git Push → Build → Test → Docker Build → Deploy to K8s
```

**Effort:** 2 weeks

---

### Priority 2: Centralized Logging

**Tool:** Elasticsearch + Logstash + Kibana (ELK Stack)

**Features:**
- Centralized log aggregation
- Full-text search
- Real-time monitoring
- Alert on errors

**Effort:** 1 week

---

### Priority 3: Application Performance Monitoring

**Tool:** Application Insights or DataDog

**Metrics:**
- Response times
- Error rates
- Database query performance
- Memory usage
- CPU usage

**Effort:** 3 days

---

## Security & Compliance

### Priority 1: Rate Limiting

**Implementation:**
```csharp
services.AddRateLimiter(options =>
{
    options.AddFixedWindowLimiter("api", policy =>
    {
        policy.Window = TimeSpan.FromMinutes(1);
        policy.PermitLimit = 60;
    });
});
```

**Effort:** 2 days

---

### Priority 2: Input Validation & Sanitization

**Tools:**
- FluentValidation for request validation
- HtmlSanitizer for user-generated HTML

**Effort:** 1 week

---

### Priority 3: Security Audit

**Tasks:**
- Penetration testing
- SQL injection checks
- XSS vulnerability checks
- OWASP Top 10 compliance

**Effort:** 2 weeks (external audit)

---

## Implementation Priority

### Phase 1: Q1 2026 (Immediate - 3 months)

| Task | Effort | Priority | Impact |
|------|--------|----------|--------|
| SignalR Real-Time Updates | 3 weeks | 🔴 Critical | High |
| Redis Caching | 2 weeks | 🔴 Critical | High |
| Rate Limiting | 2 days | 🟡 High | Medium |
| Centralized Logging | 1 week | 🟡 High | Medium |

**Total:** ~7 weeks

### Phase 2: Q2 2026 (Short-term - 3 months)

| Task | Effort | Priority | Impact |
|------|--------|----------|--------|
| Database Read Replicas | 1 week | 🟡 High | High |
| API Load Balancing | 3 days | 🟡 High | High |
| Player-to-Player Trading | 2 weeks | 🟢 Medium | High |
| Unit Tests (Start) | 2 weeks | 🟢 Medium | Medium |

**Total:** ~6 weeks

### Phase 3: Q3-Q4 2026 (Long-term - 6 months)

| Task | Effort | Priority | Impact |
|------|--------|----------|--------|
| Corporation System | 4 weeks | 🟢 Medium | High |
| Market Orders | 3 weeks | 🟢 Medium | High |
| Manufacturing | 6 weeks | 🔵 Low | Medium |
| CQRS Refactoring | 6 weeks | 🔵 Low | Medium |

**Total:** ~19 weeks

---

## Success Metrics

### Performance Targets

| Metric | Current | Target | Timeline |
|--------|---------|--------|----------|
| API Response Time | 100ms | 20ms | Q1 2026 |
| Database Load | 100% | 40% | Q1 2026 |
| Concurrent Users | 100 | 1000 | Q2 2026 |
| Server Uptime | 95% | 99.9% | Q2 2026 |
| Cache Hit Rate | 0% | 80% | Q1 2026 |

### User Experience Targets

| Metric | Current | Target | Timeline |
|--------|---------|--------|----------|
| Wallet Update Latency | 5s (polling) | <100ms | Q1 2026 |
| News Feed Updates | 30s (polling) | Real-time | Q1 2026 |
| Shop Load Time | 500ms | 50ms | Q1 2026 |
| Login Success Rate | 95% | 99% | Q2 2026 |

---

## Conclusion

This roadmap provides a clear path for scaling Echoes of Imperial from a prototype to a production-ready MMO platform.

**Immediate Focus (Next 3 months):**
1. ✅ SignalR for real-time updates
2. ✅ Redis caching for performance
3. ✅ Rate limiting for security
4. ✅ Centralized logging for monitoring

**Key Success Factors:**
- Incremental implementation (don't try to do everything at once)
- Measure before and after each change
- Prioritize user-facing improvements
- Maintain code quality throughout

**Next Steps:**
1. Review and approve roadmap with stakeholders
2. Create detailed implementation plans for Phase 1 tasks
3. Set up development/staging environments
4. Begin Phase 1 implementation

---

**Last Updated:** 2026-02-03  
**Next Review:** 2026-03-01  
**Owner:** Development Team

**Related Documentation:**
- [ARCHITECTURE.md](ARCHITECTURE.md) - System architecture
- [DATABASE_SCHEMA.md](DATABASE_SCHEMA.md) - Database structure
- [API_DOCUMENTATION.md](API_DOCUMENTATION.md) - API reference
- [UE5_INTEGRATION.md](UE5_INTEGRATION.md) - UE5 server integration
- [FIX_LOG.md](FIX_LOG.md) - Critical bug fixes
