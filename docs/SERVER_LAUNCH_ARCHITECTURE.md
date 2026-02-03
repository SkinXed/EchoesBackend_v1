# Dedicated Server Launch Scripts - Architecture

## Script Flow Diagram

```
┌─────────────────────────────────────────────────────────────────┐
│                    User Entry Points                            │
└─────────────────────────────────────────────────────────────────┘
                              │
            ┌─────────────────┼─────────────────┐
            │                 │                 │
            ▼                 ▼                 ▼
    ┌──────────────┐  ┌──────────────┐  ┌──────────────┐
    │ QuickLaunch  │  │ Launch.bat   │  │ Launch.ps1   │
    │   .bat       │  │  (Direct)    │  │ (Advanced)   │
    └──────────────┘  └──────────────┘  └──────────────┘
            │                 │                 │
            │     (calls)     │                 │
            └────────►────────┘                 │
                      │                         │
                      ▼                         ▼
            ┌───────────────────┐     ┌───────────────────┐
            │  Configuration    │     │  Configuration    │
            │  via Variables    │     │  via Parameters   │
            └───────────────────┘     └───────────────────┘
                      │                         │
                      └──────────┬──────────────┘
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │    Validation Phase     │
                    ├─────────────────────────┤
                    │ • UnrealEditor exists?  │
                    │ • Project file exists?  │
                    │ • Valid ServerType?     │
                    └─────────────────────────┘
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │  Command Line Builder   │
                    ├─────────────────────────┤
                    │ Map -server -log        │
                    │ -Port=7777              │
                    │ -ServerType=...         │
                    │ -SystemId=... or        │
                    │ -RegionId=...           │
                    └─────────────────────────┘
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │   Launch UE5 Editor     │
                    ├─────────────────────────┤
                    │ UnrealEditor.exe        │
                    │   Echoes.uproject       │
                    │   <command line>        │
                    └─────────────────────────┘
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │    Unreal Engine 5      │
                    ├─────────────────────────┤
                    │ • Load GameLevel map    │
                    │ • Initialize subsystems │
                    │ • Run as -server        │
                    └─────────────────────────┘
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │  Server Management      │
                    ├─────────────────────────┤
                    │ UEchoesServerMgmt       │
                    │ • Parse -ServerType=    │
                    │ • Parse -SystemId=      │
                    │ • Parse -RegionId=      │
                    │ • Parse -Port=          │
                    │ • Register with backend │
                    └─────────────────────────┘
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │   World Generation      │
                    ├─────────────────────────┤
                    │ AEchoesWorldGenerator   │
                    │ • Fetch config from API │
                    │ • Spawn planets/moons   │
                    │ • Setup orbits          │
                    │ • Initialize actors     │
                    └─────────────────────────┘
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │   Server Running        │
                    ├─────────────────────────┤
                    │ • Accept connections    │
                    │ • Send heartbeats       │
                    │ • Process game logic    │
                    │ • Replicate to clients  │
                    └─────────────────────────┘
                                 │
                         (user stops server)
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │   Error Checking        │
                    ├─────────────────────────┤
                    │ Check ERRORLEVEL        │
                    │ • 0 = Normal exit       │
                    │ • ≠0 = Error occurred   │
                    │ Display diagnostics     │
                    └─────────────────────────┘
```

## Configuration Flow

### Batch Script (LaunchDedicatedServer.bat)

```
1. User edits variables in script
   ├── UNREAL_EDITOR path
   ├── PROJECT_FILE path
   ├── MAP_NAME
   ├── SERVER_TYPE
   ├── SERVER_PORT
   ├── SYSTEM_ID or REGION_ID
   └── Run script

2. Script validates
   ├── UnrealEditor.exe exists?
   ├── Echoes.uproject exists?
   └── ServerType valid?

3. Script builds command
   └── "%UNREAL_EDITOR%" "%PROJECT_FILE%" GameLevel -server -log -Port=7777 -ServerType=DedicatedSystem -SystemId=...

4. Script launches server
   └── Wait for exit

5. Script checks ERRORLEVEL
   └── Display result
```

### PowerShell Script (LaunchDedicatedServer.ps1)

```
1. User runs with parameters
   └── .\LaunchDedicatedServer.ps1 -ServerType DedicatedSystem -Port 7777 -SystemId "..."

2. Script parses parameters
   ├── -ServerType (default: DedicatedSystem)
   ├── -Port (default: 7777)
   ├── -SystemId (default: 00000000-0000-0000-0000-000000000001)
   ├── -RegionId (default: 00000000-0000-0000-0000-000000000010)
   ├── -MapName (default: GameLevel)
   ├── -UnrealEditorPath (default: C:\Program Files\Epic Games\UE_5.3\...)
   └── -Help (show help)

3. Script validates
   ├── UnrealEditor.exe exists?
   ├── Echoes.uproject exists?
   └── ServerType valid?

4. Script builds command
   └── Same as batch

5. Script launches server
   └── Use Start-Process -Wait -PassThru

6. Script checks exit code
   └── Display result with colors
```

