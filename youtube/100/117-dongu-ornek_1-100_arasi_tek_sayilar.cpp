#include <iostream>
using namespace std;

/*
1-100 arası tek sayıları, çift sayılar
*/

int main() {
  int n0=1,n1 = 10;
  cout<<"Tüm Sayılar:"<<endl;
  for(int i =n0;i<=n1;i++){
    cout << i << endl;
  }
  cout<<"Çift Sayılar:"<<endl;
  for(int i =n0;i<=n1;i++){
    if(i%2 ==0) { // çift sayı olma şartı
      cout << i << endl;
    }
  }
  cout<<"Tek Sayılar:"<<endl;
  for(int i =n0;i<=n1;i++){
    if(i%2 ==1) { // tek sayı olma şartı
      cout << i << endl;
    }
  }
  
  cout<<"2. çözüm:"<<endl;
  // n0 = 0, tek
  if (n0%2 == 1){
    n0++;
  }
  for(int i =n0;i<=n1;i+=2){
    cout << i << endl;
  }
}