/*
Program Sabitleri
  #define
  const
*/

#include <iostream>

// ön işlemci sabiti, bundan sonra N sembolü 6 değerini ifade eder. 
//#define N 6 

using namespace std;

int main() {
  const int N=6; // sabit değerli değişken
  cout<<"Dizi elamanlarını giriniz ("<<N<<" eleman)"<<endl;
  // N = 7; // Hata!, çünkü sabit değerli değişken değiştirilemez
  int dizi[N];
  for(int i=0;i<N;i++){
    cout<<i+1<<". elemanı giriniz:";
    cin>>dizi[i];
  }
  // i tanımlı değil
  for(int i=0;i<N;i++){
    if(dizi[i]%2 == 0){
      dizi[i] = dizi[i]/2;
    }
    else{
      dizi[i] = 3*dizi[i] + 1;
    }
  }
  cout<<"Dizinin yeni elemanları:"<<endl;
  for(int i=0;i<N;i++){
    cout<<dizi[i]<<" ";
  }
  cout<<endl;
}