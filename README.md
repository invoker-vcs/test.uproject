# Third Person

## Project Architecture

### Binding Native Inputs

```
Define Native Gameplay Tags (define input tags)
↓
Input Config Data Asset (map input tags to actions)
↓
Custom Input Component (bind input actions to gameplay tags)
↓
Bind Input Callbacks (define input callbacks in the component)
↓
Assign Assets in Editor (assign input config data asset to the component in the editor)
```

### Binding Ability Inputs

```
Input Component (pass input tag to callback)
↓
Character (pass onto ASC)
↓
Ability System Component (use input tag to activate ability)
↓
Ability Triggered
```

### Character Startup Data

```
Character Startup Data Asset (grant input tag to ability)
↓
Give to Hero Character (abilities tagged with input tags)
```

### Component Structure

- Base Pawn Extension Component (provides helper functions)

  - Pawn Combat Component (provides combat functionality shared by both enemy and player)
    - Hero Combat Component (logic specific to player)
    - Enemy Combat Component (logic specific to enemy)

- Base Gameplay Ability (provides helper functions)
  - Hero Gameplay Ability (logic specific to player)
  - Enemy Gameplay Ability (logic specific to enemy)

## Configuration

### Project Settings

- Change copyright notice
- Change Editor Startup Map
- Change Game Default Map
- Change GameMode to "GM_TPBase"
- Update Default InputComponent Class to "TPInputComponent"

### Editor Preferences

- Code Editor - VS Code
- Disable Live Coding
- Disable automatically compile newly added C++ classes

### Plugins

- Gameplay Abilities

### Build.cs

- EnhancedInput
- GameplayTags

### Miscellaneous

.vscode -> settings.json

```

{
"C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
"files.associations": {
"\*.h": "cpp"
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
