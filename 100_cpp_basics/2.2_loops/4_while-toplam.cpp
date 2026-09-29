/*
WHILE LOOP - CALCULATE SUM OF N NUMBERS

This program demonstrates:
- User input handling
- While loop iteration
- Running sum calculation
- Loop counter management

Concept: Read N numbers from user and display running total after each input

PROGRAM FLOW:
1. Ask user how many numbers to enter (N)
2. Loop N times:
   - Display current iteration number [1], [2], etc.
   - Read each number from user
   - Add to running sum
   - Display current total
   - Increment counter
3. Program ends
*/

#include <iostream>
using namespace std;

int main() {
    // Initialize loop counter and variables
    int i = 0;        // Loop counter (0 to n-1)
    int n;            // Number of values to enter
    int number;       // Stores each input number
    int sum = 0;      // Accumulates total sum
    
    // Get count from user
    cout << "Enter how many numbers you want to sum (N): ";
    cin >> n;
    
    // While loop continues as long as i < n
    while (i < n) {
        // Display current iteration (1-indexed for user readability)
        cout << "[" << i + 1 << "] Enter number: ";
        cin >> number;
        
        // Add current number to running sum
        sum += number;
        
        // Display running total
        cout << "Running total: " << sum << endl;
        
        // Increment loop counter
        i++;
    }
    
    // Loop ends when i reaches n
    
    cout << "\nFinal Sum: " << sum << endl;
    
    return 0;
}

/*
WHILE LOOP EXPLANATION:

SYNTAX:
  while (condition) {
    // Code block executes while condition is true
    // Must have code to change condition (prevent infinite loop)
  }

EXECUTION ORDER:
1. Check condition (i < n)?
   - If TRUE: enter loop body
   - If FALSE: skip loop, continue after while block
2. Execute loop body statements
3. Go back to step 1

CHARACTERISTICS:
- Condition checked BEFORE executing body
- Body executes 0 or more times
- Good for: unknown number of iterations
- Must explicitly increment counter
- Risk: infinite loop if condition never becomes false

EXAMPLE OUTPUT:
Enter how many numbers you want to sum (N): 3
[1] Enter number: 10
Running total: 10
[2] Enter number: 20
Running total: 30
[3] Enter number: 15
Running total: 45

Final Sum: 45

KEY POINTS:
- While loop checks condition first (pre-test loop)
- Counter must be initialized BEFORE loop
- Counter must be incremented INSIDE loop
- Without proper increment, causes infinite loop
*/