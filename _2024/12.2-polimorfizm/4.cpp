#include <iostream>
using namespace std;
class Shape {
   protected:
      int width, height;
      
   public:
      Shape( int a = 0, int b = 0){
         width = a;
         height = b;
      }
      virtual int area()=0;
      virtual ~Shape() {}    
};

class Zafer: public Shape{
    public:
        Zafer(int a = 0, int b = 0):Shape(a, b) { }
        

    private:
};

int main() {
   Shape *shape = new Zafer();
   cout<<shape->area()<<endl;
   return 0;
}
