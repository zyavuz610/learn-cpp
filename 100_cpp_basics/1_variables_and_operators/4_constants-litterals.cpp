/*
============================================
THREE TYPES OF CONSTANTS (Unchangeable Values)
============================================

1. PREPROCESSOR CONSTANTS (#define)
   - Defined using #define directive
   - Replaced by preprocessor before compilation
   - No type checking
   - No memory allocation
   - Syntax: #define NAME value

2. CONST VARIABLES (const keyword)
   - Declared like regular variables with const keyword
   - Type-safe (compiler checks type)
   - Memory allocated (stored in memory)
   - Syntax: const datatype NAME = value;
   - Can be function parameters

3. LITERALS (Literal Values)
   - Hard-coded values in source code
   - Found on right side of assignment
   - Examples: 5, 'A', "Hello", 3.14
   - Syntax: direct value in code

COMPARISON: const vs #define

CONST:
  const int LENGTH = 10;
  const int WIDTH = 5;
  const char NEWLINE = '\n';
  
#DEFINE:
  #define LENGTH 10
  #define WIDTH 5
  #define NEWLINE '\n'

ADVANTAGES OF CONST OVER #DEFINE:
- Type safety (compiler checks types)
- Debugging easier (debugger sees const variables)
- Proper scope (const respects scope rules)
- Memory efficient (compiler optimizes better)

LITERALS:
  int area;
  area = 50;        // 50 is a literal constant
  char ch = 'A';    // 'A' is a character literal
  string s = "test"; // "test" is a string literal
*/

#include <iostream>
using namespace std;

// Function prototype with const parameters
int topla(const int, const int);

int main() {
  
   // ESCAPE CHARACTERS
   // Special sequences that represent non-printing characters
   cout << "Hello\r World\n\n";
  
   // CONST EXAMPLE (commented out):
   // const int LENGTH = 10;
   // const int WIDTH = 5;
   // const char NEWLINE = '\n';
   // int area = LENGTH * WIDTH;
   // cout << area << NEWLINE;

   // CALLING CONST PARAMETER FUNCTION:
   // cout << topla(5, 6) << endl;

   return 0;
}

// Function with const parameters
// const parameters prevent modification inside function
int topla(const int x, int y) {
  int a;
  // x = 5;  // ERROR: Cannot assign to const parameter!
  a = x + y;
  return a;
  // Note: Using const in parameters prevents accidental modification
  // Protects function from changing values it shouldn't change
}

/*
============================================
LITERAL CONSTANTS IN C++
============================================

Literals are hard-coded constant values of specific data types.

ESCAPE SEQUENCES:
  \n         Newline (move to next line)
  \t         Tab (horizontal spacing)
  \r         Carriage return
  \b         Backspace
  \\         Backslash character
  \'         Single quote character
  \"         Double quote character
  \0         Null character (end of string)
  \a         Bell/alert (beep sound)
  \f         Form feed
  \v         Vertical tab

INTEGER LITERALS:
  Format: digits [suffix]
  
  DECIMAL (base 10):
    212         Legal (decimal number)
    215u        Legal (unsigned integer)
    30L         Legal (long integer)
    30ul        Legal (unsigned long integer)
  
  OCTAL (base 8, starts with 0):
    078         ILLEGAL (8 is not valid octal digit)
    056         Legal (octal number = 46 in decimal)
    032         Legal (octal number = 26 in decimal)
  
  HEXADECIMAL (base 16, starts with 0x or 0X):
    0xFeeL      Legal (hex number with L suffix)
    0x4b        Legal (hex number = 75 in decimal)
    0x20        Legal (hex number = 32 in decimal)
  
  NUMBER SYSTEM PREFIXES:
    0x, 0X      Hexadecimal (base 16)
    0           Octal (base 8)
    (none)      Decimal (base 10)
  
  SUFFIXES (case insensitive):
    U, u        Unsigned integer
    L, l        Long integer
    UL, ul      Unsigned long integer

FLOATING-POINT LITERALS:
  3.14          Decimal point notation
  3.14e2        Scientific notation (3.14 × 10²)
  .5            Also valid (equals 0.5)
  2.            Also valid (equals 2.0)
  1e-3          Equals 0.001
  2.5e+10       Equals 25,000,000,000

CHARACTER LITERALS:
  'A'           Single character in single quotes
  '5'           Character '5' (not number 5)
  '\n'          Escape sequence (newline)
  '\t'          Escape sequence (tab)

STRING LITERALS:
  "Hello"       String enclosed in double quotes
  "Hello World" Strings can contain spaces
  ""            Empty string
  "Line1\nLine2" String with escape sequence

EXAMPLE OF DIFFERENT LITERALS:

  int x = 10;           // 10 is integer literal
  float f = 3.14;       // 3.14 is float literal
  char c = 'A';         // 'A' is char literal
  string s = "Test";    // "Test" is string literal
  int hex = 0x20;       // 0x20 is hex literal
  int oct = 032;        // 032 is octal literal
*/ 
		- tam sayı
		- ondalık sayı
		- kesirli kısım
		- üstel kısım bulunmaktadır
	kayan noktalı sayılar ondalıklı ya da üstel biçimde gösterilebilirler
	
	3.14159       // Legal
	314159E-5L    // Legal  314159 * 10^-5
	510E          // Illegal: E sonrası boş
	210f          // Illegal: ondalık veya üs yok, 
	.e55          // Illegal: e öncesi boş

	3.14159L   // long double
	6.02e23f   // float, f konmazsa double literal olur

Boolean Sabitler
	true, false

Karakter Sabitler
	'A', 'x' gibi tek tırnakla gösterilirler
	3 türdedirler
		1. düz karakter: tek tırnakla gösterilen ('x', 'A')
		2. excape karakter: özel anlamı olan, \ ile başlar
		3. universal karakter ('\u02C0')
		
	Escape Karakterler
		\\	\ character
		\'	' character
		\"	" character
		\?	? character
		\a	Alert or bell
		\b	Backspace
		\f	Form feed
		\n	Newline
		\r	Carriage return
		\t	Horizontal tab
		\v	Vertical tab
		
String Sabitler
	çift tırnakla işaretlenirler
	"merhaba dünya"

	"merhaba \


	dünya"

Sabit Tanımlamak
		1. #define: 
			önişlemci komutudur
			iyi programlama için sabitleri büyük harflerle tanımlamak daha iyidir.
			
		2. const
			. herhangi bir değişkenin başına yazılarak değişken sabit yapılabilir.
			. program boyunca içeriği değiştirilmeyecek değişkenler için kullanılır
			. fonksiyonların geri dönüş ve parametre değişkenlerinin değiştirilmeye karşı korunması için bu şekilde tanımlanması yararlıdır
			. readonly anlamı katar
*/
