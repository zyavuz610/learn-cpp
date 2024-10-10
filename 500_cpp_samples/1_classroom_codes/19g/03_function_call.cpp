// 2. ------------------------------------

// öğrenci numarasının palindrom kontrolü
// koşul operatörü, döngüler, operatörler, fonksiyonlar

#include <iostream>
#include <iomanip> 
#define ASK 0.50
#define FNK 0.50

using namespace std;
// sabit (6) haneli palindrom testi
int palindromTest1(int n){
  int b,o,y,bn,ob,yb;
  b = n%10; n /= 10;
  o = n%10; n /= 10;
  y = n%10; n /= 10;
  bn= n%10; n /= 10;
  ob= n%10; n /= 10;
  yb= n%10; n /= 10;
  if(b==yb && o==ob && y==bn)
    return 1;
  else
    return 0;
}
// değişken haneli palindrom testi
int palindromTest2(int n){
  int k,t=0,ydk=n;
  while(n>0)
  {
    k = n%10;
    n /= 10;
    t=t*10+k; 
  }
  // 1254
  // k=4, n=125, t=4
  // k=5, n=12, t=45
  // k=2, n=1, t=452
  // k=1, n=0, t=4521

  return (ydk==t)?1:0;
  // sonuc = (not<45)? 'f'    : 'g'      ;
}

// call by value örneği
void takas(int a,int b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

// call by pointer
void takas2(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

// call by reference örneği
void takas3(int &a,int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}
void yaz(int num, int as,int fn,float ort,char harf){
  int w[] = {9,5,5,8,8};
  cout<<setw(w[0])<<"No";
  cout<<setw(w[1])<<"AS";
  cout<<setw(w[2])<<"FN";
  cout<<setw(w[3])<<"Ort";
  cout<<setw(w[4])<<"Harf"<<endl;
  
  cout<<setw(w[0])<<num;
  cout<<setw(w[1])<<as;
  cout<<setw(w[2])<<fn;
  cout<<setw(w[3])<<fixed<<setprecision(2)<<ort;
  cout<<setw(w[4])<<harf<<endl;
}
int main() {
  int as=15,fn=16,num=2552;
  //  cin>>as>>fn;
  // float ort = (as + fn)/2.0;
  float ort = ASK*as + FNK*fn;

  char harf;
  if(ort>0 && ort<39){
    harf='F';
  }
  else if(ort<45){
    harf='D';
  }
  else if(ort<65){
    harf='C';
  }
  else if(ort<85){
    harf='B';
  }
  else if(ort<=100){
    harf='A';
  }
  else{
    harf='E';
  }
  
  yaz(num,as,fn,ort,harf);

  cout<<"Numara palindrom mu? : "<<palindromTest2(num)<<endl;

  takas(as,fn);
  cout<<"Call by value örneği"<<endl;
  yaz(num,as,fn,ort,harf);

  takas2(&as,&fn);
  cout<<"Call by pointer örneği"<<endl;
  yaz(num,as,fn,ort,harf);

  takas3(as,fn);
  cout<<"Call by reference örneği"<<endl;
  yaz(num,as,fn,ort,harf);

}

//----------------------------------
// https://repl.it/@ZaferYavuz1/190927
// 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 ...


// https://github.com/zyavuz610/learnCPP_inKTU
// zyavuz610
