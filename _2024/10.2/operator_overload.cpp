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
        Time operator+(const Time& rhs){
            Time ret;
            ret.sec = this->sec + rhs.sec;
            if(ret.sec>60){
                ret.min += 1;
                ret.sec %= 60;
            }
            ret.min += this->min + rhs.min;
            if (ret.min > 60) {
                ret.hour += 1;
                ret.min %= 60;
            }
            ret.hour += this->hour + rhs.hour;
            if(ret.hour >= 24){
                ret.hour %= 24;
            } 
            return ret;          

        }
        bool operator<(const Time &rhs){
            return (this->hour < rhs.hour);
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
    Time t,t2(11),t3(12,44),t4(1,2,3);
    t.print();
    t2.print();
    t3.print();
    t4.print();
    t4 =  t4 + t3; //  t.add(t3);
    t.print();
    t4.print();
    cout<<"--------------\n";
    t2.print();
    t3.print();
    if (t2<t3){ // t2.operator<(t3)
        cout<<"t2 daha once gelir\n";
    }
    else{
        cout<<"t3 daha once\n";
    }
    return 0;
}