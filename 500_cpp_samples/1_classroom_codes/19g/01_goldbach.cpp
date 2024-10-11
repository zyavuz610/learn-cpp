// https://repl.it/@ZaferYavuz1/190920
#include <iostream>
#define BOYUT 100

using namespace std;

int asalMi(int n){
  int asal=1;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      asal=0;
    }
  }
  return asal;
}

int main() {
  int son,i,j;
  for(i=4;i<=BOYUT;i+=2){
    for(j=2;j<i-2;j++){
      son = i-j; // i=10 için, j=2, son=8
      if(asalMi(j) && asalMi(son)){
        cout<<i<<" = "<<j<<" + "<<son<<endl;
        //break;
      }
    }
  }
  cout << "---\n";
}

/*
10
2 ... 10 asalllık
2, 8 X
3, 7 ok
...


*/
