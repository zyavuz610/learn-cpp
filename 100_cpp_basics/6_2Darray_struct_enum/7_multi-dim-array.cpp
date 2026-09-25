#include <iostream>

using namespace std;

int main() {
    // 2 (sayfa) x 3 (satir) x 4 (sutun) boyutlarinda bir dizi
    int ucBoyutluDizi[2][3][4] = {
        // Birinci sayfa (indis 0)
        {
            {10, 20, 30, 40},
            {50, 60, 70, 80},
            {90, 100, 110, 120}
        },
        // Ikinci sayfa (indis 1)
        {
            {130, 140, 150, 160},
            {170, 180, 190, 200},
            {210, 220, 230, 240}
        }
    };
    
    // Dizideki elemanlari ekrana yazdirma
    for (int sayfa = 0; sayfa < 2; ++sayfa) {
        cout << "--- Sayfa " << sayfa << " ---" << endl;
        for (int satir = 0; satir < 3; ++satir) {
            for (int sutun = 0; sutun < 4; ++sutun) {
                cout << ucBoyutluDizi[sayfa][satir][sutun] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Bireysel bir elemana erisme
    // Ikinci sayfadaki (indis 1), ucuncu satirindaki (indis 2), dorduncu sutunundaki (indis 3) eleman
    cout << "Dizinin [1][2][3] indisindeki elemani: " << ucBoyutluDizi[1][2][3] << endl;

    // Bir elemani degistirme
    ucBoyutluDizi[0][1][2] = 999;
    cout << "Dizinin [0][1][2] indisi 999 olarak degistirildi." << endl;
    cout << "Yeni deger: " << ucBoyutluDizi[0][1][2] << endl;
    
    return 0;
}