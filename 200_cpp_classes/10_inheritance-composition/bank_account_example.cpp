/*
    Kapsamli OOP Ornegi: Kalitim (Inheritance) + Bilesim (Composition) + Operator Overloading
    -----------------------------------------------------------------------------------------
    - Temel Sinif (Base Class)       : BankAccount (name, accountValue, getter/setter, print, operator overloading)
    - Turetilmis Siniflar (IS-A)     : VadeliHesap : public BankAccount
                                       VadesizHesap : public BankAccount
    - Kapsayici Sinif (HAS-A)        : IsYeri (1 adet VadesizHesap + 1 adet VadeliHesap barindirir)

    Derleme:
        g++ -std=c++17 -Wall -Wextra bank_account_example.cpp -o bank_app
    Calistirma:
        ./bank_app      (Linux / macOS / Git Bash)
        .\bank_app.exe  (Windows PowerShell / CMD)
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ============================================================================
// 1. TEMEL SINIF (BASE CLASS): BankAccount
// ============================================================================
class BankAccount {
protected:
    string name;
    double accountValue;

public:
    // Kurucu (Constructor) - Varsayilan argumanli
    BankAccount(const string& name = "Tanimsiz Hesap", double accountValue = 0.0)
        : name(name), accountValue(accountValue >= 0.0 ? accountValue : 0.0) {
        cout << "[+] BankAccount kurucusu calisti -> " << this->name << endl;
    }

    // Yikici (Destructor)
    ~BankAccount() {
        cout << "[-] BankAccount yikicisi calisti -> " << name << endl;
    }

    // --- Getter & Setter Metotlari ---
    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        if (!newName.empty()) {
            name = newName;
        }
    }

    double getAccountValue() const {
        return accountValue;
    }

    void setAccountValue(double value) {
        if (value >= 0.0) {
            accountValue = value;
        } else {
            cout << "[Uyari] Bakiye negatif olamaz! Deger degistirilmedi." << endl;
        }
    }

    // --- Temel Hesap Islemleri ---
    void deposit(double amount) {
        if (amount > 0.0) {
            accountValue += amount;
        } else {
            cout << "[Uyari] Yatirilacak tutar pozitif olmalidir." << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0.0) {
            cout << "[Uyari] Cekilecek tutar pozitif olmalidir." << endl;
            return false;
        }
        if (amount > accountValue) {
            cout << "[Uyari] Yetersiz bakiye (" << name << ")!" << endl;
            return false;
        }
        accountValue -= amount;
        return true;
    }

    // --- Yazdirma Metodu ---
    void print() const {
        cout << fixed << setprecision(2);
        cout << "Hesap Adi    : " << name << "\n"
             << "Bakiye       : " << accountValue << " TL" << endl;
    }

    // --- Operator Asiri Yukleme (Operator Overloading) ---

    // += operatoru: Hesaba para yatirma
    BankAccount& operator+=(double amount) {
        deposit(amount);
        return *this;
    }

    // -= operatoru: Hesaptan para cekme
    BankAccount& operator-=(double amount) {
        withdraw(amount);
        return *this;
    }

    // + operatoru: Iki hesabin bakiyelerini toplayarak ozet bir BankAccount dondurur
    BankAccount operator+(const BankAccount& other) const {
        return BankAccount(this->name + " + " + other.name,
                           this->accountValue + other.accountValue);
    }

    // Iliskisel operatorler (Bakiye karsilastirmasi)
    bool operator==(const BankAccount& other) const {
        return this->accountValue == other.accountValue;
    }

    bool operator>(const BankAccount& other) const {
        return this->accountValue > other.accountValue;
    }

    bool operator<(const BankAccount& other) const {
        return this->accountValue < other.accountValue;
    }

    // << akis cikis operatoru (friend)
    friend ostream& operator<<(ostream& os, const BankAccount& acc) {
        os << fixed << setprecision(2)
           << "[" << acc.name << " | Bakiye: " << acc.accountValue << " TL]";
        return os;
    }
};

// ============================================================================
// 2. TURETILMIS SINIF 1 (IS-A): VadeliHesap (Term / Savings Account)
// ============================================================================
class VadeliHesap : public BankAccount {
private:
    double interestRate; // Yillik faiz orani (orn. 0.45 -> %45)
    int maturityDays;    // Vade suresi (gun)

public:
    VadeliHesap(const string& name = "Vadeli Hesap",
                double accountValue = 0.0,
                double interestRate = 0.40,
                int maturityDays = 30)
        : BankAccount(name, accountValue),
          interestRate(interestRate >= 0.0 ? interestRate : 0.0),
          maturityDays(maturityDays > 0 ? maturityDays : 30) {
        cout << "[+] VadeliHesap kurucusu calisti -> " << this->name << endl;
    }

    ~VadeliHesap() {
        cout << "[-] VadeliHesap yikicisi calisti -> " << name << endl;
    }

    // Getter & Setter
    double getInterestRate() const { return interestRate; }
    void setInterestRate(double rate) {
        if (rate >= 0.0) interestRate = rate;
    }

    int getMaturityDays() const { return maturityDays; }
    void setMaturityDays(int days) {
        if (days > 0) maturityDays = days;
    }

    // Vade sonu tahmini basit faiz getirisi
    double calculateInterest() const {
        return accountValue * interestRate * (static_cast<double>(maturityDays) / 365.0);
    }

    // Vade doldugunda faizi ana paraya ekle
    void applyInterest() {
        double gain = calculateInterest();
        accountValue += gain;
        cout << fixed << setprecision(2)
             << "[Bilgi] " << name << " hesabina " << gain
             << " TL faiz islendi. Yeni bakiye: " << accountValue << " TL" << endl;
    }

    // Temel sinifin print() metodunu genisletme (Method Hiding / Redefining)
    void print() const {
        cout << "--- Vadeli Hesap Bilgileri ---" << endl;
        BankAccount::print();
        cout << fixed << setprecision(2)
             << "Faiz Orani   : %" << (interestRate * 100.0) << "\n"
             << "Vade Suresi  : " << maturityDays << " gun\n"
             << "Tahmini Faiz : " << calculateInterest() << " TL" << endl;
    }

    friend ostream& operator<<(ostream& os, const VadeliHesap& acc) {
        os << fixed << setprecision(2)
           << "[Vadeli: " << acc.name
           << " | Bakiye: " << acc.accountValue << " TL"
           << " | Faiz: %" << (acc.interestRate * 100.0)
           << " | Vade: " << acc.maturityDays << " gun]";
        return os;
    }
};

// ============================================================================
// 3. TURETILMIS SINIF 2 (IS-A): VadesizHesap (Checking / Demand Account)
// ============================================================================
class VadesizHesap : public BankAccount {
private:
    double overdraftLimit; // Ek hesap (KMH) limiti
    double transactionFee; // Havale / islem ucreti

public:
    VadesizHesap(const string& name = "Vadesiz Hesap",
                 double accountValue = 0.0,
                 double overdraftLimit = 5000.0,
                 double transactionFee = 10.0)
        : BankAccount(name, accountValue),
          overdraftLimit(overdraftLimit >= 0.0 ? overdraftLimit : 0.0),
          transactionFee(transactionFee >= 0.0 ? transactionFee : 0.0) {
        cout << "[+] VadesizHesap kurucusu calisti -> " << this->name << endl;
    }

    ~VadesizHesap() {
        cout << "[-] VadesizHesap yikicisi calisti -> " << name << endl;
    }

    // Getter & Setter
    double getOverdraftLimit() const { return overdraftLimit; }
    void setOverdraftLimit(double limit) {
        if (limit >= 0.0) overdraftLimit = limit;
    }

    double getTransactionFee() const { return transactionFee; }
    void setTransactionFee(double fee) {
        if (fee >= 0.0) transactionFee = fee;
    }

    // Ek hesap limiti dahil para cekme
    bool withdraw(double amount) {
        if (amount <= 0.0) {
            cout << "[Uyari] Cekilecek tutar pozitif olmalidir." << endl;
            return false;
        }
        if (amount > accountValue + overdraftLimit) {
            cout << "[Uyari] Bakiye + ek hesap limiti yetersiz (" << name << ")!" << endl;
            return false;
        }
        accountValue -= amount;
        return true;
    }

    // Baska bir hesaba islem ucreti ile havale yapma
    bool transferTo(BankAccount& target, double amount) {
        double totalCost = amount + transactionFee;
        if (withdraw(totalCost)) {
            target.deposit(amount);
            cout << fixed << setprecision(2)
                 << "[Transfer] " << name << " -> " << target.getName()
                 << " : " << amount << " TL (Islem ucreti: "
                 << transactionFee << " TL)" << endl;
            return true;
        }
        return false;
    }

    void print() const {
        cout << "--- Vadesiz Hesap Bilgileri ---" << endl;
        BankAccount::print();
        cout << fixed << setprecision(2)
             << "Ek Limit     : " << overdraftLimit << " TL\n"
             << "Islem Ucreti : " << transactionFee << " TL" << endl;
    }

    friend ostream& operator<<(ostream& os, const VadesizHesap& acc) {
        os << fixed << setprecision(2)
           << "[Vadesiz: " << acc.name
           << " | Bakiye: " << acc.accountValue << " TL"
           << " | Ek Limit: " << acc.overdraftLimit << " TL]";
        return os;
    }
};

// ============================================================================
// 4. KAPSAYICI SINIF (COMPOSITION / HAS-A): IsYeri
//    Bir is yerinin 2 adet hesabi vardir: 1 VadesizHesap + 1 VadeliHesap
// ============================================================================
class IsYeri {
private:
    string companyName;
    string taxNumber;
    VadesizHesap vadesizHesap; // 1. Hesap (Bildirim sirasi: once VadesizHesap)
    VadeliHesap vadeliHesap;   // 2. Hesap (Bildirim sirasi: sonra VadeliHesap)

public:
    // Uye baslatma listesi (Member Initializer List) ile iki hesabin baslatilmasi
    IsYeri(const string& companyName,
           const string& taxNumber,
           double vadesizBakiye,
           double ekLimit,
           double vadeliBakiye,
           double faizOrani,
           int vadeGun)
        : companyName(companyName),
          taxNumber(taxNumber),
          vadesizHesap(companyName + " - Vadesiz", vadesizBakiye, ekLimit, 15.0),
          vadeliHesap(companyName + " - Vadeli", vadeliBakiye, faizOrani, vadeGun) {
        cout << "[+] IsYeri kurucusu calisti -> " << this->companyName << endl;
    }

    ~IsYeri() {
        cout << "[-] IsYeri yikicisi calisti -> " << companyName << endl;
    }

    // Getter & Setter
    string getCompanyName() const { return companyName; }
    void setCompanyName(const string& name) {
        if (!name.empty()) companyName = name;
    }

    string getTaxNumber() const { return taxNumber; }

    // Hesaplara erisim (Delegation / dogrudan islem icin referans donusu)
    VadesizHesap& getVadesizHesap() { return vadesizHesap; }
    const VadesizHesap& getVadesizHesap() const { return vadesizHesap; }

    VadeliHesap& getVadeliHesap() { return vadeliHesap; }
    const VadeliHesap& getVadeliHesap() const { return vadeliHesap; }

    // Iki hesabin toplam bakiyesi (Yetki devri / Delegation)
    double getTotalBalance() const {
        return vadesizHesap.getAccountValue() + vadeliHesap.getAccountValue();
    }

    // Vadesiz hesaptan vadeli hesaba aktarim
    void transferToVadeli(double amount) {
        vadesizHesap.transferTo(vadeliHesap, amount);
    }

    // Is yeri genel mali raporu
    void printReport() const {
        cout << "\n==============================================" << endl;
        cout << "IS YERI MALI RAPORU" << endl;
        cout << "Sirket Adi : " << companyName << " (VKN: " << taxNumber << ")" << endl;
        cout << "==============================================" << endl;
        vadesizHesap.print();
        cout << endl;
        vadeliHesap.print();
        cout << "----------------------------------------------" << endl;
        cout << fixed << setprecision(2)
             << "TOPLAM SIRKET VARLIGI : " << getTotalBalance() << " TL" << endl;
        cout << "==============================================\n" << endl;
    }
};

// ============================================================================
// MAIN: Kalitim, Bilesim ve Operator Overloading Testi
// ============================================================================
int main() {
    cout << "=== 1. NESNE OLUSTURMA (KURUCU CAGRI SIRASI) ===" << endl;
    IsYeri sirket("KTU Teknoloji A.S.", "1234567890",
                  40000.0, 10000.0,   // Vadesiz: 40.000 TL bakiye, 10.000 TL ek limit
                  120000.0, 0.42, 90  // Vadeli : 120.000 TL bakiye, %42 faiz, 90 gun vade
    );

    // Baslangic raporu
    sirket.printReport();

    cout << "=== 2. OPERATOR OVERLOADING TESTLERI ===" << endl;
    // += ve -= operatorleri (BankAccount'tan miras alindi)
    sirket.getVadesizHesap() += 15000.0; // Satis geliri yatirildi
    sirket.getVadesizHesap() -= 5000.0;  // Fatura odendi

    // << operatoru ile hizli yazdirma
    cout << "Guncel Vadesiz: " << sirket.getVadesizHesap() << endl;
    cout << "Guncel Vadeli : " << sirket.getVadeliHesap() << endl;

    // Iliskisel operatorler (>, <, ==)
    if (sirket.getVadeliHesap() > sirket.getVadesizHesap()) {
        cout << "Karsilastirma : Vadeli hesap bakiyesi vadesiz hesaptan buyuktur." << endl;
    } else if (sirket.getVadeliHesap() == sirket.getVadesizHesap()) {
        cout << "Karsilastirma : Iki hesabin bakiyesi esittir." << endl;
    } else {
        cout << "Karsilastirma : Vadesiz hesap bakiyesi vadeli hesaptan buyuktur." << endl;
    }

    // + operatoru ile iki hesabin toplamini tek bir BankAccount nesnesinde toplama
    BankAccount toplamOzet = sirket.getVadesizHesap() + sirket.getVadeliHesap();
    cout << "Toplam Ozet   : " << toplamOzet << "\n" << endl;

    cout << "=== 3. GETTER/SETTER VE ALT SINIF METOTLARI ===" << endl;
    // Vadeli hesap faiz oranini guncelle ve vade sonu faizini islet
    sirket.getVadeliHesap().setInterestRate(0.45);
    sirket.getVadeliHesap().applyInterest();

    // Vadesiz hesaptan vadeli hesaba transfer (15 TL islem ucreti ile)
    sirket.transferToVadeli(20000.0);

    // Son rapor
    sirket.printReport();

    cout << "=== 4. PROGRAM SONU (YIKICI CAGRI SIRASI) ===" << endl;
    return 0;
}
