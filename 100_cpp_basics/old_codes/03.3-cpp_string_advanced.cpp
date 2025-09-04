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
// str.size(); kapasite, uzunluk, max_size
// str.length(); uzunluk
// str.capacity(); kapasite
// str.max_size(); ulaşılabilen maksimum boyut
// str.reserve(); yeni yer ayrılması istenir, ayrılan yer daha fazla olabilir
// str.shrink_to_fit(); kapasiteyi uzunluğa eşitler
// str.clear(); stringi temizler
// str.empty(); boş mu değil mi
// str.resize(); boyutu değiştirir
  
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

//-------------------------------------------------------
// geriye kalan string türünün fonksiyonlarını teker teker inceleyelim

// data, copy, find, substr, compare, operator+=, operator[], at, back, front, append, push_back, assign, insert,erase,replace, swap(hem üye fonksiyon, hem de 2 string alan fonksiyon),pop_back,operator+,relational operators, getline

// str.data(); stringin ilk elemanının adresini döndürür, sonuna \0 ekler, bazı versiyonlarda \0 eklemeyebilir
// str.copy(); stringin bir kısmını başka bir stringe kopyalar
    // char buffer[8];  // 7 karakter + '\0' için alan
    // size_t copied = str.copy(buffer, 7, 0);  // İlk 7 karakteri kopyala, başlangıç 0
// str.find(); stringin içinde bir karakter arar, bulursa indisini döndürür, bulamazsa string::npos döndürür
  // found = str.find("Yönelimli",0);
// str.substr(start,len); stringin bir kısmını alır, başlangıç indisini ve uzunluğunu alır
// str.compare(str2); iki stringi karşılaştırır, 0 ise eşit, -1 ise ilk string küçük, 1 ise ilk string büyük
// operatorler: +, +=, [], (karşılaştırma operatörleri)
// str.at(); stringin bir elemanına erişir, hata kontrolü yapar
// str.back(); stringin son elemanına erişir
// str.front(); stringin ilk elemanına erişir
// str.append(str2); stringin sonuna ekleme yapar
// str.push_back(char); stringin sonuna karakter ekler
// str.assign(str2); stringi başka bir string ile değiştirir
// str.insert(pos,str2); stringin belirtilen indise string2 yi ekler, diğer karakterler kayar
// str.erase(pos,len); stringin belirtilen indisten itibaren len kadar karakteri siler, diğer karakterler kayar
// str.replace(pos,len,str2); stringin belirtilen indisten itibaren len kadar karakteri siler ve yerine str2 yi ekler
// str.swap(str2); iki stringin içeriğini değiştirir
// str.pop_back(); stringin son karakterini siler, geriye karakteri döndürür



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
