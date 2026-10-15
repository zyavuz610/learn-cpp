#include <iostream>
#include <bitset>
using namespace std;

int main() {
  // CHARACTER DATA TYPE - same in C and C++
  // Stores single character: 'A', 'b', or ASCII value like 70
  char ch = 'A';
  cout << "Character Value      : " << ch << " (ASCII: " << int(ch) << ")" << endl;
  cout << "Char Memory Size     : " << sizeof(char) << " byte" << endl;
  cout << "Binary Representation: " << bitset<8>(ch) << endl;
  
  int d = 97;
  cout << "Character Value      : " << char(d) << " (ASCII: " << d << ")" << endl;
  cout << "Char Memory Size     : " << sizeof(int) << " byte" << endl;
  cout << "Binary Representation: " << bitset<16>(ch) << endl;
  return 0;
  
}