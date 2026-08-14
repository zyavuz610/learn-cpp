#include <iostream>

// Define grade weightings
#define MIDTERM_WEIGHT  0.45
#define FINAL_WEIGHT    0.55

using namespace std;

int main() {
  double midterm, final, average;
  
  // Get student scores
  cout << "Enter Midterm Score: ";
  cin >> midterm;
  cout << "Enter Final Score: ";
  cin >> final;
  
  // Calculate weighted average
  average = MIDTERM_WEIGHT * midterm + FINAL_WEIGHT * final;

  /*
  NOTE: Switch-case is more efficient than multiple if-else
  when checking a SINGLE VARIABLE for equality against specific values.
  It's cleaner and faster than chained if-else statements.
  */

  // Determine letter grade based on average
  char letterGrade = ' ';
  
  // Using if-else to map numeric score to letter grade
  if (average < 40)
    letterGrade = 'F';      // Fail
  else if (average < 45)
    letterGrade = 'D';      // Poor
  else if (average < 60)
    letterGrade = 'C';      // Satisfactory
  else if (average < 80)
    letterGrade = 'B';      // Good
  else if (average <= 100)
    letterGrade = 'A';      // Excellent
  else
    letterGrade = 'E';      // Invalid score
  
  // Display average and corresponding message using switch-case
  cout << average << " -> ";
  
  switch (letterGrade) {
    case 'A':
      cout << "Excellent! Perfect work!" << endl;
      break;
    case 'B':
      cout << "Good job, well done!" << endl;
      break;
    case 'C':
      cout << "Satisfactory, you passed the course" << endl;
      break;
    case 'D':
      cout << "Poor grade, you'll learn more next term" << endl;
      break;
    case 'F':
      cout << "Failed - Need improvement" << endl;
      break;
    default:
      cout << "Invalid Score" << endl;
  }
  
  /*
  SWITCH-CASE QUESTIONS & ANSWERS:
  
  Q1: What happens if we DON'T use break?
  A: Fall-through occurs! Execution continues to next case.
     Example: If grade is 'B', without break it would print
     "Good job" AND "Satisfactory" messages.
  
  Q2: Can letterGrade be a string instead of char?
  A: No! Switch expressions must be integral types:
     - int, char, short, long, unsigned variants
     - NOT allowed: string, float, double
     - For strings, use if-else statements instead
  
  Q3: Why are ranges checked with if-else, not switch?
  A: Switch only checks for exact equality (==)
     Cannot check ranges like: 40 <= average < 60
     That's why we use if-else first to map to single value
     Then switch on that single value
  
  SWITCH-CASE SYNTAX SUMMARY:
  
  switch (expression) {
    case value1:
      // code if expression == value1
      break;
    case value2:
    case value3:
      // code if expression == value2 OR value3
      break;
    default:
      // code if no cases match
  }
  
  BEST PRACTICES:
  1. Always include break after each case
  2. Include default case for unexpected values
  3. Use switch for multiple exact equality checks
  4. Use if-else for ranges and complex conditions
  */
  
  return 0;
}