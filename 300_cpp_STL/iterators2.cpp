#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Bir vector (dinamik dizi) oluşturalım
    vector<int> sayilar = {10, 20, 30, 40, 50};

    // 1. YÖNTEM: Uzun (Explicit) Tanımlama
    // vector<int>::iterator türünde 'it' adında bir iteratör tanımlıyoruz.
    cout << "--- Iterator ile Gezinme ---" << endl;
    for (vector<int>::iterator it = sayilar.begin(); it != sayilar.end(); ++it) {
        // *it diyerek o adresteki veriyi okuyoruz
        cout << *it << " "; 
    }
    cout << endl;

    // 2. YÖNTEM: Modern C++ (auto keyword) - Derleyici, atanan değere bakarak uygun türü belirler
    // Derleyici iteratör tipini otomatik anlar.
    cout << "--- Auto ve Tersten Gezinme ---" << endl;
    // rbegin() -> reverse begin (sondan başla)
    // rend() -> reverse end (başın öncesi)
    for (auto it = sayilar.rbegin(); it != sayilar.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}