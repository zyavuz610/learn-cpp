#include <iostream>

using namespace std;

// clockType sınıfının tanımı ve implementasyonu
class clockType {
public:
    // Sınıfın kurucu (constructor) metodu
    // Nesne oluşturulduğunda ilk değerleri atar
    clockType() {
        hr = 0;
        min = 0;
        sec = 0;
    }

    // Zamanı ayarlar
    void setTime(int hours, int minutes, int seconds) {
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

    // Zamanı alır
    void getTime(int& hours, int& minutes, int& seconds) {
        hours = hr;
        minutes = min;
        seconds = sec;
    }

    // Zamanı ekrana yazdırır
    void printTime() const {
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

    // Saniyeyi 1 artırır
    void incrementSeconds() {
        sec++;
        if (sec >= 60) {
            sec = 0;
            incrementMinutes();
        }
    }

    // Dakikayı 1 artırır
    void incrementMinutes() {
        min++;
        if (min >= 60) {
            min = 0;
            incrementHours();
        }
    }

    // Saati 1 artırır
    void incrementHours() {
        hr++;
        if (hr >= 24) {
            hr = 0;
        }
    }
    
    // İki clockType nesnesinin eşit olup olmadığını kontrol eder
    bool equalTime(const clockType& otherTime) const {
        return (hr == otherTime.hr && min == otherTime.min && sec == otherTime.sec);
    }

private:
    int hr;  // Saat
    int min; // Dakika
    int sec; // Saniye
};

// Fonksiyon: Parametre olarak bir clockType nesnesi alır.
void testTime(const clockType& otherClock) {
    // Fonksiyon içinde yeni bir clockType nesnesi (dClock) oluşturulur.
    clockType dClock;

    // dClock'un zamanı, otherClock'un zamanına ayarlanır.
    dClock.setTime(otherClock.hr, otherClock.min, otherClock.sec);
    
    // NOT: Bu satır, public olsaydı çalışırdı:
    // dClock.hr = otherClock.hr;
    // Fakat 'hr' private olduğu için 'setTime' gibi public bir metod kullanılmalıdır.
    
    cout << "\n--- testTime fonksiyonu icinde ---" << endl;
    cout << "otherClock: ";
    otherClock.printTime();
    cout << endl;

    cout << "dClock: ";
    dClock.printTime();
    cout << endl;
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

    // testTime fonksiyonunu çağır
    testTime(saat1);

    return 0;
}