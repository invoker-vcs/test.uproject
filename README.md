[comment] ------------------------------ START OF THIRD PERSON ------------------------------

### Project Settings

- Change copyright notice
- Change Editor Startup Map
- Change Game Default Map
- Change Default GameMode to "GM_ThirdPerson"
- Update Default InputComponent Class to "TPInputComponent"

### Editor Preferences

- Code Editor - VS Code
- Disable Live Coding
- Disable automatically compile newly added C++ classes

### Plugins

### Build.cs

- EnhancedInput
- GameplayTags

### Miscellaneous

.vscode -> settings.json

```
{
  "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
  "files.associations": {
    "*.h": "cpp"
  },
  "editor.formatOnSave": true,
  "C_Cpp.intelliSenseEngine": "default"
}
```

.vscode -> c_cpp_properties.json

```
"includePath": [
	"${workspaceFolder}/Source",
	"${workspaceFolder}/Source/test",
	"${workspaceFolder}/Source/test/Public",
	"${workspaceFolder}/Source/test/Private",
	"${workspaceFolder}/Intermediate/Build/Win64",
],
```

[comment] ------------------------------ END OF THIRD PERSON ------------------------------
