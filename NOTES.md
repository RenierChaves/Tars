# C++

## #include
You specify which file do you want to include and the preprocessor will open that file, read all of its content and just paste it into the file where you wrote your `#include` statement.

## Header Files
The declaration tells the compiler whether the element is an int, a double, a function, a class or some other thing. Furthermore, each name must be declared (directly or indirectly) in every .cpp file in which it is used. When you compile a program, each .cpp file is compiled independently into a compilation unit. The compiler has no knowledge of what names are declared in other compilation units. That means that if you use a class or function or global variable, you must provide a declaration of that thing in each additional .cpp file that uses it. Each declaration of that thing must be exactly identical in all files. A slight inconsistency will cause errors, or unintended behavior, when the linker attempts to merge all the compilation units into a single program.

In a header file, we just declare our function or variable or class, we do not define it, we do not say what it does. When we declare a function in a header file and include this header file in our .cpp file using #include we are telling the compiler that we want to use that function but we do not want to define it because it is already defined in some other file.

## Reference
A reference variable is a "reference" to an existing variable, and it is created with the `&` operator.
```C++
string food = "Pizza";
string& meal = food;

std::cout << food << std::endl;  // Outputs Pizza
std::cout << meal << std::endl;  // Outputs Pizza
```
When a variable is created in C++, a memory address is assigned to the variable. And when we assign a value to the variable, it is stored in this memory address. To access it, use the `&` operator, and the result will represent where the variable is stored:
```C++
string food = "Pizza";

std::cout << &food; // Outputs 0x6dfed4
```

## Pointers
When a variable is created in C++, a memory address is assigned to the variable. And when we assign a value to the variable, it is stored in this memory address. A pointer, however, is a variable that stores the memory address as its value. A pointer variable points to a data type (like int or string) of the same type and is created with the `*` operator. The address of the variable you're working with is assigned to the pointer. To access the memory address of a variable, just use the reference `&` operator before the variable, and the result will represent where the variable is stored:
```C++
int number = 10;
int* myPointer = &number; // Outputs 0x6dfed4
```

### Dereference
However, you can also use the pointer to access and change the value of the variable, by using the operator `*` before the pointer variable (the Dereference operator):
```C++
int test = 10;  // Variable declaration
int* myPointer = &test;    // Pointer declaration

std::cout << myPointer << std::endl; // Outputs 0x6dfed4
std::cout << *myPointer << std::endl; // Outputs 10

*myPointer = 5; // Change test variable to 5

std::cout << test << std::endl; // Outputs 5
std::cout << myPointer << std::endl // Outputs 0x6dfed4
```

### Parameters by Pointers or Reference
In C++, variables are passed to a function by value. When calling a function with an argument, a new variable is instantiated internally and assigned the value passed in the function call. Any modifications to the value inside the function are performed to this new variable; the variable that was invoked with the function call is unchanged.
A function can be written to perform the same task but instead accept a pointer as the argument. This lowers the memory footprint of the program. Unnecessary duplicate variables aren't created. The function can modify the variable's value directly. Any modifications to the variable in the function affect the variable here in this scope too.
```c++
void setValue(int* x) {
    *x = 5;
}

int x = 3;
setValue(&x); // Pass the memory address
std::cout << "The value of x is " << x << ", setValue() modified x." << std::endl;
// Outputs: The value of x is 5, setValue() modified x
```

In C++ (not in C), you can pass a variable by reference by passing in a variable,
and defining the function's parameter like `int& x`. Any modifications to the variable inside the function will also affect the variable here in this scope too.

```c++
void setValue(int& x) {
    x = 5;
}

int x = 3;
setValue( x );
std::cout << "The value of x is " << x << ", setValue() modified x." << std::endl;
// Outputs: The value of x is 5, setValue() modified x
```

### Pointer and Classes
Objects can also be pointed to by pointers: Once declared, a class becomes a valid type, so it can be used as the type pointed to by a pointer. Similarly as with plain data structures, the members of an object can be accessed directly from a pointer by using the arrow operator (`->`).

## Macro - C++
A macro is a fragment of code that has been given a name. Whenever the name is used, it is replaced by the contents of the macro. Preprocessor directives are lines included in the code of programs preceded by a hash sign (#). The `#ifdef` (if defined) and #ifndef (if not defined) preprocessor commands are used to test if a preprocessor macro has been "defined", if it is, the code inside the scope will be compiled.

## `extern` keyword
The extern keyword specifies that a variable, function, or template is already defined in somewhere else.

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

# Tars

## Entry Point Explained
To understand how an entry point works, need to take a look into two files, first the **EntryPoint.h** file:
```C++
#pragma once

#ifdef TARS_PLATFORM_WINDOWS

extern Tars::Application* Tars::CreateApplication();

int main(int argc, char** argv) {
	auto app = Tars::CreateApplication();
	app->Run();
	delete app;
}

#endif
```
And the **SandboxApp.cpp** file:
```C++
#include <Tars.h>

class SandBox : public Tars::Application {
public:
	SandBox() {

	}

	~SandBox() {

	}
};

Tars::Application* Tars::CreateApplication() {
	return new SandBox();
}
```
It is important to remember that this EntryPoint.h file was [included](##include) in the Tars.h file, which was included in SandboxApp.cpp. Therefore, the entire content of EntryPoint.h is included in SandboxApp.cpp too.

The EntryPoint.h file is the Entry Point of our program, which is where we will create a new application. So let's take a look into EntryPoint.h file:

### `TARS_PLATFORM_WINDOWS`
The `#ifdef TARS_PLATFORM_WINDOWS` is an if statement, which means that if the Macro `TARS_PLATFORM_WINDOWS` is true the code inside its scope will be compiled. 
```C++
#ifdef TARS_PLATFORM_WINDOWS

// Code in here...

#endif
```

### `extern Tars::CreateApplication()`
The `extern Tars::Application* Tars::CreateApplication()` statement tells the compiler that the `Tars::CreateApplication` function is defined somewhere else. If we take a close look in the SandboxApp.cpp, the `Tars::CreateApplication` is defined there and returns a `new SandBox()` instance.
```C++
extern Tars::Application* Tars::CreateApplication();
```

### `main()`
Notice that SandboxApp.cpp does not have a main() function, this is because its main function will be implemented after the compiling process. Remember that, we wrote a main() function in EntryPoint.h. That function will be included here, after the compiling process finish. So when we run the program there will be a main() to start the application.

Inside `main()` function, the `auto` keyword tells the compiler to automatically define the variable’s type from the initializer’s type. So, that means that we do not know which type of application (in C++, class name is a type) our client will create, so its much easier to tell the compiler to define the variable type when its created.

The `app->Run()` statement uses `->`, because the CreateApplication function return a pointer to the client application (a class), remember that: 
> Members of an object can be accessed directly from a pointer by using the arrow operator (`->`).
```C++
int main(int argc, char** argv) {
	auto app = Tars::CreateApplication();
	app->Run();
	delete app;
}
```
