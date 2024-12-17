/*
parametre olarak alınan türlerin farklı olmasını sağlayan template fonksiyonu
*/
#include <iostream>
using namespace std;

// Template fonksiyonu, bir parametre int ve diğerini double olarak alır
template <typename T1, typename T2>
void printSum(T1 a, T2 b) {
    cout << "Sum: " << a + b << endl;
}

int main() {
    int x = 5;
    double y = 3.5;

    // x int, y double türünden
    printSum(x, y);  // Çıktı: Sum: 8.5

    return 0;
}
