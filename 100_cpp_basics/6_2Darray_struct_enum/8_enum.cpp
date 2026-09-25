#include <iostream>
#include <string>

using namespace std;

/*
============================================
ENUMERATION (ENUM) - NAMED CONSTANT LIST
============================================

What is an Enum?
- A user-defined data type that defines a set of named constant values
- Each constant has an associated integer value
- Improves code readability (use meaningful names instead of magic numbers)
- Restricts variable to specific predefined values

Benefits:
- Better readability (DayOfWeek::Monday instead of 1)
- Type safety (compiler checks for valid values)
- Self-documenting code
- Easier to maintain and modify

SYNTAX:
  enum EnumName {
    VALUE1,        // Default value: 0
    VALUE2,        // Default value: 1
    VALUE3         // Default value: 2
  };
*/

// ============================================
// 1. BASIC ENUM - AUTO INCREMENT VALUES
// ============================================
/*
Default behavior:
- First element = 0
- Each subsequent element increases by 1
*/
enum DayOfWeek {
    Monday,     // Value: 0
    Tuesday,    // Value: 1
    Wednesday,  // Value: 2
    Thursday,   // Value: 3
    Friday,     // Value: 4
    Saturday,   // Value: 5
    Sunday      // Value: 6
};

// ============================================
// 2. ENUM WITH CUSTOM VALUES
// ============================================
/*
Assign specific values to enum constants:
- Can assign custom values to any element
- Non-assigned elements auto-increment from previous value
- Useful for level systems, status codes, etc.
*/
enum Level {
    Low = 10,      // Explicitly assigned: 10
    Medium = 50,   // Explicitly assigned: 50
    High = 100,    // Explicitly assigned: 100
    VeryHigh       // Auto-incremented: 101
};

// ============================================
// 3. ENUM CLASS (SCOPED ENUM) - MODERN C++
// ============================================
/*
Modern C++ (C++11 and later) introduced `enum class`:

Advantages:
- Scoped enumeration (use Color::Red, not just Red)
- Type-safe (no implicit conversion to int)
- Prevents naming conflicts
- Better practice than unscoped enum

Syntax:
  enum class EnumName {
    VALUE1,
    VALUE2
  };

Access: EnumName::VALUE1
*/
enum class Color {
    Red,      // Value: 0 (must access as Color::Red)
    Green,    // Value: 1
    Blue,     // Value: 2
    Yellow    // Value: 3
};

// Function using enum class parameter
void printColor(Color color) {
    switch (color) {
        case Color::Red:
            cout << "Selected color: Red" << endl;
            break;
        case Color::Green:
            cout << "Selected color: Green" << endl;
            break;
        case Color::Blue:
            cout << "Selected color: Blue" << endl;
            break;
        case Color::Yellow:
            cout << "Selected color: Yellow" << endl;
            break;
    }
}

int main() {
    // ============================================
    // 1. USING BASIC ENUM
    // ============================================
    DayOfWeek today = Saturday;
    
    // Display enum value as integer
    cout << "Today is day #" << today << " of the week" << endl;
    
    // Use enum in conditionals
    if (today == Saturday || today == Sunday) {
        cout << "It's the weekend!" << endl;
    }

    // ============================================
    // 2. USING ENUM WITH CUSTOM VALUES
    // ============================================
    Level playerLevel = High;
    cout << "\nPlayer level (as value): " << playerLevel << endl;
    
    // Access enum constants
    cout << "Low level value: " << Low << endl;
    cout << "Medium level value: " << Medium << endl;
    cout << "High level value: " << High << endl;
    cout << "Very High level value: " << VeryHigh << endl;

    // ============================================
    // 3. USING ENUM CLASS (RECOMMENDED)
    // ============================================
    
    // Must use scope resolution to access enum class values
    Color selectedColor = Color::Green;
    
    // Call function with enum class
    printColor(selectedColor);
    
    // Explicit conversion to int if needed
    int colorValue = static_cast<int>(Color::Blue);
    cout << "Blue color value: " << colorValue << endl;
    
    // NOTE: This would cause compiler error with enum class!
    // int x = Color::Green;  // ERROR: implicit conversion not allowed
    
    // Must use explicit cast:
    int y = static_cast<int>(Color::Green);  // OK: explicit conversion
    
    return 0;
}

/*
============================================
ENUM vs ENUM CLASS COMPARISON
============================================

UNSCOPED ENUM (Plain enum):
  enum Days { Monday, Tuesday, Wednesday };
  
  Pros:
  - Simpler syntax
  - Compatible with switch/if statements
  
  Cons:
  - No scope (all values in global namespace)
  - Can cause naming conflicts
  - Implicit conversion to int
  - Less type-safe

SCOPED ENUM (enum class):
  enum class Days { Monday, Tuesday, Wednesday };
  
  Pros:
  - Scoped (must use Days::Monday)
  - Prevents naming conflicts
  - Type-safe (no implicit conversion)
  - Modern C++ standard (C++11+)
  - Better for large projects
  
  Cons:
  - Slightly more verbose syntax
  - Requires scope resolution operator

RECOMMENDATION: Use enum class for new code!

============================================
ENUM PRACTICE EXAMPLES
============================================

1. TRAFFIC LIGHT:
   enum class TrafficLight { Red, Yellow, Green };

2. STATUS CODE:
   enum Status {
     Success = 0,
     Error = 1,
     Warning = 2,
     Info = 3
   };

3. DIRECTION:
   enum class Direction { North, South, East, West };

4. STATE MACHINE:
   enum class State {
     Init = 0,
     Running = 1,
     Paused = 2,
     Stopped = 3
   };

============================================
*/