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
 
 // if, else if, else koşul merdiveni. örnek uyg: harfli not hebabı 
 if( ort<40 ){       // koşul ifadesi
    cout<<ort<<" -> Kaldı\n";
  }
  else if (ort<55) {              
    cout<<ort<<" -> Şartlı Geçti\n";
  }
  else{               // hiç bir koşul sağlanmazsa
    cout<<ort<<" -> Şartlı Geçti\n";
  }
}