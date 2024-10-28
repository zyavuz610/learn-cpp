/*
Uygulama: Matris Toplamı ve Farkı
*/
#include <iostream>
#define N 2
#define M 3
using namespace std;

int main() {
  float mat1[][M] = {
    {2.6,  3.2, 1.5},
    {1.2, -2.1, 4.5}
  };
  float mat2[][M] = {
    {1,2,3},
    {4,5,6}
  };
  float toplam[N][M];
  float fark[N][M];
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      toplam[i][j] = mat1[i][j] + mat2[i][j];
      fark[i][j] = mat1[i][j] - mat2[i][j];
      cout <<i<<" "<<j<<" -> "
           << toplam[i][j]
           <<" -> "
           << fark[i][j]
           <<endl;
    }
  }
  cout<<"--- 1. Matris: ---"<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<mat1[i][j]<<",\t";
    }
    cout<<endl;
  }
  cout<<"--- 2. Matris: ---"<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<mat2[i][j]<<",\t";
    }
    cout<<endl;
  }
  cout<<"--- Toplam Matris: ---"<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<toplam[i][j]<<",\t";
    }
    cout<<endl;
  }
  cout<<"--- Fark Matris: ---"<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<fark[i][j]<<",\t";
    }
    cout<<endl;
  }
  cout<<"Program sonlandı, güle güle..."<<endl;
  return 0;
}