#include <iostream>

using namespace std;

int main() {
    // Matrisin boyutlarını tanımlayalım.
    const int SATIR_SAYISI = 3;
    const int SUTUN_SAYISI = 4;
    int matris[SATIR_SAYISI][SUTUN_SAYISI];

    // Kullanıcıdan matris elemanlarını girmesini isteyelim.
    cout << "Matrisin " << SATIR_SAYISI << "x" << SUTUN_SAYISI << " elemanlarini girin:" << endl;
    for (int i = 0; i < SATIR_SAYISI; ++i) {
        for (int j = 0; j < SUTUN_SAYISI; ++j) {
            cout << "Eleman [" << i << "][" << j << "]: ";
            cin >> matris[i][j];
        }
    }

    cout << "\n--- Sonuclar ---" << endl;

    // Her satırı dolaşarak en büyük elemanı ve indisini bulalım.
    for (int i = 0; i < SATIR_SAYISI; ++i) {
        int enBuyukEleman = matris[i][0];
        int enBuyukIndis = 0;

        // Geçerli satırdaki tüm sütunları dolaşalım.
        for (int j = 1; j < SUTUN_SAYISI; ++j) {
            // Eğer daha büyük bir eleman bulunursa, en büyük elemanı ve indisini güncelleyelim.
            if (matris[i][j] > enBuyukEleman) {
                enBuyukEleman = matris[i][j];
                enBuyukIndis = j;
            }
        }
        
        // Sonuçları ekrana yazdıralım.
        cout << i << ". satirda en buyuk eleman: " << enBuyukEleman;
        cout << " (sutun indisi: " << enBuyukIndis << ")" << endl;
    }

    return 0;
}