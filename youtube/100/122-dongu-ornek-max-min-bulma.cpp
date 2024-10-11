/*
  Döngü Örnekleri 5: Maximum Minimum Bulma Problemi
*/
#include <iostream>
using namespace std;

int main() {
  cout<<"Maksimum Minimum Bulma Problemi"<<endl;
  int n,sum=0,max=-999999,min=999999;
  while(true){
    cout<<"Sayı (çıkmak için 0):> ";
    cin>>n;
    if(n == 0){
      break;
    }
    if(n > max){
      max = n;
    }
    if (n < min){
      min = n;
    }
    sum += n;
    cout << "Maksimum :" << max << endl
         << "Minimum  :" << min << endl
         << "Toplam   :" << sum << endl;
  }
}