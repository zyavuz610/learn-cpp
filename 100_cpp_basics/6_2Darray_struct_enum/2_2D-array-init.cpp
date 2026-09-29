#include <iostream>

using namespace std;

int main() {
    // --- 1. Tanımlama Sırasında Değer Atama (Initialization) ---
    // C++'ta, bir 2D diziyi tanımlarken süslü parantezler kullanarak ilk değerlerini verebiliriz.
    // Her bir iç süslü parantez, dizinin bir satırını temsil eder.
    int matris1[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    cout << "--- Tanımlama Sirasinda Ilk Deger Atanan Matris ---" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matris1[i][j] << "\t";
        }
        cout << endl;
    }

    // --- 2. Döngü ile Değer Atama ---
    // Bir 2D diziyi tanımlayıp daha sonra iç içe döngüler kullanarak her bir elemanına değer atayabiliriz.
    // Bu yöntem, değerler dinamik olarak hesaplandığında veya kullanıcıdan alındığında kullanışlıdır.
    int matris2[3][2];
    int sayac = 100;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            matris2[i][j] = sayac;
            sayac += 10;
        }
    }

    cout << "\n--- Dongu ile Ilk Deger Atanan Matris ---" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matris2[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}