# Stargate Jump System - Complete Implementation Guide

## Overview

The Stargate Jump System enables players to travel between different game systems (solar systems, sectors, etc.) using stargate portals. The system implements secure server-to-server transitions with state preservation and ticket-based authentication.

## Architecture

### Flow Diagram

```
┌─────────────┐         ┌──────────────┐         ┌─────────────┐         ┌──────────────┐
│   Client    │         │  Source UE   │         │   Backend   │         │  Dest UE     │
│             │         │   Server     │         │    API      │         │   Server     │
└──────┬──────┘         └──────┬───────┘         └──────┬──────┘         └──────┬───────┘
       │                       │                        │                        │
       │ Enter Stargate        │                        │                        │
       ├──────────────────────>│                        │                        │
       │                       │                        │                        │
       │                       │ 1. Save State          │                        │
       │                       │    (Persistence)       │                        │
       │                       │                        │                        │
       │                       │ 2. Request Jump Ticket │                        │
       │                       ├───────────────────────>│                        │
       │                       │    POST /api/jump/     │                        │
       │                       │         request        │                        │
       │                       │                        │                        │
       │                       │    3. Validate &       │                        │
       │                       │       Issue Ticket     │                        │
       │                       │<───────────────────────┤                        │
       │                       │    {ticket, server}    │                        │
       │                       │                        │                        │
       │ 4. Client Travel RPC  │                        │                        │
       │<──────────────────────┤                        │                        │
       │  (IP:Port?Ticket=...) │                        │                        │
       │                       │                        │                        │
       │ 5. Connect to New Server                       │                        │
       ├────────────────────────────────────────────────┼───────────────────────>│
       │                       │                        │                        │
       │                       │                        │ 6. Validate Ticket     │
       │                       │                        │<───────────────────────┤
       │                       │                        │    POST /api/jump/     │
       │                       │                        │         redeem         │
       │                       │                        │                        │
       │                       │                        │ 7. Mark Redeemed       │
       │                       │                        ├───────────────────────>│
       │                       │                        │    {valid: true}       │
       │                       │                        │                        │
       │                       │                        │    8. Spawn Player     │
       │<────────────────────────────────────────────────────────────────────────┤
       │      9. Load State & Begin Play                │                        │
```

### Components

1. **Backend API (ASP.NET Core)**
   - JumpController - Manages ticket lifecycle
   - Memory cache - Stores temporary tickets
   - Security validation - X-Server-Secret authentication

2. **UE5 Source Server**
   - AEchoesStargate - Physical gate actor with triggers
   - UEchoesJumpSubsystem - Jump request coordination
   - UEchoesPersistenceSubsystem - State saving

3. **UE5 Destination Server**
   - UEchoesJumpSubsystem - Ticket validation
   - GameMode - Spawn logic with validated state

## Backend Implementation

### Endpoints

#### POST /api/jump/request

**Purpose:** Request a jump ticket from source server

**Authentication:** X-Server-Secret header required

**Request Body:**
```json
{
  "characterId": "12345678-1234-1234-1234-123456789abc",
  "stargateId": "87654321-4321-4321-4321-cba987654321",
  "sourceSystemId": "aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa",
  "destinationSystemId": "bbbbbbbb-bbbb-bbbb-bbbb-bbbbbbbbbbbb"
}
```

**Success Response (200):**
```json
{
  "success": true,
  "ticketId": "99999999-9999-9999-9999-999999999999",
  "destinationServerAddress": "192.168.1.100:7777",
  "destinationSystem": {
    "systemId": "bbbbbbbb-bbbb-bbbb-bbbb-bbbbbbbbbbbb",
    "systemName": "Alpha Centauri",
    "securityStatus": 0.8
  },
  "expiresAt": "2026-02-07T03:23:00Z",
  "message": "Jump ticket issued successfully"
}
```

**Error Response (400/404/401):**
```json
{
  "success": false,
  "message": "Stargate is not operational",
  "denialReason": "Stargate offline"
}
```

**Validation Rules:**
- Character must exist in database
- Stargate must exist and be operational
- Destination system must match stargate configuration
- Character cannot have another pending jump ticket
- X-Server-Secret must be valid

#### POST /api/jump/redeem

**Purpose:** Validate and consume jump ticket on destination server

**Authentication:** X-Server-Secret header required

