#include <iostream>
#define ARASINAV_K .45
#define FINAL_K    .55
using namespace std;

int main() {
  double a,f,ort;
  cout<<"Arasınav: ";
  cin>>a;
  cout<<"Final    :";
  cin>>f;
  ort=ARASINAV_K * a + FINAL_K * f;
//---------------------------------------------------
// koşul operatörü kullanımı (sadece eşitleme durumunda)

 string sonuc="";
  sonuc=(ort<40)?"Kaldı":"Geçti";
  cout<<ort<<" -> "<<sonuc<<"\n";   
}