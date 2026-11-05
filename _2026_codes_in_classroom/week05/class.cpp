#include <iostream>

using namespace std;

class Time {
  public:
    Time(){
      cout<<"cstor is working\n";
      hour = 10;
      min = 05;
      sec = 0;
      type = 12;
      ampm = "PM";
    }
    Time(int h, int m, int s, string type){
      cout<<"parametrized cstor is working\n";
      this->hour = h;
      this->min = m;
      this->sec = s;
      this->type = type;      
    }
    ~Time(){
      cout<<"dstor is working\n";
    }
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
  cout<<"before t1 and t2 declaration\n";
  Time t1, t2;
  cout<<"after t1 and t2 declaration\n";
  /*
  t1.setHour(12);
  t1.setMin(34);
  t1.setType("24");
  t2.setHour(22);
  t2.setMin(45);
  t2.setType("12");
*/
  t1.print();
  t2.print(); // 10:45 PM
  
  cout<<"before t3 declaration\n";
  Time *t3 = new Time();
  cout<<"after t3 declaration\n";
  t3->print();

  cout<<"before t4 declaration\n";
  Time *t4;
  cout<<"after t4 declaration\n";

  
  cout<<"before t4 allocation\n";
  t4 = new Time(12,34,45,"12");
  cout<<"after t4 allocation\n";
  t4->print();
  
  "https://codeshare.io/5XE7JE";
  return 0;
}