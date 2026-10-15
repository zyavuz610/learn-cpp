#include <iostream>

using namespace std;

int main(){
  int a = 5;
  float x = 3.14;
  int b = 10;

  int* ptr;
  ptr = &b;

  cout<<"The value of a is "<<a<<endl;
  cout<<"The value of b is "<<b<<endl;
  cout<<"The adress of a is "<<&a<<endl;
  cout<<"The adress of b is "<<&b<<endl;
  cout<<"The value of ptr is "<<ptr<<endl;
  cout<<"The value of *ptr is "<<*ptr<<endl;
  cout<<"The adress of ptr is "<<&ptr<<endl;
  return 0;  
}