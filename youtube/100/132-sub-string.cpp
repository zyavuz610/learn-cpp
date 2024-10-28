/*
String İşlemleri 5
  string içinde;
    arama
    alt string bulma
  Örnek Proje:
    isim soy isimden soyisim bulma
*/
#include <iostream>
using namespace std;

int main() {
  //          012345678901234567890123 
  string s = "Temel Seviye C++ Eğitimi";
  string s2 = s.substr(6,6);
  cout<<"String: "<<s<<endl;
  cout<<"Alt String: "<<s2<<endl;
  string ara = "C++";
  int konum = s.find(ara,0);
  cout<< (ara + " Konumu: ") <<konum<<endl;

  cout<<"------Örnek--------"<<endl;
  //                0123456
  string tamisim = "Salih Gökhan Ahmet Yavuz";
  cout<<"İsim: "<<tamisim<<endl;
  string sDizi[10], tempStr;
  int kelimeN = 0;
  int start=0,len=0;
  while(true){
    len = tamisim.find(" "); // if not, -1
    if(len == -1){
      tempStr = tamisim.substr(0,len);
      sDizi[kelimeN] = tempStr;
      kelimeN++;
      break;
    }
    else{
      tempStr = tamisim.substr(0,len);
      sDizi[kelimeN] = tempStr;
      kelimeN++;
      tamisim = tamisim.substr(len+1,-1);
    }
    cout<<"Alt String: " + tempStr<<endl;
    cout<<"Kalan String: "<<tamisim<<endl;
  }
  cout<<"Kelime Sayısı: "<<kelimeN<<endl;
  cout<<"Soyisim: "<<sDizi[kelimeN-1]<<endl;
}

/*
  Örnek Proje 2:
    kullanıcı girişi: 23,15,25,11,154
    virgülle ayrılan sayıları topla
  Örnek Proje 3:
    giriş: 3+56
    çıktı: 59
    giriş: 56*2
    çıktı: 112
   bu şekilde 2 sayı ve aralarında bir işlem olan işlemin sonucunu bul,
   işlemler: +,-,*,/,%,**
   ** operatörü üs alma, 2**3 =8 gibi
*/