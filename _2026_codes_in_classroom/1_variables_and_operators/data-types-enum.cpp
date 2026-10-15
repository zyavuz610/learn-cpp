#include <iostream>
using namespace std;

int main() {
  enum DayOfWeek { 
    Sunday, // 0
    Monday, // 1  
    Tuesday, // 2
    Wednesday=7, // 3
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
  DayOfWeek theDay = static_cast<DayOfWeek>(lastDay + 1); // does not Wraps
  cout << "The day after Last Day: " << theDay; // Output: 7 
  
  
  return 0;
}