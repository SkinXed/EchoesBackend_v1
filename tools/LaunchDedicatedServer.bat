@echo off
REM ============================================================================
REM Echoes MMO - Dedicated Server Launch Script
REM ============================================================================
REM This script launches the Echoes dedicated server with various configurations
REM Supports both DedicatedSystem (single system) and RegionalCluster modes
REM ============================================================================

setlocal enabledelayedexpansion

REM ============================================================================
REM CONFIGURATION - Modify these paths for your environment
REM ============================================================================

REM Path to Unreal Engine Editor executable
REM Default location for UE5: C:\Program Files\Epic Games\UE_5.X\Engine\Binaries\Win64\UnrealEditor.exe
set "UNREAL_EDITOR=C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe"

REM Path to the Echoes .uproject file
REM Use absolute path or relative to this script location
set "PROJECT_FILE=%~dp0Client\Echoes\Echoes.uproject"

REM Map to load (without .umap extension)
REM Available maps: GameLevel, LoginMap, EntryMap, CharacterSelectMap
set "MAP_NAME=GameLevel"

REM ============================================================================
REM SERVER CONFIGURATION
REM ============================================================================

REM Server Type: DedicatedSystem or RegionalCluster
set "SERVER_TYPE=DedicatedSystem"

REM Port number for game server
set "SERVER_PORT=7777"

REM System ID for DedicatedSystem mode (use valid GUID)
REM Example GUIDs for testing different systems:
REM   00000000-0000-0000-0000-000000000001 (Test System 1)
REM   00000000-0000-0000-0000-000000000002 (Test System 2)
set "SYSTEM_ID=00000000-0000-0000-0000-000000000001"

REM Region ID for RegionalCluster mode (use valid GUID)
REM Only used when SERVER_TYPE=RegionalCluster
set "REGION_ID=00000000-0000-0000-0000-000000000010"

REM ============================================================================
REM VALIDATION
REM ============================================================================

echo.
echo ========================================================================
echo  Echoes MMO - Dedicated Server Launcher
echo ========================================================================
echo.

REM Check if Unreal Editor exists
if not exist "%UNREAL_EDITOR%" (
    echo [ERROR] Unreal Editor not found at: %UNREAL_EDITOR%
    echo.
    echo Please update the UNREAL_EDITOR variable in this script to point to
    echo your UnrealEditor.exe location.
    echo.
    echo Typical locations:
    echo   C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe
    echo   C:\Program Files\Epic Games\UE_5.4\Engine\Binaries\Win64\UnrealEditor.exe
    echo.
    pause
    exit /b 1
)

REM Check if project file exists
if not exist "%PROJECT_FILE%" (
    echo [ERROR] Project file not found at: %PROJECT_FILE%
    echo.
    echo Please ensure this script is run from the repository root or update
    echo the PROJECT_FILE variable to point to Echoes.uproject
    echo.
    pause
    exit /b 1
)

echo [OK] Unreal Editor found
echo [OK] Project file found
echo.

REM ============================================================================
REM BUILD COMMAND LINE
REM ============================================================================

REM Build the command line based on server type
set "CMDLINE=%MAP_NAME% -server -log -Port=%SERVER_PORT% -ServerType=%SERVER_TYPE%"

if /i "%SERVER_TYPE%"=="DedicatedSystem" (
    set "CMDLINE=!CMDLINE! -SystemId=%SYSTEM_ID%"
    echo [INFO] Launching DedicatedSystem server
    echo [INFO] System ID: %SYSTEM_ID%
) else if /i "%SERVER_TYPE%"=="RegionalCluster" (
    set "CMDLINE=!CMDLINE! -RegionId=%REGION_ID%"
    echo [INFO] Launching RegionalCluster server
    echo [INFO] Region ID: %REGION_ID%
) else (
    echo [ERROR] Invalid SERVER_TYPE: %SERVER_TYPE%
    echo Valid options: DedicatedSystem, RegionalCluster
    pause
    exit /b 1
)

echo [INFO] Port: %SERVER_PORT%
echo [INFO] Map: %MAP_NAME%
echo.

REM ============================================================================
REM LAUNCH SERVER
REM ============================================================================

echo ========================================================================
echo  Starting Dedicated Server...
echo ========================================================================
echo.
echo Command: "%UNREAL_EDITOR%" "%PROJECT_FILE%" %CMDLINE%
echo.
echo Press Ctrl+C to stop the server
echo.

REM Launch the server
"%UNREAL_EDITOR%" "%PROJECT_FILE%" %CMDLINE%

REM ============================================================================
REM ERROR CHECKING
REM ============================================================================

REM Check if server exited with error
if errorlevel 1 (
    echo.
    echo ========================================================================
    echo  [ERROR] Server crashed or exited with error code: %ERRORLEVEL%
    echo ========================================================================
    echo.
    echo Common issues:
    echo   - Missing or corrupt game files
    echo   - Port already in use
    echo   - Invalid SystemId or RegionId
    echo   - Backend connection failure
    echo.
    echo Check the log output above for specific error messages.
    echo.
    pause
    exit /b %ERRORLEVEL%
) else (
    echo.
    echo ========================================================================
    echo  Server exited normally
    echo ========================================================================
    echo.
)

endlocal
exit /b 0

REM ============================================================================
REM EXAMPLES: MULTIPLE INSTANCES
REM ============================================================================
REM 
REM To run multiple server instances simultaneously (e.g., for testing 
REM RegionalCluster mode), create separate batch files or use different
REM command prompts with different configurations:
REM 
REM EXAMPLE 1: DedicatedSystem on different ports
REM ----------------------------------------------------------------------------
REM Terminal 1:
REM   set SERVER_PORT=7777
REM   set SYSTEM_ID=00000000-0000-0000-0000-000000000001
REM   LaunchDedicatedServer.bat
REM 
REM Terminal 2:
REM   set SERVER_PORT=7778
REM   set SYSTEM_ID=00000000-0000-0000-0000-000000000002
REM   LaunchDedicatedServer.bat
REM 
REM EXAMPLE 2: RegionalCluster with multiple systems
REM ----------------------------------------------------------------------------
REM Terminal 1:
REM   set SERVER_TYPE=RegionalCluster
REM   set SERVER_PORT=7777
REM   set REGION_ID=00000000-0000-0000-0000-000000000010
REM   LaunchDedicatedServer.bat
REM 
REM EXAMPLE 3: Quick launch command (single line)
REM ----------------------------------------------------------------------------
REM "C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe" ^
REM   "C:\Path\To\Echoes.uproject" ^
REM   GameLevel -server -log ^
REM   -Port=7777 ^
REM   -ServerType=DedicatedSystem ^
REM   -SystemId=00000000-0000-0000-0000-000000000001
REM 
REM EXAMPLE 4: Testing with different maps
REM ----------------------------------------------------------------------------
REM set MAP_NAME=EntryMap
REM LaunchDedicatedServer.bat
REM 
REM ============================================================================