### Quick Launch Menu (QuickLaunch.bat)

```
1. Display menu
   ├── 1. Single System Server
   ├── 2. Two System Servers
   ├── 3. Regional Cluster Server
   ├── 4. Custom Configuration
   └── 5. Exit

2. User selects option
   └── Set environment variables

3. Call LaunchDedicatedServer.bat
   └── (or spawn multiple windows)

4. Return to menu
```

## Multiple Instance Pattern

```
Terminal 1                    Terminal 2
    │                             │
    ▼                             ▼
set PORT=7777              set PORT=7778
set SYSTEMID=...001        set SYSTEMID=...002
    │                             │
    ▼                             ▼
Launch.bat                 Launch.bat
    │                             │
    ▼                             ▼
UnrealEditor.exe           UnrealEditor.exe
Port 7777                  Port 7778
    │                             │
    ▼                             ▼
Server Instance 1          Server Instance 2
System ...001              System ...002
    │                             │
    └──────────┬──────────────────┘
               │
               ▼
        Backend API Server
    (coordinates both servers)
```

## Parameter Parsing Flow

```
Command Line Arguments
    │
    ▼
FCommandLine::Get()
    │
    ├──► FParse::Value(..., "ServerType=", ...)  → ServerType
    ├──► FParse::Value(..., "SystemId=", ...)    → CurrentSolarSystemId
    ├──► FParse::Value(..., "RegionId=", ...)    → CurrentRegionId
    └──► FParse::Value(..., "Port=", ...)        → GamePort
                                │
                                ▼
            UEchoesServerManagementSubsystem
                    Initialize()
                                │
                                ├──► ServerOnly_Register()
                                ├──► ServerOnly_Heartbeat()
                                └──► ServerOnly_GetConfig()
                                                │
                                                ▼
                                    AEchoesWorldGenerator
                                    OnServerConfigReceived()
                                                │
                                                ▼
                                        Generate World
                                    (Planets, Moons, etc.)
```

## Error Handling Chain

```
LaunchDedicatedServer.bat/ps1
    │
    ├──► Check: UnrealEditor exists
    │        └──► [ERROR] Exit code 1
    │
    ├──► Check: Project file exists
    │        └──► [ERROR] Exit code 1
    │
    ├──► Check: Valid ServerType
    │        └──► [ERROR] Exit code 1
    │
    └──► Launch UnrealEditor.exe
             │
             ├──► Success (exit code 0)
             │        └──► "Server exited normally"
             │
             └──► Failure (exit code ≠ 0)
                      └──► "[ERROR] Server crashed"
                           │
                           ├──► Port in use?
                           ├──► Invalid GUID?
                           ├──► Backend unreachable?
                           ├──► Missing assets?
                           └──► Check logs
```

## File Structure

```
EchoesBackend_v1/
├── tools/
│   ├── LaunchDedicatedServer.bat    (Primary batch script)
│   ├── LaunchDedicatedServer.ps1    (PowerShell version)
│   ├── QuickLaunch.bat              (Interactive menu)
│   └── README.md                    (Documentation)
│
├── Client/
│   └── Echoes/
│       ├── Echoes.uproject          (Project file)
│       ├── Content/
│       │   └── Project/
│       │       └── Map/
│       │           └── GameLevel.umap    (Default map)
│       └── Source/
│           └── Echoes/
│               └── Core/
│                   └── Server/
│                       └── Managers/
│                           └── EchoesServerManagementSubsystem.cpp
│                               (Parses -ServerType=, -SystemId=, etc.)
│
└── docs/
    ├── WORLD_GENERATION_AUDIT.md
    └── MOON_SYSTEM_DOCUMENTATION_RU.md
```

## Usage Patterns

### Pattern 1: Quick Test (Default)
```batch
cd tools
LaunchDedicatedServer.bat
```

### Pattern 2: Custom Port
```batch
set SERVER_PORT=8888
LaunchDedicatedServer.bat
```

### Pattern 3: Different System
```batch
set SYSTEM_ID=12345678-1234-1234-1234-123456789012
LaunchDedicatedServer.bat
```

### Pattern 4: Regional Cluster
```batch
set SERVER_TYPE=RegionalCluster
set REGION_ID=AAAAAAAA-AAAA-AAAA-AAAA-AAAAAAAAAAAA
LaunchDedicatedServer.bat
```

### Pattern 5: Multiple Servers (PowerShell)
```powershell
Start-Process powershell -ArgumentList "-NoExit", "-Command", "cd $PWD; .\tools\LaunchDedicatedServer.ps1 -Port 7777 -SystemId '00000000-0000-0000-0000-000000000001'"

Start-Process powershell -ArgumentList "-NoExit", "-Command", "cd $PWD; .\tools\LaunchDedicatedServer.ps1 -Port 7778 -SystemId '00000000-0000-0000-0000-000000000002'"
```

### Pattern 6: Quick Launch Menu
```batch
tools\QuickLaunch.bat
(select option from menu)
```
