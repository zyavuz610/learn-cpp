/*
  İç-içe döngüler
    Örnek Uygulama: Asal sayı bulma
      1 ve kendisinden başka böleni olmayan sayılardır
dene: 125478912351
*/
#include <iostream>
using namespace std;

int main() {
  unsigned long int n,bolen;
  while(true){
    cout<<"n (çıkmak için \"0\"):> ";
    cin>>n;
    if(n==0) break; // çıkış
    bolen=0;
    for(int i=2;i<n;i++){
      if(n%i==0){
        bolen++;
        cout<<i<<" ";
        break;
      }
    }
    if(bolen==0){
      cout<<n<<" sayısı ASAL dır"<<endl;
    }
    else{
      cout<<n<<" sayısı ASAL DEĞİL dir"<<endl;
    }    
  }
  cout<<"Güle güle!..."<<endl;
}