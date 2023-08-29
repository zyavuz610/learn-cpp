#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
class Vector{
  public:
    Vector(){
      this->N = 10;
      cout<<"1";
      _allocate();
      cout<<"2";
      this->setRandomData();
      cout<<"3";
    }
    Vector(const short int _n){
      this->N = _n;
      _allocate();
      this->setRandomData();
    }
    void _allocate(){
      data = new char[this->N];
    }
    void setRandomData(){
      cout<<"Random başladı";
      srand (time(NULL));
      char r=0;
      for(int i=0;i<this->N;i++){
        r = (rand()%255 - 128);

        this->data[i] = r;
        cout<<(int)data[i]<<" ";
      }
    }
    void print(){
      cout<<"[";
      for(int i=0;i<this->N;i++)
        cout<<(int)this->data[i]<<",";
      cout<<"]";
    }
    void write(string _file){
      char buffer[2];
      buffer[0] = this->N / 256;
      buffer[1] = this->N % 256;

      ofstream file(_file,ios::out|ios::binary);
      file.write(buffer,2);
      file.write(this->data,this->N);
      file.close();
    }
    void read(string _file){
      char buffer[2];
      ifstream file(_file,ios::in|ios::binary);
      file.read(buffer,2);
      this->N = 256*buffer[0] + buffer[1];
      delete this->data;
      this->data = new char[this->N];
      file.read(this->data,this->N);
      file.close();
    }
    ~Vector(){
      delete data;
    }
  private:
    short int N;
    char *data;
};

int main() {
  Vector *v = new Vector(30);
  // önce burayı çalıştırın
  //v->write("data.bin");  
  
  // -73 84 45 -75 119 -24 24 -84 -124 -69 109 -18 58-65 -108 -58 74 -108 -61 -43 -46 60 1 -90 -6 -36 -67 60 92 -22
  // bunu çalıştırmadan önce "data.bin" dosyasının oluştuğundan emin olun
  v->read("data.bin");
  v->print();

}