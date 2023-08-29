/*
verilen bir tamsayının çarpanlarını ve asal çarpanlarını bulmak
    önce tüm çarpanlarını bulun,
    sonra asal çarpanlarını bulun
    daha sonra asal çarpanları cinsinden ekrana yazın
    örn; 72 = 2*2*2*3*3
    
    yaren öztürk tarafından yazılmıştır
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//bu kod vs code da yazilip g++ ile derlendi.

//Bir sayinin asal olup olmadigini kontrol etmek icin
// bool isBool(int b)
// {
//     bool flag=true;
//     for( int i = 2; i <= n / 2; ++i)
//   {
//       if(b % i == 0)
//       {
//           flag = false;
//           break;
//       }
//   }
// }

void carpan(int a){
    //vector<int> v;
    //sonuclari vector degerde saklamak istedim ama cikti  25 icin 1 5 25 0 1 5 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 24%  oldu
    for (int i=1; i<=a ; i++)
    {
        if(a%i==0)
            //v.push_back(i);
            cout<<i << " ";
    }
    // for (int j = 0; j<sizeof(v); j++)
    // {
    //     cout<< v[j]<<" ";
    // }
    // cout << sizeof(v);
}

void asalCarpan(int c)
{
    //sayinin kac tane 2 boleni var
    while (c % 2 == 0)  
    {  
        cout << 2 << " ";  
        c = c/2;  //sayi tek olana kadar 2 yazdir ve 2 ye bol 
    }  
   
    for (int i = 3; i <= sqrt(c); i = i + 2)  //n artik tek sayi 3 ten baslayarak carpanlari bulur
    //i nin tek kalmasi icin 2 arttiriyoruz. cunku tum ciftleri bulduk
    {  
        
        while (c % i == 0)  //bolunuyorsa
        {  //yukarda 2 ile yaptigimizi burada i sayisi ile yapiyoruz. 
            cout << i << " ";  //sayiyi yazdir
            c = c/i;  // c yi i ye bl
        }  
    }  
  
    if (c > 2)  //diger 2 kurala uymadigi icin bos cikti var. 
        cout << c << " ";

}

int main(){
    int inp;
    
    cout<< "Enter a number: ";
    
    cin>>inp;
    cout<< inp << "= ";
    
    carpan(inp);
    
    cout<<"\n";
    cout<< inp << "= ";
    
    asalCarpan(inp);
    return 0;
}
