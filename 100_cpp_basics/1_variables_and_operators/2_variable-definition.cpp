#include <iostream>
using namespace std;

int main() {
  // INTEGER VARIABLES
  // Declaration: int i, j=0, k;
  // i is declared but uninitialized
  // j is declared and initialized to 0
  // k is declared but uninitialized
  int i, j = 0, k;
  i = 5;
  j = -5;
  k = i * j;
  cout << "Integer result: " << k << endl;

  // CHARACTER VARIABLES
  // char stores a single byte that represents an ASCII code (homework:research ASCII table for character codes)
  // When printed, cout displays the character, not the ASCII value
  char c = 'A', ch;        // Declare two char variables
  ch = 65;                 // ASCII 65 = character 'A'
  cout << "Character from ASCII value: " << ch << endl;

  // NOTE: To display ASCII value instead of character, use int(ch)
  // Example: cout << "ASCII value: " << int(ch) << endl;

  // FLOATING-POINT VARIABLES
  float f, salary;         // Real number variables (single precision)
  f = 2.0;
  salary = f * f + 8.5;    // f*f + 8.5 = 4.0 + 8.5 = 12.5
  cout << "Salary calculation: " << salary << endl;

  // DOUBLE PRECISION VARIABLES
  double d;                // Real numbers with higher precision
  d = -4.0;
  cout << "Double result: " << d * d << endl;  // Output: 16

  /*
  ============================================
  VARIABLE NAMING CONVENTIONS
  ============================================
  
  RULES FOR VARIABLE NAMES:
  1. Must start with letter (a-z, A-Z) or underscore (_)
  2. Cannot start with a number (0-9)
  3. Are case-sensitive (myVar != myvar != MYVAR)
  4. Cannot contain special characters (except underscore)
  5. Cannot be C++ keywords (int, float, return, etc.)
  6. Should be meaningful and descriptive
  
  COMMON NAMING CONVENTIONS:
  
  1. camelCase (lower camel case):
     - First word starts with lowercase
     - Subsequent words start with uppercase
     - No spaces or underscores
     - Examples: myVariable, totalSalary, employeeName
     - Usage: Java, JavaScript, C# (common in C++)
  
  2. PascalCase (upper camel case):
     - All words start with uppercase
     - No spaces or underscores
     - Examples: MyVariable, TotalSalary, EmployeeName
     - Usage: Class names in C++, C#
  
  3. snake_case (underscore):
     - Words separated by underscores
     - All lowercase
     - Examples: my_variable, total_salary, employee_name
     - Usage: Python, C (common in C++)
  
  4. UPPER_SNAKE_CASE:
     - Words separated by underscores
     - All uppercase
     - Examples: MAX_SIZE, BUFFER_LIMIT, PI_VALUE
     - Usage: Constants in C++
  
  5. kebab-case (hyphenated):
     - Words separated by hyphens
     - All lowercase
     - Examples: my-variable, total-salary
     - Note: NOT supported in C++ (hyphens not allowed)
     - Usage: CSS, URLs, some scripting languages
  
  BEST PRACTICES FOR C++:
  - Use camelCase for variables and functions
  - Use PascalCase for class names
  - Use UPPER_SNAKE_CASE for constants (#define or const)
  - Use snake_case for file names (optional)
  - Avoid single letter names (except loop counters: i, j, k)
  - Use descriptive names that indicate purpose
  - Keep names concise but meaningful
  */
}
