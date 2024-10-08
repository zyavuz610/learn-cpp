/*
Döngü Örnekleri 2: Toplam Problemi
*/
#include <iostream>
using namespace std;

int main() {
  int n,sum=0;
  cout<<"TOPLAM BULMA ÖRNEĞİ\n";
  cout<<"n sayısı:";
  cin>>n;
  for(int i=1;i<=n;i++){
    sum = sum + i;
    /*
    sum += i  --> sum = sum + i
    sum -= i  --> sum = sum - i
    sum *= i  --> sum = sum * i
    sum /= i  --> sum = sum / i
    sum %= i  --> sum = sum % i
    */
    cout<<"i:"<<i<<" - sum:"<<sum<<endl;
  }
  cout<<"1+...+"<<n<<" = "<<sum<<endl;
  /*
  i++ : i değişkeninin değerini 1 arttır (önce okur sonra arttırır)
  ++i : i değişkeninin değerini 1 arttır (önce arttırır sonra okur)
  i = 3;
  a = i++ * 5 // a = 15, i=4
  a = ++i * 5 // i=4, a = 20

  i-- : i değişkeninin değerini 1 azaltır (önce okur sonra azaltır)
  --i : i değişkeninin değerini 1 azaltır (önce azaltır sonra okur)
  i = 3;
  a = i-- * 5 // a = 15, i=2
  a = --i * 5 // i=2, a = 10
*/
}