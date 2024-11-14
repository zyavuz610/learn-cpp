#include <iostream>
using namespace std;

class Counter{
private:
    int counter;
public:
    Counter(){
        this->counter = 0;
    }
    Counter(int counter_){
        this->counter = counter_;
    }
    void setCounter(int counter){
        this->counter = counter;
    }
    void increment(){this->counter++;}
    int getCounter(){return this->counter;}
    friend void printCounter(Counter c);
};

void printCounter(Counter c){
    cout<<"Counter is "<<c.getCounter()<<endl;
    cout<<"Counter is "<<c.counter<<endl;
}

void menu(){
    cout<<"------------------------"<<endl;
    cout<<"1. Kredi icin sira al"<<endl;
    cout<<"2. Fatura icin sira al"<<endl;
    cout<<"3. Kredi sira durumu"<<endl;
    cout<<"4. Fatura sira durumu"<<endl;
    cout<<"cikmak icin 0"<<endl;
    cout<<"Secim: ";
}

int main(){
    Counter fatura(100),kredi(400);
    int secim,durum=1;
    while(durum){
        menu();
        cin>>secim;
        switch(secim){
            case 0:
                durum = 0;
                break;
            case 1:
                kredi.increment();
                break;
            case 2:
                fatura.increment();
                break;
            case 3:
                printCounter(kredi);
                break;
            case 4:
                printCounter(fatura);
                break;
            default:
                durum = 0;
                break;
        }
    }
    cout<<"Bye.."<<endl;
    return 0;
}