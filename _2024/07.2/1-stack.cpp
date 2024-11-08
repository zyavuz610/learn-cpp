#include <iostream>
#define DEFAULT_SIZE 10
using namespace std;

class Stack {
private:
    int* arr;        // Dinamik dizi pointerı
    int top;         // Dizinin üst elemanını takip etmek için indeks
    int capacity;    // Dizi kapasitesi

public:
    Stack() { 
        arr = new int[DEFAULT_SIZE];  // Kapasitesi 10 olan bir dizi oluşturduk
        capacity = DEFAULT_SIZE;
        top = -1;   // İlk başta stack boş olduğu için -1
    }
    // Yapıcı: kapasiteyi parametre olarak alır ve diziyi oluşturur
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;   // İlk başta stack boş olduğu için -1
    }

    // Yıkıcı: Dinamik olarak oluşturulan diziyi serbest bırakır
    ~Stack() {
        delete[] arr;
    }

    // Verilen elemanı stack'e ekler
    void push(int x) {
        if (isFull()) {
            cout << "Stack taşma hatası: " << x << " eklenemedi." << endl;
            return;
        }
        arr[++top] = x;
    }

    // Stack'ten eleman çıkarır ve döner
    int pop() {
        if (isEmpty()) {
            cout << "Stack boş, cikartilacak eleman yok." << endl;
            return -1;
        }
        return arr[top--];
    }

    // Stack'teki en üstteki elemanı döner
    int peek() {
        if (!isEmpty())
            return arr[top];
        else
            cout << "Stack bos." << endl;
            return -1;
    }

    // Stack'in boş olup olmadığını kontrol eder
    bool isEmpty() {
        return top == -1;
    }

    // Stack'in dolu olup olmadığını kontrol eder
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack stack(5);  // Kapasitesi 5 olan bir stack oluşturduk

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack'in en ust elemani: " << stack.peek() << endl;
    cout << "Cikarilan eleman: " << stack.pop() << endl;
    cout << "Stack'in en ust elemani: " << stack.peek() << endl;

    return 0;
}
