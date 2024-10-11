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



      konu olarak bilinmesi gerekeneler
      - dizi oluşum, ilk değer verme
      - elemanlara erişim, işlem yapmak (okuma yazma)
      - dikkat et (hatırla!)
        - string için toplu erişim
        - diğer dizilerde tek tek erişim.
			
      
*/
//-------------------------------------------------------------
// fonksiyonlara parametre olarak dizilerin verilmesi için kullanılacak fonk. lar
double OrtalamaBul(int dizi[], int boyut) {
  int i, top = 0;       
  double ort;         
  for (i = 0; i < boyut; i++) {
      top += dizi[i];
   }
   ort = double(top) / boyut;
   return ort;
}

double OrtalamaBul2(int dizi[5], int boyut) {
  int i, top = 0;       
  double ort;         
  for (i = 0; i < boyut; i++) {
      top += dizi[i];
   }
   ort = double(top) / boyut;
   return ort;
}

// pointer bölümünde anlatılacak
double OrtalamaBul3(int *dizi, int boyut) {
  int i, top = 0;       
  double ort;         
  for (i = 0; i < boyut; i++) {
      top += *(dizi+i);
   }
   ort = double(top) / boyut;
   return ort;
}
//-------------------------------------------------------------
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

//---------------------------------------------------------------
//  Çok Boyutlu Dizi
/*
    . Birden çok boyutlu dizler C++ tarafından desteklenmektedir
    . 2 boyutlu dizi - matris olarak adlandırılabilir
    . 2 den daha yüksek boyutlu diziler tanımlamak da mümkündür, genel ismi tensor olarak adlandırılır
      int matris1[20][20];   // veri yapılarında daha ayrıntılı görülecek
      int tensor[10][20][30];
      unsigned char rgb[3][512][512];   // 512x512 boyutlu renkli bir resim için kullanılabilir
*/
/*
  int a[3][4] = {       // matrislere İLK DEĞER atama
   {0, 1, 2, 3} ,   //  satir 1 (index 0) 
   {4, 5, 6, 7} ,   //  satir 2 (index 1) 
   {8, 9, 10, 11}   //  satir 3 (index 2) 
  };
  int b[3][4] = {  
   {10, 11, 22, 43} ,   //  satir 1 (index 0) 
   {43, 51, 46, 47} ,   //  satir 2 (index 1) 
   {85, 98, 10, 71}     //  satir 3 (index 2) 
  };
  int c[3][4]={0};

  // matris toplamı
  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
      c[i][j] = a[i][j] + b[i][j];  
      cout<<setw(4)<<c[i][j]; 
    }
    cout<<endl;
  }
  */
  // matris çarpımı kodlayın (boyutlar uygun olmalı, kontrol edin)
  // transpozu kodlayın (kare matris için)
  // çıkarma kodlayın
  // matisin izini (trace) bulun (köşegen üzerindeki elemanların toplamı) (kare matris için)
  // matrisin alt ve üst üçgen bölgelerini ekrana yazın (kare matris için)

//---------------------------------------------------------------
// matrislerin fonksiyonlara parametre olarak verilmesi
/*

#define sutunSayisi 10
void fonksiyon(int matris[][sutunSayisi], int satirSayisi) {
  // Matrisin değerini değiştirebiliriz
  for (int i = 0; i < satirSayisi; i++) {
    for (int j = 0; j < sutunSayisi; j++) {
      matris[i][j] = i * j;
    }
  }
}


*/
  return 0;
}
