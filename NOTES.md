# Tars Engine

## Engine Properties Configuration
All the following configurations must be done inside *Debug* Configuration:
- Right-Button in your project and select *Properties* >> *Configuration Manager* >> *Active Solution Platform* >> *`<Edit...>`* and remove x86 platform.
- Right-Button in your project and select *Properties* >> *Configuration Manager* >> *Project Context* >> *Platform* >> *`<Edit...>`* and remove x86 platform.

All the following configuration must be done inside *All Configuration*:
- Right-Button in your project and select *Properties* >> *Configuration Properties* >> *General* and set *Configuration Type* to `Dynamic Library (.dll)`.
- Right-Button in your project and select *Properties* >> *Configuration Properties* >> *General* and set *Output Directory* inside *General* tree to `$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\`.
- Right-Button in your project and select *Properties* >> *Configuration Properties* >> *General* and set *Intermediate Directory* inside *General* tree to `$(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\`.

## SandBox Properties Configuration
All the following configurations must be done inside *Debug* Configuration:
- Right-Button in your project and select *Properties* >> *Configuration Manager* >> *Active Solution Platform* >> *`<Edit...>`* and remove x86 platform.
- Right-Button in your project and select *Properties* >> *Configuration Manager* >> *Project Context* >> *Platform* >> *`<Edit...>`* and remove x86 platform.

All the following configuration must be done inside *All Configuration*:
- Right-Button in your project and select *Properties* >> *Configuration Properties* >> *General* and set *Output Directory* inside *General* tree to `$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\`.
- Right-Button in your project and select *Properties* >> *Configuration Properties* >> *General* and set *Intermediate Directory* inside *General* tree to `$(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\`.

## Macros Configuration
All following configuration must be done inside *All Configuration*:
- Right-Button in your project and select *Properties* >> *Configuration Manager* >> *C/C++* and set *Preprocessor Definitions* to `<your-Macro-name>;`

# Tars
## Macro - C++
A macro is a fragment of code which has been given a name. Whenever the name is used, it is replaced by the contents of the macro. Preprocessor directives are lines included in the code of programs preceded by a hash sign (#).
### Macro in SandBox explained
When SandBox is compiled, it will run the EntryPoint.h because of the TARS_PLATFORM_WINDOWS Macro. The compiler will be notified that Tars::CreateApplication (because of the extern key-word) is already defined somewhere else, leading him to SandBox.cpp where the definition is settled.