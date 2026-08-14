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
    
    // --- Shallow Copy (Yüzeysel Kopyalama) ---
    // Bu, varsayılan kopyalama davranışını gösterir.
    // 'other' nesnesinin işaretçisini 'this' nesnesine atar.
    void shallowCopy(const Ogrenci& other) {
        ad = other.ad + " (shallow)";
        notlar = other.notlar; // İşaretçiyi kopyala (aynı belleği işaret etsin)
    }
    
    // --- Deep Copy (Derin Kopyalama) ---
    // Bu metod, yeni bir bellek alanı ayırır ve içeriği kopyalar.
    void deepCopy(const Ogrenci& other) {
        ad = other.ad + " (deep)";
        boyut = other.boyut;
        // Önceki dinamik belleği serbest bırak (varsa)
        if (notlar) {
            delete[] notlar;
        }
        // Yeni bir bellek alanı ayır
        notlar = new int[boyut];
        // İçeriği kopyala
        for (int i = 0; i < boyut; ++i) {
            notlar[i] = other.notlar[i];
        }
    }

    // Getter ve Setter'lar
    string getAd() const { return ad; }
    int getNot(int index) const {
        if (index >= 0 && index < boyut) return notlar[index];
        return -1;
    }
    void setNot(int index, int not_degeri) {
        if (index >= 0 && index < boyut) notlar[index] = not_degeri;
    }

private:
    string ad;
    int boyut;
    int* notlar;
};

// --- Ana Fonksiyon ---
int main() {
    // Orjinal nesne
    Ogrenci* ogrenciA = new Ogrenci("Ali", 3);
    ogrenciA->setNot(0, 90);
    ogrenciA->setNot(1, 85);
    ogrenciA->setNot(2, 95);

    cout << "\n--- Orjinal Ogrenci (Ali) ---" << endl;
    cout << "Ad: " << ogrenciA->getAd() << endl;
    cout << "Not 1: " << ogrenciA->getNot(0) << endl;

    // --- Shallow Copy (Yüzeysel Kopyalama) Örneği ---
    cout << "\n--- Shallow Copy (Yuzeyel Kopyalama) ---" << endl;
    Ogrenci* ogrenciB = new Ogrenci("Kopya B", 3);
    ogrenciB->shallowCopy(*ogrenciA);

    cout << "Kopya B notu (kopya yapildiktan sonra): " << ogrenciB->getNot(0) << endl;

    // 'Ali'nin ilk notunu değiştir
    cout << "\nAli'nin ilk notu 70 olarak degistiriliyor..." << endl;
    ogrenciA->setNot(0, 70);

    // Kopyanın notunu kontrol et. Shallow copy olduğu için o da değişmiş olmalı.
    cout << "Kopya B'nin notu: " << ogrenciB->getNot(0) << endl; // 70 olmalı!
    
    // Yüzeysel kopyalama bellek sorunlarına yol açabilir, bu yüzden dikkatli olunmalı.
    // İki nesne de aynı belleği işaret ettiği için her iki nesneyi de silmeye çalışmak hataya neden olur.
    // `delete ogrenciA` yaptıktan sonra `delete ogrenciB` bellek hatası verecektir.

    delete ogrenciA; // Sadece birini silmeliyiz.

    // --- Deep Copy (Derin Kopyalama) Örneği ---
    cout << "\n--- Deep Copy (Derin Kopyalama) ---" << endl;
    Ogrenci* ogrenciC = new Ogrenci("Veli", 3);
    Ogrenci* ogrenciD = new Ogrenci("Kopya D", 3);
    ogrenciD->deepCopy(*ogrenciC);

    cout << "Orijinal Ogrenci (Veli) notu: " << ogrenciC->getNot(0) << endl;
    cout << "Kopya D notu: " << ogrenciD->getNot(0) << endl;

    // 'Veli'nin ilk notunu değiştir
    cout << "\nVeli'nin ilk notu 60 olarak degistiriliyor..." << endl;
    ogrenciC->setNot(0, 60);
    
    // Kopyanın notunu kontrol et. Deep copy olduğu için değişmemiş olmalı.
    cout << "Orijinal Ogrenci (Veli) yeni notu: " << ogrenciC->getNot(0) << endl; // 60 olmalı
    cout << "Kopya D'nin notu: " << ogrenciD->getNot(0) << endl; // 90 (eski deger) kalmalı

    // Deep copy'de her nesnenin belleği ayrı olduğu için ikisi de güvenle silinebilir.
    delete ogrenciC;
    delete ogrenciD;

    return 0;
}