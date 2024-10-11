/*
  1. değişken tanımlama
  2. tür dönüşümü
  3. if else merdiveni
  4. takas(swap) fonksiyonu
    call by value, call by pointer
  5. cout<<setw, setprecision, fixed
  6. öğrenci numarasının palindrome olup olmadığının kontrolü, döngü kullanmadan

*/

// 1. ----------------------------
/*
// basit girdi çıktı, tür dönüşümü, if else merdiveni
#include <iostream>
#include <iomanip> 
using namespace std;
int main() {
  int as=15,fn=16;
  //  cin>>as>>fn;
  float ort = (as + fn)/2.;
  char harf;
  if(ort>0 && ort<39){
    harf='F';
  }
  else if(ort<45){
    harf='D';
  }
  else if(ort<65){
    harf='C';
  }
  else if(ort<85){
    harf='B';
  }
  else if(ort<=100){
    harf='A';
  }
  else{
    harf='E';
  }
  cout<<setw(10)<<"AS"<<setw(10)<<"FN"<<setw(12)<<"Ort"<<setw(8)<<"Harf"<<endl;
  cout <<setw(10)<<as<<setw(10)<<fn<<setw(12)<<fixed<<setprecision(2)<<ort<<setw(8)<<harf<<endl;
}
*/
// 2. ------------------------------------

// öğrenci numarasının palindrom kontrolü
// koşul operatörü, döngüler, operatörler
#include <iostream>
#include <iomanip> 
using namespace std;
// sabit (6) haneli palindrom testi
int palindromTest1(int n){
  int b,o,y,bn,ob,yb;
  b = n%10; n /= 10;
  o = n%10; n /= 10;
  y = n%10; n /= 10;
  bn= n%10; n /= 10;
  ob= n%10; n /= 10;
  yb= n%10; n /= 10;
  if(b==yb && o==ob && y==bn)
    return 1;
  else
    return 0;
}
// değişken haneli palindrom testi
int palindromTest2(int n){
  int k,t=0,ydk=n;
  while(n>0)
  {
    k = n%10;
    n /= 10;
    t=t*10+k; 
  }
  return (ydk==t)?1:0;
}

bool checkPalindrome(string inputString) {
    int len = inputString.length();
    for(int i=0;i<=len/2;i++)
        if(inputString[i]!=inputString[len-1-i])
            return false;
    return true;
}

int main() {
  int as=15,fn=16,num=2552;
  //  cin>>as>>fn;
  float ort = (as + fn)/2.;
  char harf;
  if(ort>0 && ort<39){
    harf='F';
  }
  else if(ort<45){
    harf='D';
  }
  else if(ort<65){
    harf='C';
  }
  else if(ort<85){
    harf='B';
  }
  else if(ort<=100){
    harf='A';
  }
  else{
    harf='E';
  }
  int w[] = {9,5,5,8,8};
  cout<<setw(w[0])<<"No";
  cout<<setw(w[1])<<"AS";
  cout<<setw(w[2])<<"FN";
  cout<<setw(w[3])<<"Ort";
  cout<<setw(w[4])<<"Harf"<<endl;
  
  cout<<setw(w[0])<<num;
  cout<<setw(w[1])<<as;
  cout<<setw(w[2])<<fn;
  cout<<setw(w[3])<<fixed<<setprecision(2)<<ort;
  cout<<setw(w[4])<<harf<<endl;

  cout<<"Numara palindrom mu? : "<<palindromTest2(num)<<endl;

//--------------------------------------------------
/*
  cout<<checkPalindrome("ey edip adanada pide ye");
*/
//--------------------------------------------------
  return 0;
}