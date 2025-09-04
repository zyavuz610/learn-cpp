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

/*
  kontrol edilecek koşul sadece eşitlik durumunu içeriyorsa switch-case kullanılması daha uygundur.
*/

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
}