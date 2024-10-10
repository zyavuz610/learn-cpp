/* *************************************************
   *Written by :  Nurullah Demirci
   *Department :  Computer Engineering <--> 2. Education
   *Number     :  244037
   *GSM        :  +90 531 356 0256
************************************************ */
#include <iostream>
using namespace std;

class Time{
  public:
    Time(int _h=0,int _m=0, int _s=0, int _h24=0):hour(_h),min(_m),sec(_s),hour24(_h24){
     // hour  = _h;
     // min   = _m;
     // sec   = _s;
    }
    void setTime(int _h=0,int _m=0, int _s=0){
      hour  = _h;
      min   = _m;
      sec   = _s;
    }
    void getTime(int &_h,int &_m, int &_s, int &_h24){
      _h    = hour;
      _m    = min;
      _s    = sec;
      _h24  = hour24;
    }
    Time operator+(int _t){ //Operator Overloading
        int _h;
        this->min = this->min + _t;
        if(this->min > 59){
            _h = this->min / 60;
            this->min = this->min % 60;
            this->hour   = this->hour + _h;
        }
        if(this->hour > 23){
            this->hour24 = this->hour / 24;
            this->hour = this->hour % 24;
        }
        return Time(hour, min, sec, hour24); 
    }
    void printTime(){
      cout<<hour<<":"<<min<<":"<<sec;
    }
  private:
    int hour;
    int min;
    int sec;
    int hour24;
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
    void getDate(int &_y,int &_m, int &_d){
      _y = year;
      _m = month;
      _d = day;
    }
    Date operator+(int _d){ //Operator Overloading
        int _year;
        int _month;
        int totalDay = 0;
        int FormatMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        this->day = this->day + _d;
        for(int i = 1; i < this->month; i++){
            totalDay += FormatMonth[i];
        }
        totalDay += this->day;
        if(totalDay > 365){ 
            this->year += totalDay / 365;
            totalDay = totalDay % 365;
            if(totalDay == 0){
                this->year -= 1;
                totalDay = 365;
            }
        }
        if(totalDay <= 365){
            for(int i = 1; i <= 12; i++){
                if(totalDay <= FormatMonth[i]){ this->month += 1; break; }
                else{
                    this->month = i;
                    totalDay -= FormatMonth[i];
                } 
            }
        }
        this->day = totalDay;
        return Date(year, month, day); 
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
    void setDate(Date& d, Time& t){ //Fonksiyona nesne göndererek composition ile diğer classlardan get ile veri çekme
        t.getTime(saat, dakika, saniye, saat24);
        d.getDate(yil, ay, gun);
        if(saat24 > 0){
            gun = gun + saat24;
            if(gun > 30){
                ay = ay + (gun / 30);
                gun = gun % 30;
                if(ay > 12){
                    yil = yil + (ay / 12);
                    ay = ay % 12;
                }
            }
        }
    }
    void printEvent(){ //Ekrana Yazdırma
        cout << "\e[3m" << eventName << " (";
        if(gun > 9) cout << gun << ".";
        else        cout << "0" << gun << ".";
        if(ay > 9)  cout << ay << ".";
        else        cout << "0" << ay << ".";
                    cout << yil << " ";
                    
        if(saat > 9)    cout << saat << ":";
        else            cout << "0" << saat << ":";
        if(dakika > 9)  cout << dakika << ":";
        else            cout << "0" << dakika << ":";
        if(saniye > 9)  cout << saniye;
        else            cout << "0" << saniye;
      cout<<")" << "\e[0m" << "\n";
    }
  private:
    string eventName;   // composition
    Time eventTime;     // composition
    Date eventDate;     // composition
    int yil, ay, gun, saat, dakika, saniye, saat24; //Get İle Alınan Veriler
};

int main() {
  Time t(8,49,10);
  t = t + 20;   // saate 20 dk. ekle
  Date d(2019,2,25);
  d = d + 5;    // tarihe 5 gün ekle
  Event e("Kodlama Atölyesi");
  e.setDate(d,t);
  e.printEvent(); 
  /*
  Ekran:
  Kodlama Atölyesi (02.03.2019 09:09:10)
  */ 
}
