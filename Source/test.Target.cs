// © 2025 1nvoker - MIT License

using UnrealBuildTool;
using System.Collections.Generic;

public class testTarget : TargetRules
{
	public testTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "test" } );
	}
}
