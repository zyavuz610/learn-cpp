/*
Son Güncelleme Tarihi: 21.12.2018 (15:05)
Icerigi:Basit matris islemlerini nesne yapisini kullanarak gerceklestirmek.
Programın Sahibi:Muhammed Yusuf YUCEDAG (365335)
Mail:ysfycd3@gmail.com
    :365335@ogr.ktu.edu.tr
*/

#include<iostream>
#include <ctime>
#include<string>
#include<fstream>
using namespace std;


class matris { //matris sinifi
public:
	matris(); // 100 x 100 matris
	matris(int);// kare matris
	matris(int , int);//axb matris
	void setij(int , int, double);//a[i][j]=x;
	double getij(int , int);// return a[i][j];
	void zeros();//elemanlara sıfır degeri atanması
	void ones();//elemanlara bir degeri atanması
	void random(int , int );//a-b arası random değer atanması
	void random();//elemanlara random degerler atama
	void set_label1(string , int );//satır etiketi setleme
	void set_label2(string , int );//sutun etiketi setleme
	int get_satir();
	int get_sutun();
	string& get_label1(int );//satır etiketi getleme
	string& get_label2(int );//sutun etiketi getleme
	void set_infos(string , string , double );
	double get_info(string , string );

	friend void print(matris );//etiketli matris print
	friend void print(matris  , string );//matematiksel matris print

	void operator()(string, string, double);
	double operator()(string, string );
	matris operator *(matris);
	matris operator +(matris);
	matris operator -(matris);
	matris operator ^(char);

protected:
	string* label1;
	string* label2;
	double** m;
	int satir;
	int sutun;
};
class lesson : public matris {
public:
	lesson(int,int,string);
	void set_arasinav(int,double);
	void set_final(int,double);
	void set_ortalama(int,double);
	double* get_ortalama();
	double* get_arasinav();
	double* get_final();
	void set_number(int,string);
	string* get_number();
	string* get_harfli();
	matris* get_matris();
	friend istream &operator>>(istream &, lesson&);
	friend ostream &operator<<(ostream &, lesson&);
	friend void printlesson(lesson);

private:
	string ders;
	matris* mtr;
	double* arasinav;
	double* final;
	double* ortalama;
	string* number;
	string* harfli;
	
};

