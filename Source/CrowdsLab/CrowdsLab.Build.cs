// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CrowdsLab : ModuleRules
{
    public CrowdsLab(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add("CrowdsLab");

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","MassEntity", "MassCommon", "MassNavigation", "StructUtils", "MassMovement", "NavigationSystem",
            "AIModule", "MassAIBehavior", "StateTreeModule", "GameplayTags", "SmartObjectsModule", "MassSmartObjects", "MassSignals",
            "MassRepresentation", "MassLOD", "AnimToTexture" });
    }
}
