// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Echoes : ModuleRules
{
	public Echoes(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"EnhancedInput", // For Enhanced Input System
			"HTTP", // For HTTP requests
			"Json", // For JSON parsing
			"JsonUtilities", // For JSON utilities
			"Niagara" // For Niagara VFX system
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
