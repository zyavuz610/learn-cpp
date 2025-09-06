#include <iostream>
#include <string>

using namespace std;

class Ogrenci {
public:
    // Yapıcı metot (Constructor)
    // Nesne oluşturulduğunda dinamik dizi için bellek ayırır.
    Ogrenci(string isim) {
        ad = isim;
        // 3 elemanlı int dizisi için dinamik bellek ayır.
        notlar = new int[3]; 
        // Dizinin elemanlarını başlangıç değeri olarak 0'a ayarla.
        for (int i = 0; i < 3; ++i) {
            notlar[i] = 0;
        }
        cout << ad << " adli ogrenci nesnesi olusturuldu." << endl;
    }

    // Yıkıcı metot (Destructor)
    // Nesne bellekten silindiğinde dinamik belleği serbest bırakır.
    ~Ogrenci() {
        // `delete[]` kullanarak dinamik diziyi serbest bırak.
        delete[] notlar;
        notlar = nullptr; // Bellek adresini boşalt.
        cout << ad << " adli ogrenci nesnesi yok edildi. Bellek serbest birakildi." << endl;
    }

    // Getter metotları
    string getAd() const {
        return ad;
    }

    // Not dizisinin bir elemanına erişim için getter metodu
    int getNot(int index) const {
        if (index >= 0 && index < 3) {
            return notlar[index];
        }
        return -1; // Geçersiz indis için hata kodu döndür.
    }

    // Setter metotları
    void setAd(string yeniAd) {
        ad = yeniAd;
    }

    // Not dizisinin bir elemanını ayarlamak için setter metodu
    void setNot(int index, int not_degeri) {
        if (index >= 0 && index < 3) {
            notlar[index] = not_degeri;
        } else {
            cout << "Hata: Gecersiz not indisi!" << endl;
        }
    }

    // Ortalama notu hesaplayan yardımcı metot
    double ortalamaHesapla() const {
        double toplam = 0;
        for (int i = 0; i < 3; ++i) {
            toplam += notlar[i];
        }
        return toplam / 3.0;
    }

private:
    string ad;
    int* notlar; // Dinamik bir dizi için işaretçi
};

int main() {
    // Ogrenci sınıfından dinamik bir nesne oluştur.
    Ogrenci* ogrenci1 = new Ogrenci("Ali");

    // Nesnenin özelliklerini setter metotları ile ayarla.
    ogrenci1->setNot(0, 85);
    ogrenci1->setNot(1, 92);
    ogrenci1->setNot(2, 78);

    cout << "\n--- Ogrenci Bilgileri ---" << endl;
    cout << "Ad: " << ogrenci1->getAd() << endl;
    cout << "Not 1: " << ogrenci1->getNot(0) << endl;
    cout << "Not 2: " << ogrenci1->getNot(1) << endl;
    cout << "Not 3: " << ogrenci1->getNot(2) << endl;
    cout << "Ortalama: " << ogrenci1->ortalamaHesapla() << endl;

    // Nesnenin adını değiştir.
    ogrenci1->setAd("Mehmet");
    cout << "\nAd guncellendi: " << ogrenci1->getAd() << endl;

    // Bellekten dinamik nesneyi sil.
    // Bu, yıkıcı metotun (destructor) otomatik olarak çağrılmasını sağlar.
    delete ogrenci1;
    ogrenci1 = nullptr;

    return 0;
}