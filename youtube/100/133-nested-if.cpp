/*
  İç-içe if-else

artık yıl problemi
- 4'ün katları artık yıldır (1704), diğer yıllar değil (1701)
  - 100'ün katı olan yıllar artık yıl değildir (1700)
    - 400'ün katı yıllar artık yıldır (2000)
      - 4000'in katı olan yıllar artık yıl değildir (hassaslık için)
*/
#include <iostream>
using namespace std;

int main() {
  cout<<"---- Artık Yıl BULucu (AYBUL v1.0) ----"<<endl;
  string s;
  int n;
  bool artikYil;
  while(true){
    cout<<"Giriş (çıkmak için q) :>";
    cin>>s;
    if(s=="q") { break; }
    n = stoi(s);
    if(n%4 == 0){
      artikYil = true;
      if(n%100 == 0){
        artikYil = false;
        if(n%400 == 0){
          artikYil = true;
          if(n%4000 == 0){
            artikYil = false;
          }
        }
      } 
    }
    else{
      artikYil = false;
    }
    if(artikYil){
      cout<< n << ": artık yıldır"<<endl;
    }
    else{
      cout<< n << ": artık yıl DEĞİLdir"<<endl;
    }
  }
  cout<<"Güle güle ! ..."<<endl;
}