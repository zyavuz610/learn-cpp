/*
Person
- name, surname, birth_day
+ print()
    Student
        - student_id
        + print() -> öğrenci no ile birlikte yazsın
    Lecturer
        - title 
        + print() -> title ile birlikte yazsın

Person *p[3];
Person p1("Ali", "Demir", "2000.12.14");
Student s1("Büşra","Aydın", "2000.12.14", "123456");
Lecturer l1("Enes","Özdemir", "2000.12.14" ,"Prof.Dr.");
p[0] = &p1;  p[1] = &s1;  p[2] = &l1;
for(int i=0;i<3;i++){
    p[i]->print();
}
*/
//--------------------------------------------------------------
#include <iostream>
using namespace std;
//----------------------------------------------
// Person.h
class Person{
  public:
    Person(string _name="Name", string _surname="Surname", string _birth_day="01.01.1970");
    void setPerson(string _name, string _surname, string _birth_day);
    virtual void print();
  protected:
    string name;
    string surname;
    string birth_day;
  private:

};
//----------------------------------------------
// Person.cpp
Person::Person(string _name, string _surname, string _birth_day){
  setPerson(_name,_surname,_birth_day);
}
void Person::setPerson(string _name, string _surname, string _birth_day){
  name      = _name;
  surname   = _surname;
  birth_day = _birth_day;
}
void Person::print(){
  cout  <<  name    <<  " "
        <<  surname <<  " ("
        <<  birth_day << ")"  << endl;
}
//----------------------------------------------
// Student.h
class Student : public Person{
  public:
    Student(string _name="Name", string _surname="Surname", string _birth_day="01.01.1970",string _student_id="100000");
    void print();
  protected:
    string student_id;
    // name, surname, birth_day

  private:

};
//----------------------------------------------
// Student.cpp
Student::Student(string _name, string _surname, string _birth_day,string _student_id):Person(_name,_surname,_birth_day){
  student_id = _student_id;
}
void Student::print(){
  cout  <<  student_id  << " "
        <<  name        <<  " "
        <<  surname     <<  " ("
        <<  birth_day   << ")"  << endl;
}
//----------------------------------------------
// Lecturer.h
class Lecturer : public Person {
  public:
    Lecturer(string _name="Name", string _surname="Surname", string _birth_day="01.01.1970",string _title="Öğr. Gör.");
    void print();
  protected:
    string title;
    // name, surname, birth_day
};
//----------------------------------------------
// Lecturer.cpp
Lecturer::Lecturer(string _name, string _surname, string _birth_day,string _title):Person(_name,_surname,_birth_day){
  title = _title;
}
void Lecturer::print(){
  cout  <<  title       << " "
        <<  name        <<  " "
        <<  surname     <<  " ("
        <<  birth_day   << ")"  << endl;
}
//----------------------------------------------

int main() {
  Person *p[3];
  Person p1("Ali", "Demir", "2000.12.14");
  Student s1("Büşra","Aydın", "2000.12.14", "123456");
  Lecturer l1("Enes","Özdemir", "2000.12.14" ,"Prof.Dr.");
  p[0] = &p1;  p[1] = &s1;  p[2] = &l1;
  for(int i=0;i<3;i++){
      p[i]->print();
  }
}