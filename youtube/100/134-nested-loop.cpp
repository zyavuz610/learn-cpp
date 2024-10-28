/*
  İç-içe döngüler
*/
#include <iostream>
using namespace std;

int main() {
  cout<<"n: ";
  int n;
  cin>>n;
  for(int i=0;i<n;i++){    // x --> i, satır
    for(int j=0;j<n;j++){  // i --> j, sütun
      if((i+j)%2==0){
        cout<<"#";
      }
      else{
        cout<<" ";
      }
    }
    cout<<endl;
  }

}