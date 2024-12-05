#include <iostream>
using namespace std;
 
class Time {
   private:
      int hours;             // 0 to 23
      int minutes;           // 0 to 59
      
   public:
      // required constructors
      Time() {
         hours = 0;
         minutes = 0;
      }
      Time(int h, int m) {
         hours = h;
         minutes = m;
      }
      
      // method to display time
      void displayTime() {
         cout << "H: " << hours << " M:" << minutes <<endl;
      }
      friend ostream& operator<<(ostream& output, const Time& T){
        if (T.hours < 10){
            output << "0";
        }
        output << T.hours << ":";
        if(T.minutes < 10){
            output << "0";
        }
        output << T.minutes <<endl;
        return output;
      }
      // overloaded prefix ++ operator, ++t
      Time operator++ () {
         ++minutes;          // increment this object
         if(minutes >= 60) {
            ++hours;
            minutes -= 60;
         }
         return Time(hours, minutes);
      }
      
      // overloaded postfix ++ operator
      // t++;
      Time operator++( int ) {
      
         // save the orignal value
         Time T(hours, minutes);
         
         // increment this object
         ++minutes;                    
         
         if(minutes >= 60) {
            ++hours;
            minutes -= 60;
         }
         // return old original value
         return T; 
      }
      bool operator<(Time T){
          if(hours < T.hours){
              return true;
          }
          else if(hours == T.hours){
              if(minutes < T.minutes){
                  return true;
              }
          }
          return false;
      }
};

int main() {
   Time T1(9, 59), T2(10,40);
 
   ++T1;                    // increment T1
   T1.displayTime();        // display T1
   cout<<T1;
   cout<<++T1;                    // increment T1 again
   //T1.displayTime();        // display T1
 
   cout<<T2++;                    // increment T2
   T2.displayTime();        // display T2
   cout<<T2++;                    // increment T2 again
   T2.displayTime();        // display T2

   if(T1<T2){
        cout << "T1 is less than T2" << endl;
   }
   else{
        cout << "T1 is greater than T2" << endl;
   }
   return 0;
}