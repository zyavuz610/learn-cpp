/*
BASIC INPUT/OUTPUT - CENTURY CALCULATOR

This program demonstrates:
- Using cin to read integer input from user
- Using cout to display output
- Ternary conditional operator (? :)
- Integer division and modulo operations

Concept: Given a year, calculate which century it belongs to
*/

#include <iostream>
using namespace std;

int main() {
    int year;

    // Prompt user for input
    cout << "Enter a year: ";
    cin >> year;

    /*
    CENTURY CALCULATION LOGIC:
    - Years ending in 00 (e.g., 1900, 2000): century = year / 100
      Example: 1900 / 100 = 19 (19th century)
    - All other years: century = (year / 100) + 1
      Example: 1901 / 100 = 19, then + 1 = 20 (20th century)
      Example: 2001 / 100 = 20, then + 1 = 21 (21st century)
    
    TERNARY OPERATOR (?:) SYNTAX:
      condition ? value_if_true : value_if_false
    
    Is more concise than:
      if (condition)
        century = value_if_true;
      else
        century = value_if_false;
    */
    
    // Calculate century using ternary operator
    // If year % 100 == 0, century is year/100; else century is (year/100) + 1
    int century = (year % 100 == 0) ? (year / 100) : (year / 100) + 1;

    // Display result
    cout << "Year " << year << " belongs to century " << century << endl;

    return 0;
}

/*
EXAMPLE EXECUTIONS:

Example 1:
Input:  1900
Calculation: 1900 % 100 = 0, so use 1900 / 100 = 19
Output: Year 1900 belongs to century 19

Example 2:
Input:  1901
Calculation: 1901 % 100 = 1 (not 0), so use (1901 / 100) + 1 = 19 + 1 = 20
Output: Year 1901 belongs to century 20

Example 3:
Input:  2000
Calculation: 2000 % 100 = 0, so use 2000 / 100 = 20
Output: Year 2000 belongs to century 20

Example 4:
Input:  2025
Calculation: 2025 % 100 = 25 (not 0), so use (2025 / 100) + 1 = 20 + 1 = 21
Output: Year 2025 belongs to century 21

KEY CONCEPTS:

1. CIN (Character Input)
   cin >> variable;      // Reads value from keyboard
   Stops at: whitespace, newline, end of file
   Works for: int, float, double, char, string

2. COUT (Character Output)
   cout << value;        // Outputs to screen
   cout << endl;         // Adds newline and flushes buffer

3. MODULO OPERATOR (%)
   Gives remainder after division
   year % 100:
   - Returns 0 if year ends in 00
   - Returns non-zero for all other years

4. INTEGER DIVISION (/)
   2025 / 100 = 20 (not 20.25)
   Discards fractional part

5. TERNARY OPERATOR (? :)
   (condition) ? true_value : false_value
   Equivalent to if-else but more compact
   Useful for simple conditional assignments
*/