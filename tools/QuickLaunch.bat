@echo off
REM ============================================================================
REM Quick Launch Menu for Echoes Dedicated Server Testing
REM ============================================================================
REM This script provides a menu-driven interface for common test scenarios
REM ============================================================================

setlocal

:MENU
cls
echo.
echo ========================================================================
echo  Echoes MMO - Dedicated Server Quick Launch Menu
echo ========================================================================
echo.
echo Select a test scenario:
echo.
echo  1. Single System Server (Port 7777)
echo  2. Two System Servers (Ports 7777, 7778)
echo  3. Regional Cluster Server (Port 7777)
echo  4. Custom Configuration
echo  5. Exit
echo.
echo ========================================================================
echo.

set /p choice="Enter your choice (1-5): "

if "%choice%"=="1" goto SINGLE_SYSTEM
if "%choice%"=="2" goto TWO_SYSTEMS
if "%choice%"=="3" goto REGIONAL_CLUSTER
if "%choice%"=="4" goto CUSTOM
if "%choice%"=="5" goto END

echo Invalid choice. Please try again.
timeout /t 2 >nul
goto MENU

REM ============================================================================
REM SINGLE SYSTEM SERVER
REM ============================================================================
:SINGLE_SYSTEM
cls
echo.
echo ========================================================================
echo  Launching Single System Server
echo ========================================================================
echo.
echo Configuration:
echo   Server Type: DedicatedSystem
echo   Port: 7777
echo   System ID: 00000000-0000-0000-0000-000000000001
echo.

set "SERVER_PORT=7777"
set "SERVER_TYPE=DedicatedSystem"
set "SYSTEM_ID=00000000-0000-0000-0000-000000000001"

call "%~dp0LaunchDedicatedServer.bat"

goto MENU

REM ============================================================================
REM TWO SYSTEM SERVERS (for testing)
REM ============================================================================
:TWO_SYSTEMS
cls
echo.
echo ========================================================================
echo  Launching Two System Servers
echo ========================================================================
echo.
echo This will open two separate command windows:
echo.
echo   Server 1: Port 7777, System ID: ...001
echo   Server 2: Port 7778, System ID: ...002
echo.
echo Press any key to continue...
pause >nul

REM Launch first server in new window
start "Echoes Server 1 (Port 7777)" cmd /k "cd /d "%~dp0" && set SERVER_PORT=7777 && set SYSTEM_ID=00000000-0000-0000-0000-000000000001 && LaunchDedicatedServer.bat"

REM Wait a moment before launching second server
timeout /t 2 >nul

REM Launch second server in new window
start "Echoes Server 2 (Port 7778)" cmd /k "cd /d "%~dp0" && set SERVER_PORT=7778 && set SYSTEM_ID=00000000-0000-0000-0000-000000000002 && LaunchDedicatedServer.bat"

echo.
echo Two servers launched in separate windows.
echo Close those windows to stop the servers.
echo.
pause
goto MENU

REM ============================================================================
REM REGIONAL CLUSTER SERVER
REM ============================================================================
:REGIONAL_CLUSTER
cls
echo.
echo ========================================================================
echo  Launching Regional Cluster Server
echo ========================================================================
echo.
echo Configuration:
echo   Server Type: RegionalCluster
echo   Port: 7777
echo   Region ID: 00000000-0000-0000-0000-000000000010
echo.

set "SERVER_PORT=7777"
set "SERVER_TYPE=RegionalCluster"
set "REGION_ID=00000000-0000-0000-0000-000000000010"

call "%~dp0LaunchDedicatedServer.bat"

goto MENU

REM ============================================================================
REM CUSTOM CONFIGURATION
REM ============================================================================
:CUSTOM
cls
echo.
echo ========================================================================
echo  Custom Server Configuration
echo ========================================================================
echo.

REM Server Type
echo Select Server Type:
echo   1. DedicatedSystem
echo   2. RegionalCluster
echo.
set /p type_choice="Enter choice (1-2): "

if "%type_choice%"=="1" (
    set "SERVER_TYPE=DedicatedSystem"
) else if "%type_choice%"=="2" (
    set "SERVER_TYPE=RegionalCluster"
) else (
    echo Invalid choice.
    timeout /t 2 >nul
    goto CUSTOM
)

REM Port
echo.
set /p SERVER_PORT="Enter port number (default 7777): "
if "%SERVER_PORT%"=="" set "SERVER_PORT=7777"

REM ID based on type
if "%SERVER_TYPE%"=="DedicatedSystem" (
    echo.
    echo Enter System ID (GUID format):
    echo Example: 00000000-0000-0000-0000-000000000001
    set /p SYSTEM_ID="System ID: "
    if "%SYSTEM_ID%"=="" set "SYSTEM_ID=00000000-0000-0000-0000-000000000001"
) else (
    echo.
    echo Enter Region ID (GUID format):
    echo Example: 00000000-0000-0000-0000-000000000010
    set /p REGION_ID="Region ID: "
    if "%REGION_ID%"=="" set "REGION_ID=00000000-0000-0000-0000-000000000010"
)

echo.
echo ========================================================================
echo  Launching Custom Configuration
echo ========================================================================
echo.
echo Configuration:
echo   Server Type: %SERVER_TYPE%
echo   Port: %SERVER_PORT%
if "%SERVER_TYPE%"=="DedicatedSystem" (
    echo   System ID: %SYSTEM_ID%
) else (
    echo   Region ID: %REGION_ID%
)
echo.

call "%~dp0LaunchDedicatedServer.bat"

goto MENU

REM ============================================================================
REM END
REM ============================================================================
:END
echo.
echo Exiting...
endlocal
exit /b 0
