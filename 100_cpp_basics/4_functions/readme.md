# 4. Functions and Program Modularization

## Learning Objectives
- Understand function definition and calling
- Master parameter passing techniques
- Learn about scope and lifetime of variables
- Implement pointers and references in functions

## Function Fundamentals

### Basic Functions
* [1_predefined-functions.cpp](1_predefined-functions.cpp) - Standard Library Functions
  * Built-in functions from C++ standard library
  * Mathematical functions (sqrt, pow, abs, etc.)
  * String functions
  * Using cmath, cstdlib headers

* [2_functions-1.cpp](2_functions-1.cpp) - Function Definition and Calling
  * Function syntax: return_type name(parameters)
  * Function declaration (prototype)
  * Function definition
  * Function call and return value
  * Pass by value mechanism

* [3_default-parameters.cpp](3_default-parameters.cpp) - Functions with Default Parameters
  * Declaring default parameter values
  * Calling functions with fewer arguments
  * Overriding default values
  * Rules for default parameter placement

### Pointers and References
* [4_pointers.cpp](4_pointers.cpp) - Pointer Fundamentals
  * Pointer declaration and initialization
  * Address-of operator (&)
  * Dereference operator (*)
  * Null pointers
  * Pointer arithmetic
  * Passing pointers to functions

* [5_cpp-references.cpp](5_cpp-references.cpp) - C++ References
  * Reference declaration and binding
  * Differences between pointers and references
  * References cannot be null
  * Pass by reference vs. pass by value
  * References in function parameters

### Working with Arrays in Functions
* [6_functions-and-arrays.cpp](6_functions-and-arrays.cpp) - Passing Arrays to Functions
  * Arrays decay to pointers
  * Function parameters: int arr[] notation
  * Size information loss when passing arrays
  * Passing array size as separate parameter
  * Returning pointers from functions

### Advanced Function Topics
* [7_static-vars.cpp](7_static-vars.cpp) - Static Variables and Functions
  * Static variables: lifetime and scope
  * Retained values between function calls
  * Initialization of static variables
  * Use cases: counters, caches
