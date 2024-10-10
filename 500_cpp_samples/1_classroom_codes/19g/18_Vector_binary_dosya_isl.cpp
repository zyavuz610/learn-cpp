#include "Vector.h"
using namespace std;

int main() {
  Vector *v = new Vector(100);
  //v->write("data.bin");  
  v->read("data.bin");
  v->print();

}