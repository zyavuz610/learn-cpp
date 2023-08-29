#include<iostream>
using namespace std;
class Vehicle{
 protected:
   string name;
 public:
   Vehicle(string _name="Vehicle A");
   virtual double getTax()=0;
   string getName();
};
 
class Diesel : public Vehicle{
   double motorCC;
 public:
   Diesel(string _name="TOFAŞ SLX",double _motorCC=1600);
   virtual double getTax();
};
 
class Electric : public Vehicle{
   double range;
 public:
   Electric(string _name="TOGG A",double _range=500);
   virtual double getTax();
};
//-----------------------------------------------------------------
Vehicle::Vehicle(string _name){
 this->name = _name;
}
string Vehicle::getName(){
 return name;
}
Diesel::Diesel(string _name, double _motorCC):Vehicle(_name){
 this->motorCC = _motorCC;
}
Electric::Electric(string _name,double _range):Vehicle(_name){
 this->range = _range;
}
//----------------------------------------------------------------
double Diesel::getTax(){
 return 500 + (motorCC - 1300)*20;
}
double Electric::getTax(){
 return 300 + (range-200)*10;
}
void findMaximumTax(Vehicle *ptr[],int n){
 double max = -10;
 int maxi = 0;
 for(int i=0;i<n;i++){
   if(ptr[i]->getTax() > max){
     max = ptr[i]->getTax();
     maxi = i;
   }
 }
 cout<<"Maximum Tax: ";
 cout<<ptr[maxi]->getName()<<" - "<<ptr[maxi]->getTax()<<endl;
}
//-----------------------------------------------------------------
int main(){
   Diesel d1,d2("Ford Ka",1300);
   Electric e1,e2("Tesla Model 3",400);
   Vehicle *vptr[5];
   vptr[0] = &d1;  vptr[1] = &d2;
   vptr[2] = &e1;  vptr[3] = &e2;
   findMaximumTax(vptr,4);
   return 0;
}
