/*
  İç-içe döngüler - (C++ 136)
    Örnek Uygulama: Tüm Asal sayıları bulma
*/
#include <iostream>
using namespace std;

int main() {
  unsigned long int n,bolen;
  while(true){
    cout<<"n (çıkmak için \"0\"):> ";
    cin>>n;
    if(n==0) break; // çıkış
    for(int x=2;x<=n;x++){
      // her x sayısının asal olup olmadığını bulalım
      bolen=0;
      for(int i=2;i<x;i++){
        if(x%i == 0){
          bolen++;
          break;
        } 
      }
      if(bolen==0){
        cout<<x<<" ";
      }
    }
    cout<<endl;
  }
  cout<<"Güle güle!..."<<endl;
}