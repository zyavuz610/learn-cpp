/*
Temel Programlama Yöntemleri ve Dizi Algoritmaları (Basic Algorithms)
KTÜ Bilgisayar Mühendisliği - C++ Temelleri

Bu dosya, programlamaya yeni başlayan öğrencilerin mutlaka bilmesi gereken
en temel algoritma kalıplarını (diziler üzerinde) fonksiyonel olarak içerir:
  1. Dizi Elemanlarını Yazdırma (Print Array)
  2. Toplam Bulma (Sum / Accumulation)
  3. Çarpım Bulma (Product)
  4. Ortalama Hesaplama (Average / Mean)
  5. En Büyük Elemanı Bulma (Find Maximum)
  6. En Küçük Elemanı Bulma (Find Minimum)
  7. Belirli Bir Elemanı Sayma (Count Occurrences / Frequency)
  8. Koşula Göre Sayma (Count Condition - örn: Çift Sayıları Sayma)
  9. Doğrusal Arama (Linear Search)
*/

#include <iostream>
using namespace std;

// 1. Dizi Elemanlarını Ekrana Yazdırma
void diziYazdir(const int dizi[], int boyut) {
    cout << "[ ";
    for (int i = 0; i < boyut; i++) {
        cout << dizi[i] << (i == boyut - 1 ? "" : ", ");
    }
    cout << " ]" << endl;
}

// 2. Toplam Bulma (Sum)
// Mantık: Başlangıçta toplam = 0 alınır, her eleman sırayla üzerine eklenir.
int toplamBul(const int dizi[], int boyut) {
    int toplam = 0;
    for (int i = 0; i < boyut; i++) {
        toplam += dizi[i];
    }
    return toplam;
}

// 3. Çarpım Bulma (Product)
// Mantık: Çarpma işleminin etkisiz elemanı 1 olduğu için carpim = 1 ile başlanır.
long long carpimBul(const int dizi[], int boyut) {
    long long carpim = 1;
    for (int i = 0; i < boyut; i++) {
        carpim *= dizi[i];
    }
    return carpim;
}

// 4. Ortalama Bulma (Average)
// Mantık: Toplam / Eleman Sayısı.
// DİKKAT: Tamsayı bölmesi (integer division) veri kaybına yol açabileceğinden
// değerlerden biri ondalıklı türe (double) dönüştürülmelidir.
double ortalamaBul(const int dizi[], int boyut) {
    if (boyut == 0) return 0.0;
    return static_cast<double>(toplamBul(dizi, boyut)) / boyut;
}

// 5. En Büyük Elemanı Bulma (Find Maximum)
// Mantık: İlk eleman (dizi[0]) en büyük kabul edilir.
// Sıradaki elemanlar karşılaştırılır, daha büyüğü bulunursa enBuyuk güncellenir.
int enBuyukBul(const int dizi[], int boyut) {
    int enBuyuk = dizi[0];
    for (int i = 1; i < boyut; i++) {
        if (dizi[i] > enBuyuk) {
            enBuyuk = dizi[i];
        }
    }
    return enBuyuk;
}

// 6. En Küçük Elemanı Bulma (Find Minimum)
// Mantık: İlk eleman (dizi[0]) en küçük kabul edilir.
// Sıradaki elemanlar karşılaştırılır, daha küçüğü bulunursa enKucuk güncellenir.
int enKucukBul(const int dizi[], int boyut) {
    int enKucuk = dizi[0];
    for (int i = 1; i < boyut; i++) {
        if (dizi[i] < enKucuk) {
            enKucuk = dizi[i];
        }
    }
    return enKucuk;
}

// 7. Belirli Bir Elemanın Sayısını Bulma (Frequency / Count)
// Mantık: Dizide 'aranan' değerle eşleşen her eleman için sayacı 1 artırır.
int elemanSay(const int dizi[], int boyut, int aranan) {
    int adet = 0;
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan) {
            adet++;
        }
    }
    return adet;
}

