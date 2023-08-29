#include <iostream>
using namespace std;

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

   return 0;


}
