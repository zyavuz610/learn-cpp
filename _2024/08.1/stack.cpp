#include "stack.h"
#include <iostream>
#define MAX_SIZE 100
using namespace std;

Stack::Stack(){
    top=-1;
    capacity = MAX_SIZE;
    arr = new int[capacity];
    //cout<<"ctor calisti"<<endl;
}

Stack::Stack(int cap_){
    top=-1;
    capacity = cap_;
    arr = new int[capacity];
    //cout<<"ctor2 calisti"<<endl;
}

Stack::Stack(const Stack &other){
    top = other.top;
    capacity = other.capacity;
    arr = new int[capacity];
    for(int i=0;i<=top;i++){
        arr[i] = other.arr[i];
    }
    //cout<<"copy ctor calisti"<<endl;
}

void Stack::push(int elm){
    if(!isFull()){
        arr[++top] = elm;
    }
}

int Stack::pop(){
    if(!isEmpty()){
        return arr[top--];
    }
    return -1;
}

int Stack::peek(){ 
    if(!isEmpty()){
        return arr[top];
    }
    return -1;
}

bool Stack::isEmpty(){
    return (top==-1);
}
bool Stack::isFull(){
    return (top==capacity-1);
}
void Stack::print(){
    if (isEmpty()){
        cout<<"stack bos"<<endl;
        return;
    }
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<", ";
    }
    cout<<"\n";
}
Stack::~Stack(){
    //cout<<"dstor calisti"<<endl;
    ;
}