// 8. Koşula Göre Sayma (Örn: Çift Sayıların Adedi)
// Mantık: Belirli bir şartı (sayı % 2 == 0) sağlayan elemanları sayar.
int ciftSayilariSay(const int dizi[], int boyut) {
    int adet = 0;
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] % 2 == 0) {
            adet++;
        }
    }
    return adet;
}

// 9. Doğrusal Arama (Linear Search)
// Mantık: Elemanlar baştan sona tek tek taranır.
// Aranan eleman bulunursa dizideki indeksi (0, 1, ...), bulunamazsa -1 döndürülür.
int dogrusalArama(const int dizi[], int boyut, int aranan) {
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan) {
            return i; // Bulundu, indeksini dön
        }
    }
    return -1; // Eleman dizide yok
}

int main() {
    // Örnek test dizisi
    int sayilar[] = {12, 5, 8, 20, 5, 3, 15, 7};
    int boyut = sizeof(sayilar) / sizeof(sayilar[0]);

    cout << "========================================" << endl;
    cout << "     TEMEL PROGRAMLAMA ALGORITMALARI    " << endl;
    cout << "========================================" << endl;

    // 1. Dizi Elemanlarını Yazdırma
    cout << "\n1. Dizi Elemanlari:" << endl;
    cout << "Dizi: ";
    diziYazdir(sayilar, boyut);

    // 2. Toplam Bulma
    cout << "\n2. Toplam Bulma:" << endl;
    cout << "Elemanlarin toplami: " << toplamBul(sayilar, boyut) << endl;

    // 3. Çarpım Bulma
    cout << "\n3. Carpim Bulma:" << endl;
    int kucukDizi[] = {2, 3, 4, 5};
    cout << "{2, 3, 4, 5} dizisinin carpimi: " << carpimBul(kucukDizi, 4) << endl;

    // 4. Ortalama Hesaplama
    cout << "\n4. Ortalama Hesaplama:" << endl;
    cout << "Elemanlarin ortalamasi: " << ortalamaBul(sayilar, boyut) << endl;

    // 5. En Büyük Eleman
    cout << "\n5. En Buyuk Eleman:" << endl;
    cout << "Dizideki en buyuk deger: " << enBuyukBul(sayilar, boyut) << endl;

    // 6. En Küçük Eleman
    cout << "\n6. En Kucuk Eleman:" << endl;
    cout << "Dizideki en kucuk deger: " << enKucukBul(sayilar, boyut) << endl;

    // 7. Belirli Bir Elemanı Sayma
    cout << "\n7. Eleman Sayma (Frekans):" << endl;
    int arananDeger = 5;
    cout << arananDeger << " sayisi dizide " << elemanSay(sayilar, boyut, arananDeger) << " kez geciyor." << endl;

    // 8. Koşullu Sayma
    cout << "\n8. Kosullu Sayma:" << endl;
    cout << "Dizideki cift sayilarin adedi: " << ciftSayilariSay(sayilar, boyut) << endl;

    // 9. Doğrusal Arama (Linear Search)
    cout << "\n9. Dogrusal Arama (Linear Search):" << endl;
    int ara1 = 20;
    int indeks1 = dogrusalArama(sayilar, boyut, ara1);
    if (indeks1 != -1) {
        cout << "Sonuc: " << ara1 << " degeri dizinin " << indeks1 << ". indeksinde bulundu." << endl;
    } else {
        cout << "Sonuc: " << ara1 << " degeri dizide bulunamadi." << endl;
    }

    int ara2 = 99;
    int indeks2 = dogrusalArama(sayilar, boyut, ara2);
    if (indeks2 != -1) {
        cout << "Sonuc: " << ara2 << " degeri dizinin " << indeks2 << ". indeksinde bulundu." << endl;
    } else {
        cout << "Sonuc: " << ara2 << " degeri dizide bulunamadi." << endl;
    }

    cout << "\n========================================" << endl;
    return 0;
}
