# 8. Operator and Function Overloading

## Learning Objectives
- Understand function overloading concepts
- Master operator overloading techniques
- Learn the this pointer in class context
- Implement friend functions for special access

## Function Overloading

* [function-overloading.cpp](function-overloading.cpp) - Function Overloading Basics
  * Multiple functions with same name
  * Different parameter types/counts
  * Parameter matching (signature)
  * Return type cannot distinguish overloads

* [this-pointer.cpp](this-pointer.cpp) - The This Pointer
  * Understanding 'this' pointer in classes
  * Implicit parameter in member functions
  * Accessing class members through this
  * Usage in operator overloading

## Operator Overloading

* [operator-overloading.cpp](operator-overloading.cpp) - Basic Operator Overloading
  * Overloading +, -, *, / operators
  * Operator member function syntax
  * Returning new objects

* [unary-operator.cpp](unary-operator.cpp) - Unary Operators
  * Overloading ++, --, ! operators
  * Pre and post increment
  * Unary operator member functions

* [increment-operator.cpp](increment-operator.cpp) - Increment Operator Details
  * Pre-increment (++x)
  * Post-increment (x++)
  * Implementation differences

* [binary-operators.cpp](binary-operators.cpp) - Binary Operators
  * +, -, *, / overloading
  * Operator associativity
  * Creating new objects in operations

* [relational-operators.cpp](relational-operators.cpp) - Relational Operators
  * ==, !=, <, >, <=, >= overloading
  * Comparison logic
  * Boolean return values

* [subscript-operator.cpp](subscript-operator.cpp) - Subscript Operator []
  * Array-like access for objects
  * Bounds checking
  * Left and right side operations

* [assignment-operator.cpp](assignment-operator.cpp) - Assignment Operator
  * = operator overloading
  * Deep copy implementation
  * Self-assignment check

* [function-operator.cpp](function-operator.cpp) - Function Call Operator
  * Making objects callable as functions
  * Callable objects (functors)
  * Practical applications

## Special Overloading Techniques

* [iostream-operators.cpp](iostream-operators.cpp) - Input/Output Operators
  * << and >> operator overloading
  * Friend functions for stream operators
  * Formatted output

* [friend-function.cpp](friend-function.cpp) - Friend Functions
  * Non-member functions with class access
  * Friend function declaration
  * Breaking encapsulation intentionally

* [overload-with-friend.cpp](overload-with-friend.cpp) - Friend Operators
  * Operators overloaded as friend functions
  * When to use friend vs member functions
  * Symmetrical operations

* [c-polymorphizm.c](c-polymorphizm.c) - C-Style Polymorphism
  * Function pointers approach
  * Comparison with C++ operator overloading
  * Historical context
