// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Echoes : ModuleRules
{
	public Echoes(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[] {
			ModuleDirectory
		});

		PrivateIncludePaths.AddRange(new string[] {
			ModuleDirectory
		});

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"EnhancedInput", // For Enhanced Input System
			"HTTP", // For HTTP requests
			"Json", // For JSON parsing
			"JsonUtilities", // For JSON utilities
			"Niagara", // For Niagara VFX system
			"UMG", // For UMG widgets
			"Slate", // For Slate UI
			"SlateCore" // For Slate core functionality
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
