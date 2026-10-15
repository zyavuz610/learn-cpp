#include <iostream>
#include <cctype> // isdigit()
#include <iomanip> // setprecition()

using namespace std;


int main(){
  float exam1,exam2; 
  string name;
  cout << "Name:";
  getline(cin,name);

  cout<< "Grades <exam1 exam2>:"<<endl;
  char ch, err='N';
  
  do{
    cout << "Exam1:";
    cin.get(ch);
    if(isdigit(ch)){
      cin.putback(ch);
      cin >> exam1;
      err = 'N';
    }
    else{
      cout << "Non-digit input for exam1, please enter a number!!"<<endl;
      err = 'Y';
      cin.ignore(100,'\n');
    }
  }while (err == 'Y');
  cin.ignore(100,'\n');

  
  do{
    cout << "Exam2:";
    cin.get(ch);
    if(isdigit(ch)){
      cin.putback(ch);
      cin >> exam2;
      err = 'N';
    }
    else{
      cout << "Non-digit input for exam2, please enter a number!!"<<endl;
      cin.ignore(100,'\n');
      err = 'Y';
    }
  }while (err == 'Y');

   
  cout << "Variable name: "<<name <<endl;
  cout << "Variable exam1: "<<exam1 <<endl;
  cout << "Variable exam2: "<<exam2 <<endl;

  cout << left  << setw(10) << "AD"
       << right << setw(10) << "AVG"
       << setw(12) << "RESULT"<<endl;
  
  cout.fill('='); 
  cout << setw(32) << "" << endl;
  // for python: print("="*32)
  
  cout << name << ":"
       << fixed 
       << setprecision(6)
       << (exam1 + exam2)/2
       << endl;
  string s="https://codeshare.io/5Npk9V";
  return 0;
    
}