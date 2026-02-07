# Persistence Subsystem Integration Guide

## Overview

The persistence system has been refactored to use a **Subsystem-based architecture** for better centralization, reliability, and scalability.

## Architecture

### Previous Architecture (Component-based)
```
[Ship 1] → [UPersistenceComponent] → HTTP Client → Backend API
[Ship 2] → [UPersistenceComponent] → HTTP Client → Backend API
[Ship N] → [UPersistenceComponent] → HTTP Client → Backend API
```
**Problems:**
- 1000 ships = 1000 HTTP clients
- Components die with ship destruction
- No request queuing

### New Architecture (Subsystem-based)
```
[Ship 1] → [UPersistenceComponent] ─┐
[Ship 2] → [UPersistenceComponent] ─┼→ [UEchoesPersistenceSubsystem] → HTTP Client → Backend API
[Ship N] → [UPersistenceComponent] ─┘       ↑
[PlayerController] ──────────────────────────┘
```
**Benefits:**
- Single HTTP client (centralized)
- Subsystem lives for entire game session
- Request queue with priority system
- Components only collect data

## Component Responsibilities

### UPersistenceComponent (Refactored)
**Role:** Data collection only

**What it does:**
- Collects state (position, rotation, stats)
- Runs heartbeat timer (60 seconds)
- Checks dirty flag (position >1m or stats changed)
- Calls subsystem to queue saves

**What it NO LONGER does:**
- ❌ HTTP requests
- ❌ JSON serialization
- ❌ Authentication headers
- ❌ Error handling

**Public Methods:**
```cpp
// Collect current state (public for PlayerController access)
FCommon_StateData ServerOnly_CollectCurrentState();

// Manually trigger save (queues via subsystem)
void ServerOnly_TriggerSave();

// Set character ID
void Common_SetCharacterId(const FGuid& InCharacterId);
```

### UEchoesPersistenceSubsystem (New)
**Role:** HTTP communication manager

**What it does:**
- Manages all HTTP requests
- Handles authentication (X-Server-Secret)
- Queues and batches requests
- Priority system (logout = high priority)
- JSON serialization
- Error handling and logging

**Public Methods:**
```cpp
// Queue a save (non-blocking, for heartbeat saves)
bool ServerOnly_QueueStateSave(const FGuid& CharacterId, const FCommon_StateData& StateData);

// Save immediately (for logout saves)
void ServerOnly_SaveStateImmediate(const FGuid& CharacterId, const FCommon_StateData& StateData);

// Get queue status
int32 GetQueueSize() const;
int32 GetSaveCount() const;
int32 GetFailCount() const;
```

## PlayerController Integration

### Why PlayerController?

**Problem:** Components die with ship destruction
- Ship explodes → Component destroyed immediately
- EndPlay() might not have time to save
- Data loss

**Solution:** PlayerController handles logout saves
- More stable lifecycle
- Guaranteed to exist until disconnect
- Can collect state from pawn before unpossess

### Implementation Example

```cpp
// In your AEchoesServerPlayerController.h
UCLASS()
class ECHOES_API AEchoesServerPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    // Called when player disconnects or unpossesses pawn
    virtual void OnUnPossess() override;

protected:
    // Cache character ID for logout save
    FGuid CharacterId;
};

// In your AEchoesServerPlayerController.cpp
#include "Core/Common/Networking/EchoesPersistenceSubsystem.h"
#include "Core/Common/Components/PersistenceComponent.h"

void AEchoesServerPlayerController::OnUnPossess()
{
    // Only run on server
    if (HasAuthority() && GetPawn())
    {
        // Get persistence component from pawn
        UPersistenceComponent* PersistenceComp = GetPawn()->FindComponentByClass<UPersistenceComponent>();
        
        if (PersistenceComp && CharacterId.IsValid())
        {
            // Collect current state from pawn
            FCommon_StateData CurrentState = PersistenceComp->ServerOnly_CollectCurrentState();
            
            // Get persistence subsystem
            if (UGameInstance* GameInstance = GetGameInstance())
            {
                UEchoesPersistenceSubsystem* PersistenceSubsystem = 
                    GameInstance->GetSubsystem<UEchoesPersistenceSubsystem>();
                
                if (PersistenceSubsystem)
                {
                    // Immediate save (high priority, bypasses queue)
                    PersistenceSubsystem->ServerOnly_SaveStateImmediate(CharacterId, CurrentState);
                    
                    UE_LOG(LogTemp, Log, TEXT("PlayerController: Logout save triggered for Character %s"),
                        *CharacterId.ToString(EGuidFormats::Digits));
                }
            }
        }
    }

    Super::OnUnPossess();
}
```

