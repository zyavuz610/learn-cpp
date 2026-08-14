# 4. Functions and Program Modularization

## Learning Objectives
- Understand function definition and calling
- Master parameter passing techniques
- Learn about scope and lifetime of variables
- Implement pointers and references in functions

## Function Fundamentals

### Basic Functions
* [predefined-functions.cpp](predefined-functions.cpp) - Standard Library Functions
  * Built-in functions from C++ standard library
  * Mathematical functions (sqrt, pow, abs, etc.)
  * String functions
  * Using cmath, cstdlib headers

* [functions-1.cpp](functions-1.cpp) - Function Definition and Calling
  * Function syntax: return_type name(parameters)
  * Function declaration (prototype)
  * Function definition
  * Function call and return value
  * Pass by value mechanism

* [default-parameters.cpp](default-parameters.cpp) - Functions with Default Parameters
  * Declaring default parameter values
  * Calling functions with fewer arguments
  * Overriding default values
  * Rules for default parameter placement

### Pointers and References
* [pointers.cpp](pointers.cpp) - Pointer Fundamentals
  * Pointer declaration and initialization
  * Address-of operator (&)
  * Dereference operator (*)
  * Null pointers
  * Pointer arithmetic
  * Passing pointers to functions

* [cpp-references.cpp](cpp-references.cpp) - C++ References
  * Reference declaration and binding
  * Differences between pointers and references
  * References cannot be null
  * Pass by reference vs. pass by value
  * References in function parameters

### Working with Arrays in Functions
* [functions-and-arrays.cpp](functions-and-arrays.cpp) - Passing Arrays to Functions
  * Arrays decay to pointers
  * Function parameters: int arr[] notation
  * Size information loss when passing arrays
  * Passing array size as separate parameter
  * Returning pointers from functions

### Advanced Function Topics
* [static-vars.cpp](static-vars.cpp) - Static Variables and Functions
  * Static variables: lifetime and scope
  * Retained values between function calls
  * Initialization of static variables
  * Use cases: counters, caches
