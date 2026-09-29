#include <iostream>

using namespace std;

// Dizideki elemanların toplamını hesaplayan fonksiyon
double toplamHesapla(const double arr[], int size) {
    double toplam = 0.0;
    for (int i = 0; i < size; ++i) {
        toplam += arr[i];
    }
    return toplam;
}

// Dizideki en büyük elemanın indisini bulan fonksiyon
int enBuyukIndisBul(const double arr[], int size) {
    // Dizinin boş veya geçersiz boyutlu olması durumunda -1 döndür.
    if (size <= 0) {
        return -1;
    }

    int enBuyukIndis = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[enBuyukIndis]) {
            enBuyukIndis = i;
        }
    }
    return enBuyukIndis;
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

    // Fonksiyonları çağırarak işlemleri yapalım.
    double toplam = toplamHesapla(sayilar, n);
    int enBuyukIndis = enBuyukIndisBul(sayilar, n);

    cout << "---" << endl;
    cout << "Girdiginiz sayilarin toplami: " << toplam << endl;

    if (enBuyukIndis != -1) {
        cout << "En buyuk sayi: " << sayilar[enBuyukIndis] << endl;
        cout << "En buyuk sayinin indisi: " << enBuyukIndis << endl;
    } else {
        cout << "Gecerli bir sayi girilmedi." << endl;
    }
    
    return 0;
}