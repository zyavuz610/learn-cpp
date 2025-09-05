#include <iostream>

using namespace std;

// clockType sınıfının tanımı
class clockType {
public:
    // Yapıcı metot (Constructor)
    // Nesne oluşturulduğunda değişkenleri 0'a atar
    clockType(); 

    // Zamanı ayarlar
    void setTime(int, int, int);
    // Zamanı alır
    void getTime(int&, int&, int&);
    // Zamanı ekrana yazdırır
    void printTime() const;
    // Saniyeyi 1 artırır
    void incrementSeconds();
    // Dakikayı 1 artırır
    void incrementMinutes();
    // Saati 1 artırır
    void incrementHours();
    // İki saatin eşit olup olmadığını kontrol eder
    bool equalTime(const clockType& otherTime) const;

private:
    int hr;  // Saat
    int min; // Dakika
    int sec; // Saniye
};

// Sınıf metotlarının implementasyonu

clockType::clockType() {
    hr = 0;
    min = 0;
    sec = 0;
}

void clockType::setTime(int hours, int minutes, int seconds) {
    if (hours >= 0 && hours < 24) {
        hr = hours;
    } else {
        hr = 0;
    }

    if (minutes >= 0 && minutes < 60) {
        min = minutes;
    } else {
        min = 0;
    }

    if (seconds >= 0 && seconds < 60) {
        sec = seconds;
    } else {
        sec = 0;
    }
}

void clockType::getTime(int& hours, int& minutes, int& seconds) {
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const {
    if (hr < 10) {
        cout << "0";
    }
    cout << hr << ":";
    
    if (min < 10) {
        cout << "0";
    }
    cout << min << ":";

    if (sec < 10) {
        cout << "0";
    }
    cout << sec;
}

void clockType::incrementSeconds() {
    sec++;
    if (sec >= 60) {
        sec = 0;
        incrementMinutes();
    }
}

void clockType::incrementMinutes() {
    min++;
    if (min >= 60) {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementHours() {
    hr++;
    if (hr >= 24) {
        hr = 0;
    }
}

bool clockType::equalTime(const clockType& otherTime) const {
    return (hr == otherTime.hr && min == otherTime.min && sec == otherTime.sec);
}

// ---
// Harici Fonksiyon
// clockType dizisindeki tüm saatleri ekrana yazdırır
void printAllTimes(clockType clocks[], int size) {
    cout << "--- Tum Saatler ---" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Saat " << i + 1 << ": ";
        clocks[i].printTime();
        cout << endl;
    }
}

// ---
// Main Fonksiyonu
int main() {
    // 5 elemanlı bir clockType dizisi oluştur
    // Dizi oluşturulduğunda, her bir elemanın kurucu metodu çağrılır ve saat 00:00:00 olur.
    clockType saatler[5];

    // Dizinin başlangıç halini yazdır
    cout << "Dizi olusturulduktan sonra:" << endl;
    printAllTimes(saatler, 5);

    // Dizi elemanlarının değerlerini değiştir
    cout << "\nBazı saatlerin degerleri degistiriliyor..." << endl;
    saatler[0].setTime(15, 30, 0);
    saatler[1].setTime(20, 15, 45);
    saatler[3].setTime(8, 0, 0);

    // İkinci saati (indis 1) 1 dakika artır
    cout << "\nSaat 2 (indis 1) 1 dakika artiriliyor." << endl;
    saatler[1].incrementMinutes();

    // Dizinin son halini yazdır
    cout << "\nSaatler guncellendikten sonra:" << endl;
    printAllTimes(saatler, 5);

    return 0;
}