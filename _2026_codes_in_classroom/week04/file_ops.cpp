#include <iostream>
#include <fstream>

using namespace std;

void readFromCin(){
  string name;
  cout<<"Name:";
  getline(cin,name);
  cout<<name<<endl;
}

void readFromFile(){
  ifstream inFile("input.txt");
  string name;
  getline(inFile,name);

  ofstream outFile("output.txt",ios::app);
  outFile<<name<<endl;
}

int main(){
  //readFromCin();
  readFromFile();
  return 0;  
}