**Request Body:**
```json
{
  "ticketId": "99999999-9999-9999-9999-999999999999",
  "characterId": "12345678-1234-1234-1234-123456789abc",
  "systemId": "bbbbbbbb-bbbb-bbbb-bbbb-bbbbbbbbbbbb"
}
```

**Success Response (200):**
```json
{
  "valid": true,
  "characterId": "12345678-1234-1234-1234-123456789abc",
  "destinationSystemId": "bbbbbbbb-bbbb-bbbb-bbbb-bbbbbbbbbbbb",
  "sourceSystemId": "aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa",
  "message": "Ticket validated successfully"
}
```

**Error Response (400/404):**
```json
{
  "valid": false,
  "message": "Ticket expired",
  "invalidReason": "Ticket expiration time passed"
}
```

**Validation Rules:**
- Ticket must exist in cache
- Ticket must not be expired (5 min TTL)
- Ticket must not be already redeemed
- Character ID must match ticket
- System ID must match ticket destination
- Character must exist in database

#### GET /api/jump/ticket/{ticketId}

**Purpose:** Debug endpoint to check ticket status

**Authentication:** X-Server-Secret header required

**Response (200):**
```json
{
  "ticketId": "99999999-9999-9999-9999-999999999999",
  "characterId": "12345678-1234-1234-1234-123456789abc",
  "sourceSystemId": "aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa",
  "destinationSystemId": "bbbbbbbb-bbbb-bbbb-bbbb-bbbbbbbbbbbb",
  "status": "Pending",
  "issuedAt": "2026-02-07T03:18:00Z",
  "expiresAt": "2026-02-07T03:23:00Z",
  "redeemedAt": null,
  "isExpired": false
}
```

### Configuration

**appsettings.json:**
```json
{
  "Server": {
    "Secret": "UE5-Server-Secret-Change-Me-In-Production"
  },
  "ServerAddresses": {
    "bbbbbbbb-bbbb-bbbb-bbbb-bbbbbbbbbbbb": "192.168.1.100:7777",
    "cccccccc-cccc-cccc-cccc-cccccccccccc": "192.168.1.101:7777"
  }
}
```

## UE5 Implementation

### UEchoesJumpSubsystem

**Purpose:** GameInstanceSubsystem that manages jump requests and ticket validation

**Configuration (DefaultGame.ini):**
```ini
[/Script/Echoes.EchoesJumpSubsystem]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=UE5-Server-Secret-Change-Me-In-Production
bEnableDebugLogging=true
```

**Key Methods:**

```cpp
// Request jump from source server
void ServerOnly_RequestJump(
    FGuid CharacterId,
    FGuid StargateId,
    FGuid SourceSystemId,
    FGuid DestinationSystemId,
    APawn* PlayerPawn);

// Validate ticket on destination server
void ServerOnly_ValidateJumpTicket(
    const FString& TicketId,
    FGuid CharacterId,
    FGuid SystemId,
    const FOnJumpRequestComplete& OnComplete);

// Client RPC to travel to new server
void ClientRPC_TravelToSystem(
    const FString& TravelURL,
    const FString& TicketId,
    const FString& SystemName);
```

**Delegates:**
```cpp
// Fired when jump request completes (success or failure)
UPROPERTY(BlueprintAssignable)
FOnJumpRequestComplete OnJumpRequestComplete;

// Fired when client travel begins
UPROPERTY(BlueprintAssignable)
FOnJumpInitiated OnJumpInitiated;
```

### AEchoesStargate

**Purpose:** Physical stargate actor placed in levels

**Setup in Editor:**
1. Drag AEchoesStargate into level
2. Configure properties:
   - **StargateId:** Must match database entry
   - **SourceSystemId:** Current system GUID
   - **DestinationSystemId:** Where jumps lead
   - **bIsOperational:** Enable/disable gate
   - **JumpCooldownSeconds:** Time between jumps per ship
   - **MinJumpDistance/MaxJumpDistance:** Valid jump range

**Blueprint Events:**
```cpp
// Called when ship successfully initiates jump
UFUNCTION(BlueprintImplementableEvent)
void OnJumpInitiated(AActor* Ship, const FString& DestinationSystemName);

// Called when jump fails
UFUNCTION(BlueprintImplementableEvent)
void OnJumpFailed(AActor* Ship, const FString& Reason);

// Override for custom visual effects
UFUNCTION(BlueprintNativeEvent)
void PlayJumpEffect(AActor* Ship);

// Override for idle animation
UFUNCTION(BlueprintNativeEvent)
void PlayIdleEffect();
```

