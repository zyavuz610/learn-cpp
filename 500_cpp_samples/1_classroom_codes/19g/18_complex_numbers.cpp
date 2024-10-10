#include <iostream>
using namespace std;

class mycomplex {
  private:
  int real;
  int imag;
  public:
  mycomplex();
  mycomplex(int,int);
  void setImag(int);
  void setReal(int);
  int getReal();
  int getImage();
  void print();
  mycomplex operator +(const mycomplex&);
  mycomplex operator -(const mycomplex&);
  mycomplex operator *(int);  
};

int main() {
  mycomplex c1(3,5),c2,c3;  // c2 = c3 = 0 + 0i
                            // c1 = 3 + 5i
  c2.setReal(2);
  c2.setImag(3);            // c2 = 2 + 3i
  c3 = c1 + c2;
  c3.print();               // c3 = 5 + 8i
  c3 = c1 - c2;
  c3.print();               // c3 = 1 + 2i
  c3 = c1 - c2*2;
  c3.print();               // c3 = -1 - i
  c2.setReal(3);            // c2 = 3 + 3i
  c3 = c1 - c2;             // c3 = 2i
  c3.print();               
  cout<<"Real:"<<c3.getReal()<<", Imag:"<<c3.getImage()<<endl;
                            // Real:0, Image:2
}

mycomplex::mycomplex() : real(0),imag(0) { }

mycomplex::mycomplex(int real, int imag)
{
  this->real = real;
  this->imag = imag;
}
void mycomplex::setImag(int imag){this->imag = imag;}
void mycomplex::setReal(int real) {this->real = real;}

int mycomplex::getReal() { return real; }
int mycomplex::getImage() { return imag; }

void mycomplex::print()
{
	if(real==0)
	{
		cout<<imag<<"i"<<endl;
	}
	if(imag==0)
	{
		cout<<real<<endl;
	}
	if(imag==1)
	{
		cout<<real<<" + i"<<endl;
	}
	if(imag==-1)
	{
		cout<<real<<" - i"<<endl;
	}
	if(real!=0 && imag>1)
	{
		cout<<real<<" + "<<imag<<"i"<<endl;
	}
	if(real!=0 && imag<-1)
	{
		cout<<real<<" - "<<-imag<<"i"<<endl;
	}

}

mycomplex mycomplex:: operator +(const mycomplex& m)
	{
		mycomplex temp;
		temp.real = this->real + m.real;
		temp.imag = this->imag + m.imag;
		
		return temp;
	}
	
mycomplex mycomplex:: operator -(const mycomplex& m)
	{
		mycomplex temp;
		temp.real = this->real - m.real;
		temp.imag = this->imag - m.imag;
		
		return temp;
	}

mycomplex mycomplex:: operator *(int m)
{
	mycomplex temp;
	temp.real = this->real * m;
	temp.imag = this->imag * m;
	
	return temp;
}