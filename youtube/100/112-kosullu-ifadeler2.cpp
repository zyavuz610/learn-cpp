#include <iostream>
using namespace  std;

int main() {
  double not1,not2;
  cout<<"Not Girişi Yapınız(?not1 not2):";
  cin >> not1 >> not2;
  double ort = (not1+not2)/2;
  cout<< "Ortalama:"<< ort <<endl;
  if (ort < 50) {
    cout<<"Kaldı";
  }
  else{
     cout<<"Geçti"; 
  }
  cout<<endl;

  cout<<"Harf Notu:";
  if (ort<40){
    cout<<"FF";
  }
  else if(ort < 50){
    cout<<"DD";
  }
  else if(ort<60){
    cout<<"CC";
  }
  else if(ort<70){
    cout<<"BB";
  }
  else{ // ort>=70
    cout<<"AA";
  }
  cout<<endl;
}