### Alternative: OnDetachFromPawn

```cpp
virtual void OnRep_Pawn() override
{
    APawn* OldPawn = GetPawn();
    Super::OnRep_Pawn();
    
    // If we just lost our pawn, save state
    if (OldPawn && !GetPawn())
    {
        // Trigger logout save (same logic as above)
    }
}
```

## Usage Patterns

### Pattern 1: Heartbeat Save (Automatic)
```cpp
// Component automatically queues saves every 60 seconds
// No action required - works out of the box
```

### Pattern 2: Manual Save (Game Logic)
```cpp
// When player triggers manual save (e.g., docking at station)
UPersistenceComponent* PersistenceComp = Ship->FindComponentByClass<UPersistenceComponent>();
if (PersistenceComp)
{
    PersistenceComp->ServerOnly_TriggerSave(); // Queues save via subsystem
}
```

### Pattern 3: Logout Save (Critical)
```cpp
// In PlayerController::OnUnPossess()
FCommon_StateData State = PersistenceComponent->ServerOnly_CollectCurrentState();
PersistenceSubsystem->ServerOnly_SaveStateImmediate(CharacterId, State); // Bypasses queue
```

## Configuration

### Subsystem Configuration (DefaultGame.ini)
```ini
[/Script/Echoes.EchoesPersistenceSubsystem]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=your-secret-key-here
MaxQueueSize=100
QueueProcessInterval=1.0
```

### Component Configuration (Per Ship)
```ini
[/Script/Echoes.PersistenceComponent]
HeartbeatInterval=60.0
DirtyPositionThreshold=100.0
bEnableHeartbeat=true
bEnableDirtyFlag=true
DefaultCapacitorValue=1000.0
```

## Queue Behavior

### Queue Processing
- Processes one request per second
- High priority requests (logout) go first
- Non-priority requests processed FIFO
- Max queue size: 100 (configurable)

### Priority System
```cpp
// High priority (immediate, bypasses queue)
PersistenceSubsystem->ServerOnly_SaveStateImmediate(CharacterId, State);

// Normal priority (queued)
PersistenceSubsystem->ServerOnly_QueueStateSave(CharacterId, State);
```

## Monitoring

### Log Messages

**Component:**
```
PersistenceComponent: BeginPlay on server for Character 12345678...
PersistenceComponent: Heartbeat timer triggered
PersistenceComponent: Save queued for Character 12345678...
```

**Subsystem:**
```
EchoesPersistenceSubsystem: Initialized. API URL: http://localhost:5116/api
EchoesPersistenceSubsystem: Queued save for character 12345678 (Queue: 3)
EchoesPersistenceSubsystem: Save successful for character 12345678 (Total: 42)
EchoesPersistenceSubsystem: Immediate save requested for character 12345678
```

**PlayerController:**
```
PlayerController: Logout save triggered for Character 12345678
```

### Performance Metrics
```cpp
// Get subsystem stats
UEchoesPersistenceSubsystem* Subsystem = GameInstance->GetSubsystem<UEchoesPersistenceSubsystem>();

int32 QueueSize = Subsystem->GetQueueSize();      // Current pending requests
int32 SaveCount = Subsystem->GetSaveCount();      // Total successful saves
int32 FailCount = Subsystem->GetFailCount();      // Total failed saves
```

## Migration from Old System

