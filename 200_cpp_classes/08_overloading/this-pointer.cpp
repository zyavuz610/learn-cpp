#include <iostream>

using namespace std;

class Saat {
public:
    // Yapıcı metot (constructor)
    Saat(int s, int m, int d) {
        saat = s;
        dakika = m;
        saniye = d;
    }

    // `this` pointer'ını kullanan setter metodu
    void setZaman(int saat, int dakika, int saniye) {
        // Parametre adları ile sınıfın üye değişkenlerinin adları aynı olduğunda,
        // `this->` pointer'ı ile üye değişkenlere erişim sağlarız.
        this->saat = saat;
        this->dakika = dakika;
        this->saniye = saniye;
    }

    // `*this` döndüren zincirleme (chaining) setter metodu
    Saat& zamanAyarla(int saat, int dakika, int saniye) {
        this->saat = saat;
        this->dakika = dakika;
        this->saniye = saniye;
        return *this; // Mevcut nesnenin kendisini döndürür
    }

    // Zamanı yazdıran metot
    void yazdir() {
        cout << saat << ":" << dakika << ":" << saniye << endl;
    }

private:
    int saat, dakika, saniye;
};

int main() {
    Saat benimSaat(10, 30, 0);

    // --- `this` pointer'ı kullanımı ---
    cout << "Baslangic zamani: ";
    benimSaat.yazdir();

    benimSaat.setZaman(14, 45, 15);
    cout << "setZaman() ile yeni zaman: ";
    benimSaat.yazdir();

    // --- `*this` ile fonksiyon zincirleme (chaining) ---
    // `zamanAyarla` metodu `*this` döndürdüğü için, metot çağrısı sonrasında
    // aynı nesne üzerinde başka metotlar da çağrılabilir.
    // Bu, daha akıcı ve okunabilir kod yazmamızı sağlar.
    cout << "zamanAyarla() ile yeni zaman (zincirleme):" << endl;
    benimSaat.zamanAyarla(18, 50, 20).yazdir();

    return 0;
}