#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H

// Bu, sınıfın arayüz (interface) dosyasıdır.
// Sadece sınıf tanımı ve metot prototipleri (imzaları) bulunur.
// Bu sayede, sınıfın nasıl kullanıldığı açıkça görülürken,
// iç işleyişi (implementasyonu) gizlenir.

class clockType {
public:
    // Yapıcı (constructor) metot
    clockType();

    // Setters ve Getters
    void setTime(int, int, int);
    void getTime(int&, int&, int&);

    // Diğer metotlar
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType& otherTime) const;

private:
    int hr;
    int min;
    int sec;
};

#endif // CLOCKTYPE_H