/*
String İşlemleri 3
  string indisleme (karakterlere bireysel erişim)
  ASCII değerleri
  Örnek Uygulama:
    sayının rakamları toplamını bulmak
    12345 ==> 1+2+3+4+5=15
*/
#include <iostream>
using namespace std;

int main() {
  string s="Adanada pide ye-ABCD";
  /*
  char c0 = s[0]; // A, 65 değeri
  char c1 = s[1]; // d, 100 değeri
  cout<< s <<"[0]:"<<c0<<":"<<int(c0)<<endl;
  cout<< s <<"[1]:"<<c1<<":"<<int(c1)<<endl;
  */
  //-------------------------------------
  /*
  for(int i=0;i<s.size();i++){
    cout << s 
         <<"[" << i <<"]:"
         << s[i] // char karşılığı
         << ":" 
         <<int(s[i])  // ASCII değeri
         <<endl;
  }
  */
  //-----------------------------------------
  /*
  int n=2536789;
  int sum=0,rakam;
  string str = to_string(n); // "2536789"
  // 2,  5,  3,  6,  7,  8,  9
  // 50  53  51  54  55  56  57
  // 2 + 5 + 3 + 6 + 7 + 8 + 9 = 40
  char c;
  for(int i=0;i<str.length();i++){
    c = str[i]; // '1'
    rakam = int(c) - 48;
    sum += rakam;
  }
  cout<<"Rakamlar Toplamı:"<<sum<<endl;
  */

  int n = 2536789;
  int sum=0;
  int rakam;
  while(n>0){
    rakam = n%10; // 9, 8, 7, 6, 3, 5, 2
    sum += rakam; // 9+8+7+6+3+5+2 = 40
    n = n/10; // 253678.9 -> 253678 
              // 25367.8  -> 25367
              // 2536.7   -> 2536
              // 253
              // 25
              // 2
              // 0.0      -> 0
    cout << rakam <<"," << sum << ", "<< n <<endl;
  }
  cout<<"Rakam Toplamı:"<<sum<<endl;
  
}