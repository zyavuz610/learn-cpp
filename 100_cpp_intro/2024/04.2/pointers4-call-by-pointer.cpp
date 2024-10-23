#include <iostream>
using namespace std;

void takas1(float f1,float f2){
    float temp = f1;
    f1 = f2;
    f2 = f1;
}
void takas2(float *f1,float *f2){
    float temp = *f1;
    *f1 = *f2;
    *f2 = temp;
}
int main(){
    float f1 = 15.0,f2=20.0;
    cout<<"Takas Oncesi:"<<f1<<","<<f2<<endl;    
    // takas1(f1,f2); // call by value
    takas2(&f1,&f2); // call by pointer
    cout<<"Takas Sonrasi:"<<f1<<","<<f2<<endl;    
    return 0;
}