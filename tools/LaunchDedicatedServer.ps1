# ============================================================================
# Echoes MMO - Dedicated Server Launch Script (PowerShell)
# ============================================================================
# This script launches the Echoes dedicated server with various configurations
# Supports both DedicatedSystem (single system) and RegionalCluster modes
# ============================================================================

param(
    [string]$ServerType = "DedicatedSystem",
    [string]$Port = "7777",
    [string]$SystemId = "00000000-0000-0000-0000-000000000001",
    [string]$RegionId = "00000000-0000-0000-0000-000000000010",
    [string]$MapName = "GameLevel",
    [string]$UnrealEditorPath = "C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe",
    [switch]$NoLog,
    [switch]$Help
)

# ============================================================================
# HELP
# ============================================================================

if ($Help) {
    Write-Host @"

Echoes MMO - Dedicated Server Launcher (PowerShell)

USAGE:
    .\LaunchDedicatedServer.ps1 [OPTIONS]

OPTIONS:
    -ServerType <type>      Server type: DedicatedSystem or RegionalCluster
                           Default: DedicatedSystem
    
    -Port <port>           Port number for game server
                           Default: 7777
    
    -SystemId <guid>       System ID for DedicatedSystem mode
                           Default: 00000000-0000-0000-0000-000000000001
    
    -RegionId <guid>       Region ID for RegionalCluster mode
                           Default: 00000000-0000-0000-0000-000000000010
    
    -MapName <map>         Map to load (without .umap extension)
                           Default: GameLevel
                           Available: GameLevel, LoginMap, EntryMap, CharacterSelectMap
    
    -UnrealEditorPath <path>  Path to UnrealEditor.exe
                              Default: C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe
    
    -NoLog                 Don't show console log window
    
    -Help                  Show this help message

EXAMPLES:
    # Launch DedicatedSystem server on default port
    .\LaunchDedicatedServer.ps1

    # Launch with custom system ID and port
    .\LaunchDedicatedServer.ps1 -SystemId "12345678-1234-1234-1234-123456789012" -Port 7778

    # Launch RegionalCluster server
    .\LaunchDedicatedServer.ps1 -ServerType RegionalCluster -RegionId "AAAAAAAA-AAAA-AAAA-AAAA-AAAAAAAAAAAA"

    # Launch with different map
    .\LaunchDedicatedServer.ps1 -MapName EntryMap

MULTIPLE INSTANCES:
    # Terminal 1
    .\LaunchDedicatedServer.ps1 -Port 7777 -SystemId "00000000-0000-0000-0000-000000000001"

    # Terminal 2
    .\LaunchDedicatedServer.ps1 -Port 7778 -SystemId "00000000-0000-0000-0000-000000000002"

"@
    exit 0
}

# ============================================================================
# CONFIGURATION
# ============================================================================

# Determine project file path relative to script location
$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectFile = Join-Path (Split-Path -Parent $ScriptDir) "Client\Echoes\Echoes.uproject"

# ============================================================================
# VALIDATION
# ============================================================================

Write-Host ""
Write-Host "========================================================================"
Write-Host " Echoes MMO - Dedicated Server Launcher"
Write-Host "========================================================================"
Write-Host ""

# Check if Unreal Editor exists
if (-not (Test-Path $UnrealEditorPath)) {
    Write-Host "[ERROR] Unreal Editor not found at: $UnrealEditorPath" -ForegroundColor Red
    Write-Host ""
    Write-Host "Please specify the correct path using -UnrealEditorPath parameter"
    Write-Host ""
    Write-Host "Typical locations:"
    Write-Host "  C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe"
    Write-Host "  C:\Program Files\Epic Games\UE_5.4\Engine\Binaries\Win64\UnrealEditor.exe"
    Write-Host ""
    exit 1
}

# Check if project file exists
if (-not (Test-Path $ProjectFile)) {
    Write-Host "[ERROR] Project file not found at: $ProjectFile" -ForegroundColor Red
    Write-Host ""
    Write-Host "Please ensure this script is run from the tools directory"
    Write-Host ""
    exit 1
}

Write-Host "[OK] Unreal Editor found" -ForegroundColor Green
Write-Host "[OK] Project file found" -ForegroundColor Green
Write-Host ""

# Validate server type
if ($ServerType -notin @("DedicatedSystem", "RegionalCluster")) {
    Write-Host "[ERROR] Invalid ServerType: $ServerType" -ForegroundColor Red
    Write-Host "Valid options: DedicatedSystem, RegionalCluster"
    exit 1
}

# ============================================================================
# BUILD COMMAND LINE
# ============================================================================

$LogFlag = if (-not $NoLog) { "-log" } else { "" }
$CmdLineArgs = @("$MapName", "-server", $LogFlag, "-Port=$Port", "-ServerType=$ServerType")

if ($ServerType -eq "DedicatedSystem") {
    $CmdLineArgs += "-SystemId=$SystemId"
    Write-Host "[INFO] Launching DedicatedSystem server" -ForegroundColor Cyan
    Write-Host "[INFO] System ID: $SystemId" -ForegroundColor Cyan
} elseif ($ServerType -eq "RegionalCluster") {
    $CmdLineArgs += "-RegionId=$RegionId"
    Write-Host "[INFO] Launching RegionalCluster server" -ForegroundColor Cyan
    Write-Host "[INFO] Region ID: $RegionId" -ForegroundColor Cyan
}

Write-Host "[INFO] Port: $Port" -ForegroundColor Cyan
Write-Host "[INFO] Map: $MapName" -ForegroundColor Cyan
Write-Host ""

# ============================================================================
# LAUNCH SERVER
# ============================================================================

Write-Host "========================================================================"
Write-Host " Starting Dedicated Server..."
Write-Host "========================================================================"
Write-Host ""
Write-Host "Command: $UnrealEditorPath $ProjectFile $($CmdLineArgs -join ' ')" -ForegroundColor Gray
Write-Host ""
Write-Host "Press Ctrl+C to stop the server"
Write-Host ""

# Launch the server and capture exit code
try {
    $Process = Start-Process -FilePath $UnrealEditorPath `
                            -ArgumentList (@("`"$ProjectFile`"") + $CmdLineArgs) `
                            -Wait `
                            -PassThru `
                            -NoNewWindow

    $ExitCode = $Process.ExitCode
} catch {
    Write-Host ""
    Write-Host "========================================================================"
    Write-Host " [ERROR] Failed to launch server" -ForegroundColor Red
    Write-Host "========================================================================"
    Write-Host ""
    Write-Host "Error: $_" -ForegroundColor Red
    Write-Host ""
    exit 1
}

# ============================================================================
# ERROR CHECKING
# ============================================================================

if ($ExitCode -ne 0) {
    Write-Host ""
    Write-Host "========================================================================"
    Write-Host " [ERROR] Server crashed or exited with error code: $ExitCode" -ForegroundColor Red
    Write-Host "========================================================================"
    Write-Host ""
    Write-Host "Common issues:"
    Write-Host "  - Missing or corrupt game files"
    Write-Host "  - Port already in use"
    Write-Host "  - Invalid SystemId or RegionId"
    Write-Host "  - Backend connection failure"
    Write-Host ""
    Write-Host "Check the log output above for specific error messages."
    Write-Host ""
    exit $ExitCode
} else {
    Write-Host ""
    Write-Host "========================================================================"
    Write-Host " Server exited normally" -ForegroundColor Green
    Write-Host "========================================================================"
    Write-Host ""
}

exit 0
