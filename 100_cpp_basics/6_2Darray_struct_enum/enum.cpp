#include <iostream>
#include <string>

using namespace std;

// --- 1. Temel Enum Tanımı ve Kullanımı ---
// `enum` anahtar kelimesi ile bir sabit listesi tanımlarız.
// Varsayılan olarak, ilk elemanın değeri 0'dır ve her eleman bir artar.
enum HaftaninGunleri {
    Pazartesi, // Varsayilan deger 0
    Sali,      // Varsayilan deger 1
    Carsamba,  // Varsayilan deger 2
    Persembe,  // Varsayilan deger 3
    Cuma,      // Varsayilan deger 4
    Cumartesi, // Varsayilan deger 5
    Pazar      // Varsayilan deger 6
};

// --- 2. Enum Elemanlarına Özel Değerler Atama ---
// Elemanlara kendi istediğimiz tam sayı değerlerini atayabiliriz.
// Atama yapılmayan elemanlar, kendisinden önceki elemanın değerini bir artırır.
enum Seviye {
    Dusuk = 10,
    Orta = 50,
    Yuksek = 100,
    CokYuksek // Bu eleman 101 degerini alir
};

// --- 3. `enum class` (Kapsamlı Enum) Kullanımı ---
// Modern C++'ta `enum class` kullanmak daha güvenlidir.
// - Enum elemanları yalnızca kendi kapsamları içinden erişilebilir. (Sari -> Renk::Sari)
// - Implicit (örtülü) tam sayı dönüşümü yoktur, bu da tür güvenliğini artırır.
enum class Renk {
    Kirmizi,
    Yesil,
    Mavi,
    Sari
};

void hangiRenk(Renk r) {
    switch (r) {
        case Renk::Kirmizi:
            cout << "Secilen renk: Kirmizi" << endl;
            break;
        case Renk::Yesil:
            cout << "Secilen renk: Yesil" << endl;
            break;
        case Renk::Mavi:
            cout << "Secilen renk: Mavi" << endl;
            break;
        case Renk::Sari:
            cout << "Secilen renk: Sari" << endl;
            break;
    }
}

int main() {
    // --- 1. Temel Enum Kullanımı ---
    HaftaninGunleri bugun = Cumartesi;
    
    // Enum değişkeninin değerini (tam sayı) yazdırabiliriz.
    cout << "Bugun haftanin " << bugun << ". gunu." << endl;
    
    if (bugun == Cumartesi) {
        cout << "Bugun Cumartesi!" << endl;
    }

    // --- 2. Özel Değer Atanmış Enum Kullanımı ---
    Seviye oyuncuSeviyesi = Yuksek;
    cout << "\nOyuncunun seviyesi (deger olarak): " << oyuncuSeviyesi << endl;
    
    // Enum elemanlarina erisim
    cout << "Dusuk seviye degeri: " << Dusuk << endl;

    // --- 3. `enum class` Kullanımı ---
    // Enum class elemanlarına erişim için kapsam belirtilmesi gerekir.
    // `Renk::` kullanimi zorunludur.
    Renk secilenRenk = Renk::Yesil;
    
    hangiRenk(secilenRenk);
    
    // Hata: `enum class`'dan doğrudan bir tam sayiya atama yapamazsiniz.
    // int x = Renk::Mavi; // Derleme hatasi verir!
    
    // Gerekirse açıkça dönüştürme yapmalısınız.
    int maviDeger = static_cast<int>(Renk::Mavi);
    cout << "Mavi renginin degeri: " << maviDeger << endl;
    
    return 0;
}