matris* lesson::get_matris() {
	return mtr;
}
lesson::lesson(int a, int b,string s) {
	mtr = new matris(a, b);
	ders = s;
}
void lesson::set_arasinav(int i,double d) {
	arasinav[i] = d;
}
void lesson::set_final(int i,double d) {
	final[i] = d;
}
void lesson::set_ortalama(int i,double d) {
	ortalama[i] = d;
}
double* lesson::get_ortalama() {
	return ortalama;
}
double* lesson::get_arasinav() {
	return arasinav;
}
double* lesson::get_final() {
	return final;
}
void lesson::set_number(int i,string s) {
	number[i] = s;
}
string* lesson::get_number() {
	return number;
}
string* lesson::get_harfli() {
	return harfli;
}
void printlesson(lesson less) {
	double toplam = 0;
	int kalan=0, gecen=0;
	matris m = *less.mtr;
	cout <<less.ders<< " Tablo Bilgisi:\n\n\t\t";
	for (int i = 0; i < m.get_sutun(); i++) {
		cout << m.get_label2(i) << "\t\t";
	}
	for (int i = 0; i < m.get_satir(); i++) {
		cout << "\n" << m.get_label1(i) << "\t\t";
		for (int j = 0; j < m.get_sutun(); j++) {
			cout << m.get_info(m.get_label1(i), m.get_label2(j)) << "\t\t";
		}
		cout << less.harfli[i];
		if (less.harfli[i] == "FF" || less.harfli[i] == "FD" || less.harfli[i] == "DD") {
			cout << "\tKALDI";
			kalan++;
		}
		else {
			cout << "\tGECTI";
			gecen++;
		}
		toplam += less.ortalama[i];
	}
	cout << "\n\nSinif Ortalamasi : " << toplam / less.satir << endl
		<< "Gecen ogrenci sayisi : "<<gecen << endl
		<< "Kalan ogrenci sayisi : " << kalan << endl;
}
istream &operator>>(istream &input, lesson& less) {
	string temp;
	int size,count=0;

	size = less.mtr->get_satir();
	less.arasinav = new double[size];
	less.final = new double[size];
	less.number = new string[size];
	less.ortalama = new double[size];
	less.harfli = new string[size];

	while (!input.eof() && count<size) {
		input >> temp;
		less.number[count] = temp;
		input >> temp;
		less.arasinav[count] = stod(temp);
		input >> temp;
		less.final[count] = stod(temp);
		less.ortalama[count] = (less.arasinav[count] + less.final[count]) / 2;
		count++;
	}
	less.mtr->set_label2("Vize",0);
	less.mtr->set_label2("Final", 1);
	less.mtr->set_label2("Ortalama", 2);

	for (int i = 0; i < size; i++) {
		less.mtr->set_label1(less.number[i], i);
		less.mtr->setij(i, 0, less.arasinav[i]);
		less.mtr->setij(i, 1, less.final[i]);
		less.mtr->setij(i, 2, less.ortalama[i]);
		
		if (less.final[i] >= 45){
			if      (less.ortalama[i] <= 100 && less.ortalama[i] >= 90)less.harfli[i] = "AA";
			else if (less.ortalama[i] <= 89 && less.ortalama[i] >= 80)less.harfli[i] = "BA";
			else if (less.ortalama[i] <= 79 && less.ortalama[i] >= 75)less.harfli[i] = "BB";
			else if (less.ortalama[i] <= 74 && less.ortalama[i] >= 70)less.harfli[i] = "CB";
			else if (less.ortalama[i] <= 69 && less.ortalama[i] >= 60)less.harfli[i] = "CC";
			else if (less.ortalama[i] <= 59 && less.ortalama[i] >= 50)less.harfli[i] = "DC";
			else if (less.ortalama[i] <= 49 && less.ortalama[i] >= 40)less.harfli[i] = "DD";
			else if (less.ortalama[i] <= 39 && less.ortalama[i] >= 30)less.harfli[i] = "FD";
			else if (less.ortalama[i] <= 29) less.harfli[i] = "FF";
			else less.harfli[i] = "FF";
		}
		else less.harfli[i] = "FF";
	}
	return input;
}
ostream &operator<<(ostream &output, lesson &less) {
	double toplam = 0;
	int kalan = 0, gecen = 0;
	matris m = *less.mtr;
	output << less.ders << " Tablo Bilgisi:\n\n\t\t\t";
	for (int i = 0; i < m.get_sutun(); i++) {
		output << m.get_label2(i) << "\t";
	}
	for (int i = 0; i < m.get_satir(); i++) {
		output << "\n" << m.get_label1(i) << "\t\t";
		for (int j = 0; j < m.get_sutun(); j++) {
			output << m.get_info(m.get_label1(i), m.get_label2(j)) << "\t\t";
		}
		output << "\t\t"<<less.harfli[i];
		if (less.harfli[i] == "FF" || less.harfli[i] == "FD" || less.harfli[i] == "DD") {
			output << "\tKALDI";
			kalan++;
		}
		else {
			output << "\tGECTI";
			gecen++;
		}
		toplam += less.ortalama[i];
	}
	output << "\n\nSinif Ortalamasi : " << toplam / less.satir << "\n"
		<< "Gecen ogrenci sayisi : " << gecen << "\n"
		<< "Kalan ogrenci sayisi : " << kalan << "\n";

	return output;
}


