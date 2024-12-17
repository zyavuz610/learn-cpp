/*
içeriğinde faklı veri türleri barındıran bir template sınıfı örneği...
*/
#include <iostream>
using namespace std;

// Template sınıfı, iki farklı türde veri tutar
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    // Constructor
    Pair(T1 f, T2 s) : first(f), second(s) {}

    // Getter fonksiyonları
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }

    // Setter fonksiyonları
    void setFirst(T1 f) { first = f; }
    void setSecond(T2 s) { second = s; }

    // Üçüncü türdeki veriyi yazdırmak için bir fonksiyon
    void print() const {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    // int ve double türlerini içeren bir Pair nesnesi oluşturuyoruz
    Pair<int, double> p1(5, 3.14);

    p1.print();  // Çıktı: First: 5, Second: 3.14

    // string ve bool türlerini içeren bir Pair nesnesi oluşturuyoruz
    Pair<string, bool> p2("C++", true);

    p2.print();  // Çıktı: First: C++, Second: 1

    return 0;
}
