#include <iostream>
using namespace std;

class Zaman {
    public:
        void setTime(int h,int m,int s){
            saat = h;
            dakika = m;
            saniye = s;
        }
        void print(){
            cout<<saat<<":"<<dakika<<":"<<saniye<<endl;
        }
        void incrementSecond(int n){
            saniye += n;
            if(saniye >= 60){
                dakika++;
                saniye %= 60;
            }
        }
    private:
        int saat;
        int dakika;
        int saniye;
};

int main(){
    Zaman t1;
    t1.setTime(10,20,33);
    cout<<"Önce: ";
    t1.print();
    t1.incrementSecond(130);
    cout<<"Sonra: ";
    t1.print();
    return 0;
}