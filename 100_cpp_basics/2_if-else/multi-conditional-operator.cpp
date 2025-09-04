#include <iostream>
#define ARASINAV_K .45
#define FINAL_K    .55
using namespace std;

int main() {
  double a,f,ort;
  cout<<"Arasinav: ";
  cin>>a;
  cout<<"Final    :";
  cin>>f;
  ort=ARASINAV_K * a + FINAL_K * f;
 

 // çoklu şartlarda koşul operatörü (nested)
  string sonuc="";
  sonuc=(ort<40)?"Kaldı":(ort<55)?"Şartlı Geçti":"Geçti";
  cout<<ort<<" -> "<<sonuc<<"\n";
}