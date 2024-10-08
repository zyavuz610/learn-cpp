/*
Döngü Örnekleri 3: Hesap Makinesi (Toplama)
*/
#include <iostream>
using namespace std;

int main() {
  int n,sum=0;
  cout<<"TOPLAM PROBLEMİ 2\n";
  do{
    cout<<"Sayı (çıkmak için 0):";
    cin>>n;
    sum += n;
    cout<<sum-n<<" + "<<n<<" = "<<sum<<endl;
  }while(n!=0);
  cout<<"Toplam: "<<sum<<endl;
}