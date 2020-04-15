# Tars Engine

## Engine Properties Configuration
All the following configurations must be done inside ***Debug*** Configuration:
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***Active Solution Platform*** >> ***Edit...*** and remove x86 platform.
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***Project Context*** >> ***Platform*** >> ***Edit...*** and remove x86 platform.

All the following configuration must be done inside ***All Configuration***:
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Configuration Type*** to `Dynamic Library (.dll)`.
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Output Directory*** inside ***General*** tree to `$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\`.
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Intermediate Directory*** inside ***General*** tree to `$(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\`.

## SandBox Properties Configuration
All the following configurations must be done inside ***Debug*** Configuration:
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***Active Solution Platform*** >> ***Edit...*** and remove x86 platform.
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***Project Context*** >> ***Platform*** >> ***Edit...*** and remove x86 platform.

All the following configuration must be done inside ***All Configuration***:
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Output Directory*** inside ***General*** tree to `$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\`.
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Intermediate Directory*** inside ***General*** tree to `$(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\`.

## Macros Configuration
All following configuration must be done inside ***All Configuration***:
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***C/C++*** and set ***Preprocessor Definitions*** to `<your-Macro-name>;`