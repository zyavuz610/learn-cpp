#include <iostream>
#include <cmath>   // Matematiksel fonksiyonlar için
#include <cctype>  // Karakter fonksiyonları için

using namespace std;

int main() {
    // abs(x) - Tam sayının mutlak değerini alır.
    cout << "--- abs(x) ---" << endl;
    int tamSayi = -5;
    cout << tamSayi << " sayisinin mutlak degeri: " << abs(tamSayi) << endl;

    cout << "\n--- ceil(x) ---" << endl;
    // ceil(x) - Ondalıklı sayıyı bir üst tam sayıya yuvarlar.
    double sayi1 = 4.2;
    double sayi2 = -4.2;
    cout << sayi1 << " sayisinin ust tamsayisi: " << ceil(sayi1) << endl;
    cout << sayi2 << " sayisinin ust tamsayisi: " << ceil(sayi2) << endl;

    cout << "\n--- cos(x) ---" << endl;
    // cos(x) - Açının (radyan cinsinden) kosinüsünü hesaplar.
    double aci = 0.0; // Radyan cinsinden 0 derece
    cout << "0 radyanin kosinusu: " << cos(aci) << endl;

    cout << "\n--- exp(x) ---" << endl;
    // exp(x) - e^x (Euler sayısının x. kuvveti) değerini hesaplar.
    double x = 1.0;
    cout << "e^" << x << " = " << exp(x) << endl;

    cout << "\n--- fabs(x) ---" << endl;
    // fabs(x) - Ondalıklı sayının mutlak değerini alır.
    double ondalikliSayi = -7.8;
    cout << ondalikliSayi << " sayisinin mutlak degeri: " << fabs(ondalikliSayi) << endl;

    cout << "\n--- floor(x) ---" << endl;
    // floor(x) - Ondalıklı sayıyı bir alt tam sayıya yuvarlar.
    double sayi3 = 4.8;
    double sayi4 = -4.8;
    cout << sayi3 << " sayisinin alt tamsayisi: " << floor(sayi3) << endl;
    cout << sayi4 << " sayisinin alt tamsayisi: " << floor(sayi4) << endl;

    cout << "\n--- pow(x,y) ---" << endl;
    // pow(x, y) - x'in y. kuvvetini hesaplar.
    double taban = 2.0;
    double us = 3.0;
    cout << taban << "^" << us << " = " << pow(taban, us) << endl;

    cout << "\n--- tolower(x) ---" << endl;
    // tolower(x) - Büyük harfi küçük harfe dönüştürür.
    char buyukHarf = 'A';
    cout << buyukHarf << " harfinin kucuk hali: " << (char)tolower(buyukHarf) << endl;

    cout << "\n--- toupper(x) ---" << endl;
    // toupper(x) - Küçük harfi büyük harfe dönüştürür.
    char kucukHarf = 'a';
    cout << kucukHarf << " harfinin buyuk hali: " << (char)toupper(kucukHarf) << endl;

    return 0;
}