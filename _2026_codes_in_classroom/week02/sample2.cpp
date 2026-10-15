#include <iostream>
#define DIFF 32
#define SIZE 3
// #include "stdio.h"
using namespace std;

const float mC = 0.4, fC = 0.6;

float func(const float a, const float b){
  //::mC = 20; ERROR
  float mC = 0.1, fC = 0.9;
  return ::mC*a + ::fC*b;  
}

string upperCase(string str){
  int n = str.length();
  string rStr = str; // copy
  for(int i=0;i<n;i++){
    if(int(str[i]) >= int('a') && int(str[i]) <= 'z')
    rStr[i] = char(  int(str[i])  - DIFF);
  }
  return rStr;
}

int main() {
  int _a , b_, c = 10, _, num1 ;
  cout<<c<<endl;
  cout<<_<<endl;

  /*
  3 öğrenci düşünün
  bir dizi tanımlayalım, içinde 3 öğrencinin arasınav ve final notları olsun.
  %40 arasınav
  %60 final olsun
  her öğrencinin adı olsun
  ortalamaları bul ve ekrana yaz.  
  */

  float midTermArr[] = {20,55,68};
  float final_[] = {35,45,12};
  string names[] = {"Alice", "Bob","ismail"};
  float avg[SIZE]={0}; // init
  int num = SIZE;

  for(int i=0;i<num;i++){
    //avg[i] = mC * midTermArr[i] + fC * final_[i];
    avg[i] = func(midTermArr[i],final_[i]);
    names[i] = upperCase(names[i]);
    cout<< names[i] << ": "<< avg[i];
    if(avg[i]<45){
      int k; "k is local in if statement";
      cout<<" - FAILED";
    } 
    else cout<<" - SUCCESS";
    cout<<endl;
    
  }
"To compile: g++ sample2.cpp -o run";
"To run: ./run";
  "https://codeshare.io/G7m8NL";
  return 0;
}




