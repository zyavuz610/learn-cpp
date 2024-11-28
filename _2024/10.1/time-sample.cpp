#include <iostream>
using namespace std;

class Time{
    private:
        int hour;
        int min;
        int sec;
    public:
        Time(){
            this->hour = 0;
            this->min = 0;
            this->sec = 0;
        }
        Time(int hr, int mn=0, int sc=0){
            this->hour = hr;
            this->min = mn;
            this->sec = sc;
        }
        void print(){
            if(this->hour<10) cout<<"0";
            cout<<this->hour<<":";
            if(this->min<10) cout<<"0";
            cout<<this->min<<":";
            if(this->sec<10) cout<<"0";
            cout<<this->sec<<"\n";
        }
        void add(const Time& rhs){
            this->sec += rhs.sec;
            if(this->sec>60){
                this->min += 1;
                this->sec %= 60;
            }

            this->min += rhs.min;
            if (this->min > 60) {
                this->hour += 1;
                this->min %= 60;
            }
            this->hour += rhs.hour;
            if(this->hour >= 24){
                this->hour %= 24;
            }            
        }
};

int main(){
    Time t,t2(12),t3(12,44),t4(1,2,3);
    t.print();
    t2.print();
    t3.print();
    t4.print();
    t.add(t3);
    t.print();
    return 0;
}