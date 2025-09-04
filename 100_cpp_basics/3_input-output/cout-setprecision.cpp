#include <iostream>
#include <iomanip> // setprecision ve fixed için gerekli

using namespace std;

int main() {
    double pi = 3.141592653589793;
    double fiyat = 12.3456;
    double buyuk_sayi = 1234567.89;

    cout << "Varsayilan hassasiyet (default precision):" << endl;
    cout << "Pi: " << pi << endl;
    cout << "Fiyat: " << fiyat << endl;
    cout << "Buyuk Sayi: " << buyuk_sayi << endl;

    cout << "\n--- setprecision kullanimi ---" << endl;
    
    // cout.setprecision(5) kullanimi
    // Bu, toplamda 5 basamak goruntuleyecek sekilde ayarlar.
    // Noktadan sonraki basamak sayisini degil, toplam basamak sayisini ayarlar.
    cout << "Hassasiyet 5 olarak ayarlandi:" << endl;
    cout << setprecision(5);
    cout << "Pi: " << pi << endl;
    cout << "Fiyat: " << fiyat << endl;
    cout << "Buyuk Sayi: " << buyuk_sayi << endl; // Bilimsel notasyona gecebilir

    cout << "\n--- fixed ve setprecision kullanimi ---" << endl;
    
    // cout.setprecision() ve fixed bir arada kullanildiginda,
    // hassasiyet yalnizca ondalik noktadan sonraki basamak sayisini kontrol eder.
    cout << "Hassasiyet 3 olarak ayarlandi (fixed ile):" << endl;
    cout << fixed << setprecision(3);
    cout << "Pi: " << pi << endl;
    cout << "Fiyat: " << fiyat << endl;
    cout << "Buyuk Sayi: " << buyuk_sayi << endl;

    cout << "\n--- Tekrar varsayilan ayarlara donme ---" << endl;
    
    // Varsayilan ayarlara donmek icin setprecision'i 6'ya ayarlayabiliriz.
    // fixed modunu kapatmak icin `cout << defaultfloat;` kullanilabilir.
    cout << defaultfloat;
    cout << setprecision(6);
    cout << "Varsayilana dondu:" << endl;
    cout << "Pi: " << pi << endl;

    return 0;
}