/*

String İşlemleri 4
  string içinde özel karakterler
    \n, \", \t, \\, \0 (NULL)
  string formatlama
    #include <cstdio> 
    #include "stdio.h" // C dili için

*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  cout<<"Adam ka\nepeye\t \"Oturma!\" dedi."<<endl;
  int n1 = 20;
  int n2 = 25;
  int sum = n1 + n2;
  cout << n1 << " + " << n2 << " = " << sum << endl;
  printf("Sonuç => %d + %d = %d\n",n1,n2,sum);
}