**Trigger Behavior:**
1. Ship enters trigger volume
2. Checks operational status
3. Validates cooldown and distance
4. Gets character ID from ship
5. Calls ServerOnly_InitiateJump
6. Subsystem requests ticket
7. On success, sends ClientRPC_TravelToSystem

### Integration with Existing Systems

**Persistence Integration:**
```cpp
bool UEchoesJumpSubsystem::SaveCharacterStateBeforeJump(FGuid CharacterId, APawn* PlayerPawn)
{
    // Get persistence subsystem
    UEchoesPersistenceSubsystem* PersistenceSubsystem = 
        GetGameInstance()->GetSubsystem<UEchoesPersistenceSubsystem>();
    
    // Collect state from pawn components
    FCommon_StateData StateData;
    // ... collect position, rotation, stats ...
    
    // Force immediate save (high priority)
    PersistenceSubsystem->ServerOnly_SaveStateImmediate(CharacterId, StateData);
    
    return true;
}
```

**Character ID Extraction:**
```cpp
FGuid AEchoesStargate::GetCharacterIdFromShip_Implementation(AActor* Ship) const
{
    APawn* Pawn = Cast<APawn>(Ship);
    if (Pawn)
    {
        APlayerController* PC = Cast<APlayerController>(Pawn->GetController());
        if (PC && PC->PlayerState)
        {
            // Get from your custom PlayerState
            AYourPlayerState* PS = Cast<AYourPlayerState>(PC->PlayerState);
            if (PS)
            {
                return PS->CharacterId;
            }
        }
    }
    return FGuid();
}
```

**Destination Server Validation:**
```cpp
// In GameMode::PreLogin or PostLogin
void AYourGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);
    
    // Extract ticket from connection URL
    FString OptionsString = NewPlayer->PlayerState->SavedNetworkAddress;
    FString TicketId;
    if (FParse::Value(*OptionsString, TEXT("Ticket="), TicketId))
    {
        // Validate ticket before spawning
        UEchoesJumpSubsystem* JumpSys = GetGameInstance()->GetSubsystem<UEchoesJumpSubsystem>();
        
        FOnJumpRequestComplete OnComplete;
        OnComplete.BindLambda([this, NewPlayer](bool bValid, const FJumpResponseData& Response)
        {
            if (bValid)
            {
                // Spawn player at saved position
                SpawnPlayerWithSavedState(NewPlayer, Response.CharacterId);
            }
            else
            {
                // Kick player
                NewPlayer->ClientTravel("", TRAVEL_Absolute, true);
            }
        });
        
        JumpSys->ServerOnly_ValidateJumpTicket(
            TicketId,
            CharacterId, // From player state
            CurrentSystemId,
            OnComplete);
    }
}
```

## Security Considerations

### Ticket Security

1. **One-Time Use:** Tickets are marked as redeemed after first use
2. **Short Expiration:** 5-minute window prevents abuse
3. **Character Binding:** Ticket tied to specific character
4. **System Binding:** Must match destination system
5. **Server Authentication:** X-Server-Secret prevents spoofing

### Attack Vectors & Mitigations

| Attack | Mitigation |
|--------|-----------|
| Ticket Replay | Mark as redeemed, check status |
| Ticket Forgery | Server-side generation, GUID complexity |
| Wrong Character | Validate character ID matches |
| Wrong System | Validate system ID matches destination |
| Expired Ticket | Strict 5-minute TTL with timestamp check |
| Duplicate Jumps | Block new tickets if pending exists |
| Unauthorized Request | X-Server-Secret authentication |

### Best Practices

1. **Always Save State First:** Call persistence before requesting ticket
2. **Handle Failures Gracefully:** Show UI feedback on denial
3. **Log All Actions:** Track jumps for audit trail
4. **Monitor Ticket Usage:** Alert on unusual patterns
5. **Secure Server Secret:** Use strong, unique secrets in production
6. **Rate Limiting:** Consider adding rate limits to jump endpoints
7. **Validate on Both Ends:** Source server pre-validates, destination post-validates

