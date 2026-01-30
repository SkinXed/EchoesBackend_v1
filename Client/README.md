# Echoes - Unreal Engine 5.6 Project

This directory contains the Unreal Engine 5.6 client project for Echoes.

## Project Information

- **Engine Version**: Unreal Engine 5.6
- **Project Name**: Echoes
- **Target Platforms**: Windows, Linux, Mac

## Requirements

- Unreal Engine 5.6 installed
- Visual Studio 2022 (for Windows) or appropriate C++ compiler for your platform

## Opening the Project

1. Navigate to `Client/Echoes/`
2. Double-click on `Echoes.uproject` to open in Unreal Engine 5.6
3. The first time you open the project, UE may ask to rebuild modules - click Yes

## Project Structure

```
Client/Echoes/
├── Config/              # Project configuration files
├── Content/             # Game assets (blueprints, materials, meshes, etc.)
├── Source/              # C++ source code
│   └── Echoes/          # Main game module
├── Echoes.uproject      # Unreal Engine project file
```

## Building the Project

From the command line:
```bash
# Generate project files
<UE5.6Path>/Engine/Build/BatchFiles/GenerateProjectFiles.bat Echoes.uproject

# Build the project
<UE5.6Path>/Engine/Build/BatchFiles/Build.bat EchoesEditor Win64 Development Echoes.uproject
```

Or simply open the .uproject file and let Unreal Engine build it automatically.
