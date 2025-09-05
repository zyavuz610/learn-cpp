#include <iostream>
#include "clockType.h" // Sınıfın arayüzünü (tanımını) dahil et

// Bu dosya, programın ana mantığını içerir ve sınıfı kullanır.
// Implementasyon detaylarına erişimi yoktur.

/*
Derlemek için:
g++ imp-hiding.cpp clockType.cpp -o saat_programi
*/
using namespace std;

int main() {
    clockType saat1;
    clockType saat2;

    saat1.setTime(10, 45, 30);
    saat2.setTime(10, 45, 35);
    
    cout << "Saat 1: ";
    saat1.printTime();
    cout << endl;

    cout << "Saat 2: ";
    saat2.printTime();
    cout << endl;

    if (saat1.equalTime(saat2)) {
        cout << "Saatler esit." << endl;
    } else {
        cout << "Saatler esit degil." << endl;
    }

    // Saat 1'i 5 saniye artır
    cout << "Saat 1, 5 saniye artiriliyor..." << endl;
    for (int i = 0; i < 5; ++i) {
        saat1.incrementSeconds();
    }
    
    cout << "Saat 1: ";
    saat1.printTime();
    cout << endl;

    if (saat1.equalTime(saat2)) {
        cout << "Saatler esit." << endl;
    } else {
        cout << "Saatler esit degil." << endl;
    }
    
    return 0;
}