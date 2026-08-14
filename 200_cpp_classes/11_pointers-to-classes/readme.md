# 11. Pointers to Classes and Dynamic Memory Management

## Learning Objectives
- Master pointer operations with classes
- Understand dynamic memory allocation
- Learn deep vs shallow copy concepts
- Implement proper memory cleanup

## Pointers and Classes

* [pointer-to-classes.cpp](pointer-to-classes.cpp) - Pointer to Class Objects
  * Declaring pointers to class instances
  * Arrow operator (->) for member access
  * Pointer arithmetic with objects
  * Memory addresses of objects

* [struct_pointers.cpp](struct_pointers.cpp) - Pointers to Structures
  * Struct member access through pointers
  * Comparing struct and class pointers
  * Practical pointer usage

## Dynamic Memory Allocation

* [new-delete.cpp](new-delete.cpp) - New and Delete Operators
  * Dynamic memory allocation with new
  * Memory deallocation with delete
  * Heap vs Stack allocation
  * Memory leaks prevention
  * Null pointers after deletion

* [dynamic-arrays.cpp](dynamic-arrays.cpp) - Dynamic Arrays
  * Creating arrays at runtime
  * Variable-size arrays
  * Dynamic 2D arrays
  * Proper deletion of dynamic arrays

* [dynamic-array-example.cpp](dynamic-array-example.cpp) - Dynamic Array Applications
  * Practical use cases
  * Resizing arrays
  * Memory efficiency

## Copy Semantics

* [copy-constructor.cpp](copy-constructor.cpp) - Copy Constructor
  * Default copy behavior
  * Implementing custom copy constructor
  * When copy constructor is called
  * Deep copy implementation

* [shallow-deep-copy.cpp](shallow-deep-copy.cpp) - Shallow vs Deep Copy
  * Shallow copy problems with pointers
  * Deep copy benefits
  * Pointer aliasing issues
  * Proper resource management

## Advanced Pointers

* [pointers-classes-advanced.cpp](pointers-classes-advanced.cpp) - Advanced Pointer Techniques
  * Pointer to pointer
  * Array of pointers to objects
  * Void pointers (type-agnostic)
  * Generic programming with pointers

* [function-pointer.cpp](function-pointer.cpp) - Function Pointers
  * Pointers to member functions
  * Callback functions
  * Using function pointers
  * Callbacks in class context

* [full-example.cpp](full-example.cpp) - Complete Dynamic Memory Example
  * Comprehensive demonstration
  * Combining all concepts
  * Memory safety practices

## Static Members

* [static-members.cpp](static-members.cpp) - Static Class Members
  * Shared member variables
  * Static member initialization
  * Static methods
  * Class-level data

* [static-dynamic-sample.cpp](static-dynamic-sample.cpp) - Mixing Static and Dynamic
  * Combining static and dynamic allocation
  * Static members with objects
  * Practical applications
