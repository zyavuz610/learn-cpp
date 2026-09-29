/*
DO-WHILE LOOP - CALCULATE SUM OF N NUMBERS

This program demonstrates:
- Do-while loop (post-test condition)
- Running sum calculation
- User input handling in loop body

Key Difference from While Loop:
- Condition checked AFTER loop body executes
- Loop body ALWAYS executes at least once
- Good for: menu systems, input validation

Concept: Read N numbers from user and display running total after each input
*/

#include <iostream>
using namespace std;

int main() {
    // Initialize variables
    int i = 0;        // Loop counter
    int n;            // Number of values to enter
    int number;       // Stores each input number
    int sum = 0;      // Accumulates total sum
    
    // Get count from user
    cout << "Enter how many numbers you want to sum (N): ";
    cin >> n;
    
    // Do-while loop: body executes first, condition checked after
    do {
        // Display current iteration (1-indexed for user readability)
        cout << "[" << i + 1 << "] Enter number: ";
        cin >> number;
        
        // Add current number to running sum
        sum += number;
        
        // Display running total
        cout << "Running total: " << sum << endl;
        
        // Increment loop counter
        i++;
        
        // Condition checked HERE (after body executes)
    } while (i < n);
    
    // Loop ends when i reaches n
    
    cout << "\nFinal Sum: " << sum << endl;
    
    return 0;
}

/*
DO-WHILE LOOP EXPLANATION:

SYNTAX:
  do {
    // Code block
  } while (condition);
  
  NOTE: Semicolon REQUIRED at end of while (differs from while loops)

EXECUTION ORDER:
1. Execute loop body (all statements inside do block)
2. Check condition
   - If TRUE: go back to step 1
   - If FALSE: exit loop, continue after while statement

KEY CHARACTERISTICS:
- Condition checked AFTER body (post-test loop)
- Body executes 1 or more times (always at least once!)
- Useful for: input validation, menu systems
- Prevents duplicate code

WHEN TO USE DO-WHILE:
- When loop body must execute at least once
- Input validation loops (ask again if invalid)
- Menu systems (show menu, then ask for choice)

EXAMPLE OUTPUT:
Enter how many numbers you want to sum (N): 3
[1] Enter number: 10
Running total: 10
[2] Enter number: 20
Running total: 30
[3] Enter number: 15
Running total: 45

Final Sum: 45

COMPARISON: WHILE vs DO-WHILE

WHILE LOOP:
- Checks condition FIRST
- May execute 0 times
- Use when: iterations depend on condition

  int i = 10;
  while (i < 5) {      // Condition false, never executes!
    cout << i << endl;
  }

DO-WHILE LOOP:
- Checks condition LAST
- Always executes at least once
- Use when: body must run before condition check

  int i = 10;
  do {
    cout << i << endl;  // Executes once even though condition false!
  } while (i < 5);

MENU SYSTEM EXAMPLE (Do-While Advantage):

  int choice;
  do {
    cout << "1. Add  2. Subtract  3. Exit: ";
    cin >> choice;
    // Process choice (body always runs)
  } while (choice != 3);
  
  With while loop, we'd need to duplicate menu display code!
*/