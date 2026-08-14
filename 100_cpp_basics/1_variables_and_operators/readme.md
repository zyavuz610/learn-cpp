# 1. Variables and Operators

## Learning Objectives
- Understand different data types in C++
- Learn variable declaration and initialization
- Master arithmetic, relational, and logical operators
- Work with type casting techniques

## Core Concepts

### Data Types & Variables
* [data-types.cpp](data-types.cpp) - Fundamental Data Types
  * Primitive types: int, float, double, char, bool
  * Size of each data type using sizeof()
  * Integer ranges and floating-point precision
  * Memory allocation for variables

* [variable-definition.cpp](variable-definition.cpp) - Variable Declaration and Initialization
  * Syntax for declaring variables
  * Different initialization methods
  * Variable naming conventions
  * Scope of variables

* [local-global-variables.cpp](local-global-variables.cpp) - Variable Scope and Lifetime
  * Local variables (function scope)
  * Global variables (program scope)
  * Static variables behavior
  * Scope resolution operator (::)

* [constants-litterals.cpp](constants-litterals.cpp) - Constants and Literal Values
  * Using const keyword for named constants
  * Different types of literals
  * Character and string literals
  * Preprocessor directive #define

### Operators
* [operators.cpp](operators.cpp) - All Operator Types in C++
  * Arithmetic operators (+, -, *, /, %)
  * Relational operators (==, !=, <, >, <=, >=)
  * Logical operators (&&, ||, !)
  * Bitwise operators (&, |, ^, ~, <<, >>)
  * Assignment operators (=, +=, -=, etc.)
  * Increment/Decrement (++, --)
  * Operator precedence and associativity

### Type Casting
* [type-convertion.cpp](type-convertion.cpp) - Type Conversion and Casting
  * Implicit (automatic) type conversion
  * Explicit type conversion
  * C-style casting
  * Potential data loss in conversions
  * Integer to float and vice versa

### Advanced Casting Operators
* [const_cast.cpp](const_cast.cpp) - Const_cast Operator
  * Removing const qualifier
  * Use cases and best practices
  * When const_cast indicates design issues

* [reinterpret-cast.cpp](reinterpret-cast.cpp) - Reinterpret_cast Operator
  * Low-level type reinterpretation
  * Pointer type casting
  * Platform-dependent behavior
  * Dangerous usage scenarios