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
            cout<<"("<<en<<",";
            cout<<boy<<","<<yuk<<") ==> ";
            cout<<volume<<endl;
        }
        void all_in_one(){
            getValues();
            VolumeCalculation();
            printData();
        }
        double en;
    private:
        double boy;
        double yuk;
        double volume;
};

int main(){
    Kutu k1,k2;
    //k1.getValues();
    //k2.getValues();
    //k1.VolumeCalculation();
    //k1.printData();
    k1.all_in_one();
    k2.all_in_one();
    k1.en = 20;
    return 0;
}