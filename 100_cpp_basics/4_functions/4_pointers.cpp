#include <iostream>
using namespace std;

//-------------------------------------------------------------
// fonksiyonlara parametre olarak dizilerin verilmesi (pointer olarak) için kullanılacak fonk.
double OrtalamaBul3(int *dizi, int boyut) {
  int i, top = 0;       
  double ort;         
  for (i = 0; i < boyut; i++) {
      top += *(dizi+i);
   }
   ort = double(top) / boyut;
   return ort;
}



int main () {
   int  var = 93;   
   int  *i;        

   i = &var;       

   cout << "var içeriği: ";
   cout << var << endl;

   cout << "Pointer değeri: ";
   cout << i << endl;

   cout << "Pointer içeriği: ";
   cout << *i << endl;

//--------------------------------------------------------------
/*
    int *p;			// bellek organizasyonunu gösterelim
		int sayi;
		sayi = 78;
		p = &sayi;
		*p = 24;
    cout<<p<<endl;	
    cout<<*p<<endl;
    cout<<sayi<<endl;
    cout<<&sayi<<endl;
    cout<<&p<<endl;
  return 0;
}
*/

/*
Çıktı
0x7fffeba0c7a4
24
24
0x7fffeba0c7a4
0x7fffeba0c7a8

*/

//--------------------------------------------------------------
/*
	Dizi ve Pointer ilişkisi
		. dizi ismi	ilk elemanı gösteren bir pointer dir
		. int a[10]; tanımı yapıldığında "&a[0] = a" olur
*/
/*	
  int SUTUN1=6,SUTUN2=7;
	double r[]={3.0,2.5,10.0,-2.3,9.8};	// 5 elemanlı dizi
	double *p;
	p = r;		// pointer diziyi gösteriyor
		
	cout<<setw(SUTUN1)<<"Sıra"<<setw(SUTUN2)<<"Deger"<<endl;
	for(int i=0;i<5;i++){
		cout<<setw(SUTUN1)<<i<<setw(SUTUN2)<<*(p+i)<<endl;
	}
 */ 
//--------------------------------------------------------------

   return 0;


}
