#include <iostream>
using namespace std;

void takas1(float f1,float f2){
    float temp = f1;
    f1 = f2;
    f2 = f1;
}
int main(){
    float f1 = 15.0,f2=20.0;
    cout<<"Takas Öncesi:"<<f1<<","<<f2<<endl;    
    takas1(f1,f2); // call by value
    cout<<"Takas Sonrası:"<<f1<<","<<f2<<endl;    
    return 0;
}