//-------------------------------------------------------------------------
/*
	
	pure virtual function
		* temel sınıfta tanımlanır
		* temel sınıfta tanımlı herhangi bir işlevi yoktur, sadece fonksiyonun prototipi tanımlıdır
		* virtual type func-name(parameters...)=0;  şeklinde tanımlanır.
		* her türetilmiş sınıfta bu fonksiyon tanımlanmak zorundadır.
      * "pure_virtual_function.cpp" dosyasını inceleyin
	abstract class,
		* bir sınıf en az 1 adet  saf sanal fonk. varsa o sınıf soyut sınıf olarak bilinir
	
		// An abstract class 
		class Test 
		{    
		    // Data members of class 
		public: 
		    // Pure Virtual Function 
		    virtual void show() = 0; 

		   // Other members ...

	abstract (soyut) class özellikleri - Interfaces
		1. En az bir saf sanal fonk. varsa, bu sınıf soyutdur.
		2. soyut sınıf tipinde pointer ve referanslar tanımlanabilir. ancak nesne değişken tanımlanamaz
		3. türeyen sınıfta temel sınıftaki fonk.nu aşırı yüklemezsek o halde türetilen sınıf da soyut olur
      * "pure_virtual_function.cpp" dosyasını inceleyin
		4. soyut sınıfın yapıcı fonksiyonları olabilir.
		
}; 	
	
*/
//--------------------------------------------------------------------------------------
/*
	virtual destractor
	
	
*/
/*  sanal yakıcı fonk. YOK
#include<iostream> 
  
using namespace std; 
  
class base { 
  public: 
    base()      
    { cout<<"Constructing base \n"; } 
    ~base() 
    { cout<<"Destructing base \n"; }      
}; 
  
class derived: public base { 
  public: 
    derived()      
    { cout<<"Constructing derived \n"; } 
    ~derived() 
    { cout<<"Destructing derived \n"; } 
}; 
  
int main(void) 
{ 
  derived *d = new derived();   
  base *b = d; 
  delete b;  
  return 0; 
} 
*/
/*  çıktı (derleyiciden derleyiciye fark edebilir)
Constructing base 
Constructing derived 
Destructing base 
*/

/*
// sanal yakıcı fonk. kullanılıyor
// türetilmiş sınıfın yıkıcı fonk. nun çağrılması garanti ediliyor
#include<iostream> 
  
using namespace std; 
  
class base { 
  public: 
    base()      
    { cout<<"Constructing base \n"; } 
    virtual ~base() 
    { cout<<"Destructing base \n"; }      
}; 
  
class derived: public base { 
  public: 
    derived()      
    { cout<<"Constructing derived \n"; } 
    ~derived() 
    { cout<<"Destructing derived \n"; } 
}; 
  
int main(void) 
{ 
  derived *d = new derived();   
  base *b = d; 
  delete b;  
  return 0; 
} 
*/
/*  çıktı
Constructing base 
Constructing derived 
Destructing derived 
Destructing base 
*/
