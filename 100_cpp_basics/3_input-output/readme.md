# 3. Input and Output Operations

## Learning Objectives
- Master console input/output operations
- Handle formatted output for professional presentation
- Implement file operations in C++
- Solve input validation and error handling

## Input Stream Operations (cin)

### Basic Input
* [1_cin-intro.cpp](1_cin-intro.cpp) - Console Input Fundamentals
  * Using cin to read from keyboard
  * The extraction operator (>>)
  * Reading integers, floats, and characters
  * Input buffering behavior

* [2_cin-multiple-input.cpp](2_cin-multiple-input.cpp) - Reading Multiple Values
  * Reading multiple inputs in one statement
  * Different data types in sequence
  * Whitespace handling

### Advanced Input Handling
* [3_cin-ignore.cpp](3_cin-ignore.cpp) - Ignoring Input Buffer Characters
  * cin.ignore() function
  * Clearing input buffer after errors
  * Handling newline characters

* [4_cin-putback.cpp](4_cin-putback.cpp) - Putting Characters Back
  * cin.putback() function
  * Returning character to input stream

* [5_cin-peek.cpp](5_cin-peek.cpp) - Peeking at Next Character
  * cin.peek() function
  * Reading without consuming input

* [6_cin-get.cpp](6_cin-get.cpp) - Reading Individual Characters
  * cin.get() function variants
  * Reading characters including whitespace
  * Difference between >> and get()

* [7_cin-clear.cpp](7_cin-clear.cpp) - Clearing Input Stream States
  * cin.clear() function
  * Resetting error flags
  * Recovering from input errors

## Output Stream Operations (cout)

### Formatted Output
* [8_cout-setprecision.cpp](8_cout-setprecision.cpp) - Controlling Decimal Precision
  * setprecision() for floating-point display
  * Fixed vs. scientific notation
  * Decimal places in output

* [9_cout-unsetf.cpp](9_cout-unsetf.cpp) - Unsetting Format Flags
  * Removing format flags
  * unsetf() function usage

* [a_cout-showpoint.cpp](a_cout-showpoint.cpp) - Always Display Decimal Point
  * showpoint manipulator
  * Forcing decimal point display

* [b_cout-setw.cpp](b_cout-setw.cpp) - Column Width Formatting
  * setw() for field width control
  * Aligning output in columns
  * Creating formatted tables

* [c_cout-left-right.cpp](c_cout-left-right.cpp) - Text Alignment
  * left and right manipulators
  * Text justification

* [d_cout-fill.cpp](d_cout-fill.cpp) - Fill Character Control
  * setfill() for padding character
  * Creating leaders and separators

## File Input/Output Operations

### File Operations Fundamentals
* [e_file-open.cpp](e_file-open.cpp) - Opening and Creating Files
  * File streams: ifstream, ofstream, fstream
  * Opening files in different modes
  * File existence checking
  * Error handling when opening files

* [f_file-read.cpp](f_file-read.cpp) - Reading from Files
  * Reading entire files
  * Reading line-by-line
  * End-of-file detection (eof())
  * Handling file reading errors

### Advanced File Operations
* [g_ostream-modes.cpp](g_ostream-modes.cpp) - File Open Modes
  * ios::in, ios::out, ios::app modes
  * ios::trunc (truncate existing file)
  * ios::binary for binary files
  * Combining multiple modes

* [h_random-access-files.cpp](h_random-access-files.cpp) - Random Access in Files
  * seekg() and seekp() for file positioning
  * tellg() and tellp() for getting position
  * Direct access to specific file locations
  * Updating records in files