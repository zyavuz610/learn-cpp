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

    // Kopya yapıcı: başka bir Stack nesnesinden kopyalama yapar
    /*
    Stack(const Stack& other) {
        capacity = other.capacity;
        top = other.top;
        arr = new int[capacity];
        for (int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }
    }
    */

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
    // Kopya yapıcıyı kullanarak yeni bir stack oluşturuyoruz
    Stack stack2 = stack;

    // stack2'nin içeriğini kontrol edelim
    cout << "stack2'nin en ust elemani: " << stack2.peek() << endl;

    // stack1 ve stack2 bağımsızdır; stack2'den eleman çıkarıp değişiklik yapabiliriz
    stack2.pop();
    cout << "stack2'den bir eleman cikarildiktan sonra en ust elemani: " << stack2.peek() << endl;
    stack2.push(45);
    // stack1 hala aynı kalır
    cout << "stack1'in en ust elemani (degismedi): " << stack.peek() << endl;

    return 0;
}
