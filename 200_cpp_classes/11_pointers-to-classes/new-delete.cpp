#include <iostream>
#include <string>

using namespace std;

/*
 * `new` ve `delete` Nedir?
 *
 * `new` ve `delete` operatörleri, C++'ta programın çalışma anında (runtime) dinamik olarak bellek yönetimi yapmamızı sağlar.
 *
 * `new` operatörü, bellekte bir nesne veya dizi için yer ayırır ve o nesneye veya dizinin ilk elemanına işaret eden bir bellek adresi döndürür.
 * `delete` operatörü ise, `new` ile ayrılan belleği serbest bırakır.
 *
 * Neden İhtiyaç Duyulur?
 *
 * Programın derleme zamanında bellekte ne kadar yer kaplayacağı bilinmediğinde, dinamik bellek yönetimine ihtiyaç duyarız.
 * Örneğin, bir dizinin boyutunun kullanıcı girdisine göre belirlenmesi gerektiğinde veya nesnelerin program çalışırken oluşturulup yok edilmesi gerektiğinde bu operatörler kullanılır.
 * `delete` kullanmak zorunludur, aksi halde bellekte "bellek sızıntısı" (memory leak) oluşur.
 */

// Basit bir EvcilHayvan sınıfı
class EvcilHayvan {
public:
    // Yapıcı metot (constructor)
    EvcilHayvan(string isim, int y) {
        ad = isim;
        yas = y;
        cout << ad << " nesnesi olusturuldu." << endl;
    }

    // Yıkıcı metot (destructor)
    ~EvcilHayvan() {
        cout << ad << " nesnesi yok edildi." << endl;
    }

    // Getter metotları
    string getAd() const {
        return ad;
    }
    int getYas() const {
        return yas;
    }

    // Setter metotları
    void setAd(string yeniAd) {
        ad = yeniAd;
    }
    void setYas(int yeniYas) {
        if (yeniYas >= 0) {
            yas = yeniYas;
        } else {
            cout << "Hata: Yas negatif olamaz!" << endl;
        }
    }

private:
    string ad;
    int yas;
};

int main() {
    // --- 1. Dinamik Tekil Nesne Oluşturma ---
    // `new` ile yığın (heap) bellekte bir EvcilHayvan nesnesi oluştur.
    EvcilHayvan* kedi = new EvcilHayvan("Tekir", 3);

    cout << "\nKedi adi: " << kedi->getAd() << endl;
    cout << "Kedi yasi: " << kedi->getYas() << endl;

    // Setter ile değerleri değiştirme
    kedi->setAd("Pamuk");
    kedi->setYas(4);
    
    cout << "Yeni kedi adi: " << kedi->getAd() << endl;
    cout << "Yeni kedi yasi: " << kedi->getYas() << endl;

    // `delete` ile yığın bellekteki nesneyi yok et ve belleği serbest bırak.
    delete kedi;
    kedi = nullptr;

    // --- 2. Dinamik Nesne Dizisi Oluşturma ---
    // `new` ile yığın bellekte 2 elemanlı bir EvcilHayvan dizisi oluştur.
    EvcilHayvan* kopekler = new EvcilHayvan[2]{
        EvcilHayvan("Karabas", 5),
        EvcilHayvan("Max", 2)
    };
    
    cout << "\nIlk kopek: " << kopekler[0].getAd() << ", " << kopekler[0].getYas() << " yasinda." << endl;
    cout << "Ikinci kopek: " << kopekler[1].getAd() << ", " << kopekler[1].getYas() << " yasinda." << endl;

    // Dizi elemanlarının değerlerini değiştirme
    kopekler[0].setAd("Lupo");
    kopekler[0].setYas(6);
    
    cout << "\nGüncellenen ilk kopek: " << kopekler[0].getAd() << ", " << kopekler[0].getYas() << " yasinda." << endl;

    // `delete[]` ile tüm dizi elemanlarını yok et ve belleği serbest bırak.
    delete[] kopekler;
    kopekler = nullptr;

    return 0;
}