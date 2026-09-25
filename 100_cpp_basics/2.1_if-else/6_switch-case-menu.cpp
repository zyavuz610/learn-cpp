#include <iostream>
#define ARASINAV_K .45
#define FINAL_K    .55
using namespace std;

int main() {
// switch-case ile menü uygulaması
cout<<"Program Menüsü"<<endl;
cout<<"1. Toplama"<<endl;
cout<<"2. Çıkarma"<<endl;
cout<<"3. Çarpma"<<endl;
cout<<"4. Bölme"<<endl;
cout<<"5. Çıkış"<<endl;
cout<<"Seçiminiz: ";
int secim;
cin>>secim;
switch(secim){
  case 1:
    cout<<"Toplama işlemi"<<endl;
    break;
  case 2:
    cout<<"Çıkarma işlemi"<<endl;
    break;
  case 3:
    cout<<"Çarpma işlemi"<<endl;
    break;
  case 4: 
    cout<<"Bölme işlemi"<<endl;
    break;
  case 5:
    cout<<"Çıkış"<<endl;
    break;
  default:
    cout<<"Hatalı seçim"<<endl;
}
  return 0;
}

//--------------------------------------------------------------------------------------------

/*
soru: if-else ile switch-case ifadeleri arasında ne fark vardır? bunları birbirleri yerine kullanabilir miyiz?

*/