void print(matris m, string s) {//olusturdugumuz matrisin eleman degerlerini cikti olarak yazdirir

	cout << "olusturulan matris :" << endl<<endl;

	for (int j = 0; j < m.satir; j++) {
		cout << "  |\t";
		for (int k = 0; k < m.sutun; k++) {
			cout << m.m[j][k] << "\t";
		}
		cout << "|";
		cout << endl;
	}
	cout << endl;
}
void print(matris m) {
	cout << "Tablo bilgisi:\n\n\t\t\t";
	for (int i = 0; i < m.sutun; i++) {
		cout << m.get_label2(i) << "\t\t";
	}
	for (int i = 0; i < m.satir; i++) {
		cout << "\n" << m.get_label1(i) << "\t\t";
		for (int j = 0; j < m.sutun; j++) {
			cout << m.get_info(m.get_label1(i), m.get_label2(j)) << "\t\t";
		}
	}
cout << endl << endl;
}
matris matris::operator-(matris mtr) {
	if (satir != mtr.satir && sutun != mtr.sutun) {
		cout << "bu işlem yapilamaz " << endl;
		cout << "Girilen matrislerin boyutları aynı olmalıdır." << endl;
		getchar();
		exit(-1);
	}
	matris b(satir, sutun);
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			b.m[i][j] = m[i][j] - mtr.m[i][j];
		}
	}
	return b;
}
matris matris::operator+(matris mtr) {
	if (satir != mtr.satir && sutun != mtr.sutun) {
		cout << "bu işlem yapilamaz " << endl;
		cout << "Girilen matrislerin boyutları aynı olmalıdır." << endl;
		getchar();
		exit(-1);
	}
	matris b(satir, sutun);
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			b.m[i][j] = m[i][j] + mtr.m[i][j];
		}
	}
	return b;
}
matris matris::operator *(matris m) {
	if (sutun != m.satir)
	{
		cout << "bu işlem yapilamaz " << endl;
		cout << "1. matrisin sutun sayisi 2. matrisin satir sayisina eşit olmali" << endl;
		exit(-1);
	}
	matris mtr(satir, m.sutun);
	mtr.zeros();
	double temp = 0;

	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < m.sutun; j++) {
			for (int k = 0; k < sutun; k++) {
				temp = mtr.getij(i, j) + getij(i, k) * m.getij(k, j);
				mtr.setij(i, j, temp);
			}
		}
	}
	return mtr;
}
matris matris::operator ^(char c) {
	matris mtr(sutun,satir);

	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			mtr.m[j][i] = m[i][j];
		}
	}
	return mtr;
}
void matris::operator()(string s1, string s2, double d) {
	int i, j;
	for (i = 0; i < satir; i++) if (get_label1(i) == s1) break;
	for (j = 0; j < sutun; j++) if (get_label2(j) == s2) break;
	setij(i, j, d);
}
double matris::operator()(string s1, string s2){
	int i, j;
	for (i = 0; i < satir; i++) if (get_label1(i) == s1) break;
	for (j = 0; j < sutun; j++) if (get_label2(j) == s2) break;
	return getij(i, j);
}
matris::matris(){//constructor fonk1 satir ve sutunu setler ve 100 x 100 luk bir matris olusturur
	label1 = new string[100];
	label2 = new string[100];
	satir = sutun = 100;
	m = new double*[100];
	for (int i = 0; i < 100; i++) {
		m[i] = new double[100];
	}
}
matris::matris(int boyut) {//constructor fonk2 satir ve sutunu setler ve boyut x boyut luk bir matris olusturur
	label1 = new string[boyut];
	label2 = new string[boyut];
	satir = sutun = boyut;
	m = new double*[boyut];
	for (int i = 0; i < boyut; i++) {
		m[i] = new double[boyut];
	}
}
matris::matris(int boyut1, int boyut2) {//constructor fonk1 satir ve sutunu setler ve boyut1 x boyut2 lik bir matris olusturur
	label1 = new string[boyut1];
	label2 = new string[boyut2];
	satir = boyut1;
	sutun = boyut2;
	m = new double*[boyut1];
	for (int i = 0; i < boyut1; i++) {
		m[i] = new double[boyut2];
	}
}
void matris::setij(int i, int j, double x) {//olusturdugumuz sinif uyesinin m[i][j] adresli bolgesine x degerini setler
	m[i][j] = x;
}
double matris::getij(int i, int j) {//olusturdugumuz sinif uyesinin m[i][j] adresli bolgesinin icerik degerini getler
	return m[i][j];
}
void matris::zeros() {//olusturdugumuz sinif uyesinin butun adreslerinin icerigini 0 olarak setler
	for (int j = 0; j < satir; j++) {
		for (int k = 0; k < sutun; k++) {
			m[j][k] = 0;
		}
	}
}
void matris::ones() {
	for (int j = 0; j < satir; j++) {
		for (int k = 0; k < sutun; k++) {
			m[j][k] = 1;
		}
	}
}
void matris::random(int aralik1, int aralik2) {//olusturdugumuz diziye istenilen araliklarda degerler setler
	srand((unsigned)time(NULL));//her seferinde farkli rakamlar uretmesi icin
	for (int j = 0; j < satir; j++) {
		for (int k = 0; k < sutun; k++) {
			m[j][k] = rand() % (aralik2 - aralik1 + 1) + aralik1;
		}
	}
}
void matris::random() {//olusturdugumuz diziye random degerler setler
	srand((unsigned)time(NULL));//her seferinde farkli rakamlar uretmesi icin
	for (int j = 0; j < satir; j++) {
		for (int k = 0; k < sutun; k++) {
			m[j][k] = rand()/10.47;
		}
	}
}
void matris::set_label1(string s, int i) {
	label1[i] = s;
}
void matris::set_label2(string s, int i) {
	label2[i] = s;
}
int matris::get_satir() {
	return satir;

}
int matris::get_sutun() {
	return sutun;
}
string& matris::get_label1(int i) {
	return label1[i];
}
string& matris::get_label2(int i) {
	return label2[i];
}
void matris::set_infos(string s1, string s2, double d) {
	int i, j;
	for ( i = 0; i < satir; i++) if (get_label1(i) == s1) break;
	for ( j = 0; j < sutun; j++) if (get_label2(j) == s2) break;
	setij(i, j, d);

}
double matris::get_info(string s1, string s2) {
	int i, j;
	for (i = 0; i < satir; i++) if (get_label1(i) == s1) break;
	for (j = 0; j < sutun; j++) if (get_label2(j) == s2) break;
	return getij(i, j);
}




