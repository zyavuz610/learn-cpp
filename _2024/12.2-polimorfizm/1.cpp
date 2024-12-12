#include <iostream>
using namespace std;

class Hayvan {
public:
    Hayvan() {
        cout << "Hayvan cstor fonksiyonu" << endl;
    }
    //virtual void sesCikar() { // Sanal fonksiyon
    void sesCikar() { // Normal fonksiyon
        cout << "Hayvan bir ses çıkarıyor." << endl;
    }
    virtual ~Hayvan() {
        cout << "Hayvan dstor fonksiyonu" << endl;
    } // Sanal yıkıcı
};

class Kopek : public Hayvan {
public:
    Kopek() {
        cout << "Kopek cstor fonksiyonu" << endl;
    }
    void sesCikar() override {
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
    void sesCikar() override {
        cout << "Miyav!" << endl;
    }
    ~Kedi() {
        cout << "Kedi dstor fonksiyonu" << endl;
    }
};



int main() {
    Hayvan* h1 = new Kopek();
    Hayvan* h2 = new Kedi();
    
    sesCikart(h1); // Kopek'in sesCikar fonksiyonu çağrılır
    sesCikart(h2); // Kedi'nin sesCikar fonksiyonu çağrılır
    
    delete h1;
    delete h2;
    return 0;
}
