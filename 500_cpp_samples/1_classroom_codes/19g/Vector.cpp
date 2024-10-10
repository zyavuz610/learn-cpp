#include "Vector.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
Vector::Vector(){                 // parametresiz yapıcı method
  this->N = 10;           // default 10 eleman
  cout<<"1";
  _allocate();            // yer ayır
  cout<<"2";
  this->setRandomData();  // ragtgele değerler atandı
  cout<<"3";
}
Vector::Vector(const short int _n){
  this->N = _n;           // eleman sayısı
  _allocate();            // yer ayır
  this->setRandomData();  // rastgele değerler ata
}
void Vector::_allocate(){
  this->data = new char[this->N];   // 1D dynamic memory alloacation
}
void Vector::setRandomData(){           // rastgele methodu
  cout<<"Random başladı:\n";
  long int _seed = time(NULL);
  srand (_seed);           // rastgele için tohum ayarlar 
  cout<<"Tohum:"<<_seed<<endl;
  char r=0;
  for(int i=0;i<this->N;i++){   // N tane rastgele sayı
    r = (rand()%255 - 128);     // r € [-128,127], char aralığı
    this->data[i] = r;
    //cout<<(int)data[i]<<" ";
  }
}
void Vector::print(){
  cout<<"[";
  int ch;
  for(int i=0;i<this->N;i++){
    ch = (int)this->data[i];
    ch = (ch<0)?ch+256:ch;
    cout<<ch<<",";
  }
  cout<<"]";
}
void Vector::write(string _file){
  char buffer[2];
  buffer[0] = this->N / 256;
  buffer[1] = this->N % 256;

  ofstream file(_file,ios::out|ios::binary);
  file.write(buffer,2);
  file.write(this->data,this->N);
  file.close();
}
void Vector::read(string _file){
  char buffer[2];
  ifstream file(_file,ios::in|ios::binary);
  file.read(buffer,2);
  this->N = 256*buffer[0] + buffer[1];
  delete this->data;
  this->data = new char[this->N];
  file.read(this->data,this->N);
  file.close();
}
Vector::~Vector(){
  delete data;
}