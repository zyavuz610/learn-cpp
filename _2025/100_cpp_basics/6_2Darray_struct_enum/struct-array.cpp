#include <iostream>
#include <string>

// 'Ogrenci' adında bir yapı (struct) tanımlayalım.
// Bu yapı, bir öğrenciye ait bilgileri bir arada tutar.
struct Ogrenci {
    std::string ad;
    int yas;
    double notOrtalamasi;
};

int main() {
    // Ogrenci yapısında 3 elemanlı bir dizi oluşturalım.
    // Her bir eleman bir Ogrenci nesnesidir.
    Ogrenci ogrenciler[3];

    // Dizinin elemanlarına tek tek değer atayalım.
    // Dizi indislerini (0, 1, 2) ve nokta (.) operatörünü kullanarak
    // her bir öğrencinin özelliklerine erişiriz.

    // Birinci öğrenci (indis 0)
    ogrenciler[0].ad = "Ahmet";
    ogrenciler[0].yas = 20;
    ogrenciler[0].notOrtalamasi = 3.5;

    // İkinci öğrenci (indis 1)
    ogrenciler[1].ad = "Ayse";
    ogrenciler[1].yas = 21;
    ogrenciler[1].notOrtalamasi = 3.8;

    // Üçüncü öğrenci (indis 2)
    ogrenciler[2].ad = "Mehmet";
    ogrenciler[2].yas = 19;
    ogrenciler[2].notOrtalamasi = 3.2;

    std::cout << "--- Ogrenci Listesi ---" << std::endl;

    // Döngü kullanarak dizi elemanlarını (öğrencileri) yazdıralım.
    for (int i = 0; i < 3; ++i) {
        std::cout << "Ogrenci " << i + 1 << ":" << std::endl;
        std::cout << "  Ad: " << ogrenciler[i].ad << std::endl;
        std::cout << "  Yas: " << ogrenciler[i].yas << std::endl;
        std::cout << "  Not Ortalamasi: " << ogrenciler[i].notOrtalamasi << std::endl;
        std::cout << "----------------------" << std::endl;
    }

    // Ayrıca, tek bir öğrenciye ait bilgilere de doğrudan erişebiliriz.
    std::cout << "Ikinci ogrencinin adi: " << ogrenciler[1].ad << std::endl;

    return 0;
}