/*
veri yaplarında çokça kullanılan bir yığın class ı yazalım,
yığın veri yapısı LIFO (Last In First Out) mantığına göre çalışır.

max kapasite 100 olup, push, pop, peek, isEmpty, isFull fonksiyonlarını içermelidir.
peek fonksiyonu yığının en üstündeki elemanı döner. yığın eleman sayısı değişmez
pop fonksiyonu yığının en üstündeki elemanı döner ve yığından çıkarır.
...


stack dizisi dinamik olsun.

*/

#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Stack {
    private:
        int* arr;
        int top;
        int capacity;
    public:
        Stack(){
            top=-1;
            capacity = MAX_SIZE;
            arr = new int[capacity];
            cout<<"ctor calisti"<<endl;
        }
        Stack(int cap_){
            top=-1;
            capacity = cap_;
            arr = new int[capacity];
            cout<<"ctor2 calisti"<<endl;
        }
        void push(int elm){
            if(!isFull()){
                arr[++top] = elm;
            }
        }
        int pop(){
            if(!isEmpty()){
                return arr[top--];
            }
        }
        int peek(){ 
            if(!isEmpty()){
                return arr[top];
            }
        }
        bool isEmpty(){
            return (top==-1);
        }
        bool isFull(){
            return (top==capacity-1);
        }
        void print(){
            if (isEmpty()){
                cout<<"stack bos"<<endl;
                return;
            }
            for(int i=0;i<=top;i++){
                cout<<arr[i]<<", ";
            }
            cout<<"\n";
        }
};

int main(){
    Stack s1(20),s2;
    return 0;
}