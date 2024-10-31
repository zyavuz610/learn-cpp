#include <iostream>
using namespace std;

void getValues(double &a, double &b, double &c){
    cout<<"3 deger giriniz:";
    cin>>a>>b>>c;
}
double volumeCalculation(double a,double b, double c){
    return a*b*c;
}
void printData(double vol){
    cout<<"Hacim:"<<vol<<endl;
}

int main(){
    double en,boy,yuk;
    getValues(en,boy,yuk); //cbr
    en = 100;
    double volume = volumeCalculation(en,boy,yuk);
    printData(volume);
    double en2,boy2,yuk2;
    getValues(en,boy,yuk); //cbr
    double volume2 = volumeCalculation(en2,boy2,yuk2);
    printData(volume2);
    return 0;
}