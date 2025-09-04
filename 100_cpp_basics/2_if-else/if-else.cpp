#include <iostream>
#define ARASINAV_K .45
#define FINAL_K    .55
using namespace std;

int main() {
  double a,f,ort;
  cout<<"Arasinav: ";
  cin>>a; // user input
  cout<<"Final    :";
  cin>>f;

  // cin>>a>>f; // user input alternative

  ort=ARASINAV_K * a + FINAL_K * f;

 //  if-else ifadesi
 if( ort<40 ){       // koşul ifadesi
    cout<<ort<<" -> Kaldi\n";
  }
  else {              // if deyimindeki koşul sağlanmazsa
    cout<<ort<<" -> Gecti\n";
  }
}