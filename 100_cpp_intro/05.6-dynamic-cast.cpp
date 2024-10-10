    // dynamic_cast, özellikle kalıtım (inheritance) yapısında, işaretçiler veya referanslar arasında tür dönüşümünde kullanılır. dynamic_cast bir downcasting işlemi yapar ve bu, çalışma zamanı (runtime) kontrolü gerektirir. Eğer dönüşüm başarısız olursa, nullptr döner.

    #include <iostream>

class Base {
public:
    virtual void show() { std::cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class\n"; }
};

int main() {
    Base* basePtr = new Derived();  // Base türünde işaretçi, Derived nesnesini işaret ediyor.
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // dynamic_cast ile dönüşüm

    if (derivedPtr) {
        derivedPtr->show();  // Başarılı dönüşüm, Derived class fonksiyonu çağrılır.
    } else {
        std::cout << "Dönüşüm başarısız!\n";
    }

    delete basePtr;
    return 0;
}
