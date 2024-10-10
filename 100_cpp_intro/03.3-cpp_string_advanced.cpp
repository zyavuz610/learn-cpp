#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
/*
  // string kopyalama, c_str()
  string str = "Nesne Yönelimli Programlama";
  char cstr[100];
  strcpy(cstr,str.c_str());
  cout<<cstr<<endl;
  cout<<"ilk harf: "<<char(cstr[0] + 32)<<endl;
*/
//-----------------------------------------------
/*
// 10'arlı sayıları matris şeklinde yazıyoruz
  for(int x=0;x<5;x++){
    for(int i=0;i<10;i++){
      cout<<i;
    }
  }
  cout<<endl;
  
  //string str = "Nesne Yönelimli Programlama";
  string str("Nesne Yönelimli Programlama");

  cout<<str<<endl;
  cout<<"Size : "<<str.size()<<endl;
  cout<<"length : "<<str.length()<<endl;    // aynı
  cout<<"capacity : "<<str.capacity()<<endl;  // bellekte ayrılan yer
  str.reserve(50); // yeni yer ayrılması istenir, ayrılan yer daha fazla olabilir
  cout<<"new capacity : "<<str.capacity()<<endl;  // bellekte ayrılan yer
  cout<<"Max size : "<<str.max_size()<<endl;  // ulaşılabilecek maximum boyut

  str.shrink_to_fit();
  cout<<"new capacity : "<<str.capacity()<<endl;

  str.clear();
  cout<<str<<endl;
  cout<<"Size : "<<str.size()<<endl;
  if(str.empty()) cout<<"Boş String"<<endl;
 */ 
//-------------------------------------------------------
/*
  string str("Nesne Yönelimli Programlama");
  str.resize(str.size()+10);
  cout<<str<<endl;
  cout<<"Size : "<<str.size()<<endl;
  */
//-----------------------------
/*
  string str("Nesne Yönelimli Programlama");
  str.resize(str.size()+10,'-');
  cout<<str<<endl;
  cout<<"Size : "<<str.size()<<endl;
*/
//--------------------------------
/*
  string str("Nesne Yönelimli Programlama");
  str.resize(str.size()-10);
  cout<<str<<endl;
  cout<<"Size : "<<str.size()<<endl;
*/

// geriye kalan string türünün fonksiyonlarını teker teker inceleyelim

// data, copy, find, substr, compare, operator+=, operator[], at, back, front, append, push_back, assign, insert,erase,replace, swap(hem üye fonksiyon, hem de 2 string alan fonksiyon),pop_back,operator+,relational operators, operator>>, operator<<, getline

/*
  Örnek Projeler
  10:07:45:145 den saat dakika saniye gibi bilgileri çıkaralım

  öğrenci notlarını hesaplayalım ve 
    ad soyad a göre,
    harfli nota göre sıralayalım
    ad soyad büyük harfe çevirelim
    girilen cümlenin hece sayısını bulalım
*/  

//----------------------------------------------------------------------------------------

/*
    // Input Functions:  getline, push_back(), pop_back()
    getline(cin,str);
    cout << str << endl; 
    // push_back() to insert a character at end
    str.push_back('s'); 
    cout << str << endl;
  
    // pop_back() to delete a character from end 
    str.pop_back(); 
    cout << str << endl;
*/

//---------------------------------------------------------------------

/*
    // Capacity Functions
        // Initializing string 
    string str = "c++ programming is easy to learn"; 
    cout << str << endl; 
    str.resize(13);
    cout << str << endl;  
    cout << "Capacity: " << str.capacity() << endl;
    cout<<"length: "<<str.length()<<endl;
    str.shrink_to_fit();
    cout << "capacity after shrinking is : " << str.capacity() << endl;
*/

//-------------------------------------------------------------------------------

/*
    // Manipulating Functions. copy(“char array”, len, pos), swap()

    string str1 = "geeksforgeeks is for geeks"; 
  
    // Declaring 2nd string 
    string str2 = "geeksforgeeks rocks"; 
  
    // Declaring character array 
    char ch[80]; 
  
    // using copy() to copy elements into char array 
    // copies "geeksforgeeks" 
    str1.copy(ch,13,0); 
  
    // Diplaying char array 
    cout << "The new copied character array is : "; 
    cout << ch << endl << endl; 
  
    // Displaying strings before swapping 
    cout << "The 1st string before swapping is : "; 
    cout << str1 << endl; 
    cout << "The 2nd string before swapping is : "; 
    cout << str2 << endl; 
  
    // using swap() to swap string content 
    str1.swap(str2); 
  
    // Displaying strings after swapping 
    cout << "The 1st string after swapping is : "; 
    cout << str1 << endl; 
    cout << "The 2nd string after swapping is : "; 
    cout << str2 << endl; 
*/

// http://www.cplusplus.com/reference/string/string/
  return 0;
}
