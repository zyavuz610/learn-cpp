/*
ARRAYS - LINEAR DATA STRUCTURE

What are Arrays?
- Collection of multiple data elements of the SAME data type
- Fixed size determined at declaration
- Elements stored CONTIGUOUSLY in memory
- All elements same size
- Accessed by index starting from 0

ARRAY SYNTAX:
  datatype arrayName[size];
  
EXAMPLES:
  int numbers[100];        // 100-element integer array
  double values[10];       // 10-element floating-point array
  char name[50];           // 50-element character array

WHY USE ARRAYS?
Instead of: int num1, num2, num3, ..., num50;
Use: int numbers[50];
Access: numbers[0], numbers[1], ..., numbers[49]

KEY CHARACTERISTICS:
- Zero-indexed: first element is index 0
- Linear: elements stored sequentially in memory
- Fixed size: determined at compile time
- Contiguous: elements next to each other in memory
- Index determines: memory_address = base_address + (index * element_size)

============================================
ARRAY DECLARATION AND INITIALIZATION
============================================

1. DECLARATION ONLY (uninitialized):
   int arr[5];              // 5 elements, values undefined

2. ARRAY SIZE BY INITIALIZER:
   int arr[] = {2, 3, 5, 6, 9};  // Size automatically = 5

3. PARTIAL INITIALIZATION:
   int arr[5] = {1, 2};     // First 2 elements: 1, 2; rest: 0

4. COMPLETE INITIALIZATION:
   int arr[5] = {1, 2, 3, 4, 5};

5. ALL ZEROS:
   int arr[5] = {0};        // All elements initialized to 0

6. VARIABLE SIZE (C++11):
   int n = 5;
   double arr[n];           // NOT standard C++ (Variable Length Array)
   // For standard C++, use vector or new instead

============================================
CHARACTER ARRAYS (C STRINGS)
============================================

A C string is a char array that ENDS with null character '\0':

1. STRING LITERAL INITIALIZATION:
   char str[] = "Hello";    // Size = 6 (includes '\0')
   // str[0]='H', str[1]='e', str[2]='l', str[3]='l', str[4]='o', str[5]='\0'

2. SIZED STRING:
   char str[20] = "World";  // Size = 20, stores "World\0" + padding
   // First 6 elements: 'W','o','r','l','d','\0'
   // Remaining 14 elements: 0 (null bytes)

3. CHARACTER ARRAY INITIALIZATION:
   char str[] = {'H','e','l','l','o','\0'};  // Size = 6

4. NAMED ARRAY:
   char name[16] = {'J','o','h','n','\0'}; // "John" + null terminator

IMPORTANT: Always ensure size is large enough for string + null terminator!
// ERROR: char str[5] = "Hello";  // "Hello" is 6 chars (5 + '\0')
// ERROR: char arr[5] = {'H','e','l','l','o','\0'}; // 6 chars in 5-size array

============================================
ARRAY ACCESS AND OPERATIONS
============================================

READING ARRAY ELEMENTS:
  cout << arr[0];           // Print first element
  int x = arr[2];           // Get third element

WRITING TO ARRAY ELEMENTS:
  arr[0] = 10;              // Set first element to 10
  cin >> arr[i];            // Read input into array[i]

LOOPING THROUGH ARRAYS:
  for (int i = 0; i < n; i++) {
    cout << arr[i];         // Access each element
  }

KEY RESTRICTIONS:
  int x[5] = {1,2,3,4,5};
  int y[5] = {6,7,8,9,10};
  
  x = y;      // ERROR: Cannot assign entire arrays
  cin >> x;   // ERROR: Cannot read entire array with >>
  if (x == y) // ERROR: Cannot compare arrays with ==

============================================
COMMON ARRAY PROBLEMS
============================================

EXERCISE: Given N numbers:
1. Find sum of all elements
2. Find minimum and maximum elements
3. Calculate average
4. Find elements below average
5. Find elements above average
6. Find 2nd maximum element
7. Find 2nd minimum element
8. Calculate standard deviation

============================================
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //==================================================
    // ARRAY ELEMENT ACCESS EXAMPLE
    //==================================================
    
    int n;
    const int COL1 = 6;      // Column width for formatting
    const int COL2 = 7;      // Column width for formatting
    
    // Get array size from user
    cout << "Enter number of elements (N): ";
    cin >> n;
    
    if (n <= 0 || n > 100) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    
    int numbers[100];        // Array to store numbers
    
    // READ: Input array elements
    for (int i = 0; i < n; i++) {
        cout << "Enter number[" << i << "]: ";
        cin >> numbers[i];
    }
    
    // WRITE: Display array with formatted output
    cout << "\n";
    cout << setw(COL1) << "Index" << setw(COL2) << "Value" << endl;
    cout << "=====================" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << setw(COL1) << i << setw(COL2) << numbers[i] << endl;
    }
    
    //==================================================
    // EXERCISES TO PRACTICE
    //==================================================
    
    // TODO: 1. Calculate sum of all elements
    // TODO: 2. Find minimum element
    // TODO: 3. Find maximum element
    // TODO: 4. Calculate average
    // TODO: 5. Find elements below average
    // TODO: 6. Find elements above average
    // TODO: 7. Find second maximum element
    // TODO: 8. Find second minimum element
    // TODO: 9. Calculate standard deviation
    // TODO: 10. Sort array elements
    
    // HINT: Use setw(), setprecision(), fixed for formatting
    // HINT: Create separate functions for each operation
    
    return 0;
}
