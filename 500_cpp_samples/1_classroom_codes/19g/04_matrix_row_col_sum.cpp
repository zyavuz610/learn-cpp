#include <iostream>
#include <iomanip>
using namespace std;
#define ROW 3
#define COL 4
/*
  * mat     : matrix
  * row,col : matrix dimensions
  * r1,r2   : rows to be changed
  * c1,c2   : cols to be changed
*/
void changeRows(int mat[ROW][COL],int row,int col,int r1,int r2){
  for(int j=0;j<col;j++){
    swap(mat[r1][j],mat[r2][j]);
  }
}
void changeCols(int mat[ROW][COL],int row,int col,int c1,int c2){
  for(int i=0;i<row;i++){
    swap(mat[i][c1],mat[i][c2]);
  }
}
int * findRowsSum(int mat[ROW][COL],int row,int col){
  int *rowsSum = new int[ROW];
  for(int i=0;i<row;i++){
    rowsSum[i] = 0;
    for(int j=0;j<col;j++){
      rowsSum[i] += mat[i][j];
    }
  }
  return rowsSum;
}
int * findColsSum(int mat[ROW][COL],int row,int col){
  int *colsSum = new int[COL];
  for(int j=0;j<col;j++){
    colsSum[j] = 0;
    for(int i=0;i<row;i++){
      colsSum[j] += mat[i][j];
    }
  }
  return colsSum;
}

void printMat(int mat[ROW][COL],int row,int col){
  cout<<setw(3)<<" ";
  for(int j=0;j<col;j++){
    cout<<setw(3)<<right<<j;    
  }
  cout<<endl;
  for(int i=0;i<row;i++){
    cout<<setw(1)<<left<<i<<setw(2)<<":"<<right;
    for(int j=0;j<col;j++){
      cout<<setw(3)<<mat[i][j];    
    }
    cout<<endl;
  }
  cout<<"======================================"<<endl;
}
void printMatwithSum(int mat[ROW][COL],int row,int col,int *rSum,int *cSum){
  cout<<setw(3)<<" ";
  for(int j=0;j<col;j++){
    cout<<setw(4)<<right<<j;    
  }
  cout<<"   "<<setw(4)<<"Top"<<endl;
  for(int i=0;i<row;i++){
    cout<<setw(1)<<left<<i<<setw(2)<<":"<<right;
    for(int j=0;j<col;j++){
      cout<<setw(4)<<mat[i][j];    
    }
    cout<<" = "<<setw(4)<<rSum[i];
    cout<<endl;
  }
  cout<<"---------------------------------"<<endl;
  cout<<setw(3)<<"Top";
  for(int j=0;j<col;j++){
    cout<<setw(4)<<right<<cSum[j];    
  }
  cout<<endl;
  cout<<"======================================"<<endl;
}

void sortWithRows(int mat[ROW][COL],int row,int col){
  int *sumOfRows = findRowsSum(mat,row,col);
  for(int i=0;i<row;i++){
    for(int j=i;j<row;j++){
      if(sumOfRows[i] > sumOfRows[j]){
        swap(sumOfRows[i],sumOfRows[j]);  
        changeRows(mat,row,col,i,j);
      }
    }
  }
}
void sortWithCols(int mat[ROW][COL],int row,int col){
  int *sumOfCols = findColsSum(mat,row,col);
  for(int i=0;i<col;i++){
    for(int j=i;j<col;j++){
      if(sumOfCols[i] > sumOfCols[j]){
        swap(sumOfCols[i],sumOfCols[j]);  
        changeCols(mat,row,col,i,j);
      }
    }
  }
}

int main() {
  int m[ROW][COL] = { {3, 5, 7, 18},
                      {13,15,71, 8},
                      {32,51,17, 4}
                      };
  int *sumOfRows;
  int *sumOfCols;
  cout<<"Orjinal Matris:"<<endl;
  printMat(m,ROW,COL);       

  changeRows(m,ROW,COL,0,2);
  cout<<"0. ve 2. satırlar yer değiştirdi:"<<endl;
  printMat(m,ROW,COL);

  changeCols(m,ROW,COL,1,3);
  cout<<"1. ve 3. sütunlar yer değiştirdi:"<<endl;
  printMat(m,ROW,COL);

  sumOfRows = findRowsSum(m,ROW,COL);
  sumOfCols = findColsSum(m,ROW,COL);
  cout<<"satır ve sütun toplamları yazıldı:"<<endl;
  printMatwithSum(m,ROW,COL,sumOfRows,sumOfCols);
  
  sortWithRows(m,ROW,COL);
  sumOfRows = findRowsSum(m,ROW,COL);
  sumOfCols = findColsSum(m,ROW,COL);
  cout<<"satır toplamlarına göre sıralandı:"<<endl;
  printMatwithSum(m,ROW,COL,sumOfRows,sumOfCols);

  sortWithCols(m,ROW,COL);
  sumOfRows = findRowsSum(m,ROW,COL);
  sumOfCols = findColsSum(m,ROW,COL);
  cout<<"sütun toplamlarına göre sıralandı:"<<endl;
  printMatwithSum(m,ROW,COL,sumOfRows,sumOfCols);
  return 0;
}