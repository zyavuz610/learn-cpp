#include "clockType.h"
#include <iostream>

// Bu, sınıfın implementasyon (uygulama) dosyasıdır.
// Burada, .h dosyasında bildirilen metotların kodları bulunur.
// Sınıfın iç işleyişi, bu dosyada gizlenir.

using namespace std;

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
    if (hr < 10) cout << "0";
    cout << hr << ":";
    if (min < 10) cout << "0";
    cout << min << ":";
    if (sec < 10) cout << "0";
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