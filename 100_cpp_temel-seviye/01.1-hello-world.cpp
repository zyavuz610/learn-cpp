#include <iostream>
using namespace std;

int main() {
  cout << "Merhaba herkese\n";
  return 0;
}

/*
Similarities between C and C++ are:

Both the languages have a similar syntax.
Code structure of both the languages are same.
The compilation of both the languages is similar.
They share the same basic syntax. Nearly all of C’s operators and keywords are also present in C++ and do the same thing.
C++ has a slightly extended grammar than C, but the basic grammer is the same.
Basic memory model of both is very close to the hardware.
Same notions of stack, heap, file-scope and static variables are present in both the languages.

C	vs C++
=======================================
C was developed by Dennis Ritchie between the year 1969 and 1973 at AT&T Bell Labs.	
C++ was developed by Bjarne Stroustrup in 1979.
=======================================
C does no support polymorphism, encapsulation, and inheritance which means that C does not support object oriented programming.	
C++ supports polymorphism, encapsulation, and inheritance because it is an object oriented programming language.
=======================================
C is a subset of C++.	
C++ is a superset of C.
=======================================
C contains 32 keywords.	
C++ contains 52 keywords.
=======================================
For the development of code, C supports procedural programming.	
C++ is known as hybrid language because C++ supports both procedural and object oriented programming paradigms.
=======================================
Data and functions are separated in C because it is a procedural programming language.	
Data and functions are encapsulated together in form of an object in C++.
=======================================
C does not support information hiding.	
Data is hidden by the Encapsulation to ensure that data structures and operators are used as intended.
=======================================
Built-in data types is supported in C.	
Built-in & user-defined data types is supported in C++. (e.g.string)
  C-style string || std::string
=======================================
C is a function driven language because C is a procedural programming language.	
C++ is an object driven language because it is an object oriented programming.
=======================================
Function and operator overloading is not supported in C.	
Function and operator overloading is supported by C++.
=======================================
C is a function-driven language. (ana bileşen:fonksiyon)
C++ is an object-driven language (ana bileşen, nesne)
=======================================
Functions in C are not defined inside structures.	
Functions can be used inside a structure in C++.
=======================================
Namespace features are not present inside the C.	
Namespace is used by C++, which avoid name collisions.
=======================================
Header file used by C is stdio.h.	
Header file used by C++ is iostream.h.
=======================================
Reference variables are not supported by C.	
Reference variables are supported by C++.
=======================================
Virtual and friend functions are not supported by C.	
Virtual and friend functions are supported by C++.
=======================================
C does not support inheritance.	
C++ supports inheritance.
=======================================
Instead of focusing on data, C focuses on method or process.	
C++ focuses on data instead of focusing on method or procedure.
=======================================
C provides malloc() and calloc() functions for dynamic memory allocation, and free() for memory de-allocation.	
C++ provides new operator for memory allocation and delete operator for memory de-allocation.
=======================================
Direct support for exception handling is not supported by C.	
Exception handling is supported by C++.
=======================================
scanf() and printf() functions are used for input/output in C.	
cin and cout are used for input/output in C++.

Ref: https://www.geeksforgeeks.org/difference-between-c-and-c/
*/
