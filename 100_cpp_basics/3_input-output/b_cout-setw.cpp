#include <iostream>
#include <iomanip> // setw için gerekli

using namespace std;

int main() {
    string ad1 = "Ahmet";
    string ad2 = "Ayse";
    string ad3 = "Mehmet";

    double fiyat1 = 12.3;
    double fiyat2 = 125.75;
    double fiyat3 = 24.5;
    
    // setw() fonksiyonu, bir sonraki çıktının ne kadar boşluk kaplayacağını belirler.
    // Bu, metinleri veya sayıları hizalamak için çok kullanışlıdır.
    // setw() sadece bir sonraki çıktı için geçerlidir ve sürekli kullanılması gerekir.

    cout << "--- Varsayilan Cikis ---" << endl;
    cout << ad1 << " " << fiyat1 << endl;
    cout << ad2 << " " << fiyat2 << endl;
    cout << ad3 << " " << fiyat3 << endl;

    cout << "\n--- setw Kullanimi ---" << endl;
    cout << "Isimler ve Fiyatlar" << endl;
    
    // setw() ile isimleri ve fiyatları hizalayalım.
    // İsimler için 10 karakter, fiyatlar için 8 karakter genişlik ayarlayalım.
    
    cout << setw(10) << ad1 << setw(8) << fiyat1 << endl;
    cout << setw(10) << ad2 << setw(8) << fiyat2 << endl;
    cout << setw(10) << ad3 << setw(8) << fiyat3 << endl;
    
    // setw() ile ondalık sayıları hizalamak için fixed ve setprecision da kullanılır.
    cout << "\n--- setw, fixed ve setprecision Kullanimi ---" << endl;
    
    cout << fixed << setprecision(2); // Ondalık noktadan sonra 2 basamak gösterir.
    
    cout << setw(10) << ad1 << setw(8) << fiyat1 << endl;
    cout << setw(10) << ad2 << setw(8) << fiyat2 << endl;
    cout << setw(10) << ad3 << setw(8) << fiyat3 << endl;

    return 0;
}