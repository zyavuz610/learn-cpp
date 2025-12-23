#include <iostream>
#include <vector>
#include <algorithm> // Algoritmalar icin sart

using namespace std;

// Yazdırmak için yardımcı fonksiyon
void yazdir(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> sayilar = {50, 10, 40, 20, 30, 10};

    cout << "Orijinal: ";
    yazdir(sayilar);

    // 1. SIRALAMA (Sort)
    // begin() ve end() iteratörleri aralığı belirtir
    sort(sayilar.begin(), sayilar.end());
    cout << "Sirali:   ";
    yazdir(sayilar);

    // 2. TERS ÇEVİRME (Reverse)
    reverse(sayilar.begin(), sayilar.end());
    cout << "Ters:     ";
    yazdir(sayilar);

    // 3. SAYMA (Count)
    // Dizide kaç tane '10' var?
    int adet = count(sayilar.begin(), sayilar.end(), 10);
    cout << "Dizide " << adet << " adet '10' sayisi var." << endl;

    // 4. ARAMA (Find)
    // '40' sayısını arayalım
    auto it = find(sayilar.begin(), sayilar.end(), 40);

    if (it != sayilar.end()) {
        // it, bulunan elemanın adresidir.
        // Konteynerin başından ne kadar uzakta olduğunu bulmak için 'distance' kullanabiliriz.
        cout << "40 sayisi bulundu! Indeks sirasi: " << distance(sayilar.begin(), it) << endl;
    } else {
        cout << "Sayi bulunamadi." << endl;
    }

    return 0;
}