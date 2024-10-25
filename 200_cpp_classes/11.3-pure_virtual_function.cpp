//----------------------------------------------------------------------------
/*
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
      
    //  virtual int area(){
    //    cout<<"Area function called\n";
    //    return 0;
    //  } 
    
};
class Rectangle: public Shape {
   public:
      Rectangle( int a = 0, int b = 0):Shape(a, b) { }
};

class Triangle: public Shape {
   public:
      Triangle( int a = 0, int b = 0):Shape(a, b) { }
};

// Main function for the program
int main() {
   Shape *shape;

   //  abstract class olduğu için hata verir, çünkü tanımlanmamış area() fonk. var
   Rectangle rec(10,7);
   Triangle  tri(10,5);
   shape = &rec;
   shape->area();
   shape = &tri;
   shape->area();
   return 0;
}
*/
//------------------------------------------------------------------------


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
class Rectangle: public Shape {
   public:
      Rectangle( int a = 0, int b = 0):Shape(a, b) { }
      int area(){return width*height;}
};

class Triangle: public Shape {
   public:
      Triangle( int a = 0, int b = 0):Shape(a, b) { }
      int area(){return 0.5*width*height;}
};

// Main function for the program
int main() {
   Shape *shape;
   Rectangle rec(10,5);
   Triangle  tri(10,5);
   shape = &rec;
   cout<<shape->area()<<endl;
   shape = &tri;
   cout<<shape->area()<<endl;
   //Shape s2; // bu şekilde saf sanal sınıflar tek başına kullanılamazlar.
   return 0;
}
