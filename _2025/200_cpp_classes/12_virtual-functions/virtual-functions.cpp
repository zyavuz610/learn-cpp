//************************************************************************************************
/*
	Virtual Functions (Sanal Fonksiyonlar)
		* sanal fonksiyonlar görünüşte var olup gerçekte olmayan fonksiyonlardır.
		* Gerçekte bir gövdesi olmayan fonksiyonlardır,
    * bir fonksiyon "virtual" olarak tanımlanmışsa derleyici bağlama (binding) işlemini koşma zamanına bırakır. nesnenin tipine göre hangi fonksiyonun çağrılacağına karar verilir.
		* miras kavramında, base class'te sanal bir fonksiyon tanımlanır ve derived class'ta bu fonksiyon aşırı yüklenir
		* daha sonra base class türünde bir pointer ile derived class fonksiyonları çağrılır (polimorfizm)
		
		* sanal fonksiyonlar miras durumunda hangi fonksiyonun çağrılacağını garanti eder. pointer neyi gösteriyorsa onun fonksiyonu kullanılır
		* runtime polimorfizm gerçekleştirmek için kullanılır.
			- hangi fonksiyonun çağrılacağı koşma zamanında belli olur. (run-time binding | dynamic binding | late-binding)
			- <hangi fonksiyonun çağrılacağı derleme zamanında belirli ise compile-time binding | static binding | early-binding> <binding=bağlama, birleştirme>
		* virtual anahtar kelimesi ile kullanılır.	
		
	KURALLAR
		* sanal fonksiyonlar "puplic" alanda tanımlanmalıdır.
		* sanal fonksiyonlar "static" ya da "friend" olamazlar
		* run-time polimorfizm için sanal fonksiyonlar, base class ın pointer ı ile çağrılmalıdırlar.
		* base class ve derived class taki sanal fonksiyonların prototipleri (parametre sayıları, türleri) aynı olmak zorundadır
		* Her zaman temel sınıfta tanımlanırlar ve türetilmiş sınıfta geçersiz kılınırlar (overload). 
		* Türetilmiş sınıfın geçersiz kılınması (veya sanal işlevi yeniden tanımlaması) zorunlu değildir, bu durumda fonksiyonun temel sınıfı kullanılır.
		* Bir sınıf sanal yıkıcıya sahip olabilir, ancak sanal bir kurucu olamaz.	
*/
//---------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

// Temel Sınıf (Base Class)
class Hayvan {
public:
    // Sanal fonksiyon: 'virtual' anahtar kelimesi ile tanımlanır.
    // Bu, derleyicinin hangi 'sesCikar' fonksiyonunu çağıracağına
    // çalışma anında (runtime) karar vermesini sağlar.
    virtual void sesCikar() {
        std::cout << "Hayvan bir ses çıkarıyor." << std::endl;
    }

    // Sanal olmayan fonksiyon: Bu her zaman temel sınıfın fonksiyonunu çağırır.
    void yemekYe() {
        std::cout << "Hayvan yemek yiyor." << std::endl;
    }

    // Sanal Yıkıcı (Virtual Destructor): Miras hiyerarşisinde
    // türemiş sınıfların yıkıcılarının doğru şekilde çağrılması için önemlidir.
    virtual ~Hayvan() {
        std::cout << "Hayvan yıkıcısı çalıştı." << std::endl;
    }
};

// Türemiş Sınıf (Derived Class)
class Kedi : public Hayvan {
public:
    // Sanal fonksiyonu geçersiz kılma (override).
    // 'override' anahtar kelimesi opsiyoneldir ancak iyi bir pratik olup
    // derleyicinin hata yapmamanızı sağlamasına yardımcı olur.
    void sesCikar() override {
        std::cout << "Miyav! Miyav!" << std::endl;
    }

    ~Kedi() {
        std::cout << "Kedi yıkıcısı çalıştı." << std::endl;
    }
};

// Türemiş Sınıf (Derived Class)
class Kopek : public Hayvan {
public:
    void sesCikar() override {
        std::cout << "Hav! Hav!" << std::endl;
    }

    ~Kopek() {
        std::cout << "Köpek yıkıcısı çalıştı." << std::endl;
    }
};

int main() {
    // Hayvan tipinde bir pointer oluşturuyoruz.
    Hayvan* hayvanPtr;

    // 1. Kedi nesnesi oluşturup, pointer'ı bu nesneye atıyoruz.
    Kedi kediObj;
    hayvanPtr = &kediObj;
    std::cout << "--- Pointer bir Kedi nesnesine işaret ediyor ---" << std::endl;

    // Sanal Fonksiyon Çağrısı: Pointer 'Hayvan' tipinde olsa da,
    // işaret ettiği nesnenin ('Kedi') 'sesCikar' fonksiyonunu çağırır.
    hayvanPtr->sesCikar(); // Çıktı: Miyav! Miyav!

    // Sanal Olmayan Fonksiyon Çağrısı: Bu, her zaman temel sınıfın
    // 'yemekYe' fonksiyonunu çağırır.
    hayvanPtr->yemekYe(); // Çıktı: Hayvan yemek yiyor.

    std::cout << "\n";

    // 2. Köpek nesnesi oluşturup, pointer'ı bu nesneye atıyoruz.
    Kopek kopekObj;
    hayvanPtr = &kopekObj;
    std::cout << "--- Pointer bir Kopek nesnesine işaret ediyor ---" << std::endl;

    // Sanal Fonksiyon Çağrısı: İşaret ettiği nesne 'Kopek' olduğu için
    // 'Kopek' sınıfının 'sesCikar' fonksiyonunu çağırır.
    hayvanPtr->sesCikar(); // Çıktı: Hav! Hav!

    return 0;
}