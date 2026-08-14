#include <iostream>
#define ARASINAV_K .45
#define FINAL_K    .55
using namespace std;

int main() {
  double a,f,ort;
  cout<<"Arasinav: ";
  cin>>a;
  cout<<"Final    :";
  cin>>f;
  ort=ARASINAV_K * a + FINAL_K * f;

  // iç içe swtich-case
  switch(harf) {
   case 'A': 
      cout << "Dış switch-case durumu";
      switch(ch2) {
         case 'A':
            cout << "İç switch-case durumu";
            break;
         case 'B': // ...
      }
      break;
   case 'B': 
      cout<<"İyi iş çıkardın"<<endl;
      break;
   default:
      cout<<"Eksik Puan"<<endl;
      break;
   // not yazılımı üzerinden bir örnek düşününü ve kodlayın...
  }
}