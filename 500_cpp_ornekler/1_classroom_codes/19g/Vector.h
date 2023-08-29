#include <iostream>
using namespace std;

class Vector{
  public:
    Vector();
    Vector(const short int _n);
    void _allocate();
    void setRandomData();
    void print();
    void write(string _file);
    void read(string _file);
    ~Vector();
  private:
    short int N;    // eleman sayısı (2 byte)
    char *data;     // elemanları tutan char dizisi
};