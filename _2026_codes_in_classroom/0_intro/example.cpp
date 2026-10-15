#include <iostream>
using namespace std;

int main() {
  double s1=60, s2=35;
  double avg = 0.5*s1 + 0.5*s2;

  if (avg<50){
    cout << "UN-SUCCESSFULL";
  }
  else {
    cout << "SUCCESSFULL";
  }
  cout << "\n" << endl;
  return 0;
}