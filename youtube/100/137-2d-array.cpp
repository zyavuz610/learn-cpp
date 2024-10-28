/*
  2 boyutlu diziler (matris)
*/
#include <iostream>
using namespace std;
int main() {
  int arr_1D[] = { 1, 2,3,4, 5};
  int arr_2D[2][3] = { {2,3,4}, // 2x3 lük bir matris
                       {5,6,7}};
  float mat[10][20]; // float matris tanımı
  cout<<"1D dizi örneği"<<endl;
  for(int i=0;i<5;i++){
    cout<<arr_1D[i]<<" ";
  }
  cout<<endl;
  cout<<"2D dizi örneği"<<endl;
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      cout<<arr_2D[i][j]<<" ";
    }
    cout<<endl;
  }
}