#include <iostream>
using namespace std;

class Kutu {
    public:
        void getValues(){
            cout<<"3 deger giriniz:";
            cin>>en>>boy>>yuk;
        }
        double VolumeCalculation(){
            volume = en*boy*yuk;
            return volume;
        }
        void printData(){
            cout<<"Hacim:"<<volume;
        }
    private:
        double en;
        double boy;
        double yuk;
        double volume;
};

int main(){
    Kutu k1,k2;
    k1.getValues();
    //k2.getValues();
    k1.VolumeCalculation();
    k1.printData();
    return 0;
}