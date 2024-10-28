/*

String İşlemleri 1
  Kullanıcıdan içinde boşluk olan string değerleri alma

*/
#include <iostream>
using namespace std;

int main() {
  string s;
  cout<<"Ad Soyad:";
  //cin>>s;
  getline(cin,s);
  cout<<"Merhaba "<<s<<endl;
}