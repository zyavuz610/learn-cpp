#include <iostream>

using namespace std;

// clockType sınıfının tanımı
class clockType {
public:
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
    
    // İki clockType nesnesinin eşit olup olmadığını kontrol eder
    // Fonksiyon, başka bir clockType nesnesini 'const' referans olarak alır.
    // 'const' kullanmak, nesnenin fonksiyon içinde değiştirilemeyeceğini garanti eder.
    // Bu, 'call by reference' yönteminin güvenli bir kullanımıdır.
    bool equalTime(const clockType& otherTime) const;

private:
    int hr;  // Saat
    int min; // Dakika
    int sec; // Saniye
};

// Sınıf metotlarının implementasyonu (uygulaması)

void clockType::setTime(int hours, int minutes, int seconds) {
    // Verilen değerlerin geçerli olup olmadığını kontrol eder
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
    // Zaman değerlerini referans parametreler aracılığıyla döndürür
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const {
    // Zamanı HH:MM:SS formatında yazdırır
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
    // İki saat nesnesinin saat, dakika ve saniye değerlerini karşılaştırır
    return (hr == otherTime.hr && min == otherTime.min && sec == otherTime.sec);
}

// Main fonksiyonu
int main() {
    clockType saat1;
    clockType saat2;
    int h, m, s;

    // Saat 1'in zamanını ayarlar
    saat1.setTime(10, 45, 30);
    cout << "Saat 1: ";
    saat1.printTime();
    cout << endl;

    // Saat 1'i 5 saniye artırır
    for (int i = 0; i < 5; ++i) {
        saat1.incrementSeconds();
    }
    cout << "Saat 1 (5 saniye sonra): ";
    saat1.printTime();
    cout << endl;

    // Saat 2'nin zamanını ayarlar
    saat2.setTime(10, 45, 35);
    cout << "Saat 2: ";
    saat2.printTime();
    cout << endl;
    
    // İki saatin eşitliğini kontrol eder
    if (saat1.equalTime(saat2)) {
        cout << "Saatler esit." << endl;
    } else {
        cout << "Saatler esit degil." << endl;
    }
    
    // Saat 1'in zamanını alır ve ekrana yazdırır
    saat1.getTime(h, m, s);
    cout << "Saat 1'in degerleri (degiskenlere atandi): " << h << ":" << m << ":" << s << endl;

    return 0;
}