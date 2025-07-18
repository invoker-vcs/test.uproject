# Third Person

## Input Actions

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

## Animation Blueprint

### Animation Layer Interface

```
AnimLayer Interface (declares states)
↓
Fire State (empty, no animation)
↓
Idle State (empty, no animation)
```

```
Animation Blueprint (implements interface)
↓
AnimLayer Interface (plug empty states into outputs)
```

```
AnimLayer Interface
↓
ABP_BaseAnimLayer (implements interface, define states, create variables)
↓
ABP_UnarmedLayer, ABP_PistolLayer (fill in actual anim assets)
```

## Data

### Character Startup Data

```
Character Startup Data Asset (grant input tag to ability)
↓
Give to Hero Character (abilities tagged with input tags)
```

### Weapon Data

```
Hero Weapon Data
↓
Default Weapon Ability (UnEquipAxe, AxeLightAttack/AxeHeavyAttack)
↓
Input Mapping Context (override key binding, weapon key binding)
↓
Anim Layer to Link
```

## Structure

### Component Structure

- Base Pawn Extension Component (provides helper functions)

  - Pawn Combat Component (provides combat functionality shared by both enemy and player)
    - Hero Combat Component (logic specific to player)
    - Enemy Combat Component (logic specific to enemy)

- Base Gameplay Ability (provides helper functions)
  - Hero Gameplay Ability (logic specific to player)
  - Enemy Gameplay Ability (logic specific to enemy)

### Weapon Class Structure

- Base Weapon (handles damage detection)
  - Hero Weapon (weapon data unique to player)

## Setups

### New Ability Process

1. Ability Tags
2. Gameplay Ability
3. Anim Montage
4. Ability Input Action
5. Grant Ability

## New Enemy Character Process

1. Enemy Character Class
2. Enemy Startup Data Asset
3. Enemy Gameplay Ability
4. Enemy Combat Component

#

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
