#include <iostream>

using namespace std;

// Dizi ve boyutunu parametre olarak alan, toplamı döndüren fonksiyon
double toplamHesapla(const double arr[], int size) {
    double toplam = 0.0;
    for (int i = 0; i < size; ++i) {
        toplam += arr[i];
    }
    return toplam;
}

int main() {
    int n;
    double sayilar[100]; 

    cout << "Kac adet sayi girmek istiyorsunuz? (Maksimum 100): ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Lutfen 1 ile 100 arasinda bir tamsayi girin." << endl;
        return 1;
    }

    cout << "Lutfen " << n << " adet sayi girin:" << endl;

    // Sayıları kullanıcıdan alıp diziye ekleyelim.
    for (int i = 0; i < n; ++i) {
        cin >> sayilar[i];
    }

    // Fonksiyonu çağırarak sayıların toplamını hesaplayalım.
    double sonuc = toplamHesapla(sayilar, n);

    cout << "Girdiginiz sayilarin toplami: " << sonuc << endl;

    return 0;
}