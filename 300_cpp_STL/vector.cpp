/*
	VECTOR
		dinamik dizi, 
		dizinin boyutu eleman sayısına göre otomatik ayarlanır
		
		push_back()	: dizinin sonuna eleman ekler
		size()		: dizide bulunan eleman sayısını verir
		operator[]	: belli indisteki elemana erişim için kullanılır
		swap()		: v1.swap(v2); v1 ile v2 nin eleman değerleri yer değiştirir
		empty()		: dizi boşsa true geri döndürür
		back()		: son elemanın değerini döndürür, son elemanı silmez
		pop_back()	: son elemanın değerini geri döndürür, son elemanı siler
		insert(i,x)	: i. indise x değerini ekler, diğer elemanları kaydırır
		erase(i)	: i. elamanı siler, diğer elemanları kaydırır
		
Iterators

begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin() – Returns a constant iterator pointing to the first element in the vector.
cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

*/


// C++ program to illustrate the 
// iterators in vector 
#include <iostream> 
#include <vector> 
  
using namespace std; 
  
int main() 
{ 
    vector<int> g1; 
  
    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 
  
    cout << "Output of begin and end: "; 
    for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " "; 
  
    cout << "\nOutput of cbegin and cend: "; 
    for (auto i = g1.cbegin(); i != g1.cend(); ++i) 
        cout << *i << " "; 
  
    cout << "\nOutput of rbegin and rend: "; 
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
        cout << *ir << " "; 
  
    cout << "\nOutput of crbegin and crend : "; 
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir) 
        cout << *ir << " "; 
  
    return 0; 
}

//-----------------------------------------------------------------

