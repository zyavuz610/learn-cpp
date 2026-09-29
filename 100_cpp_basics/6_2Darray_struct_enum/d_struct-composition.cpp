#include <iostream>
#include <string>

// Adres bilgilerini tutan bir yapı
struct Adres {
    std::string sokak;
    std::string sehir;
    std::string postaKodu;
};

// Kişisel bilgileri ve adres bilgisini tutan ana yapı
struct Kisi {
    std::string ad;
    int yas;
    Adres adresBilgisi; // Adres yapısını burada kullanıyoruz
};

int main() {
    // Kisi tipinde bir değişken oluşturalım
    Kisi kisi1;

    // Ana yapının elemanlarına erişme
    kisi1.ad = "Emirhan";
    kisi1.yas = 28;

    // Alt yapıdaki elemanlara erişim. İki nokta (.) operatörü arka arkaya kullanılır.
    kisi1.adresBilgisi.sokak = "Gunes Sokak, No: 5";
    kisi1.adresBilgisi.sehir = "Ankara";
    kisi1.adresBilgisi.postaKodu = "06000";

    // Değerleri ekrana yazdıralım
    std::cout << "--- Kisi Bilgileri ---" << std::endl;
    std::cout << "Ad: " << kisi1.ad << std::endl;
    std::cout << "Yas: " << kisi1.yas << std::endl;
    std::cout << "Adres:" << std::endl;
    std::cout << "  Sokak: " << kisi1.adresBilgisi.sokak << std::endl;
    std::cout << "  Sehir: " << kisi1.adresBilgisi.sehir << std::endl;
    std::cout << "  Posta Kodu: " << kisi1.adresBilgisi.postaKodu << std::endl;

    return 0;
}