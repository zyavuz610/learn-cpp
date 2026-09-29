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
 

  // nested (içiçe) koşul ifadeleri
  double kanaat = 3.5;
  if(ort<45){
    cout<<ort<<" -> Kaldı"<<endl;
    if (ort>39 && kanaat >2.5){
      cout<<ort<<" -> Şartlı Geçebilir"<<endl;
    }
  }
}