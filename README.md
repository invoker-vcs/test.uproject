# Third Person

## Project Architecture

### Input Binding Structure

```mermaid
graph TD
    A[Define Native Gameplay Tags\n(e.g., Input.Jump, Input.Fire)] --> B[Create Input Config Data Asset\n(Map Input Tags to Input Actions)]
    B --> C[Custom Input Component\n(Binds Input Actions to Gameplay Tags)]
    C --> D[Binding Inputs\n(Define Input Callbacks)]
    D --> E[Assign Assets in Editor\n(Fill in Input Action Assets)]

    style A fill:#f9f,stroke:#333,stroke-width:1px
    style B fill:#bbf,stroke:#333,stroke-width:1px
    style C fill:#bfb,stroke:#333,stroke-width:1px
    style D fill:#ffd,stroke:#333,stroke-width:1px
    style E fill:#fcc,stroke:#333,stroke-width:1px

### Component Structure

- Base Pawn Extension Component (provides helper functions)

  - Pawn Combat Component (provides combat functionality shared by both enemy and player)
    - Hero Combat Component (logic specific to player)
    - Enemy Combat Component (logic specific to enemy)

- Base Gameplay Ability (provides helper functions)
  - Hero Gameplay Ability (logic specific to player)
  - Enemy Gameplay Ability (logic specific to enemy)

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

```

```

```
