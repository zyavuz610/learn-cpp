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
  int sum=0;
  int max=-999999,min=999999;
  int max_indis,min_indis;
  for(int i=0;i<sayi;i++){
    sum += nufuslar[i];
    if(nufuslar[i] > max){
      max = nufuslar[i];
      max_indis = i;
    }
    if(nufuslar[i] < min){
      min = nufuslar[i];
      min_indis = i;
    }
  }
  cout<<"Toplam Nüfus: "<<sum<<endl;
  cout<<"En çok Nüfus: "<<endl
      <<koyler[max_indis]<<": "<<max<<endl;
  cout<<"En az Nüfus: "<<endl 
      <<koyler[min_indis]<<": "<<min<<endl;
}