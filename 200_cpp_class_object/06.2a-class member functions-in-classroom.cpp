#include <iostream>
using namespace std;

class Box {
   private:
      double length;         // Length of a box
      double breadth;        // Breadth of a box
      double height;         // Height of a box
      string name;
   public:
      // Member functions declaration
      double getVolume(void);
      void printVolume();
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );
      void setName(string nm);
};

double Box::getVolume(void) {
   return length * breadth * height;
}

void Box::setLength( double len ) {
   length = len;
}
void Box::setBreadth( double bre ) {
   breadth = bre;
}
void Box::setHeight( double hei ) {
   height = hei;
}
void Box::setName(string nm){
  name = nm;
}

void Box::printVolume(){
  double volume = getVolume();
  cout<<"Volume of "<<name<<" : "<<volume<<endl;
}
int main() {
   Box Box1;                // Box türünden Box1 isimli nesne
   Box Box2;                // Box türünden Box2 isimli nesne
   double volume = 0.0;     // 
 
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
   Box1.setName("Box1");

   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
   Box2.setName("Box2");

   volume = Box1.getVolume();
   Box1.printVolume();

   // volume of box 2
   volume = Box2.getVolume();
   Box2.printVolume();
   return 0;
}