int main() {

  //EXAMPLE 1: Matris sinifinin get ve set fonksiyonlari ile
  //		 matris uzerinde islemler(deger atama ,deger alma,yazdirma).
  /*matris m1(4);
	m1.random(1,10);
	print(m1,"math");
	cout << "\nSetlendikten sonra matris:\n"<<endl;
	m1.setij(3, 3, 100);
	print(m1,"math");
	cout <<"\nAranan konumun degeri: " <<m1.getij(3, 3) << endl;*/

   //EXAMPLE 2: Satir ve sutun etiketleri ile () operatorunun asiri
   //         yuklenmesi sonucu basit islemler gerceklestirmek.
  /*matris table(3, 4);
	table.set_label1("Veri yapıları", 0);
	table.set_label1("Sayısal Tasarım", 1);
	table.set_label1("Ayrık Matematik", 2);
	table.set_label2("Kredi", 0);
	table.set_label2("Vize", 1);
	table.set_label2("Final", 2);
	table.set_label2("Ortalama", 3);

	table("Veri yapıları"  , "Kredi", 3);
	table("Sayısal Tasarım", "Kredi", 4);
	table("Ayrık Matematik", "Kredi", 3);

	table("Veri yapıları"  , "Vize", 26.5);
	table("Sayısal Tasarım", "Vize", 32.5);
	table("Ayrık Matematik", "Vize",23.48);

	table("Veri yapıları"  , "Final", 31.33);
	table("Sayısal Tasarım", "Final", 38.89);
	table("Ayrık Matematik", "Final", 40.47);

	double ort1 = (table("Veri yapıları"  , "Vize") + table("Veri yapıları", "Final"  )) / 2;
	double ort2 = (table("Sayısal Tasarım", "Vize") + table("Sayısal Tasarım", "Final")) / 2;
	double ort3 = (table("Ayrık Matematik", "Vize") + table("Ayrık Matematik", "Final")) / 2;

	table("Veri yapıları", "Ortalama", ort1);
	table("Sayısal Tasarım", "Ortalama", ort2);
	table("Ayrık Matematik", "Ortalama", ort3);

	print(table);
	print(table, "math");*/

	/*EXAMPLE 3: Dosyadan okunan ogrenci not bilgilerini
				operator overloading (>>) ile okunup(Vizeve final 
				notlari alinir ortalama hesaplanir kisiye ozel harfli
				not atanir(mutlak harfi nota gore) ve gecip gecmedigi
				bilgisi ekrana ve dosyaya yazdirilir) operator overloading 
				(<<) yardimiyla ekrana yazdirilmasi.*/
	
	/*
	ifstream file;
	ofstream txt;
	file.open("sınıf.txt");
	txt.open ("sınıf2.txt");
	lesson Ayrik(133, 3,"Ayrik Matematik"); // ogrenci sayisi,sutun sayisi,ders adi
	file >> Ayrik;
	txt  << Ayrik;
	printlesson(Ayrik);
	file.close();
	txt.close();
	*/


	//EXAMPLE 4: Matris İşlemleri(Operator Overloading)
	/*
	>Matris transpozesi							+
	>Matris çarpma                              +
	>Matris toplama                             +
	>Matris çıkarma                             +
	*/

	/*
	//CARPMA:
	matris m1(2), m2(2),m3;
	m1.random(1,10);
	m2.random(5,10);
	print(m1, "math");
	print(m2, "math");
	m3 = m1 * m2;
	print(m3, "math");
	//TOPLAMA:
	print(m1, "math");
	print(m2, "math");
	m3 = m1 + m2;
	print(m3, "math");
	//CIKARMA:
	print(m1, "math");
	print(m2, "math");
	m3 = m1 - m2;
	print(m3, "math");
	//TRANSPOZE:
	matris m(3,4),t;
	m.random(1, 10);
	print(m, "math");
	t = m ^'T';
	print(t,"math");*/
	
	getchar();
	return 0;
}