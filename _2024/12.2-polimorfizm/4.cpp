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
};

int main() {
   Shape *shape = new Zafer();
   cout<<shape->area()<<endl;
   return 0;
}
