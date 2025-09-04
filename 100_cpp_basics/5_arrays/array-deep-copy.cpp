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

// Dizideki en büyük elemanın indisini bulan fonksiyon
int enBuyukIndisBul(const double arr[], int size) {
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

//---
// Derin kopyalama (deep copy) yapan fonksiyon
// Yeni bir bellek alanı tahsis eder ve değerleri kopyalar.
void deepCopy(const double source[], double dest[], int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = source[i];
    }
}

//---
// Sığ kopyalama (shallow copy) yapan fonksiyon
// Sadece işaretçiyi veya referansı kopyalar, aynı bellek alanını kullanırlar.
void shallowCopy(const double *source, double *&dest) {
    dest = const_cast<double*>(source);
}

int main() {
    int n;
    
    cout << "Kac adet sayi girmek istiyorsunuz? (Maksimum 100): ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Lutfen 1 ile 100 arasinda bir tamsayi girin." << endl;
        return 1;
    }

    double original_sayilar[100];

    cout << "Lutfen " << n << " adet sayi girin:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> original_sayilar[i];
    }

    cout << "---" << endl;
    cout << "Orijinal dizi:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << original_sayilar[i] << " ";
    }
    cout << endl;
    cout << "---" << endl;

    // Toplam ve en büyük sayıyı bulma
    double toplam = toplamHesapla(original_sayilar, n);
    int enBuyukIndis = enBuyukIndisBul(original_sayilar, n);

    cout << "Girdiginiz sayilarin toplami: " << toplam << endl;

    if (enBuyukIndis != -1) {
        cout << "En buyuk sayi: " << original_sayilar[enBuyukIndis] << endl;
        cout << "En buyuk sayinin indisi: " << enBuyukIndis << endl;
    } else {
        cout << "Gecerli bir sayi girilmedi." << endl;
    }
    cout << "---" << endl;

    // Derin Kopyalama Örneği
    cout << "Derin kopyalama ornegi:" << endl;
    double deep_copied_sayilar[100];
    deepCopy(original_sayilar, deep_copied_sayilar, n);

    // Derin kopyada bir elemanı değiştirme. Orijinal dizi etkilenmez.
    if (n > 0) {
        deep_copied_sayilar[0] = 999.9;
    }
    
    cout << "deep_copied_sayilar dizisinin ilk elemani degistirildi." << endl;
    cout << "Yeni deep_copied_sayilar[0]: " << deep_copied_sayilar[0] << endl;
    cout << "Orijinal sayilar[0]: " << original_sayilar[0] << endl;
    cout << "---" << endl;

    // Sığ Kopyalama Örneği
    cout << "Sig kopyalama ornegi:" << endl;
    double *shallow_copied_sayilar;
    shallowCopy(original_sayilar, shallow_copied_sayilar);

    // Sığ kopyada bir elemanı değiştirme. Orijinal dizi de etkilenir.
    if (n > 0) {
        shallow_copied_sayilar[0] = 111.1;
    }

    cout << "shallow_copied_sayilar[0] degistirildi." << endl;
    cout << "Yeni shallow_copied_sayilar[0]: " << shallow_copied_sayilar[0] << endl;
    cout << "Orijinal sayilar[0] da degisti: " << original_sayilar[0] << endl;

    return 0;
}