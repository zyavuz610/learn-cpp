#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double sayi1 = 25.0;
    double sayi2 = 25.123;
    double sayi3 = 25.000;

    cout << "--- Varsayilan Cikis ---" << endl;
    cout << "sayi1: " << sayi1 << endl; // Ondalık hane gözükmez.
    cout << "sayi2: " << sayi2 << endl;
    cout << "sayi3: " << sayi3 << endl;

    cout << "\n--- showpoint Kullanimi ---" << endl;
    // showpoint, ondalık noktalı sayıların her zaman ondalık noktasını ve
    // sondaki sıfırları göstermesini sağlar.
    // Bu, özellikle para birimi veya kesin ölçümler için kullanışlıdır.
    cout << showpoint;

    cout << "showpoint aktifken:" << endl;
    cout << "sayi1: " << sayi1 << endl;
    cout << "sayi2: " << sayi2 << endl;
    cout << "sayi3: " << sayi3 << endl;

    // showpoint, setprecision ile birlikte kullanıldığında daha anlamlı hale gelir.
    cout << "\n--- showpoint ve setprecision Kullanimi ---" << endl;
    cout << fixed << setprecision(3); // Ondalık noktadan sonra 3 basamak gösterir.
    
    cout << "showpoint ve fixed ile birlikte:" << endl;
    cout << "sayi1: " << sayi1 << endl;
    cout << "sayi2: " << sayi2 << endl;
    cout << "sayi3: " << sayi3 << endl;

    return 0;
}