#include <iostream>

using namespace std;

int main() {
    // 2D Dizi Tanımlama ve İlk Değer Ataması
    // 3 satır ve 4 sütundan oluşan bir tamsayı dizisi
    int matris[3][4] = {
        {10, 20, 30, 40},    // İlk satır
        {50, 60, 70, 80},    // İkinci satır
        {90, 100, 110, 120}  // Üçüncü satır
    };

    cout << "--- Orijinal Matris ---" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matris[i][j] << "\t";
        }
        cout << endl;
    }

    // Bireysel Elemanları Değiştirme
    // Dizinin elemanlarına satır ve sütun indislerini kullanarak erişilir.
    // Örnek: matris[satir_indisi][sutun_indisi]
    
    // İkinci satırın üçüncü elemanını (indisler: [1][2]) değiştirme
    matris[1][2] = 777;
    
    // İlk satırın ilk elemanını (indisler: [0][0]) değiştirme
    matris[0][0] = 111;
    
    // Üçüncü satırın son elemanını (indisler: [2][3]) değiştirme
    matris[2][3] = 999;

    cout << "\n--- Degistirilen Matris ---" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matris[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}