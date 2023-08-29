/*

### Algorithms
* <code> #include <algorithm> </code> kütüphanesinde bulunurlar.
* İçerisinde çeşitli algoritmalar bulunur.

    sorting
    searching
    important STL algorithms
        sort(first_iterator, last_iterator) 
        reverse(first_iterator, last_iterator) 
        *max_element (first_iterator, last_iterator)
        *min_element (first_iterator, last_iterator)
        accumulate(first_iterator, last_iterator, initial value of sum)
*/

//-------------------------------------------------------

/*

 Sorting: Verilen diziyi sıralar, algoritma olarak *Quick-sort* kullanır.
  
  sort(startaddress, endaddress)
*/

#include <algorithm> 
#include <iostream> 
using namespace std; 

template <typename Type>
void show(Type a[]) { 
    for(int i = 0; i < 10; ++i) 
        cout << a[i] << " ";
    cout<<endl; 
} 

int main() { 
    string arr[] = {"a", "cc", "d", "w", "j", "yt", "pl", "sd", "f", "y"}; 
    // int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    
    int n = sizeof(arr)/sizeof(arr[0]); 

    show(arr); 
  
    // artan sırada sıralamak için
    // sort(arr, arr+n); 

    // ters sırada sıralamak için
    //sort(arr, arr+n, greater<int>());
    sort(arr, arr+n, greater<string>());
  
    cout << "Array after sorting : \n"; 
    show(arr);
  
    return 0; 
} 

//---------------------------------------------------
/*
 binary search
    binary_search(startaddress, endaddress, valuetofind)
 - verilen dizi önce sıralı olması gerekir
 */

/*
#include <algorithm> 
#include <iostream> 
  
using namespace std; 
  
void show(int a[], int arraysize) 
{ 
    for (int i = 0; i < arraysize; ++i) 
        cout << a[i] << " "; 
} 
  
int main() 
{ 
    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
    int asize = sizeof(a) / sizeof(a[0]); 
    cout << "\n The array is : "; 
    show(a, asize); 
  
    cout << "\n\nLet's say we want to search for 2 in the array"; 
    cout << "\n So, we first sort the array"; 
    sort(a, a + asize); 
    cout << "\n\n The array after sorting is : "; 
    show(a, asize); 
    
    cout << "\n\nNow, we do the binary search"; 
    if (binary_search(a, a + 10, 2)) 
        cout << "\nElement found in the array"; 
    else
        cout << "\nElement not found in the array"; 
  
    cout << "\n\nNow, say we want to search for 10"; 
    if (binary_search(a, a + 10, 10)) 
        cout << "\nElement found in the array"; 
    else
        cout << "\nElement not found in the array"; 
  
    return 0; 
} 
*/
//--------------------------------------------------------------------
/*
    important STL algorithms
        sort(first_iterator, last_iterator) 
            To sort the given vector.
        reverse(first_iterator, last_iterator) 
            To reverse a vector.
        *max_element (first_iterator, last_iterator)
            To find the maximum element of a vector.
        *min_element (first_iterator, last_iterator)
            To find the minimum element of a vector.
        accumulate(first_iterator, last_iterator, initial value of sum)
            To find the minimum element of a vector.

*/
#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <numeric> //For accumulate operation 
using namespace std; 
  
int main() 
{ 
    // Initializing vector with array values 
    int arr[] = {10, 20, 5, 23 ,42 , 15}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 
  
    cout << "Vector is: "; 
    for (int i=0; i<n; i++) 
        cout << vect[i] << " "; 
  
    // Sorting the Vector in Ascending order 
    sort(vect.begin(), vect.end()); 
  
    cout << "\nVector after sorting is: "; 
    for (int i=0; i<n; i++) 
       cout << vect[i] << " "; 
  
    // Reversing the Vector 
    reverse(vect.begin(), vect.end()); 
  
    cout << "\nVector after reversing is: "; 
    for (int i=0; i<6; i++) 
        cout << vect[i] << " "; 
  
    cout << "\nMaximum element of vector is: "; 
    cout << *max_element(vect.begin(), vect.end()); 
  
    cout << "\nMinimum element of vector is: "; 
    cout << *min_element(vect.begin(), vect.end()); 
  
    // Starting the summation from 0 
    cout << "\nThe summation of vector elements is: "; 
    cout << accumulate(vect.begin(), vect.end(), 0); 
  
    return 0; 
} 

//---------------------------------------------------
/*
    count(first_iterator, last_iterator,x)
        To count the occurrences of x in vector.
    find(first_iterator, last_iterator, x)
        Points to last address of vector ((name_of_vector).end()) if element is not present in vector.

*/

#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 
  
int main() 
{ 
    // Initializing vector with array values 
    int arr[] = {10, 20, 5, 23 ,42, 20, 15}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 
  
    cout << "Occurrences of 20 in vector : "; 
  
    // Counts the occurrences of 20 from 1st to 
    // last element 
    cout << count(vect.begin(), vect.end(), 20); 
  
    // find() returns iterator to last address if 
    // element not present 
    find(vect.begin(), vect.end(),5) != vect.end()? 
                         cout << "\nElement found": 
                     cout << "\nElement not found"; 
  
    return 0; 
}

//-----------------------------------------------------

/*
    binary_search(first_iterator, last_iterator, x)
        Tests whether x exists in sorted vector or not.
    lower_bound(first_iterator, last_iterator, x)
        returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.
    upper_bound(first_iterator, last_iterator, x)
        returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’.
*/
#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 
  
int main() 
{ 
    // Initializing vector with array values 
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 
  
    // Sort the array to make sure that lower_bound() 
    // and upper_bound() work. 
    sort(vect.begin(), vect.end()); 
  
    // Returns the first occurrence of 20 
    auto q = lower_bound(vect.begin(), vect.end(), 20); 
  
    // Returns the last occurrence of 20 
    auto p = upper_bound(vect.begin(), vect.end(), 20); 
  
    cout << "The lower bound is at position: "; 
    cout << q-vect.begin() << endl; 
  
    cout << "The upper bound is at position: "; 
    cout << p-vect.begin() << endl; 
  
    return 0; 
} 

//-----------------------------------------------
// ctd....
/*
Some Manipulating Algorithms
https://www.geeksforgeeks.org/c-magicians-stl-algorithms/

*/


