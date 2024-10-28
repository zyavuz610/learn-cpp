/*
  switch-case
*/
#include <iostream>
using namespace  std;

int main() {
  int n;
  bool durum=true;
  while(durum){
    cout<<"1. Ekle"<<endl;
    cout<<"2. Sil"<<endl;
    cout<<"3. Düzenle"<<endl;
    cout<<"4. Yardım"<<endl;
    cout<<"5. Çıkış"<<endl;
    cout<<"------------------"<<endl;
    cout<<"Seçim:";
    cin>>n;
    switch(n){
      case 1:
        cout<<"Ekle seçildi"<<endl;
        break;
      case 2:
        cout<<"Sil seçildi"<<endl;
        break;
      case 3:
        cout<<"Düzenle seçildi"<<endl;
        break;
      case 4:
        cout<<"Yardım seçildi"<<endl;
        break;
      case 5:
        cout<<"Çıkış seçildi"<<endl;
        durum=false;
        break;
      default:
        cout<<"Hiçbiri seçilmedi"<<endl;
    }
  }
  
  /*
  if(n==1)      cout<<"Ekle seçildi"<<endl;
  else if(n==2) cout<<"Sil seçildi"<<endl;
  else if(n==3) cout<<"Düzenle seçildi"<<endl;
  else if(n==4) cout<<"Yardım seçildi"<<endl;
  else if(n==5) cout<<"Çıkış seçildi"<<endl;
  */
  
  
}