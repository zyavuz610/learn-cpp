#include <iostream>

using namespace std;

class Time {
  public:
    void setHour(int h){
      hour = h;
    }
    void setMin(int m){
      min = m;
    }
    int getHour(){
      return hour;
    }
    int getMin(){
      return min;
    }
    void setAmPm(string a){
      ampm = a;
    }
    void setType(string t){
      type = t;
    }
    string getAmPm(){
      return ampm;
    }
    string getType(){
      return type;
    }
    void print(){
      if (hour>=12) ampm = "PM";
      else ampm = "AM";
      cout<<"Time is: ";
      if(type=="12"){
        cout<<hour%12<<":"
            <<min << " " 
            << ampm<<endl;
      }
      else{
        cout<<hour<<
          
          ":"
            <<min <<endl;        
      }
    }
  private:
    int hour;
    int min;
    int sec;
    string type; // 12, 24
    string ampm;
}; 

int main(){
  Time t1, t2;
  t1.setHour(12);
  t1.setMin(34);
  t1.setType("24");
  t2.setHour(22);
  t2.setMin(45);
  t2.setType("12");

  t1.print();
  t2.print(); // 10:45 PM
  "https://codeshare.io/5XE7JE";
  return 0;
}