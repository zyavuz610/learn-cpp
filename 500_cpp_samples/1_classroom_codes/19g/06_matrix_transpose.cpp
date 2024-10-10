#include <iostream>
#define ROW 4
#define COL 4
using namespace std;
void transpoze(int mat[][COL],int r,int c){
  int temp;
  for(int i=0;i<r;i++){
    for(int j=0;j<i;j++){
      temp      = mat[i][j];
      mat[i][j] = mat[j][i];
      mat[j][i] = temp;
    }
  }  
}
void print(int mat[][COL],int r,int c){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }  
}
int main() {
  int mat[][COL] = {{3,9,5,7},
                 {1,-2,8,4}, 
                 {3,9,5,1}, 
                 {-5,2,5,0} 
                };
  transpoze(mat,ROW,COL);
  print(mat,ROW,COL);
  return 0;
}