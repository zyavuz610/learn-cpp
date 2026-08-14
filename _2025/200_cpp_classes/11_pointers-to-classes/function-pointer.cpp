#include <iostream>
#include <string>

using namespace std;

class Ogrenci {
public:
    // Yapıcı metot (Constructor)
    Ogrenci(string isim, int notSayisi) {
        ad = isim;
        boyut = notSayisi;
        notlar = new int[boyut];
        for (int i = 0; i < boyut; ++i) {
            notlar[i] = 0;
        }
        cout << ad << " adli ogrenci nesnesi olusturuldu." << endl;
    }

    // Yıkıcı metot (Destructor)
    ~Ogrenci() {
        delete[] notlar;
        cout << ad << " adli ogrenci nesnesi yok edildi. Bellek serbest birakildi." << endl;
    }
    
    // --- Yeni Eklenen Metot ---
    // Notlar dizisinin bir kopyasını döndüren metot
    // Geriye bir int işaretçisi (pointer) döndürür.
    int* getNotlarKopyasi() const { // const anahtar kelimesi, bu metodun sınıfın veri üyelerini değiştirmeyeceğini garanti eder.
        // Notlar dizisi için yeni bir bellek alanı ayır.
        int* kopyaNotlar = new int[boyut];
        // Orijinal notları yeni diziye kopyala.
        for (int i = 0; i < boyut; ++i) {
            kopyaNotlar[i] = notlar[i];
        }
        // Yeni dizinin başlangıç adresini döndür.
        return kopyaNotlar;
    }
    
    // Getter ve Setter'lar
    string getAd() const { return ad; }
    void setNot(int index, int not_degeri) {
        if (index >= 0 && index < boyut) {
            notlar[index] = not_degeri;
        }
    }
    void notlariYazdir() const {
        cout << "Notlar: ";
        for (int i = 0; i < boyut; ++i) {
            cout << notlar[i] << " ";
        }
        cout << endl;
    }

private:
    string ad;
    int boyut;
    int* notlar;
};

// --- Ana Fonksiyon ---
int main() {
    // Orjinal öğrenci nesnesini oluştur.
    Ogrenci* ogrenci1 = new Ogrenci("Ahmet", 3);
    
    // Notları ayarla.
    ogrenci1->setNot(0, 85);
    ogrenci1->setNot(1, 92);
    ogrenci1->setNot(2, 78);
    
    cout << "\nOrijinal notlar:" << endl;
    ogrenci1->notlariYazdir();
    
    // getNotlarKopyasi() metodunu çağır ve dönen işaretçiyi bir değişkene ata.
    int* ahmetinNotKopyasi = ogrenci1->getNotlarKopyasi();
    
    // Kopyalanan notları yazdır.
    cout << "\nKopyalanan notlar:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << ahmetinNotKopyasi[i] << " ";
    }
    cout << endl;
    
    // Orijinal nesnenin notunu değiştir.
    cout << "\nOrijinal notlarin ilk elemani degistiriliyor (85 -> 65)..." << endl;
    ogrenci1->setNot(0, 65);
    
    cout << "\nDegisiklikten sonra orijinal notlar:" << endl;
    ogrenci1->notlariYazdir();
    
    // Kopyalanan notları tekrar yazdır. Değişmemiş olması gerekir.
    cout << "Kopyalanan notlar (degismemeli):" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << ahmetinNotKopyasi[i] << " ";
    }
    cout << endl;
    
    // ÖNEMLİ: getNotlarKopyasi metodu `new` kullandığı için,
    // dönen işaretçiyi `delete` ile serbest bırakmalıyız.
    delete[] ahmetinNotKopyasi;
    ahmetinNotKopyasi = nullptr;

    // Orijinal nesneyi sil.
    delete ogrenci1;
    ogrenci1 = nullptr;

    return 0;
}