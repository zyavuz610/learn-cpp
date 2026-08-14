#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
/*  DİZİLER - ARRAYS
		. Aynı veri tipinden birden çok veri içeren yapılardır
		. Belli bir boyutu vardır, yani kaç eleman içerdiği bellidir (dizinin boyutu)
		. aynı türden bireysel değişkenleri 
		sayi, sayi1, sayi2, ..., sayi50 vs tanımlamak yerine dizi tanımlanır ve dizinin adına sıra numarası (indis,index) verilerek o elemana erişilir.
		. diziler lineer veri türüdür, yani elemanlar bellekte peşpeşe dizilirler ve tüm elemanlar aynı boyuttadırlar.
		. sıra numarası (indis) c/c++ dilinde 0 dan başlar (bir çok programlama dilinde olduğu gibi; bu durum dizinin isminin aynı zamanda ilk elemanın başlangıç adresi olması ve sonraki elemanlara erişim için başlangıç adresi + indis in kullanılması ile de ilişkilidir.)

		...
		int sayi[100];	// 100 elemanlı int tipinde ve sayi isminde dizi
		double r[10];
		char s[100];	

    int n = 5;
    double dizi[n];  // C++ 11 standartlarına göre bu tanımlama yapılamaz
    cout << "C++ version: " << __cplusplus << endl;
		...
		
		. DİZİLERE İLK DEĞER VERME
			int sayi[] = {2,3,5,6,9};	// 5 elemanlı dizi
			sayi[0] = 10;				// ilk eleman 10 olarak ayarlanıyot
			char s[] = {'B','i','l','g','i','s','a','y','a','r'};

      int dizi[5] = {0};  // Tüm elemanlar 0 olur
      int dizi[5] = {1, 2, 3, 4, 5};  // 5 elemanlı bir dizi, her eleman tanımlı
      int dizi[5] = {1, 2};  // İlk iki eleman 1 ve 2, geri kalanlar 0
      int dizi[] = {1, 2, 3, 4, 5};  // Boyut otomatik olarak 5 olur
	  
	  // C string tanımlama, karakter dizisi
	  char str[] = "Merhaba";  // str dizisi 8 elemanlı olur, son eleman null karakterdir '\0'
	  char str2[20] = "Dünya"; // str2 dizisi 20 elemanlı olur, ilk 6 eleman 'D','ü','n','y','a','\0', geri kalanlar ise 0 olur
	  char ch[] = {'M', 'e', 'r', 'h', 'a', 'b', 'a', '\0'}; // ch dizisi de 8 elemanlı olur
	  char ch2[10] = {'D', 'ü', 'n', 'y', 'a', '\0'}; // ch2 dizisi 10 elemanlı olur, ilk 6 eleman tanımlı, geri kalanlar 0 olur
	  // char ch3[5] = "Merhaba"; // HATA! çünkü "Merhaba" ifadesi 8 karakterlidir, 5 karakterlik diziye sığmaz
	  // char ch4[5] = {'M', 'e', 'r', 'h', 'a', 'b', 'a', '\0'}; // HATA! çünkü 8 karakterlik ifade 5 karakterlik diziye sığmaz
	  char name[16] = {'J', 'o', 'h', 'n', '\0'};



      konu olarak bilinmesi gerekeneler
      - dizi oluşuma, ilk değer verme
      - elemanlara erişim, işlem yapmak (okuma yazma)
      - dikkat et (hatırla!)
        - string için toplu erişim
        - diğer dizilerde tek tek erişim.
			
      
*/
//-------------------------------------------------------------
/*
// örnek: 
// sonsuz while döngüsü oluşturunuz, kullanıcıdan 10 elemanlı bir diziye elemanları girmesini isteyiniz, q girerse çıkış yapınız
// kullanıcıdan ad, soyad, arasınav, final notlarını alınız
// bu değerleleri bir diziye atınız, dizi indisleri id olarak düşünülebilir
// ekrana tablo şeklinde id, ad, soyad, arasınav, final, ortalama, harf notu, geçti/kaldı yazdırınız.
// setw(), setprecision(), fixed, setfill() fonksiyonlarını kullanınız
*/
//-------------------------------------------------------------
/*
illegal dizi işlemleri
 int x[5] = {1,2,3,4,5}; // array initialization
 int y[5] = {6,7,8,9,10};
 x = y;  // bu işlem yapılamaz
 cin>>x;  // bu işlem yapılamaz
 if(x==y)  // bu işlem yapılamaz
*/
int main() {

//----------------------------------------------------------
//	Dizi elemanlarına erişim

	int n,SUTUN1=6,SUTUN2=7;
  cout<<"N:";
	cin>>n;
	int sayi[100];
	for(int i=0;i<n;i++){
		cout<<i<<". sayi : ";
		cin>>sayi[i];
	}
	cout<<setw(SUTUN1)<<"Sıra"<<setw(SUTUN2)<<"Deger"<<endl;
	for(int i=0;i<n;i++){
		cout<<setw(SUTUN1)<<i<<setw(SUTUN2)<<sayi[i]<<endl;
	}
  // Dizi elemanlarının toplamını bulunuz
  // En küçük, en büyük elemanı, ortalama bulunuz
  // Ortalamadan küçük elemanları, ortalamadan büyük elemanları bulunuz
  // 2. max, ve 2. min elemanı bulunuz
  // dizinin matematikteki formülüne göre standart sapmasını bulunuz

  return 0;
}
