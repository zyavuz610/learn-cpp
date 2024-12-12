/*
// 	MULTIPLE INHERITANCE
	- şu ana kadar görülen "single inheritance", yani tek bir sınıftan bir kez miras alınıyor
	- şimdi birden çok sınıftan miras alınması durumuna bakalım:
	- bir sınıf birden çok başka sınıftan miras alabilr,
	- her bir sınıftan miras alma yöntemi farklı olabilir
	- miras alırken virgül ile ayrım yapılır
	
	- base class üye fonksiyonları çakıştığında belirsizlik oluşabilir !!!!!

*/

//------------------------------------------------------------------
/*
      multiple inheritance
            * 2 base class
            * 1 derived class
*/


#include <iostream>
using namespace std;


class Shape {                 // Base class Shape
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      
   protected:
      int width;
      int height;
};


class PaintCost {             // Base class PaintCost
   public:
      int getCost(int area) {
         return area * 70;
      }
};


class Rectangle: public Shape, public PaintCost {     // Derived class
   public:
      int getArea() {
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   area = Rect.getArea();
   
   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;

   return 0;
}

/*
Çıktı:
Total area: 35
Total paint cost: $2450
*/

//==========================================================================
/*
	Çok Seviyeli Miras - Multi-level Inheritance
	- bir sınıf başka bir türetilmiş sınıftan miras alıyor
	- Derived Class >> Base Class 1 >> Base Class 2
	ya da
	- Base Class 1
		- Base Class 2
			- Derived Class
	- aşağıda bir örnek var
	
	Örnek: C++ Stream Classes (ağaç şeklinde çizilebilir)
	- ios
		- istream (cin)
			- ifstream
			- istringstream
			- iostream
		- ostream (cout,cerr,clog)
			- ofstream
			- ostringstream
			- iostream (hem istreamden hem de ostreamden miras alıyor)
		
	
*/

// C++ program to implement Multilevel Inheritance 

/*
#include <iostream> 
using namespace std; 
  
 
class Vehicle  {        // base class
      public: 
            Vehicle() 
            { 
                  cout << "This is a Vehicle" << endl; 
            } 
}; 
class fourWheeler: public Vehicle {  
      public: 
            fourWheeler() 
            { 
                  cout<<"Objects with 4 wheels are vehicles"<<endl; 
            } 
}; 
 
class Car: public fourWheeler{ // sub class derived from two base classes
   public: 
     car() 
     { 
       cout<<"Car has 4 Wheels"<<endl; 
     } 
}; 
  
// main function 
int main() 
{    
    //creating object of sub class will 
    //invoke the constructor of base classes 
    Car obj; 
    return 0; 
} 


*/
//==================================================================
/*
	Çoklu Miras Durumunda Belirsizlik
		- base class ların her ikisi de aynı fonksiyona sahipse bu durumda hangisinin çağırılacağı belirsiz olduğu için hata olur

class base1
{
  public:
     void someFunction( )
     { .... ... .... }  
};
class base2
{
    void someFunction( )
     { .... ... .... } 
};
class derived : public base1, public base2
{
    
};

int main()
{
    derived obj;
    obj.someFunction() // Error!  
}

!!!!!!!!!!!!!!!!!!!!!!! bu problem şu şekilde aşılır !!!!!!!!!!!!!!!!!!!!!!!!

int main()
{
    obj.base1::someFunction( );  // Function of base1 class is called
    obj.base2::someFunction();   // Function of base2 class is called.
}
	
*/

//===============================================================================
/*
	Hiyerarşik Miras
		- birden fazla türetilmiş sınıf aynı sınıftan türetiliyorsa hiyerarşik miras olur
		- base class
			- first_derived class
			- second_derived_class
			- third_derived_class
		
class base_class {
     ... .. ...
}

class first_derived_class: public base_class {
     ... .. ...
}

class second_derived_class: public base_class {
     ... .. ...
}

class third_derived_class: public base_class {
     ... .. ...
}

*/

/*
      yukarıdaki miras şekillerine örnek veriniz (sınıf içi çalışma)
*/