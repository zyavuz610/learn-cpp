#include <iostream>
#include <iomanip>
using namespace std;

int main() {
//-------------------------------------------------------

  char ad[50];
  cout << "Adınız : ";
  cin >> ad;   // cin.get(ad); fonksiyonu da aynı işi yapar
  cout << "Merhaba " << ad << endl;

//-------------------------------------------------------
// birden çok değişkeni aynı anda giriş yapmak için
// cin >> a >> b >> c;
// string değişkenler için
// getline(cin,ad); // boşluklar dahil alır
// cin>>ad;         // boşluklardan sonra alınmaz
//-------------------------------------------------------
/*
örnek: ortalama hesaplama
  int a,b,c;
  cout<<"3 sayı giriniz: ";
  cin>>a>>b>>c;
  cout<<"Ortalama: "<<(a+b+c)/3<<endl;
*/
//-------------------------------------------------------
/*
örnek2: öğrenci adı ve notları girilerek ortalama hesaplama
  string ad;
  int a,b,c;
  cout<<"Adınız: ";
  cin>>ad;
  cout<<"3 not giriniz: ";
  cin>>a>>b>>c;
  cout<<"Ortalama: "<<(a+b+c)/3<<endl;

  ya da aşağıdaki gibi de yapılabilir
  cout<<"Adınız ve 3 notunuzu giriniz: ";
  cin>>ad>>a>>b>>c;
*/
//-------------------------------------------------------
/*
// örnek3: while döngüsü ile sonsuz giriş yaparak ortalama hesaplama
  string ad;
  float a,b,c;
  while(1){
    cout<<"Öğrenci adı ve 3 not giriniz: ";
    cin>>ad;
    if(ad == "q") break;
    cin>>a>>b>>c;
    cout<<ad<<endl;
    cout<<"Ortalama: "<<(a+b+c)/3<<endl;
  }
*/
//-------------------------------------------------------
/*
    <iostream>
      bu kütüphanede standart giriş çıkış fonksiyonları tanımlıdır
      cout, cin, cerr, clog
    <iomanip>
      bu kütüphanede formatlı giriş çıkış fonksiyonları tanımlıdır
      setw, setprecision
    <fstream>
      bu kütüphanede dosya üzerinde işlem yapan fonksiyonlar ve türler tanımlıdır,
      fstream, ifstream, ofstream ...
*/
//------------------------------------------------------
// setw(n) formatlı yazdırma fonksiyonu, n karakterlik alan ayırır
// #include <iomanip> eklenmeli
// setprecison - hane sayısını belirler, noktadan sonra kaç hane yazılacağını belirler
// fixed - ondalık sayıları kesirli olarak gösterilmesini sağlar
//  aktif hale getirmek için
//    cout<<fixed<<setprecision(2)<<ort<<endl;
//  pasif hale getirmek için
//    cout<<std::noshowpoint<<ort<<endl; veya std::defaultfloat kullanılır
/*
  cout<<setw(15)<<"Ad";
  cout<<setw(15)<<"Arasınav";
  cout<<setw(15)<<"Final";
  cout<<setw(15)<<"Ortalama";
  cout<<endl;
  int a=25,f=55;            // rasgele başlangıç değerleri
  double a_d,f_d,ort;
  for(int i=0;i<10;i++){
    a=(a*f*f+53)%100;          // 0-100 arası bir not elde et
    f=(f*a*a+71)%100;
    a_d = (double)a;
    f_d = (double)f;
    ort=0.35165* a_d + 0.64835*f_d;
    cout<<setw(15)<<i+1;
    cout<<setw(15)<<a;
    cout<<setw(15)<<f;
    cout<<setw(15)<<setprecision(10)<<ort<<endl;
    //cout<<setw(15)<<fixed<<setprecision(10)<<ort<<endl;
  }
*/
//--------------------------------------------------------------    
/*
  double a = 30;
  double b = 10000.0;
  double pi = 3.1416;
  cout.precision (5);
  cout <<   showpoint << a << '\t' << b << '\t' << pi << '\n';
  cout << noshowpoint << a << '\t' << b << '\t' << fixed << setprecision(2)<< pi << '\n';
  
  //cout << noshowpoint << a << '\t' << b << '\t';
  //cout<<scientific;
  //cout.precision(2);
  //cout<< pi << '\n';
  */

//--------------------------------------------------------
  return 0;
}

/*
örnek programlar
- ortalama hesaplama, sonsuz döngü ile
- girilen yılın artık yıl olup olmadığını bulma, yüzyılını da hesaba kat
- girilen sayının asal olup olmadığını bulma
- girilen sayının faktöriyelini bulma
- girilen sayının karesini bulma
--------------------------------------------------------
bu programlar ayrıca fonksiyonlar bölümünde de çözülebilir
*/