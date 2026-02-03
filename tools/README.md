# Dedicated Server Launch Tools

This directory contains scripts for launching and testing Echoes MMO dedicated servers on Windows.

## Available Scripts

### 1. LaunchDedicatedServer.bat (Windows Batch)
Traditional Windows batch script with simple configuration variables.

**Features:**
- Easy to edit configuration variables at the top of the file
- Clear error messages and validation
- Examples for multiple instances in comments
- Works on all Windows versions

### 2. LaunchDedicatedServer.ps1 (PowerShell)
Modern PowerShell script with command-line parameters and advanced features.

**Features:**
- Command-line parameters for flexible configuration
- Colored console output
- Built-in help system
- Better error handling
- No need to edit the script file

## Quick Start

### Using Batch Script

1. Open `LaunchDedicatedServer.bat` in a text editor
2. Update the `UNREAL_EDITOR` path to match your Unreal Engine installation
3. Double-click the script or run from command prompt:
   ```cmd
   tools\LaunchDedicatedServer.bat
   ```

### Using PowerShell Script

1. Open PowerShell in the repository root
2. Run the script with desired parameters:
   ```powershell
   .\tools\LaunchDedicatedServer.ps1 -Help
   ```

## Configuration

### Required Paths

**Unreal Editor:** Path to `UnrealEditor.exe`
- Default: `C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe`
- Adjust for your UE5 version (5.3, 5.4, etc.)

**Project File:** Automatically detected at `Client/Echoes/Echoes.uproject`

**Map Name:** Default is `GameLevel`
- Available maps: `GameLevel`, `LoginMap`, `EntryMap`, `CharacterSelectMap`

### Server Types

#### DedicatedSystem (Default)
Single solar system server. Requires a SystemId GUID.

**Batch Example:**
```batch
set "SERVER_TYPE=DedicatedSystem"
set "SYSTEM_ID=00000000-0000-0000-0000-000000000001"
```

**PowerShell Example:**
```powershell
.\LaunchDedicatedServer.ps1 -ServerType DedicatedSystem -SystemId "00000000-0000-0000-0000-000000000001"
```

#### RegionalCluster
Multi-system regional server. Requires a RegionId GUID.

**Batch Example:**
```batch
set "SERVER_TYPE=RegionalCluster"
set "REGION_ID=00000000-0000-0000-0000-000000000010"
```

**PowerShell Example:**
```powershell
.\LaunchDedicatedServer.ps1 -ServerType RegionalCluster -RegionId "00000000-0000-0000-0000-000000000010"
```

## Command Line Parameters

The server accepts the following command-line parameters (parsed by `UEchoesServerManagementSubsystem`):

| Parameter | Description | Required | Example |
|-----------|-------------|----------|---------|
| `-ServerType=` | Server mode | No (default: DedicatedSystem) | `-ServerType=RegionalCluster` |
| `-SystemId=` | Solar system GUID | For DedicatedSystem | `-SystemId=00000000-0000-0000-0000-000000000001` |
| `-RegionId=` | Region GUID | For RegionalCluster | `-RegionId=00000000-0000-0000-0000-000000000010` |
| `-Port=` | Game server port | No (default: 7777) | `-Port=7778` |
| `-server` | Run as dedicated server | Yes | (flag only) |
| `-log` | Show console output | Recommended | (flag only) |

## Running Multiple Instances

### Scenario 1: Testing Multiple Systems (DedicatedSystem)

**Terminal 1:**
```batch
set SERVER_PORT=7777
set SYSTEM_ID=00000000-0000-0000-0000-000000000001
LaunchDedicatedServer.bat
```

**Terminal 2:**
```batch
set SERVER_PORT=7778
set SYSTEM_ID=00000000-0000-0000-0000-000000000002
LaunchDedicatedServer.bat
```

Or with PowerShell:
```powershell
# Terminal 1
.\LaunchDedicatedServer.ps1 -Port 7777 -SystemId "00000000-0000-0000-0000-000000000001"

# Terminal 2
.\LaunchDedicatedServer.ps1 -Port 7778 -SystemId "00000000-0000-0000-0000-000000000002"
```

### Scenario 2: Testing Regional Cluster

**Terminal 1:**
```powershell
.\LaunchDedicatedServer.ps1 -ServerType RegionalCluster -Port 7777 -RegionId "00000000-0000-0000-0000-000000000010"
```

## Troubleshooting

### Error: "Unreal Editor not found"
**Solution:** Update the path to UnrealEditor.exe in the script or parameter.

Common locations:
- `C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe`
- `C:\Program Files\Epic Games\UE_5.4\Engine\Binaries\Win64\UnrealEditor.exe`

### Error: "Project file not found"
**Solution:** Ensure you're running the script from the repository root or the tools directory.

### Server crashes immediately
**Possible causes:**
- Port already in use (try a different port)
- Invalid SystemId or RegionId format (must be valid GUID)
- Backend server not running or unreachable
- Missing game assets or corrupt installation

Check the console output (with `-log` flag) for specific error messages from `LogEchoesServer`.

### PowerShell execution policy error
If you get "script cannot be loaded because running scripts is disabled", run:
```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

## Expected Server Output

When the server starts successfully, you should see:

```
[LogEchoesServer] EchoesServerManagementSubsystem initialized
[LogEchoesServer] Using ServerType from command line: DedicatedSystem
[LogEchoesServer] Using SolarSystemId from command line: 00000000-0000-0000-0000-000000000001
[LogEchoesServer] ╔══════════════════════════════════════════════════════════╗
[LogEchoesServer] ║    SERVER CONFIGURATION                                  ║
[LogEchoesServer] ╚══════════════════════════════════════════════════════════╝
[LogEchoesServer] Server Type: DedicatedSystem
[LogEchoesServer] Instance ID: <generated-guid>
[LogEchoesServer] Game Port: 7777
[LogEchoesServer] Solar System ID: 00000000-0000-0000-0000-000000000001
```

Followed by world generation logs:
```
[LogTemp] ╔══════════════════════════════════════════════════════════╗
[LogTemp] ║   ECHOES WORLD GENERATOR - DEDICATED SYSTEM CONFIG      ║
[LogTemp] ╚══════════════════════════════════════════════════════════╝
[LogTemp] System: <system-name>
[LogTemp] Planets: <count>
...
```

## Advanced Usage

### Custom Map

```powershell
.\LaunchDedicatedServer.ps1 -MapName EntryMap
```

### No Console Log (headless)

```powershell
.\LaunchDedicatedServer.ps1 -NoLog
```

### Complete Custom Configuration

```powershell
.\LaunchDedicatedServer.ps1 `
    -ServerType DedicatedSystem `
    -Port 8888 `
    -SystemId "AAAAAAAA-BBBB-CCCC-DDDD-EEEEEEEEEEEE" `
    -MapName GameLevel `
    -UnrealEditorPath "D:\UnrealEngine\UE_5.4\Engine\Binaries\Win64\UnrealEditor.exe"
```

## Integration with Backend

The dedicated server automatically:
1. Registers with the backend API on startup
2. Sends heartbeat every 30 seconds
3. Fetches world configuration (systems, planets, etc.)
4. Unregisters on clean shutdown

Ensure the backend API is running and accessible before starting the dedicated server.

## See Also

- [World Generation System Documentation](../docs/WORLD_GENERATION_AUDIT.md)
- [Server Management Subsystem](../Client/Echoes/Source/Echoes/Core/Server/Managers/EchoesServerManagementSubsystem.h)
- [World Generator](../Client/Echoes/Source/Echoes/Core/Common/World/EchoesWorldGenerator.h)
