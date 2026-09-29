#include <iostream>
#include <string>

// Enum tanımlama: Programın durumunu belirten sabitler
enum Durum {
    Baslatiliyor,
    Calisiyor,
    Duraklatildi,
    Hata
};

// Enum'u bir fonksiyona parametre olarak gönderme örneği
void durumBilgisiVer(Durum mevcutDurum) {
    std::cout << "Programin durumu: ";
    
    // Switch-case yapısı, enum'lar için idealdir.
    switch (mevcutDurum) {
        case Baslatiliyor:
            std::cout << "Baslatiliyor..." << std::endl;
            break;
        case Calisiyor:
            std::cout << "Calisiyor." << std::endl;
            break;
        case Duraklatildi:
            std::cout << "Duraklatildi." << std::endl;
            break;
        case Hata:
            std::cout << "Bir hata olustu!" << std::endl;
            break;
        default:
            std::cout << "Bilinmeyen durum." << std::endl;
            break;
    }
}

// Fonksiyonun geri dönüş değeri olarak enum kullanma örneği
Durum programiDurdur() {
    std::cout << "Program durdurma islemi baslatildi." << std::endl;
    // ... durdurma işlemleri ...
    return Durum::Duraklatildi;
}

int main() {
    // Enum değişkeni tanımlama
    Durum programinDurumu = Baslatiliyor;

    // Fonksiyonu çağırma ve enum değerini gönderme
    durumBilgisiVer(programinDurumu);

    // Durumu değiştirme
    programinDurumu = Calisiyor;
    durumBilgisiVer(programinDurumu);

    // Geri dönüş değeri enum olan fonksiyonu kullanma
    programinDurumu = programiDurdur();
    durumBilgisiVer(programinDurumu);

    return 0;
}