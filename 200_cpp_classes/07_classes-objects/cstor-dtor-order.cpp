/*
 * C++ Yapıcı (Constructor) ve Yıkıcı (Destructor) Çağrılma Sırası
 * Blok İçerisinde ve Dışında Nesne Ömrü (Scope & Lifetime)
 * KTÜ Bilgisayar Mühendisliği - Nesne Yönelimli Programlama
 */

#include <iostream>
#include <string>

using namespace std;

class Nesne {
private:
    string isim;
    string kapsam;

public:
    // Kurucu Metot (Constructor)
    Nesne(string ad, string yer) : isim(ad), kapsam(yer) {
        cout << "[+] Kurucu (Ctor) : " << isim << " olusturuldu -> Kapsam: " << kapsam << endl;
    }

    // Yıkıcı Metot (Destructor)
    ~Nesne() {
        cout << "[-] Yikici (Dtor) : " << isim << " YOK EDILDI!   <- Kapsam: " << kapsam << endl;
    }

    void selamVer() const {
        cout << "    >> " << isim << " isini yapiyor..." << endl;
    }
};

// 1. GLOBAL NESNE (Tüm fonksiyonların ve blokların dışında)
// main() çalışmadan ÖNCE belleğe yüklenir ve kurulur.
Nesne globalNesne("1. GlobalNesne", "GLOBAL KAPSAM");

void ornekFonksiyon() {
    cout << "\n>>> ornekFonksiyon() BASLADI <<<" << endl;
    
    // Fonksiyon içi yerel nesne
    Nesne fonkYerel("FonksiyonYerel", "ornekFonksiyon() Yerel");
    
    // Statik yerel nesne: Sadece İLK çağrıda oluşturulur, fonksiyon bitince yok EDİLMEZ!
    // Program sonlanırken yok edilir.
    static Nesne fonkStatik("FonksiyonStatik", "ornekFonksiyon() STATIK");
    
    fonkYerel.selamVer();
    fonkStatik.selamVer();

    cout << ">>> ornekFonksiyon() BITIYOR <<<" << endl;
    // fonkYerel burada yok edilir (kapsam bitti). fonkStatik yaşamaya devam eder!
}

int main() {
    cout << "\n==============================================" << endl;
    cout << "              main() BASLADI                  " << endl;
    cout << "==============================================" << endl;

    // 2. main() İÇİNDE YEREL NESNE (Dış Blok)
    Nesne mainNesne1("2. MainNesne_1", "main() Dis Blok");
    Nesne mainNesne2("3. MainNesne_2", "main() Dis Blok");

    cout << "\n--- [1. IC BLOK (Nested Scope) BASLIYOR] ---" << endl;
    {
        // 3. İÇ BLOK İÇERİSİNDE TANIMLANAN NESNELER
        // Sadece bu { ... } parantezleri arasında yaşarlar.
        Nesne icBlok1("4. IcBlokNesne_A", "1. Ic Blok");
        Nesne icBlok2("5. IcBlokNesne_B", "1. Ic Blok");

        icBlok1.selamVer();
        icBlok2.selamVer();

        cout << "--- [1. IC BLOK BITIYOR] ---" << endl;
        // DİKKAT: LIFO Kuralı!
        // En son oluşturulan 'IcBlokNesne_B' İLK yok edilir!
        // Ardından 'IcBlokNesne_A' yok edilir.
    }
    cout << "--- [1. IC BLOK SONRASI, main() DEVAM EDIYOR] ---\n" << endl;

    // Fonksiyon çağrısı
    ornekFonksiyon();

    cout << "\n--- [2. IC BLOK (Dinamik Bellek Karsilastirmasi)] ---" << endl;
    {
        Nesne stackNesne("6. StackNesne", "2. Ic Blok (Stack)");
        
        // Dinamik olarak new ile oluşturulan nesne
        Nesne* heapNesne = new Nesne("7. HeapNesne", "2. Ic Blok (Heap/Dinamik)");

        // Blok bitmeden önce delete çağrılmazsa HeapNesne'nin yıkıcısı ÇALIŞMAZ (Bellek Sızıntısı)!
        cout << "    [Manuel Delete Cagrisi Yapiliyor]" << endl;
        delete heapNesne; // Yıkıcı burada manuel tetiklenir
    } // stackNesne burada otomatik yok edilir

    cout << "\n==============================================" << endl;
    cout << "              main() BITIYOR                  " << endl;
    cout << "==============================================" << endl;

    // main() biterken:
    // 1. main yerel nesneleri ters sırayla (LIFO) yok edilir: MainNesne_2, sonra MainNesne_1
    // 2. static yerel nesneler yok edilir: FonksiyonStatik
    // 3. global nesneler yok edilir: GlobalNesne

    return 0;
}

