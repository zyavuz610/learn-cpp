//-------------------------------------------------------------------------
/*
	
	pure virtual function
		* temel sınıfta tanımlanır
		* temel sınıfta tanımlı herhangi bir işlevi yoktur, sadece fonksiyonun prototipi tanımlıdır
		* virtual type func-name(parameters...)=0;  şeklinde tanımlanır.
		* her türetilmiş sınıfta bu fonksiyon tanımlanmak zorundadır.
      * "pure_virtual_function.cpp" dosyasını inceleyin
	abstract class,
		* bir sınıf en az 1 adet  saf sanal fonk. varsa o sınıf soyut sınıf olarak bilinir

    bir başka deyişle:
    Saf sanal fonksiyonlar, bir temel sınıfın türemiş sınıflar tarafından mutlaka uygulanması gereken bir "sözleşme" tanımlamasına olanak tanır. 
    Bir sınıf en az bir saf sanal fonksiyona sahipse, o sınıf soyut sınıf (abstract class) olarak adlandırılır. 
    Soyut sınıflardan doğrudan nesne oluşturamazsınız, ancak bu sınıfları işaret eden pointer'lar veya referanslar tanımlayabilirsiniz.
	
		// An abstract class 
		class Test     
		    // Data members of class 
		public: 
		    // Pure Virtual Function 
		    virtual void show() = 0; 

		   // Other members ...

	abstract (soyut) class özellikleri - Interfaces
		1. En az bir saf sanal fonk. varsa, bu sınıf soyutdur.
		2. soyut sınıf tipinde pointer ve referanslar tanımlanabilir. ancak nesne değişken tanımlanamaz
		3. türeyen sınıfta temel sınıftaki fonk.nu aşırı yüklemezsek o halde türetilen sınıf da soyut olur
      * "pure_virtual_function.cpp" dosyasını inceleyin
		4. soyut sınıfın yapıcı fonksiyonları olabilir.
		
}; 	
	
*/
//--------------------------------------------------------------------------------------
#include <iostream>

// Soyut Sınıf (Abstract Class)
class Sekil {
public:
    // Saf sanal fonksiyon (Pure Virtual Function).
    // "= 0" ifadesi, bu fonksiyonun temel sınıfta bir gövdesi olmadığını
    // ve türemiş sınıflar tarafından mutlaka tanımlanması gerektiğini belirtir.
    virtual double alanHesapla() = 0;

    // Saf sanal olmayan bir sanal fonksiyon da olabilir.
    virtual void bilgiYazdir() {
        std::cout << "Bu bir geometrik şekildir." << std::endl;
    }

    // Sanal yıkıcı: Bellek sızıntılarını önlemek için gereklidir.
    virtual ~Sekil() {
        std::cout << "Sekil yıkıcısı çalıştı." << std::endl;
    }
};

// Türemiş Sınıf (Dikdörtgen)
class Dikdortgen : public Sekil {
private:
    double en, boy;
public:
    Dikdortgen(double e, double b) : en(e), boy(b) {
        std::cout << "Dikdörtgen yapıcısı çalıştı." << std::endl;
    }

    // Saf sanal fonksiyonun uygulanması (override).
    // Bu fonksiyonu tanımlamak ZORUNLUDUR, aksi takdirde Dikdörtgen sınıfı da soyut olur.
    double alanHesapla() override {
        return en * boy;
    }

    void bilgiYazdir() override {
        std::cout << "Bu bir dikdörtgen." << std::endl;
    }

    ~Dikdortgen() {
        std::cout << "Dikdörtgen yıkıcısı çalıştı." << std::endl;
    }
};

// Türemiş Sınıf (Üçgen)
class Ucgen : public Sekil {
private:
    double taban, yukseklik;
public:
    Ucgen(double t, double y) : taban(t), yukseklik(y) {
        std::cout << "Üçgen yapıcısı çalıştı." << std::endl;
    }

    // Saf sanal fonksiyonun uygulanması (override).
    double alanHesapla() override {
        return (taban * yukseklik) / 2.0;
    }

    void bilgiYazdir() override {
        std::cout << "Bu bir üçgen." << std::endl;
    }

    ~Ucgen() {
        std::cout << "Üçgen yıkıcısı çalıştı." << std::endl;
    }
};

int main() {
    // Sekil sınıfı soyut olduğu için, doğrudan nesne oluşturamazsınız.
    // Sekil sekil; // HATA!

    // Ancak, Sekil tipinde pointer ve referanslar tanımlayabilirsiniz.
    Sekil* sekilPtr1 = new Dikdortgen(5.0, 4.0);
    Sekil* sekilPtr2 = new Ucgen(6.0, 3.0);

    std::cout << "Dikdörtgenin alanı: " << sekilPtr1->alanHesapla() << std::endl;
    sekilPtr1->bilgiYazdir(); // Çıktı: Bu bir dikdörtgen.

    std::cout << "------------------------" << std::endl;

    std::cout << "Üçgenin alanı: " << sekilPtr2->alanHesapla() << std::endl;
    sekilPtr2->bilgiYazdir(); // Çıktı: Bu bir üçgen.

    // Belleği serbest bırakırken sanal yıkıcılar sayesinde
    // doğru yıkıcılar çağrılır.
    delete sekilPtr1;
    delete sekilPtr2;

    return 0;
}