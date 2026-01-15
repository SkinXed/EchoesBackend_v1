# Server Controllers Architecture

## Overview
This document describes the refactored server controller architecture implemented to improve separation of concerns, maintainability, and code organization.

## Architecture Principles

### Separation of Concerns
The server functionality has been split into two distinct domains:

1. **Management Domain** (`Controllers/Management/ServerManagementController.cs`)
   - Server lifecycle management (registration, unregistration)
   - Health monitoring (heartbeat)
   - Cluster statistics and monitoring
   - Administrative operations

2. **Gameplay Domain** (`Controllers/Gameplay/GameServerController.cs`)
   - Client-facing operations
   - System data retrieval
   - Connection routing
   - Gameplay endpoints

### Design Patterns

#### Unified Error Handling
All controllers follow a consistent error handling pattern:
```csharp
try
{
    // Business logic
    return Ok(response);
}
catch (ArgumentException ex)
{
    _logger.LogWarning(ex, "Context");
    return BadRequest(new { success = false, error = ex.Message });
}
catch (Exception ex)
{
    _logger.LogError(ex, "Context");
    return StatusCode(500, new { success = false, error = "Internal server error" });
}
```

Benefits:
- Consistent logging for debugging
- Secure error messages (no exception details exposed)
- Proper HTTP status codes
- Uniform response structure

#### DTO-Based Communication
All endpoints use strongly-typed DTOs located in `Models/DTOs/Server/`:
- Input validation via data annotations
- XML documentation for all properties
- Explicit nullability handling
- Type safety throughout the pipeline

## Directory Structure

```
Models/
└── DTOs/
    └── Server/
        ├── RegisterServerRequest.cs      # Server registration payload
        ├── HeartbeatRequest.cs            # Health update payload
        ├── ConnectionRequest.cs           # Client connection request
        ├── ConnectionInfoResponse.cs      # Connection routing response
        ├── ServerStatsResponse.cs         # Cluster statistics
        └── ServerListResponse.cs          # Server list with metadata

Controllers/
├── Management/
│   └── ServerManagementController.cs      # Server admin operations
└── Gameplay/
    └── GameServerController.cs            # Client-facing operations

Services/
└── ServerRequests/
    ├── IGameServerService.cs              # Service interface
    └── GameServerService.cs               # Business logic implementation
```

## Controller Details

### ServerManagementController
**Route:** `/api/server-management`

**Responsibilities:**
- Accept server registrations from game server instances
- Process periodic heartbeats with metrics
- Handle graceful server shutdowns
- Provide cluster statistics
- List and filter registered servers

**Key Methods:**
- `RegisterServer(RegisterServerRequest)` - Register new server instance
- `Heartbeat(HeartbeatRequest)` - Update server health and metrics
- `UnregisterServer(string instanceId)` - Remove server from cluster
- `GetStats()` - Retrieve cluster-wide statistics
- `GetServers(filters)` - List servers with optional filtering

### GameServerController
**Route:** `/api/gameserver`

**Responsibilities:**
- Serve solar system data to clients
- Route clients to appropriate game servers
- Handle connection requests
- Provide API health checks

**Key Methods:**
- `GetSystemData(Guid systemId)` - Retrieve full system information
- `GetServerForSystem(Guid systemId)` - Find best server for system
- `RequestConnection(ConnectionRequest)` - Request connection with routing info
- `Handshake()` - Health check endpoint

## Data Flow

### Server Registration Flow
```
Game Server → POST /api/server-management/register
                  ↓
         RegisterServerRequest (validated)
                  ↓
         IGameServerService.RegisterServerAsync()
                  ↓
         Database (GameServerNode created)
                  ↓
         Response with server ID and type
```

### Client Connection Flow
```
Game Client → POST /api/gameserver/request-connection
                  ↓
         ConnectionRequest (validated)
                  ↓
         IGameServerService.GetConnectionForSystemAsync()
                  ↓
         Server selection logic:
           1. Check for dedicated system server
           2. Find regional cluster server
           3. Fallback to any available server
                  ↓
         ConnectionInfoResponse with routing info
```

### Heartbeat Flow
```
Game Server → POST /api/server-management/heartbeat (every 30s)
                  ↓
         HeartbeatRequest (status, metrics)
                  ↓
         IGameServerService.UpdateHeartbeatAsync()
                  ↓
         Database (GameServerNode updated)
                  ↓
         Response with next heartbeat interval
```

## Service Layer

### IGameServerService
Interface defining server management operations:
- `RegisterServerAsync(RegisterServerRequest)` - Register server
- `UpdateHeartbeatAsync(HeartbeatRequest)` - Process heartbeat
- `GetConnectionForSystemAsync(Guid)` - Find server for system
- `UnregisterServerAsync(string)` - Remove server
- `GetAllServersAsync()` - List all servers

### GameServerService
Implementation with business logic:
- Server registration with duplicate handling
- Load balancing and server selection
- Health monitoring and timeout detection
- Transaction management for consistency

## Security Considerations

1. **Exception Handling**: Exception messages are never exposed in API responses
2. **Input Validation**: All inputs validated using data annotations
3. **Logging**: Detailed logging for debugging without exposing to clients
4. **Type Safety**: Strongly-typed DTOs prevent injection attacks

## Monitoring & Observability

### Logging
All operations are logged with context:
```csharp
_logger.LogInformation("Player {PlayerId} requesting connection to {SystemId}", 
    playerId, systemId);
```

### Metrics Available
Via `/api/server-management/stats`:
- Total servers
- Online/Starting servers
- Total players
- Capacity utilization
- Server type breakdown
- Average load

## Performance Considerations

1. **Database Queries**: Optimized with proper indexes on LastHeartbeat, RegionId, SolarSystemId
2. **Caching**: Consider caching server list for high-traffic scenarios
3. **Connection Pooling**: Entity Framework handles connection pooling automatically
4. **Async Operations**: All database operations are async for better scalability

## Future Enhancements

1. **Health Checks**: Add ASP.NET Core health check integration
2. **Metrics Export**: Prometheus metrics endpoint
3. **Rate Limiting**: Add rate limiting for registration endpoints
4. **API Versioning**: Support multiple API versions for gradual migration
5. **WebSocket Support**: Real-time server status updates
6. **Auto-scaling**: Automatic server provisioning based on load

## Testing Strategy

### Unit Tests
- Test DTO validation
- Test service layer logic
- Mock database context

### Integration Tests
- Test full endpoint flows
- Verify error handling
- Test authentication/authorization

### Load Tests
- Test heartbeat handling under load
- Test connection routing at scale
- Verify server selection performance

## Maintenance

### Adding New Endpoints
1. Add to appropriate controller (Management or Gameplay)
2. Create/update DTOs with XML documentation
3. Implement business logic in service layer
4. Add error handling following established pattern
5. Update migration guide if needed

### Modifying Existing Endpoints
1. Consider backward compatibility
2. Update DTOs while maintaining old structure if possible
3. Add API versioning if breaking changes are needed
4. Update documentation

## References

- [ASP.NET Core Controllers](https://docs.microsoft.com/en-us/aspnet/core/web-api/)
- [Entity Framework Core](https://docs.microsoft.com/en-us/ef/core/)
- [RESTful API Design](https://restfulapi.net/)
