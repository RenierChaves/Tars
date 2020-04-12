# C++

## #include
You specify wich file do you want to include and the preprocessor will open that file, read all of its content and just paste it into the file where your wrote your `#include` statement.

## Reference
A reference variable is a "reference" to an existing variable, and it is created with the `&` operator.
```C++
string food = "Pizza";
string &meal = food;

std::cout << food << std::endl;  // Outputs Pizza
std::cout << meal << std::endl;  // Outputs Pizza
```
When a variable is created in C++, a memory address is assigned to the variable. And when we assign a value to the variable, it is stored in this memory address. To access it, use the & operator, and the result will represent where the variable is stored:
```C++
string food = "Pizza";

std::cout << &food; // Outputs 0x6dfed4
```

## Pointers
When a variable is created in C++, a memory address is assigned to the variable. And when we assign a value to the variable, it is stored in this memory address. A pointer however, is a variable that stores the memory address as its value. A pointer variable points to a data type (like int or string) of the same type, and is created with the * operator. The address of the variable you're working with is assigned to the pointer. To access the memory address of a variable, just use the Reference operator (`&`) before the variable name, and the result will represent where the variable is stored:
```C++
int number = 10;
int* myPointer = &number; // Outputs 0x6dfed4
```

However, you can also use the pointer to get the value of the variable, by using the * operator before the pointer variable (the dereference operator):
```C++
int number = 10;  // Variable declaration
int* myPointer = &number;    // Pointer declaration

std::cout << myPointer << std::endl; // Outputs 0x6dfed4
std::cout << *myPointer << std::endl; // Outputs 10
```

However, you can also access the variable value and change it through a pointer:
```C++
int number = 10;  // Variable declaration
int* myPointer = &number;    // Pointer declaration

std::cout << myPointer << std::endl; // Outputs 0x6dfed4
std::cout << *myPointer << std::endl; // Outputs 10

*myPointer = 5;

std::cout << number << std::endl; // Outputs 5
std::cout << myPointer << std::endl // Outputs 0x6dfed4
```

# Tars Engine

## Engine Properties Configuration
All the following configurations must be done inside ***Debug*** Configuration:
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***Active Solution Platform*** >> ***<Edit...>*** and remove x86 platform.
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***Project Context*** >> ***Platform*** >> ***<Edit...>*** and remove x86 platform.

All the following configuration must be done inside ***All Configuration***:
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Configuration Type*** to `Dynamic Library (.dll)`.
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Output Directory*** inside ***General*** tree to `$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\`.
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Intermediate Directory*** inside ***General*** tree to `$(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\`.

## SandBox Properties Configuration
All the following configurations must be done inside ***Debug*** Configuration:
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***Active Solution Platform*** >> ***<Edit...>*** and remove x86 platform.
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***Project Context*** >> ***Platform*** >> ***<Edit...>*** and remove x86 platform.

All the following configuration must be done inside ***All Configuration***:
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Output Directory*** inside ***General*** tree to `$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\`.
- Right-Button in your project and select ***Properties*** >> ***Configuration Properties*** >> ***General*** and set ***Intermediate Directory*** inside ***General*** tree to `$(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\`.

## Macros Configuration
All following configuration must be done inside ***All Configuration***:
- Right-Button in your project and select ***Properties*** >> ***Configuration Manager*** >> ***C/C++*** and set ***Preprocessor Definitions*** to `<your-Macro-name>;`

# Tars
## Macro - C++
A macro is a fragment of code which has been given a name. Whenever the name is used, it is replaced by the contents of the macro. Preprocessor directives are lines included in the code of programs preceded by a hash sign (#).
### Macro in SandBox explained
When SandBox is compiled, it will run the EntryPoint.h because of the TARS_PLATFORM_WINDOWS Macro. The compiler will be notified that Tars::CreateApplication (because of the extern key-word) is already defined somewhere else, leading him to SandBox.cpp where the definition is settled.