// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MemoryOfMoon : ModuleRules
{
	public MemoryOfMoon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"LevelSequence",
			"MovieScene",
			"UMG",
			"Slate", 
			"SlateCore"
		});
		
		PublicIncludePaths.AddRange(new string[] { "MemoryOfMoon" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
