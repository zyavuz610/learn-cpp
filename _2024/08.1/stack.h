#ifndef STACK_H // include komutu ile birden fazla include edilmesini engeller
#define STACK_H

class Stack {
    private:
        int* arr;
        int top;
        int capacity;
    public:
        Stack();
        Stack(int cap_);
        Stack(const Stack &other);
        void push(int elm);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
        void print();
        ~Stack();
};

#endif // STACK_H