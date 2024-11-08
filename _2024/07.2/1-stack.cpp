/*
veri yaplarında çokça kullanılan bir yığın class ı yazalım,
yığın veri yapısı LIFO (Last In First Out) mantığına göre çalışır.

max kapasite 100 olup, push, pop, peek, isEmpty, isFull fonksiyonlarını içermelidir.
peek fonksiyonu yığının en üstündeki elemanı döner. yığın eleman sayısı değişmez
pop fonksiyonu yığının en üstündeki elemanı döner ve yığından çıkarır.
...

*/

#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Stack {
    private:
        int arr[MAX_SIZE];
        int top;
    public:
        Stack(){
            top=-1;
            cout<<"ctor calisti"<<endl;
        }
        void push(int elm){
            arr[++top] = elm;
        }
        int pop(){
            return arr[top--];
        }
        int peek(){ 
            return arr[top];
        }
        bool isEmpty(){
            return (top==-1);
        }
        bool isFull(){
            return (top==MAX_SIZE-1);
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
    Stack s1;
    return 0;
}