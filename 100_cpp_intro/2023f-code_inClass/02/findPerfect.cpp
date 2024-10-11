#include <iostream>

using namespace std;

// fonksiyon bildirimi (ing: declaration)
bool isPerfect(int);

int main(){
  int n;
  cout << "Bir sayı giriniz: ";
  cin >> n;
  if(isPerfect(n))
    cout << n << " mükemmel sayıdır" << endl;
  else
    cout << n << " mükemmel sayı değildir" << endl;
  return 0;
}

// fonksiyon tanımı (ing: definition)
bool isPerfect(int n){
  int sum=0;
  for(int i=1;i<n;i++){
    if(n%i==0)
      sum+=i;
  }
  if(sum==n)
    return true;
  else
    return false;
}