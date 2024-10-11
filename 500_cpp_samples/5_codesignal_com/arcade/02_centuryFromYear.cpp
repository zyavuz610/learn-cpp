/*
  verilen yılın hangi yüzyıla ait olduğunu bulan fonk.
  1-100 = 1
  101-200 = 2
  ...
  1701-1800 = 18
*/

#include <iostream>
using namespace std;

int centuryFromYear(int year) {
    return (year+99)/100;
}

int main() {
  cout<<centuryFromYear(1701);
  return 0;
}