### Step 1: Remove Old Properties
Old components had these properties (now removed):
- ❌ `ApiBaseUrl` - Now in subsystem
- ❌ `ServerSecret` - Now in subsystem
- ❌ `bSaveInProgress` - Managed by subsystem
- ❌ `SaveCount` / `FailCount` - Tracked by subsystem

### Step 2: Update Component Creation
```cpp
// Old way (still works, but API/Secret not needed)
UPersistenceComponent* Comp = NewObject<UPersistenceComponent>(Ship);
Comp->ApiBaseUrl = "...";  // ❌ Remove
Comp->ServerSecret = "..."; // ❌ Remove
Comp->CharacterId = CharId;
Comp->RegisterComponent();

// New way (cleaner)
UPersistenceComponent* Comp = NewObject<UPersistenceComponent>(Ship);
Comp->CharacterId = CharId;  // Only this is needed
Comp->RegisterComponent();
```

### Step 3: Update Logout Logic
```cpp
// Old way (in Component::EndPlay - unreliable)
void UPersistenceComponent::EndPlay(...)
{
    ServerOnly_SaveToBackend(CurrentState); // ❌ Component handled HTTP
}

// New way (in PlayerController::OnUnPossess - reliable)
void APlayerController::OnUnPossess()
{
    FCommon_StateData State = Component->ServerOnly_CollectCurrentState();
    Subsystem->ServerOnly_SaveStateImmediate(CharacterId, State); // ✅ Subsystem handles HTTP
}
```

## Troubleshooting

### "Failed to get EchoesPersistenceSubsystem"
**Cause:** Subsystem not registered or initialized
**Solution:** Ensure subsystem is properly created by GameInstance

### "No persistence subsystem available"
**Cause:** Component trying to save but subsystem not found
**Solution:** Check that GameInstance has subsystem registered

### "Queue full, dropping oldest request"
**Cause:** Too many save requests, queue limit reached
**Solution:** 
- Increase `MaxQueueSize` in config
- Reduce heartbeat frequency
- Check for save spam

### Saves not happening on logout
**Cause:** PlayerController not calling SaveStateImmediate
**Solution:** Implement OnUnPossess logic in your server player controller

## Best Practices

### DO ✅
- Use `SaveStateImmediate()` for critical saves (logout, important events)
- Use `QueueStateSave()` for regular saves (heartbeat, minor updates)
- Implement logout save in PlayerController::OnUnPossess()
- Monitor queue size to detect issues
- Configure subsystem once in DefaultGame.ini

### DON'T ❌
- Don't bypass subsystem and make direct HTTP calls
- Don't rely on Component::EndPlay() for logout saves
- Don't create multiple subsystem instances
- Don't ignore queue full warnings
- Don't use SaveStateImmediate() for every save (defeats purpose of queue)

## Performance Considerations

### Network
- Queue reduces API calls by batching
- One request per second max (configurable)
- Immediate saves bypass queue (use sparingly)

### Memory
- Queue size: ~1KB per request
- Max 100 requests = ~100KB
- Subsystem: ~10KB overhead

### CPU
- Timer runs once per second (negligible)
- JSON serialization per save (~0.1ms)
- HTTP client reused (no allocation overhead)

## Future Enhancements

### Planned Features
- [ ] Batch API (multiple saves in one request)
- [ ] Retry logic for failed saves
- [ ] Exponential backoff on errors
- [ ] WebSocket for real-time updates
- [ ] Compression for large states
- [ ] State diff (only send changes)

## References

- Subsystem Header: `Core/Common/Networking/EchoesPersistenceSubsystem.h`
- Subsystem Implementation: `Core/Common/Networking/EchoesPersistenceSubsystem.cpp`
- Component Header: `Core/Common/Components/PersistenceComponent.h`
- Component Implementation: `Core/Common/Components/PersistenceComponent.cpp`
- Backend API: `Controllers/PersistenceController.cs`

## License

Copyright Epic Games, Inc. All Rights Reserved.
