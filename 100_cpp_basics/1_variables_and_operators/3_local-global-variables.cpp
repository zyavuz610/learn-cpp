#include <iostream>     // Required library for cout and endl

// Function prototype: Declares 'topla' function before main function
// This tells compiler that 'topla' function exists and will be defined later
int topla(int, int); 

// GLOBAL VARIABLE
// Accessible from any function in the program
// Automatically initialized to 0 by the system
// Scope: entire program (all functions)
int g;

int main() {
    // LOCAL VARIABLES
    // Only accessible within the main() function
    // Must be explicitly initialized by the programmer
    int a, b;
    
    // Assigning values to local variables
    a = 10;
    b = 20;

    // Accessing global variable from main() and assigning value
    g = a + b;
    
    // Calling topla() function with a and b as arguments
    // The function returns their sum and assigns it to global variable g
    g = topla(a, b); 
    
    // Display the final value of global variable g
    std::cout << g << std::endl;
    
    // Note: The '::' operator is the scope resolution operator
    // It specifies the namespace (std) where cout and endl are defined
    // If we used: using namespace std;
    // We could simplify the above line to: cout << g << endl;

    return 0;
}

// FUNCTION DEFINITION
// Function name: topla (meaning "sum" or "add")
// Parameters: x, y (formal parameters/arguments)
int topla(int x, int y) {
    // FORMAL PARAMETERS (FUNCTION PARAMETERS)
    // Parameters receive the values passed when function is called
    // x receives value of 'a' (10), y receives value of 'b' (20)
    // Scope: only within topla() function
    // Parameters act like local variables inside the function
    
    // Return statement: sends result back to caller
    return x + y;
}

/*
============================================
THREE TYPES OF VARIABLE SCOPE
============================================

1. LOCAL VARIABLES (Local Scope)
   - Scope: Only within the block where defined
   - Lifetime: Created when block is entered, destroyed when exited
   - Initialization: Must be explicitly initialized by programmer
   - Example: Variables inside main() or other functions
   
2. FORMAL PARAMETERS (Parameter Scope)
   - Scope: Only within the function where defined as parameter
   - Lifetime: Exists during function execution
   - Initialization: Automatically initialized when function is called
   - Act like local variables within their function
   - Receive their values from arguments passed to function
   
3. GLOBAL VARIABLES (Global/File Scope)
   - Scope: Entire program (all functions can access)
   - Lifetime: Entire program execution
   - Initialization: Automatically initialized to 0 by system
   - Defined outside all functions
   - Can be accessed from any function

INITIALIZATION RULES:
- Global variables: automatically initialized to 0
- Local variables: MUST be explicitly initialized
- Parameters: initialized when function is called

SCOPE RULE:
Any declaration becomes valid for all statements AFTER it in the same scope

CORRECT CODE:
  int a = 5, b = 6, c;
  ...
  c = a + b;        // OK: a, b, c already declared

INCORRECT CODE:
  c = a + b;        // ERROR: a, b, c not yet declared
  ...
  int a = 0, b = 3, c;

============================================
ARGUMENTS vs PARAMETERS (Don't Confuse!)
============================================

PARAMETERS:
- Variables in function definition
- Appear in function declaration/definition
- Formal variables that receive values
- Example: int topla(int x, int y) { ... }
           ^^^^^    ^^^^^^^^ These are PARAMETERS

ARGUMENTS:
- Actual values passed when calling function
- Appear in function call
- Values sent to the function
- Example: topla(10, 20);
           ^^^^^^^^^^ These are ARGUMENTS (10 and 20)

HOW THEY WORK:
- Parameters (x, y) receive values from arguments (10, 20)
- Parameter x gets value 10, parameter y gets value 20
- Parameters are local variables within the function

============================================
NAME CONFLICTS: GLOBAL vs LOCAL
============================================

When a local variable has the SAME NAME as a global variable:
- Local variable shadows (hides) the global variable
- Local variable takes precedence
- Use scope resolution operator (::) to access global

EXAMPLE:

#include <iostream>
using namespace std;

int g = 10;         // Global variable g

int main() {
    int g = 20;    // Local variable g (shadows global g)
    
    // Using local g:
    cout << "Local g: " << g << endl;          // Output: 20
    
    // Accessing global g with scope resolution operator:
    cout << "Global g: " << ::g << endl;       // Output: 10
    
    return 0;
}

SCOPE RESOLUTION OPERATOR (::)
- Syntax: ::variable_name
- Accesses global variable when local variable shadows it
- Only works for global variables
- Format: :: (two colons)
*/
