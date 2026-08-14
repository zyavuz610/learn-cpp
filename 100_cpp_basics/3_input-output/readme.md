# 3. Input and Output Operations

## Learning Objectives
- Master console input/output operations
- Handle formatted output for professional presentation
- Implement file operations in C++
- Solve input validation and error handling

## Input Stream Operations (cin)

### Basic Input
* [cin-intro.cpp](cin-intro.cpp) - Console Input Fundamentals
  * Using cin to read from keyboard
  * The extraction operator (>>)
  * Reading integers, floats, and characters
  * Input buffering behavior

* [cin-multiple-input.cpp](cin-multiple-input.cpp) - Reading Multiple Values
  * Reading multiple inputs in one statement
  * Different data types in sequence
  * Whitespace handling

### Advanced Input Handling
* [cin-ignore.cpp](cin-ignore.cpp) - Ignoring Input Buffer Characters
  * cin.ignore() function
  * Clearing input buffer after errors
  * Handling newline characters

* [cin-putback.cpp](cin-putback.cpp) - Putting Characters Back
  * cin.putback() function
  * Returning character to input stream

* [cin-peek.cpp](cin-peek.cpp) - Peeking at Next Character
  * cin.peek() function
  * Reading without consuming input

* [cin-get.cpp](cin-get.cpp) - Reading Individual Characters
  * cin.get() function variants
  * Reading characters including whitespace
  * Difference between >> and get()

* [cin-clear.cpp](cin-clear.cpp) - Clearing Input Stream States
  * cin.clear() function
  * Resetting error flags
  * Recovering from input errors

## Output Stream Operations (cout)

### Formatted Output
* [cout-setprecision.cpp](cout-setprecision.cpp) - Controlling Decimal Precision
  * setprecision() for floating-point display
  * Fixed vs. scientific notation
  * Decimal places in output

* [cout-unsetf.cpp](cout-unsetf.cpp) - Unsetting Format Flags
  * Removing format flags
  * unsetf() function usage

* [cout-showpoint.cpp](cout-showpoint.cpp) - Always Display Decimal Point
  * showpoint manipulator
  * Forcing decimal point display

* [cout-setw.cpp](cout-setw.cpp) - Column Width Formatting
  * setw() for field width control
  * Aligning output in columns
  * Creating formatted tables

* [cout-left-right.cpp](cout-left-right.cpp) - Text Alignment
  * left and right manipulators
  * Text justification

* [cout-fill.cpp](cout-fill.cpp) - Fill Character Control
  * setfill() for padding character
  * Creating leaders and separators

## File Input/Output Operations

### File Operations Fundamentals
* [file-open.cpp](file-open.cpp) - Opening and Creating Files
  * File streams: ifstream, ofstream, fstream
  * Opening files in different modes
  * File existence checking
  * Error handling when opening files

* [file-read.cpp](file-read.cpp) - Reading from Files
  * Reading entire files
  * Reading line-by-line
  * End-of-file detection (eof())
  * Handling file reading errors

### Advanced File Operations
* [ostream-modes.cpp](ostream-modes.cpp) - File Open Modes
  * ios::in, ios::out, ios::app modes
  * ios::trunc (truncate existing file)
  * ios::binary for binary files
  * Combining multiple modes

* [random-access-files.cpp](random-access-files.cpp) - Random Access in Files
  * seekg() and seekp() for file positioning
  * tellg() and tellp() for getting position
  * Direct access to specific file locations
  * Updating records in files