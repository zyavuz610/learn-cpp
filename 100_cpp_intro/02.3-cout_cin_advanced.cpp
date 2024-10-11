#include <iostream>
#include <iomanip>  // gerekli header
using namespace std;

int main() {

//---------------------------------------------  
/*  
stream:   bir kaynaktan hedefe doğru giden karakter dizisi
istream:  giriş cihazından bilgisayara doğru akan karakter dizisi
ostream:  bilgisayardan dış cihaza (ekran, dosya vs..) doğru akan karakter dizisi

<iostream>  : istream ve ostream türünden sınıfları içeren header

  istream cin;    şeritten okur kafayı ilerletir
	ostream cout;   çıktıyı yazar, kafayı ilerletir

  örnek:
    cin>>variable>>variable...;
    cin>>payRate>>hoursWorked;

   ard arda >> opetratörü ile girdiler alınabilir, bir sonraki giriş için tüm beyaz boşluk karakterleri atlanır
   whitespace(beyaz boşluk): boşluk, tab, yeni satır('\n') gibi ayırıcı karakterleri

   cin>>ch;		girişten "AB" girildiğinde		ch='A', 'B' bir sonraki giriş için tutulur
*/
//------------------------------------------------
/*
// kullanıcıdan giriş almak
   double z;
   cin>>z;		
   giriş: 39		sonuç: z=39.0
*/
//------------------------------------------------
/*
// birden fazla giriş almak
   int x,y;
   cin>>x>>y;
   giriş: 25 67		sonuç: x=25, y=67
*/
//---------------------------------------------
/*
  // cin.get(varChar);  sıradaki karakteri (whitespace, boşluk dahil) okur
  char ch1,ch2;
  int num;
  cin.get(ch1);
  cin.get(ch1);
  cin.get(ch2);
  cin>>num;
      
  // giriş: A 25
  // ch1='A';    ch2=' ';   num=25;
  cout<<int(ch1)<<" "<<int(ch2)<<" "<<num;
*/
//------------------------------------------------
/*
  // cin.ignore(intExp,chExp);    intExp sayıda karakter ya da chExp karakteri görene kadar girilen karakterleri görmezden gelir, hangi şart ilk önce sağlanırsa
  int a,b;
  //Suppose the input is:
  // 25 67 89 43 72
  // 12 78 34

  // Örnek:

  cin>>a;
  cin.ignore(5,'\n');
  cin>>b;

  cout<<"a="<<a<<endl;
  cout<<"b="<<b<<endl;
  // The first statement cin>>a; stores 25 in a. 
  // The second statement, cin.ignore(100,'\n'); discards all of the remaining numbers in the first line.
  // The third statement cin>>b; stores 12 (from the next line) in b.
*/
//------------------------------------------------
/*
// The peek and the putback Functions
  // cin.peek();  sıradaki karakteri okur, ama kafayı ilerletmez
  // cin.putback(ch);  ch karakterini geri koyar, kafayı ilerletmez
*/
  char ch1,ch2,ch3;
  int num;
  cin>>ch1;
  ch2 = cin.peek();
  //cin>>ch2;
  cin>>num;
  cout<<ch1<<" "<<ch2<<" "<<num<<endl;
  //cin.putback(ch2);
  cin>>ch2;
  cout<<ch1<<" "<<ch2<<" "<<num<<endl;
//-------------------------------------------------------------------
//Functions peek and putback
/*
	char ch;

	cout<<"Line 1: Enter a string: ";		//Line 1
	cin.get(ch);					//Line 2
	cout<<endl;						//Line 3
	cout<<"Line 4: After first cin.get(ch); "
	    <<"ch = "<<ch<<endl;			//Line 4
cin.get(ch);					//Line 5
	cout<<"Line 6: After second cin.get(ch); " 
	    <<"ch = "<<ch<<endl;			//Line 6

	cin.putback(ch);					//Line 7
	cin.get(ch);					//Line 8
	cout<<"Line 9: After putback and then " 
	    <<"cin.get(ch); ch = "<<ch<<endl;	//Line 9
	
	ch = cin.peek();					//Line 10
	cout<<"Line 11: After cin.peek(); ch = "
	    <<ch<<endl;					//Line 11
	cin.get(ch);					//Line 12
	cout<<"Line 13: After cin.get(ch); ch = "
	    <<ch<<endl;					//Line 13
*/
/*
Sample Run: In this sample run, the user input is in red.
Line 1: Enter a string: abcd
Line 4: After first cin.get(ch); ch = a
Line 6: After second cin.get(ch); ch = b
Line 9: After putback and then cin.get(ch); ch = b
Line 11: After cin.peek(); ch = c
Line 13: After cin.get(ch); ch = c

*/
//---------------------------------------------------------------

  // getline(cin,str);
/****
  string ad;
  cin>>ad; // whitespace görene kadar alır
  cout<<"Merhaba "<<ad<<endl;
***/

/****
  string ad;
  getline(cin,ad);  // tüm satırı alır
  cout<<"Merhaba "<<ad<<endl;
***/
/*****
  char ad[256];
  //cin.getline(ad,256,'u');
  cin.getline(ad,5,'\n');
  cout<<"Merhaba "<<ad<<endl;
***/

//------------------------------------------------------------------

  // cout
/******
cout<<expression or manipulator
    <<expression or manipulator...;
expression is evaluated, its value is printed, and manipulator is used to format the output. 

cout<<setprecision(2); // toplam hane sayısını belirtir.

cout<<fixed;           // ondalık kısımda duyarlılık alır
****/  
/*
  double x=107.123,y=23;
  cout<<setprecision(3)<<x<<endl;  // 107 yazar
  cout<<fixed<<setprecision(2)<<x<<endl;  // 107.12 yazar
  cout<<fixed<<scientific<<setprecision(4)<<x<<endl;  // 1.0712e+02 (1.0712*10^2) yazar
  cout.unsetf(ios::fixed);    // fixed bayrağını unset yapar
  cout.unsetf(ios::scientific);
  cout<<setprecision(3)<<x<<endl;  // 107 yazar

  //cout<<showpoint;
  cout<<setprecision(4)<<y<<endl;  // 23.00 yazar

  cout.setf(ios::scientific);   // bayrağı setler
                                // fixed, scientific, showpoint...
  cout<<setprecision(4)<<y<<endl;  // 23.00 yazar
*/
//------------------------------------------------------------
/*
// showpoint
    double num1 = 10.0;
    double num2 = 15.123;
    
    // showpoint olmadan
    std::cout << "showpoint olmadan:\n";
    std::cout << num1 << "\n";  // Sadece tam sayı kısmını gösterir (10)
    std::cout << num2 << "\n";  // Ondalık kısmını gösterir (15.123)

    // showpoint ile
    std::cout << "\nshowpoint ile:\n";
    std::cout << std::showpoint << num1 << "\n";  // Ondalık nokta zorlanır (10.0000)
    std::cout << std::showpoint << num2 << "\n";  // Ondalık nokta zaten var (15.123)
*/
//------------------------------------------------------------
/** 
 *  setw(n);    
    bir sonra gelen ifadeyi n sütunda yazacak şekilde ayarlar, 
    default olarak sağa dayalıdır, 
    cout<<left ile sola cout<<right ile sağa ayarlanabilir
    taşma olursa gerektiği kadar genişletilir
**/
/*
  int x = 19;						//Line 1
	int a = 345;					//Line 2
	double y = 76.384;				//Line 3

	cout<<fixed<<showpoint;				//Line 4  
  cout<<"12345678901234567890"<<endl;		//Line 5

	cout<<setw(5)<<x<<endl;				//Line 6
	cout<<setw(5)<<a<<setw(5)<<"Hi"
	    <<setw(5)<<x<<endl<<endl;			//Line 7
	
	cout<<setprecision(2);				//Line 8
	cout<<setw(6)<<a<<setw(6)<<y
	    <<setw(6)<<x<<endl;				//Line 9
    	cout<<setw(6)<<x<<setw(6)<<a
	    <<setw(6)<<y<<endl<<endl;			//Line 10

	cout<<setw(5)<<a<<x<<endl;			//Line 11
	cout<<setw(2)<<a<<setw(4)<<x<<endl;		//Line 12
  */
//----------------------------------------------------
/*
  // fill() ve setfill()
  int x = 15;						//Line 1			
	int y = 7634;					//Line 2

	cout<<"12345678901234567890"<<endl;		//Line 3
	cout<<setw(5)<<x<<setw(7)<<y
	    <<setw(8)<<"Warm"<<endl;			//Line 4

	cout.fill('*');					
	cout<<setw(5)<<x<<setw(7)<<y
	    <<setw(8)<<"Warm"<<endl;			
      cout<<setw(5)<<x<<setw(7)<<setfill('#')	
	    <<y<<setw(8)<<"Warm"<<endl;		

	cout<<setw(5)<<setfill('@')<<x
	    <<setw(7)<<setfill('#')<<y
	    <<setw(8)<<setfill('^')<<"Warm"
	    <<endl;						//Line 8

	cout.fill(' ');					//Line 9
	cout<<setw(5)<<x<<setw(7)<<y
	    <<setw(8)<<"Warm"<<endl;			//Line 10  
*/
//---------------------------------------------------
/*
  // left, right manipulator
  int x = 15;						//Line 1
	int y = 7634;					//Line 2

	cout<<left;						//Line 3
	
	cout<<"12345678901234567890"<<endl;		//Line 4
	cout<<setw(5)<<x<<setw(7)<<y
	    <<setw(8)<<"Warm"<<endl;			//Line 5

	cout.fill('*');					//Line 6
cout<<setw(5)<<x<<setw(7)<<y
	    <<setw(8)<<"Warm"<<endl;			//Line 7

	cout<<setw(5)<<x<<setw(7)<<setfill('#')<<y
	    <<setw(8)<<"Warm"<<endl;			//Line 8


	cout<<setw(5)<<setfill('@')<<x
	    <<setw(7)<<setfill('#')<<y
	    <<setw(8)<<setfill('^')<<"Warm"<<endl; //Line 9
						
	cout.unsetf(ios::left);				//Line 10
	cout.fill(' ');					//Line 11

	cout<<setw(5)<<x<<setw(7)<<y
	    <<setw(8)<<"Warm"<<endl;			//Line 12
*/
//------------------------------------------------------
/*** flush
    cout fonksiyonu ekrana bir şey yazarken buffer kullanır,
    buffer dolmadan genelde ekrana bir şey yazmaz,
    buffer dolduğunda ya da endl gördüğünde ekrana yazma işlemi gerçekleştirir
    bazen öyle durumlar olur ki buffer dolmadan bufferda bulunan karakterlerin ekrana yazılması gerekir
    bu durumda
    cout<<flush;  kullanılır
int num;
cout<<"Enter an integer: " <<flush;		//Line 1
cin>>num;					//Line 2
cout<<endl;					//Line 3
******/
//-----------------------------------------------------------

  return 0;
}