## Testing Guide

### Manual Testing

**Test 1: Successful Jump**
1. Place two stargate actors in two different levels
2. Configure with matching database entries
3. Fly ship into source gate
4. Verify state save occurs
5. Verify client travels to destination
6. Verify ticket validation succeeds
7. Verify player spawns at correct position

**Test 2: Expired Ticket**
1. Request jump ticket via API
2. Wait 6 minutes
3. Attempt to redeem ticket
4. Verify rejection with "expired" reason

**Test 3: Duplicate Ticket**
1. Request jump ticket
2. Redeem ticket successfully
3. Attempt to redeem same ticket again
4. Verify rejection with "already redeemed" reason

**Test 4: Wrong Character**
1. Request ticket for Character A
2. Attempt redemption with Character B ID
3. Verify rejection

**Test 5: Stargate Offline**
1. Set stargate bIsOperational = false
2. Attempt to enter gate
3. Verify jump denied
4. Verify OnJumpFailed event fires

**Test 6: Cooldown System**
1. Jump through gate
2. Immediately attempt second jump
3. Verify blocked by cooldown
4. Wait for cooldown expiry
5. Verify next jump succeeds

### Automated Testing

```csharp
// Backend unit test example
[Fact]
public async Task JumpRequest_ValidParameters_ReturnsTicket()
{
    // Arrange
    var controller = CreateJumpController();
    var request = new JumpRequestDto { /* ... */ };
    
    // Act
    var result = await controller.RequestJump(request);
    
    // Assert
    var okResult = Assert.IsType<OkObjectResult>(result.Result);
    var response = Assert.IsType<JumpResponseDto>(okResult.Value);
    Assert.True(response.Success);
    Assert.NotNull(response.TicketId);
}
```

## Troubleshooting

### Common Issues

**Issue:** "Missing X-Server-Secret header"
- **Cause:** ServerSecret not configured in DefaultGame.ini
- **Fix:** Add ServerSecret configuration matching backend

**Issue:** "Ticket not found or expired"
- **Cause:** Client took too long to travel (>5 min)
- **Fix:** Increase ticket expiration or optimize connection time

**Issue:** "Character ID mismatch"
- **Cause:** GetCharacterIdFromShip returns wrong/invalid ID
- **Fix:** Implement proper character ID extraction in Blueprint

**Issue:** "Stargate is not operational"
- **Cause:** bIsOperational is false or stargate not in database
- **Fix:** Enable stargate and ensure database entry exists

**Issue:** "Jump already in progress"
- **Cause:** Previous jump ticket still pending
- **Fix:** Wait for expiration or cancel previous jump

### Debug Logging

Enable verbose logging:
```ini
[/Script/Echoes.EchoesJumpSubsystem]
bEnableDebugLogging=true
```

Check logs for:
- Jump request sent/received
- Ticket generation
- Validation attempts
- State saves
- Client travel commands

### Performance Monitoring

Monitor these metrics:
- Jump request latency
- Ticket validation latency
- State save duration
- Client travel time
- Cache hit rate
- Ticket expiration rate

## Future Enhancements

### Planned Features

1. **Jump Queues:** Handle multiple ships waiting at busy gates
2. **Jump Cost:** Deduct fuel/credits for jumps
3. **Access Control:** Restrict jumps based on standings/permissions
4. **Jump History:** Track player jump patterns
5. **Emergency Jumps:** Special tickets for evacuation scenarios
6. **Mass Jumps:** Support for fleet/group jumps
7. **Jump Animations:** Cinematic sequences during transition
8. **Destination Preview:** Show destination system before confirming

### Scalability Considerations

- **Redis Integration:** Move from memory cache to Redis for multi-server
- **Database Tickets:** Store long-term jump history
- **Load Balancing:** Route jumps to least-loaded destination server
- **Region Support:** Handle cross-region jumps with different servers

## Summary

The Stargate Jump System provides a robust, secure mechanism for interstellar travel with:

✅ **Complete Implementation:** Backend API + UE5 subsystem + Actor  
✅ **Security:** Ticket-based auth with expiration  
✅ **State Preservation:** Automatic save before jump  
✅ **Error Handling:** Comprehensive validation and feedback  
✅ **Production Ready:** Configuration, logging, monitoring  

For questions or issues, refer to the troubleshooting section or check debug logs.
