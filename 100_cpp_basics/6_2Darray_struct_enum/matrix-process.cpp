#include <iostream>

using namespace std;

// 2D diziyi ekrana yazdıran fonksiyon
void matrisYazdir(int matris[3][4]) {
    cout << "--- Matrisin Mevcut Durumu ---" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matris[i][j] << "\t";
        }
        cout << endl;
    }
}

// 2D dizideki tüm elemanların toplamını bulan fonksiyon
int toplamBul(int matris[3][4]) {
    int toplam = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            toplam += matris[i][j];
        }
    }
    return toplam;
}

// 2D dizinin tüm elemanlarını 2 ile çarpan fonksiyon
void matrisiCarp(int matris[3][4], int carpan) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            matris[i][j] *= carpan;
        }
    }
}

int main() {
    // 2D dizi tanımlama ve ilk değer ataması
    int matris[3][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };

    // Matrisin ilk halini ekrana yazdır
    matrisYazdir(matris);

    // Matristeki elemanların toplamını hesapla ve yazdır
    int matris_toplami = toplamBul(matris);
    cout << "\nMatrisin elemanlarinin toplami: " << matris_toplami << endl;
    
    // Matrisin tüm elemanlarını 2 ile çarp
    matrisiCarp(matris, 2);

    // İşlemden sonra matrisin yeni halini ekrana yazdır
    cout << "\n--- Elemanlar 2 ile carpildiktan sonraki matris ---" << endl;
    matrisYazdir(matris);

    return 0;
}