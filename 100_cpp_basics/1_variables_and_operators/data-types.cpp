#include <iostream>
#include <bitset>
using namespace std;

int main() {

   // BOOLEAN DATA TYPE - new in C++ (C does not have a boolean type)
   // Stores true or false values
   // Values: true (1) or false (0)
   bool isEmpty = true;
   cout << "Boolean Value        : " << isEmpty << endl;
   cout << "Boolean Memory Size  : " << sizeof(bool) << " byte" << endl;
   cout << "Binary Representation: " << bitset<8>(isEmpty) << endl;


/*
   // CHARACTER DATA TYPE - same in C and C++
   // Stores single character: 'A', 'b', or ASCII value like 70
   char ch = 'A';
   cout << "Character Value      : " << ch << " (ASCII: " << int(ch) << ")" << endl;
   cout << "Char Memory Size     : " << sizeof(char) << " byte" << endl;
   cout << "Binary Representation: " << bitset<8>(ch) << endl;
*/

/*
   // INTEGER DATA TYPE - same in C and C++
   // Stores whole numbers (positive, negative, or zero)
   int n = -500;
   cout << "Integer Value        : " << n << endl;
   cout << "Int Memory Size      : " << sizeof(int) << " bytes" << endl;
   cout << "Short Int Memory     : " << sizeof(short int) << " bytes" << endl;
   cout << "Long Int Memory      : " << sizeof(long int) << " bytes" << endl;
*/
   
/*
   // SIGNED vs UNSIGNED DIFFERENCE - same in C and C++
   // Signed: can store negative numbers (uses one bit for sign)
   // Unsigned: only positive numbers (uses all bits for value)
   short int i;              // Signed: range is -32768 to 32767
   short unsigned int j;     // Unsigned: range is 0 to 65535
   j = 50000;
   i = j;                    // Overflow! i becomes negative: 65536 - 50000
   cout << i << " " << j;
*/

/*
   // FLOATING-POINT DATA TYPES - same in C and C++
   // Short int signed/unsigned differences
   short int i;              // Signed variable
   short unsigned int j;     // Unsigned variable
   j = 50000;
   i = j;                    // This causes overflow
   cout << i << " " << j;
*/


   return 0;
}

/*
============================================
FUNDAMENTAL DATA TYPES IN C++
============================================

BASIC TYPES:
  bool              Boolean: true or false (1 byte) - C++ only
  char              Single character (1 byte)
  int               Whole number/integer (4 bytes)
  float             Floating-point number (4 bytes)
  double            Double precision float (8 bytes)
  void              No value (used in function returns)

DATA TYPE MODIFIERS:
  signed            Can store negative values (default for char, int)
  unsigned          Only positive values (extends positive range)
  short             Reduces memory size
  long              Increases range of values

============================================
COMPLETE DATA TYPE REFERENCE
============================================

TYPE | SIZE | RANGE
-----|------|------
char                     1 byte       -128 to 127
unsigned char            1 byte       0 to 255
signed char              1 byte       -128 to 127
int                      4 bytes      -2,147,483,648 to 2,147,483,647
unsigned int             4 bytes      0 to 4,294,967,295
signed int               4 bytes      -2,147,483,648 to 2,147,483,647
short int                2 bytes      -32,768 to 32,767
unsigned short int       2 bytes      0 to 65,535
signed short int         2 bytes      -32,768 to 32,767
long int                 4 bytes      -2,147,483,648 to 2,147,483,647
signed long int          4 bytes      Same as long int
unsigned long int        4 bytes      0 to 4,294,967,295
float                    4 bytes      +/- 3.4e +/- 38 (~7 digits precision)
double                   8 bytes      +/- 1.7e +/- 308 (~15 digits precision)
long double              8 bytes      +/- 1.7e +/- 308 (~15 digits precision)

NOTES:
- Smaller types (char, short) use less memory but have limited range
- Larger types (long, double) use more memory but store larger values
- Floating-point numbers have limited precision

============================================
TYPEDEF - CREATING TYPE ALIASES
============================================

Purpose: Create aliases for existing data types

Syntax:
  typedef existing_type new_name; // same as using new_name = existing_type; in C++11 and later
    sample:
      typedef int Age;
      Age myAge = 25;
      cout << "My age is: " << myAge << endl; // Output: My age is: 25

Example:
  typedef float Volume;
  Volume vol1, vol2;      // vol1 and vol2 are float type
  
Benefits:
  - Makes code more readable
  - Easier to change types globally
  - Better code documentation

============================================
ENUMERATION DATA TYPE (enum) - same in C and C++
============================================

Purpose: Define set of named integer constants

Features:
  - Variables hold specific predetermined values
  - Uses memory efficiently
  - Makes code more readable

Syntax:
  enum TypeName { value1, value2, value3, ... };

Example 1 - Days of Week:
  enum DayOfWeek { 
    Sunday = 0, 
    Monday = 1, 
    Tuesday = 2, 
    Wednesday = 3, 
    Thursday = 4, 
    Friday = 5, 
    Saturday = 6 
  };

Example 1.1 - Using enum without values: day of week:
  enum DayOfWeek { 
    Sunday, // 0
    Monday, // 1  
    Tuesday, // 2
    Wednesday, // 3
    Thursday, // 4
    Friday, // 5
    Saturday // 6
  };
  
  DayOfWeek today = Wednesday;
  cout << "Day: " << today;    // Output: 3

  DayOfWeek tomorrow = static_cast<DayOfWeek>(today + 1);
  cout << "Tomorrow: " << tomorrow; // Output: 4

  DayOfWeek lastDay = Saturday;
  cout << "Last Day: " << lastDay; // Output: 6
  DayOfWeek theDay = static_cast<DayOfWeek>(lastDay + 1); // Wraps around to 0 (Sunday)

Example 2 - Seasons:
  enum Season { 
    spring = 0, 
    summer = 4, 
    autumn = 8,
    winter = 12
  };
  
  Season current = summer;
  cout << "Season value: " << current;  // Output: 4

Advantages of enum:
  - Improves code readability
  - Prevents invalid values
  - Easier to maintain
  - Self-documenting code
*/
