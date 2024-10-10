#include <iostream>
using namespace std;

float ortalamaBul(int dizi[]){
  int top = 0;
  for(/* 1 */int i=0 ;/* 2 */i<10 ;/* 3 */i++ ){
      top += dizi[i];
  }
  return top/10.;
}

void grafikCiz(int dizi[],int n){
  int ys;
  for(int i=0;i<n;i++){
    ys = dizi[i] / 10;
    for(int j=0;j<ys;j++){
      cout<<"*";
    }
    cout<<endl;
  }
}

int ortaDegerBul(int *dizi){
  // önce diziyi sırala
  int temp;
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      if(dizi[i] > dizi[j]){
        temp = dizi[i];
        dizi[i] = dizi[j];
        dizi[j] = temp;
      }
  return dizi[5];
}

int * minmaxBul(int dizi[],int n){
  int *m = new int[2];
  m[0] = -1000;
  m[1] = 1000;
  return m;
}

int main() {
  int dizi[10] ={101,21,26,41,65,50,37,82,15,93};
  grafikCiz(dizi,10);
  cout <<"Ortalama: "<< ortalamaBul(dizi)<<endl;
  cout <<"Orta Değer: "<< ortaDegerBul(dizi)<<endl;
  grafikCiz(dizi,10);

  int *m = minmaxBul(dizi,10);
  cout <<"(Min,Max)= "<<m[0]<<","<<m[1]<<endl;
  return 0;
}