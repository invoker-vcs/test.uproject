// © 2025 1nvoker - MIT License

using UnrealBuildTool;
using System.Collections.Generic;

public class testEditorTarget : TargetRules
{
	public testEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "test" } );
	}
}
