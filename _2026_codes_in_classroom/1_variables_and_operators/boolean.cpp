#include <iostream>
#include <bitset>
using namespace std;

int main() {
   bool isEmpty = true;
   cout << "Boolean Value        : " << isEmpty << endl;
   cout << "Boolean Memory Size  : " << sizeof(bool) << " byte" << endl;
   cout << "Binary Representation: " << bitset<4>(isEmpty) << endl;

  return 0;
}