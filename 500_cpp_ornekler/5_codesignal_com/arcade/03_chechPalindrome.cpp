/*
  verilen bir string in palindrome olduğunun bulunması

  tersi kendine eşit olan string
  Örn;
  amma
  adanada
  ey edip adanada pide ye
*/

#include <iostream>
using namespace std;

bool checkPalindrome(string inputString) {
    int len = inputString.length();
    for(int i=0;i<=len/2;i++)
        if(inputString[i]!=inputString[len-1-i])
            return false;
    return true;
}

int main() {
  cout<<checkPalindrome("ey edip adanada pide ye");
  return 0;
}
