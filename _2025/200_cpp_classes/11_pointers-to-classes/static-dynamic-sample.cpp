#include <iostream>
using namespace std;

class myMatrix{
  public:
    myMatrix(){
      _allocate(6,6);
    }
    myMatrix(int _rowCount,int _colCount){
      _allocate(_rowCount,_colCount);
    }
    void printSumMemory(){
        cout<<sumMemory<<endl;
    }
    void incSumMemory(){
        sumMemory += 100; 
    }
    static int objCount;
    static int sumMemory;
  protected:
    void _allocate(int _r,int _c){
        rowCount = _r;
        colCount = _c;
        data = new int*[rowCount];
        for(int i=0;i<rowCount;i++){
            data[i] = new int[colCount];
        }
        objCount++;
        sumMemory += rowCount * colCount;
    }
    int rowCount;
    int colCount;
    int **data;
  private:
};


int myMatrix::objCount  = 0;
int myMatrix::sumMemory = 0;


int main() {
  myMatrix m1,m2,m3(30,40);
  cout<<myMatrix::objCount<<endl;
  m1.printSumMemory();
  m2.printSumMemory();
  m1.incSumMemory();
  m2.printSumMemory();
}