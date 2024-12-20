#include <iostream> // for cout
using namespace std;

template <class T>
class Stack {
private:
    T* elems;        // dynamic array
    size_t capacity; // size of the allocated array
    size_t count;    // number of elements in the stack

public:
    Stack() : elems(nullptr), capacity(0), count(0) {}

    ~Stack() {
        delete[] elems;
    }

    void push(T const& elem) {
        if (count == capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newElems = new T[newCapacity];
            for (size_t i = 0; i < count; ++i) {
                newElems[i] = elems[i];
            }
            delete[] elems;
            elems = newElems;
            capacity = newCapacity;
        }
        elems[count++] = elem;
    }

    void pop() {
        if (empty()) {
            cout << "Error: Stack<>::pop(): empty stack" << std::endl;
            return;
        }
        --count;
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
    Stack<int> s;
    
    s.pop(); // Error: Stack<>::pop(): empty stack
    cout << s.top() << std::endl; // Error: Stack<>::top(): empty stack

    s.push(10);
    s.push(20);
    cout << s.top() << std::endl; // 20
    s.pop();
    cout << s.top() << std::endl; // 10

    return 0;
}