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
        void set_en(double en_) { en = en_;}
        void set_boy(double boy_) { boy = boy_;}
        void set_yuk(double yuk_) { yuk = yuk_;}
        double get_en() {return en;}
        double get_boy() {return boy;}
        double get_yuk() {return yuk;}
        double get_volume() {return volume;}
    private:
        double en;
        double boy;
        double yuk;
        double volume;
};

int main(){
    Kutu k1,k2;
    k1.set_en(10);   // k1.en = 10;  HATA!
    k1.set_boy(20);
    k1.set_yuk(35);
    k1.VolumeCalculation();
    cout<<"Hacim:"<<k1.get_volume()<<endl;
    return 0;
}