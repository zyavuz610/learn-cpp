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

//------------------------------------------------------
/*
  kontrol edilecek koşul sadece eşitlik durumunu içeriyorsa switch-case kullanılması daha uygundur.
*/
/*
  char harf=' ';
  if(ort<40)
    harf='F';
  else if(ort<45)
    harf='D';
  else if(ort<60)
    harf='C';
  else if(ort<80)
    harf='B';
  else if(ort<=100)
    harf='A';
  else
    harf='E';
// neden else if içerisinde aralık kontrol edilmiyor?
  cout<<ort<<" -> ";
  switch(harf){
    case 'A':
      cout<<"Mükemmel"<<endl;
      break;
    case 'B':
      cout<<"İyi iş çıkardın"<<endl;
      break;
    case 'C':
      cout<<"Dersi geçtin, iyisin"<<endl;
      break;
    case 'D':
      cout<<"Seneye daha ilginç şeyler anlatılacak"<<endl;
      break;
    default:
      cout<<"Eksik Puan"<<endl;
  }
  // 1. break kullanılmazsa ne olur?
  // harf değişkeni string türünden olabilir mi?
*/
//----------------------------------------------------
/*
  // iç içe swtich-case
  switch(harf) {
   case 'A': 
      cout << "Dış switch-case durumu";
      switch(ch2) {
         case 'A':
            cout << "İç switch-case durumu";
            break;
         case 'B': // ...
      }
      break;
   case 'B': // ...
   // not yazılımı üzerinden bir örnek düşününü ve kodlayın...
}
*/  
/*
// switch-case ile menü uygulaması
cout<<"Program Menüsü"<<endl;
cout<<"1. Toplama"<<endl;
cout<<"2. Çıkarma"<<endl;
cout<<"3. Çarpma"<<endl;
cout<<"4. Bölme"<<endl;
cout<<"5. Çıkış"<<endl;
cout<<"Seçiminiz: ";
int secim;
cin>>secim;
switch(secim){
  case 1:
    cout<<"Toplama işlemi"<<endl;
    break;
  case 2:
    cout<<"Çıkarma işlemi"<<endl;
    break;
  case 3:
    cout<<"Çarpma işlemi"<<endl;
    break;
  case 4: 
    cout<<"Bölme işlemi"<<endl;
    break;
  case 5:
    cout<<"Çıkış"<<endl;
    break;
  default:
    cout<<"Hatalı seçim"<<endl;
}
*/

  return 0;
}

//--------------------------------------------------------------------------------------------

/*
soru: if-else ile switch-case ifadeleri arasında ne fark vardır? bunları birbirleri yerine kullanabilir miyiz?

*/
