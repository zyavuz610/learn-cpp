/*
Döngü Örnekleri 4: Hesap Makinesi (4 İşlem)
*/
#include <iostream>
using namespace std;

int main() {
  string islem;
  int sonuc=0,n;
  cout<<"Hesap Makinesi v2"<<endl;
  while(true){
    cout<<"İşlem + Sayı (çıkmak için q):";
    cin>>islem;
    if(islem == "q"){
      break;
    }
    cin>>n;
    //cout<<"Girilen İşlem:"<<islem<<endl;
    //cout<<"Sayı:"<<n<<endl;
    if(islem == "+"){
      sonuc += n;
      cout<<sonuc-n<< " "<<islem<<" = "<<sonuc<<endl;
    }
    else if(islem == "-"){
      sonuc -= n;
      cout<<sonuc+n<< " "<<islem<<" = "<<sonuc<<endl;
    }
    else if(islem == "*"){
      sonuc *= n;
      cout<<sonuc/n<< " "<<islem<<" = "<<sonuc<<endl;
    }
    else if(islem == "/"){
      sonuc /= n;
      cout<<sonuc*n<< " "<<islem<<" = "<<sonuc<<endl;
    }
    else{
      cout<<"Hatalı İşlem!"<<endl;
      //break;
    }
    
  }
  cout<<"Sonuç:"<<sonuc<<endl;
}