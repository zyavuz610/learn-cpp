// for_dongusu.cpp
// Example: For loop that prints numbers from 0 to 9

#include <iostream>
using namespace std;

/*
============================================
FOR LOOP - 4 ESSENTIAL COMPONENTS
============================================

Loops have 4 main parts:

1. INITIALIZATION (expression1)
   - Code executed before loop starts
   - Usually declares and initializes loop counter
   - Optional: can be empty
   - Example: int i = 0;  or  i = 1;  or  int i=0, j=5;

2. CONDITION (expression2)
   - Required: loop continues while condition is TRUE
   - Evaluated before each iteration
   - Example: i < 10;  or  i < 10 && j > 20;
   - If always true: INFINITE LOOP
   - If always false: LOOP NEVER EXECUTES

3. INCREMENT/UPDATE (expression3)
   - Executed at the END of each loop iteration
   - Usually increments counter
   - Example: i++;  or  i--;  or  i+=2;
   - Can have multiple statements: i++, j--;

4. LOOP BODY (statement)
   - Code that repeats
   - Executes as long as condition is true
   - Can be single statement or block { }

============================================
FOR LOOP SYNTAX:
============================================

for (initialization; condition; update) {
    // Loop body - this code repeats
    // Code here executes as long as condition is true
}

============================================
EXECUTION ORDER:
============================================

1. initialization executes ONCE (before first iteration)
2. condition is checked
3. If condition TRUE: loop body executes
4. update executes
5. Go back to step 2 (check condition again)
6. If condition FALSE: exit loop

Example with i=0; i<3; i++:
-  i=0 (initialization)
-  Is 0<3? YES -> print 0
-  i++ (now i=1)
-  Is 1<3? YES -> print 1
-  i++ (now i=2)
-  Is 2<3? YES -> print 2
-  i++ (now i=3)
-  Is 3<3? NO -> exit loop

============================================
COMMON PATTERNS:
============================================

// Count from 0 to n-1
for (int i = 0; i < n; i++) { ... }

// Count from 1 to n
for (int i = 1; i <= n; i++) { ... }

// Count backwards
for (int i = n-1; i >= 0; i--) { ... }

// Skip numbers (count by 2)
for (int i = 0; i < n; i += 2) { ... }

// Multiple variables
for (int i=0, j=10; i<5; i++, j--) { ... }

// Empty loop (no initialization)
int i = 0;
for ( ; i < 10; i++) { ... }
*/

int main() {
    // FOR LOOP EXAMPLE: Print numbers 0 through 9
    // Initialization: int i = 0
    // Condition: i < 10 (loop continues while i is less than 10)
    // Update: i++ (increment i by 1 after each iteration)
    // Body: cout << i << endl; (print current value and newline)
    
    int i;
    
    // This loop will execute 10 times: when i = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    for (i = 0; i < 10; i++) {
        cout << i << endl;  // Print the current value of i
    }
    
    cout << "\nLoop finished. Final value of i: " << i << endl;
    // Note: After loop ends, i still equals 10
    
    return 0;
}

/*
============================================
ADVANCED FOR LOOP EXAMPLES
============================================

// Example 1: Sum numbers 1 to 100
int sum = 0;
for (int i = 1; i <= 100; i++) {
    sum += i;
}
cout << "Sum: " << sum << endl;

// Example 2: Print multiplication table
for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= 12; j++) {
        cout << (i * j) << "\t";
    }
    cout << endl;
}

// Example 3: Search in array
int arr[] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
    if (arr[i] == 30) {
        cout << "Found 30 at index " << i << endl;
        break;  // Exit loop when found
    }
}

// Example 4: Process with condition
for (int i = 1; i <= 20; i++) {
    if (i % 2 == 0) {
        cout << i << " is even" << endl;
    }
}

============================================
FOR LOOP vs OTHER LOOPS:
============================================

FOR LOOP:
- Use when you know exact number of iterations
- Counter-based
- Clean for array processing

WHILE LOOP:
- Use when number of iterations is unknown
- Condition-based
- Useful for input validation

DO-WHILE LOOP:
- Execute body at least once
- Useful for menus
*/