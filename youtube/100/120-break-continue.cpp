/*
break/continue deyimleri
  break: özel şart sağlandığında döngüyü kırar (sonlandırır)
  continue: özel şart sağlandığında bir sonraki tekrardan devam eder
*/
#include <iostream>
using namespace std;

int main() {
/*
  int n=20;
  for(int i=1;i<=n;i++){
    if(i%7 == 0){
      //break;
      continue;
    }
    cout<<i<<endl;
  }
  cout<<"Döngü sonlandı"<<endl;
  */
  int n,sum=0;
  cout<<"TOPLAM PROBLEMİ 2\n";
  
  while(true){
    cout<<"Sayı (çıkmak için 0):";
    cin>>n;
    if (n==0){
      break;
    }
    sum += n;
    cout<<sum-n<<" + "<<n<<" = "<<sum<<endl;
  }
  cout<<"Toplam: "<<sum<<endl;
}