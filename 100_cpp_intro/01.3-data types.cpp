#include <iostream>
#include <bitset>
using namespace std;

int main() {

   // bool
   bool dolu = true;    // true(1), false(0) 
   cout << "Doluluk Durumu        : " << dolu << endl;
   cout << "Boolean bellek boyutu : " << sizeof(bool) << endl;
   cout << "İkili Gösterim: "<<bitset<8>(dolu)<<endl;


/*
   // char
   char ch='A'; // ch='b', ch=70
   cout << "Karakter Icerigi      : " << ch << "(" << int(ch) << ")" << endl;
   cout << "char bellek boyutu    : " << sizeof(char) << endl;
  cout << "İkili Gösterim: "<<bitset<8>(ch)<<endl;
*/
/*
   // int
   int n=-500;
   cout << "Tam Sayı İçeriği      : " << n << endl;
   cout << "int bellek boyutu     : " << sizeof(int) << endl;
   cout << "short int bellek boyutu : " << sizeof(short int) << endl;
   cout << "long int bellek boyutu : " << sizeof(long int) << endl;
*/
   
/*
   short int i;           // signed, unsigned farkı
   short unsigned int j;  
   j = 50000;
   i = j;  // i=65536-50000
   cout << i << " " << j;
*/   
 /*  

   // float, double
   short int i;           // signed, unsigned farkı
   short unsigned int j;  
   j = 50000;
   i = j;  // i=65536-50000
   cout << i << " " << j;
*/


   return 0;
}

/*
        ******** Temel Veri Tipleri ***************
        bool            Boolean: doğru ya da yanlış
        char            Karakter
        int             Tam Sayı
        float           float    
        double          double
        void            değer içermeyen
        *********** Veri Tipi Düzenleyici Anahtar Kelimeleri *******************
        signed                  hiç bir şey yazılmazsa "signed" olarak alınır
        unsigned
        short
        long
        ***********************************************************
        char	                1byte	        -127 to 127 
        unsigned char	        1byte	        0 to 255
        signed char	        1byte	        -127 to 127
        int	                4bytes	        -2147483648 to 2147483647
        unsigned int	        4bytes	        0 to 4294967295
        signed int	        4bytes	        -2147483648 to 2147483647
        short int	        2bytes	        -32768 to 32767
        unsigned short int	Range	        0 to 65,535
        signed short int	Range	        -32768 to 32767
        long int	        4bytes	        -2,147,483,648 to 2,147,483,647
        signed long int	        4bytes	        same as long int
        unsigned long int	4bytes	        0 to 4,294,967,295
        
        float	                4bytes	        +/- 3.4e +/- 38 (~7 digits)
        double	                8bytes	        +/- 1.7e +/- 308 (~15 digits)
        long double	        8bytes	        +/- 1.7e +/- 308 (~15 digits) (bazı derleyicilerde 16)
        *********************************************************************
        typedef Tanımlama
                - c++ da typedef kullanarak var olan t,iplerden yeni bir tip tanımlanabilir
                - örneğin;
                        typedef float hacim;
                        hacim hacim1;           // hacim anahtar kelimesi artık float olarak değerlendirilecek
        *********************************************************************
        enum
                - değişkenler belli bilgileri tutmak için kullanılır ve belirli tiplerde tanımlanır
                - değişkenler bellekte yer kaplar
                - ileride yeniden ele alacağız

            //           0        1     ...
            enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
            week today;
            today = Wednesday;
            cout << "Day " << today+1;

      bir diğer örnek
         enum season {   
            spring = 0, 
            summer = 4, 
            autumn = 8,
            winter = 12
         };
*/
