#include <iostream> // for cout
using namespace std;

template <class T>
class Stack {
private:
    T* elems;        // dynamic array
    int capacity; // size of the allocated array
    int count;    // number of elements in the stack

public:
    Stack() : capacity(10), count(0) {
        elems = new T[10];
    }
    Stack(int cap) : capacity(cap), count(0) {
        elems = new T[capacity];
    }

    ~Stack() {
        delete[] elems;
    }

    void push(T const& elem) {
        if (count == capacity) {
            cout<<",capacity is full"<<endl;
            return;
        }
        elems[count++] = elem;
    }

    T pop() {
        if (empty()) {
            cout << "Error: Stack<>::pop(): empty stack" << std::endl;
            return 0; // Default-constructed T
        }
        return --count;
    }

    T top() {
        if (empty()) {
            cout << "Error: Stack<>::top(): empty stack" << std::endl;
            return T(); // Default-constructed T
        }
        return elems[count - 1];
    }

    bool empty() {
        return count == 0;
    }
};


int main() {
    Stack<int> s(30);
    
    //s.pop(); // Error: Stack<>::pop(): empty stack
    //cout << s.top() << std::endl; // Error: Stack<>::top(): empty stack

    s.push(10);
    s.push(20);
    cout << s.top() << std::endl; // 20
    s.pop();
    cout << s.top() << std::endl; // 10

    return 0;
}