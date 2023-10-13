#include <iostream>

using namespace std;

// fonksiyon bildirimi (ing: declaration)
int findSum(int,int);
int findCentury(int);

int main(){
  int a,b,c;
  a=findSum();
  b=findSum(5);
  c=findSum(5,6);
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "c=" << c << endl;
  return 0;
}

// fonksiyon tanımı (ing: definition)
int findSum(int a=10,int b=20){
  return a+b;
}

int findCentury(int year){
  return (year-1)/100+1;
}