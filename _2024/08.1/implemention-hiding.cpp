#include <iostream>
#include "stack.h"
#define MAX_SIZE 100
using namespace std;

int main(){
    Stack s1(20),s2;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<"s1----------------"<<endl;
    s1.print();
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.pop();
    cout<<"s2----------------"<<endl;
    s2.print();
    Stack s3 = s1; // s3 nesnesi içindeki copy constructor .çağrılır, bu metoda s1 nesnesi parametre olarak gönderilir, s3.Stack(s1);
    s3.pop();
    s3.push(40);
    s3.push(50);
    cout<<"s3----------------"<<endl;
    s3.print();
    cout<<"s1----------------"<<endl;
    s1.print();
    cout<<"----------------"<<endl;
    return 0;
}


