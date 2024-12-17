#include <iostream>
using namespace std;

class Hayvan {
public:
    Hayvan() {
        cout << "Hayvan cstor fonksiyonu" << endl;
    }
    //virtual void sesCikar() { // Sanal fonksiyon
    void sesCikar() { // Normal fonksiyon
        cout << "Hayvan bir ses cikariyor." << endl;
    }
    ~Hayvan() {
        cout << "Hayvan dstor fonksiyonu" << endl;
    } // Sanal yıkıcı
};

class Kopek : public Hayvan {
public:
    Kopek() {
        cout << "Kopek cstor fonksiyonu" << endl;
    }
    void sesCikar(){
        cout << "Hav hav!" << endl;
    }
    ~Kopek() {
        cout << "Kopek dstor fonksiyonu" << endl;
    }
};

class Kedi : public Hayvan {
public:
    Kedi() {
        cout << "Kedi cstor fonksiyonu" << endl;
    }
    void sesCikar(){
        cout << "Miyav!" << endl;
    }
    ~Kedi() {
        cout << "Kedi dstor fonksiyonu" << endl;
    }
};



int main() {
    Hayvan* kopek = new Kopek();
    Hayvan* kedi = new Kedi();
    
    kopek->sesCikar(); // Hav hav!
    kedi->sesCikar(); // Miyav!
    
    delete kopek;
    delete kedi;
    return 0;
}

/*
problemli çıktı üretir, çünkü sesCikar() fonksiyonu sanal değil,
sanal olmadığı için türetilmiş sınıfların sesCikar() fonksiyonları çağrılmaz.
derleme zamanında hangi fonksiyonun çağrılacağı belli olduğu için
polimorfizm sağlanamaz.

çözüm: sesCikar() fonksiyonunu sanal yapmak
*/
