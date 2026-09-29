#include <iostream>

// Define weightings for course grade calculation
#define MIDTERM_WEIGHT  0.45    // Midterm exam contributes 45%
#define FINAL_WEIGHT    0.55    // Final exam contributes 55%

using namespace std;

int main() {
  // Variable declarations for grade calculation
  double midterm, final, average;
  
  // Prompt user for midterm exam score
  cout << "Enter Midterm Exam Score: ";
  cin >> midterm;  // Read midterm score from user input
  
  // Prompt user for final exam score
  cout << "Enter Final Exam Score: ";
  cin >> final;    // Read final score from user input
  
  // Alternative method (commented out): cin >> midterm >> final;
  
  // Calculate the weighted average
  // Formula: average = (midterm * 45%) + (final * 55%)
  average = MIDTERM_WEIGHT * midterm + FINAL_WEIGHT * final;
  
  // Display the calculated average
  cout << "Final Average: " << average << endl << endl;
  
  // DECISION MAKING WITH IF-ELSE STATEMENT
  // Determine if student passed or failed based on average
  
  if (average < 40) {
    // Execute this block if the condition is TRUE (average < 40)
    cout << average << " --> FAILED" << endl;
    cout << "Note: You need at least 40 to pass the course." << endl;
  }
  else {
    // Execute this block if the condition is FALSE (average >= 40)
    cout << average << " --> PASSED" << endl;
    cout << "Congratulations! You have successfully passed the course." << endl;
  }
  
  cout << endl << "Program finished." << endl;
  return 0;
}

/*
============================================
IF-ELSE STATEMENT EXPLANATION
============================================

SYNTAX:
if (condition) {
    // Execute this block if condition is true
}
else {
    // Execute this block if condition is false
}

HOW IT WORKS:
1. The condition is evaluated (true or false)
2. If true: Execute the code inside the if block
3. If false: Skip if block and execute else block (if present)
4. Continue with code after if-else

IN THIS EXAMPLE:
- Condition: average < 40
- If true (average less than 40): Print "FAILED"
- If false (average 40 or more): Print "PASSED"

IMPORTANT NOTES:
- Condition must be enclosed in parentheses
- Curly braces {} define the code block (optional for single statement)
- Else clause is optional
- Multiple if-else can be chained: if() ... else if() ... else if() ... else {}

COMPARISON OPERATORS USED IN CONDITIONS:
- == (equal to)
- != (not equal to)
- < (less than)
- > (greater than)
- <= (less than or equal to)
- >= (greater than or equal to)

REAL-WORLD APPLICATIONS:
- Grade classification (as in this example)
- Age verification
- Login validation
- Game state decisions
- Error checking
*/