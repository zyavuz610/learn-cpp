#include <iostream>
using namespace std;

class Time{
  public:
    Time(int _hour=0,int _min=0):hour(_hour),min(_min){

    }
    void printTime(){
      cout<<hour<< ":"<<min;
    }
    void setTime(int _hour=0,int _min=0){
      this->hour  = _hour;
      this->min   = _min;
    }
    void getTime(int &_hour,int &_min){
      _hour = this->hour;
      _min  = this->min;
    }
  private:
    int hour;
    int min;
};

class Date{
  public:
  Date()
  {//default constructor
        month = 1;
        day = 1;
        year = 1900;
  }

  Date(int m, int d, int y)
  {//constructor that accepts parameters
        if(m >= 1 && m <= 12)//makes sure month is valid
              month = m;
        else
              month = 1;
        if(d >= 1 && d <= 31)//makes sure day is valid
              day = d;
        else
              day = 1;
        if(y >= 1900 && y <= 2030)//makes sure year is valid
              year = y;
        else
              year = 1900;
  }
  void setDate(int m, int d, int y)
  {//sets a valid date
        if(m >= 1 && m <= 12)
              month = m;
        else
              month = 1;
        if(d >= 1 && d <= 31)
              day = d;
        else
              day = 1;
        if(y >= 1900 && y <= 2030)
              year = y;
        else
              year = 1900;
  }

  void getDate(int& m, int& d, int& y)
  {//returns the month, day and year
        month = m;
        day = d;
        year = y;
  }

  void printDate()
  {//displays the month, day and year to the screen
        if(month < 10)
              cout << "0";
        cout << month << "/";
        if(day < 10)
              cout << "0";
        cout << day << "/";
        cout << year;
  }
  private:
      int month;
      int day;
      int year;
};

class Event{
  public:
    Event(string _eventName="Event 1",int _year=2019,int _month=11,int _day=19,int _hour=18,int _min=15):eventDate(_year,_month,_day),eventTime(_hour,_min),eventName(_eventName)
    
    {

      /*
      this->eventName = _eventName;
      Date _date(_year,_month,_day);
      this->eventDate = _date;
      Time _time(_hour,_min);
      this->eventTime = _time;
      */
      cout<<"Event constructor\n";
    }
    void printEvent(){
      cout<<eventName<<" (";
      eventDate.printDate();
      cout<<" ";
      eventTime.printTime();
      cout<<")"<<endl;
    }

  private:
    string eventName; // composition
    Time eventTime;   // composition
    Date eventDate;   // composition

};

int main() {
  Time t(10,32);
  t.printTime();
  
  t.setTime(16,45);
  t.printTime();

  int _hour=11,_min=22;
  cout << "Hello the time is "<<_hour<<":"<<_min<<"\n";
  t.getTime(_hour,_min);    // call by reference
  cout << "Hello the time is "<<_hour<<":"<<_min<<"\n";
  
  Event e;
  e.printEvent();
  Event e1[100];
}