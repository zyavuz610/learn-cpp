#include <iostream>
using namespace std;

int main() {
  cout<<"Dizi Örnek Uygulama (Kullanıcıdan Değer Alma)"<<endl;
  string koyler[100];
  int nufuslar[100];
  int sayi=0;
  string s;
  int n;
  while(true){
    cout<<"Köy ismi + Nüfus (çıkmak için q):>";
    cin>>s;  // köy bilgisi al
    if(s=="q"){
      break;
    }
    koyler[sayi] = s;
    cin>>n;    // nüfus bilgisi al
    nufuslar[sayi] = n;
    sayi++;
  }
  for(int i=0;i<sayi;i++){
    cout<<koyler[i]<<": "<<nufuslar[i]<<endl;
  }
}