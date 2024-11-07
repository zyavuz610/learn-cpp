#include <iostream>
using namespace std;

class Student{
public:
    Student();
    Student(string, float, float, string);
private:
    string name;
    string course;
    float mid_point;
    float final_point;
    float gpa;
};

int main(){
    Student s1;
    return;
}
//---------------------------------------------------
Student::Student(){
    name = "Elif";
}
Student::Student(string name_,float mid_=0, float final_=0, string course_="Deneme"){
    name = name_;
    mid_point = mid_;
    final_point = final_;
    course = course_;
}
/*
print(); // tüm liste ekrana
print("a.txt"); // tüm liste dosyaya
print("a.txt",0); // kalanlar dosyaya
print(1); // geçenler ekrana
*/