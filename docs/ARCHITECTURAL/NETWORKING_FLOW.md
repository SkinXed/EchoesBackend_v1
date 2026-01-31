# Networking Flow and Architecture

## Overview

This document describes the network architecture and data flow for the Echoes MMO backend system.

## Architecture Pattern

The Echoes backend follows a **three-tier architecture**:

```
[Unreal Engine 5 Client] <-> [ASP.NET Core API] <-> [PostgreSQL Database]
```

### Principle: "Postgres is Truth"

All authoritative game state lives in the PostgreSQL database. The backend API serves as a stateless gateway that:
- Validates client requests
- Enforces business logic
- Reads/writes to the database
- Returns responses to clients

## Communication Protocols

### HTTP/HTTPS REST API
- **Primary protocol** for client-server communication
- JSON payloads for data exchange
- JWT-based authentication
- Server secret for internal service calls

### WebSocket (Future)
- Planned for real-time updates
- Combat events
- Position synchronization
- Chat messages

## Network Flow Diagrams

### Authentication Flow

```
Client -> API: POST /api/auth/login {username, password}
API -> DB: Query user credentials
DB -> API: User data + hash
API -> Client: JWT token + refresh token
```

### Ship Stats Retrieval

```
Client -> API: GET /api/ship/{id}/stats [X-Server-Secret]
API -> DB: Query ship base stats
API -> DB: Query fitted modules
DB -> API: Ship + modules data
API -> API: Calculate total mass, stats
API -> Client: ShipStatsDto
Client -> Client: Apply stats to physics component
```

### Module Fitting

```
Client -> API: POST /api/ship/{id}/modules {moduleTypeId, slot}
API -> DB: Validate module exists
API -> DB: Validate slot available
API -> DB: Insert ship_instance_module
DB -> API: Confirmation
API -> Client: Updated ship stats
Client -> Client: Refresh ship configuration
```

## API Endpoint Categories

### Authentication & Authorization
- `POST /api/auth/login` - User login
- `POST /api/auth/register` - New account
- `POST /api/auth/refresh` - Refresh JWT token
- `POST /api/auth/logout` - Logout

### Ship Management
- `GET /api/ship/{id}/stats` - Get ship statistics
- `POST /api/ship/{id}/modules` - Add module to ship
- `DELETE /api/ship/{id}/modules/{moduleId}` - Remove module
- `GET /api/ship/{id}/fitting` - Get full ship fitting

### Inventory
- `GET /api/inventory/{characterId}` - Get character inventory
- `POST /api/inventory/transfer` - Transfer items
- `GET /api/inventory/ships` - List owned ships

### Universe & Navigation
- `GET /api/universe/systems` - Get star systems
- `GET /api/universe/stations` - Get stations
- `POST /api/navigation/warp` - Initiate warp

## Security Considerations

### Authentication Layers

1. **Client Authentication**: JWT tokens for player sessions
2. **Server Authentication**: X-Server-Secret header for internal calls
3. **Request Validation**: Input validation on all endpoints
4. **Rate Limiting**: Protection against abuse

### Data Validation

- All inputs sanitized and validated
- Database queries use parameterized statements
- Authorization checks on every request
- Ownership verification for resources

## Performance Optimization

### Caching Strategy
- Redis for frequently accessed data (future)
- In-memory caching for static game data
- Database connection pooling

### Database Optimization
- Indexes on frequently queried columns
- Efficient JOIN operations
- Pagination for large result sets
- Materialized views for complex aggregations

## Monitoring & Logging

### Health Checks
- `/health` - Overall system health
- Database connectivity
- External service status

### Logging Levels
- **ERROR**: Critical failures requiring immediate attention
- **WARN**: Potential issues or degraded performance
- **INFO**: Normal operations and state changes
- **DEBUG**: Detailed diagnostic information

## Regional Cluster Architecture (Future)

```
                    [Global Load Balancer]
                            |
        +-------------------+-------------------+
        |                   |                   |
   [US Cluster]      [EU Cluster]      [ASIA Cluster]
        |                   |                   |
    [DB Master]         [DB Master]         [DB Master]
        |                   |                   |
  [Read Replicas]     [Read Replicas]     [Read Replicas]
```

### Cross-Region Considerations
- Data residency requirements
- Latency optimization
- Character transfer mechanisms
- Market data synchronization

## Network Protocols & Formats

### Request Format
```http
POST /api/endpoint HTTP/1.1
Host: api.echoes.game
Authorization: Bearer {jwt_token}
X-Server-Secret: {server_secret}
Content-Type: application/json

{
  "field": "value"
}
```

### Response Format
```json
{
  "success": true,
  "data": { ... },
  "error": null,
  "timestamp": "2026-01-31T19:38:00Z"
}
```

## Error Handling

### HTTP Status Codes
- `200 OK` - Successful request
- `201 Created` - Resource created
- `400 Bad Request` - Invalid input
- `401 Unauthorized` - Missing/invalid authentication
- `403 Forbidden` - Insufficient permissions
- `404 Not Found` - Resource doesn't exist
- `500 Internal Server Error` - Server-side failure

### Error Response Format
```json
{
  "success": false,
  "data": null,
  "error": {
    "code": "INVALID_INPUT",
    "message": "Ship module slot is already occupied",
    "details": { ... }
  },
  "timestamp": "2026-01-31T19:38:00Z"
}
```

## Future Enhancements

- [ ] WebSocket implementation for real-time events
- [ ] Redis caching layer
- [ ] GraphQL API for flexible queries
- [ ] gRPC for high-performance internal services
- [ ] Message queue for async processing (RabbitMQ/Kafka)
- [ ] Service mesh for microservices architecture

---

**Status**: Active Development  
**Last Updated**: 2026-01-31  
**Owner**: Backend Architecture Team
