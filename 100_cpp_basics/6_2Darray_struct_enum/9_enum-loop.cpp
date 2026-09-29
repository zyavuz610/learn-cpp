#include <iostream>
#include <string>

using namespace std;

// Mevsimleri temsil eden bir enum tanımlayalım.
enum Mevsimler {
    Ilkbahar, // Varsayılan olarak 0
    Yaz,      // 1
    Sonbahar, // 2
    Kis       // 3
};

// Enum değerlerini string'e dönüştüren bir yardımcı fonksiyon
string mevsimAdiniBul(Mevsimler m) {
    switch (m) {
        case Ilkbahar: return "Ilkbahar";
        case Yaz:      return "Yaz";
        case Sonbahar: return "Sonbahar";
        case Kis:      return "Kis";
        default:       return "Bilinmiyor";
    }
}

int main() {
    // Enum'daki tüm elemanları bir döngü ile işlemek için
    // for döngüsü kullanabiliriz.
    // Başlangıç olarak Ilkbahar (0) ve bitiş olarak Kis'in (3) bir fazlasını kullanırız.
    cout << "Yilin mevsimleri:" << endl;
    for (int i = Ilkbahar; i <= Kis; ++i) {
        // Döngüdeki tam sayı değerini enum türüne dönüştürelim
        Mevsimler mevcutMevsim = static_cast<Mevsimler>(i);

        // Mevsimin adını ve değerini yazdıralım
        cout << mevsimAdiniBul(mevcutMevsim) << " (deger: " << mevcutMevsim << ")" << endl;
    }

    // `enum class` için döngü örneği:
    cout << "\n--- enum class ornegi ---" << endl;
    enum class Renkler {
        Kirmizi,
        Yesil,
        Mavi
    };
    
    for (int i = static_cast<int>(Renkler::Kirmizi); i <= static_cast<int>(Renkler::Mavi); ++i) {
        Renkler mevcutRenk = static_cast<Renkler>(i);
        cout << "Renk degeri: " << i << endl;
    }

    return 0;
}