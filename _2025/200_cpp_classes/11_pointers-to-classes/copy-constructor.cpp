/*
 * Kopyalama Kurucusu (Copy Constructor) Nedir?
 *
 * Kopyalama kurucusu, bir sınıftan yeni bir nesne oluşturulurken, aynı sınıftan
 * var olan bir nesneyi kullanarak başlatmak için kullanılan özel bir yapıcı (constructor) metottur.
 *
 * Ne Zaman Kullanılır?
 *
 * - MyClass obj2 = obj1; gibi bir atama ile nesne tanımlandığında.
 * - Fonksiyonlara değerle (by value) parametre geçirildiğinde.
 * - Fonksiyonlardan değerle (by value) geri dönüş yapıldığında.
 *
 * Neden İhtiyaç Duyulur?
 *
 * Varsayılan (derleyici tarafından sağlanan) kopyalama kurucusu sığ kopyalama (shallow copy) yapar.
 * Bu, nesne içindeki işaretçi (pointer) adresini kopyalar, işaretçinin gösterdiği veriyi değil.
 * Sonuç olarak, birden fazla nesne aynı bellek alanını işaret eder. Bu da bellek sızıntısı
 * veya hatalı bellek erişimi gibi sorunlara yol açar.
 *
 * Kendi kopyalama kurucumuzu tanımlayarak derin kopyalama (deep copy) yapabiliriz.
 * Bu, hem nesneyi hem de işaretçinin gösterdiği veriyi kopyalar ve her nesnenin
 * bağımsız bir bellek alanına sahip olmasını sağlar.
 */

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

    // Kopyalama Kurucusu (Copy Constructor)
    // Bir Ogrenci nesnesi, baska bir Ogrenci nesnesinden kopyalanirken bu metot calisir.
    Ogrenci(const Ogrenci& digerOgrenci) {
        ad = "Kopya-" + digerOgrenci.ad;
        boyut = digerOgrenci.boyut;

        // Derin kopyalama (Deep Copy) yaparız
        // Yeni bir bellek alanı ayırır ve orijinalin içeriğini kopyalarız.
        notlar = new int[boyut];
        for (int i = 0; i < boyut; ++i) {
            notlar[i] = digerOgrenci.notlar[i];
        }

        cout << ad << " adli ogrenci nesnesi kopyalama kurucusu ile olusturuldu." << endl;
    }

    // Yıkıcı metot (Destructor)
    ~Ogrenci() {
        delete[] notlar;
        cout << ad << " adli ogrenci nesnesi yok edildi. Bellek serbest birakildi." << endl;
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

int main() {
    // 1. Orijinal nesne oluşturuluyor
    Ogrenci ogrenciA("Ali", 3);
    ogrenciA.setNot(0, 90);
    ogrenciA.setNot(1, 85);
    ogrenciA.setNot(2, 95);

    cout << "\n--- Durum 1: Orijinal Nesne (Ali) ---" << endl;
    cout << "Ad: " << ogrenciA.getAd() << endl;
    ogrenciA.notlariYazdir();

    // 2. Kopyalama Kurucusu'nun Çağrılması
    // Bu satır, ogrenciA'yı kullanarak ogrenciB'yi başlatır.
    // Tanımladığımız kopyalama kurucusu burada devreye girer.
    Ogrenci ogrenciB = ogrenciA; 
    
    cout << "\n--- Durum 2: Kopya Nesne (Kopya-Ali) ---" << endl;
    cout << "Ad: " << ogrenciB.getAd() << endl;
    ogrenciB.notlariYazdir();

    // 3. Farkı Gözlemleme
    // Orijinal nesnenin notunu değiştiriyoruz.
    cout << "\n--- Not Degisikligi ---" << endl;
    cout << "Orijinal nesnenin ilk notu 70 olarak degistiriliyor." << endl;
    ogrenciA.setNot(0, 70);

    // Her iki nesnenin notlarını tekrar yazdırıyoruz.
    // Derin kopyalama sayesinde, ogrenciA'daki değişiklik ogrenciB'yi etkilemez.
    cout << "\nOrijinal (Ali) : " << ogrenciA.getAd() << endl;
    ogrenciA.notlariYazdir();

    cout << "Kopya (Kopya-Ali) : " << ogrenciB.getAd() << endl;
    ogrenciB.notlariYazdir();
    
    // Eğer bir kopyalama kurucusu tanımlamasaydık (veya varsayılanı kullansaydık),
    // ogrenciB'nin ilk notu da 70 olurdu ve bu bellek yönetimi sorunlarına yol açardı.

    return 0; 
    // Program bittiğinde, ogrenciA ve ogrenciB nesnelerinin yıkıcı metotları
    // otomatik olarak çağrılır ve dinamik bellekler serbest bırakılır.
}