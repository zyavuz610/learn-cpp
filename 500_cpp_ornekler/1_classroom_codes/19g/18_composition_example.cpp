#include <iostream>
using namespace std;

class Time{
  public:
    Time(int _h=0,int _m=0, int _s=0):hour(_h),min(_m),sec(_s){
     // hour  = _h;
     // min   = _m;
     // sec   = _s;
    }
    void setTime(int _h=0,int _m=0, int _s=0){
      hour  = _h;
      min   = _m;
      sec   = _s;
    }
    void getTime(int &_h,int &_m, int _s){
      _h = hour;
      _m = min;
      _s = sec;
    }
    void printTime(){
      cout<<hour<<":"<<min<<":"<<sec;
    }
  private:
    int hour;
    int min;
    int sec;
};

class Date{
  public:
    Date(int _y=0,int _m=0, int _d=0){
      year  = _y;
      month = _m;
      day   = _d;
    }
    void setDate(int _y=0,int _m=0, int _d=0){
      year  = _y;
      month = _m;
      day   = _d;
    }
    void getDate(int &_y,int &_m, int _d){
      _y = year;
      _m = month;
      _d = day;
    }
    void printDate(){
      cout<<day<<"."<<month<<"."<<year;
    }
  private:
    int year;
    int month;
    int day;
};

class Event{
  public:
    Event(string _eventName="Event 1",int _year=2000,int _month=11,int _day=14,int _hour=12,int _min=32,int _sec=15):eventName(_eventName),eventTime(_hour,_min,_sec),eventDate(_year,_month,_day){

     // eventName = _eventName;
     // eventTime.setTime(_hour,_min,_sec);
     // eventDate.setDate(_year,_month,_day);

      /*

      eventName = _eventName;
      Time t(_hour,_min,_sec);
      eventTime = t;
      Date d(_year,_month,_day);
      eventDate = d;

      */
    }
    void setEvent(string _eventName="Event 1",int _year=2000,int _month=11,int _day=14,int _hour=12,int _min=32,int _sec=15){
     eventName = _eventName;
     eventTime.setTime(_hour,_min,_sec);
     eventDate.setDate(_year,_month,_day); 
    }
    void printEvent(){
      cout<<eventName<<" (";
      eventDate.printDate();
      cout<<" ";
      eventTime.printTime();
      cout<<")\n";
    }
  private:
    string eventName;   // composition
    Time eventTime;     // composition
    Date eventDate;     // composition
};

int main() {
  Time t(10,20,30);
  t.printTime();
  int h=5,m=5,s=5;
  cout<<"\nSaat="<<h<<":"<<m<<":"<<s<<endl;
  t.getTime(h,m,s);   // call by reference
  cout<<"Saat="<<h<<":"<<m<<":"<<s<<endl;
  
  Date d(1071,20,30);
  d.printDate();
  int y=1905,mn=5,dy=5;
  cout<<"\nTarih="<<y<<":"<<mn<<":"<<dy<<endl;
  d.getDate(y,mn,dy);   // call by reference
  cout<<"Tarih="<<y<<":"<<mn<<":"<<dy<<endl;

  Event e[100];
  e[0].printEvent();
  e[1].setEvent("Kodlama Atölyesi");
  e[1].printEvent();
}