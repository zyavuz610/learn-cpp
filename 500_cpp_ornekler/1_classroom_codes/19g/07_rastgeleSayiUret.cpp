#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int * SayiUret(int n) {
   //static int  r[10];   // adresi geri döndürülecek dizi static olarak tanımlanmalıdır
   //static int *r = new int[n]; // static olursa hep aynı yer olur
   int *r = new int[n];

   
   // tohum setle
   srand( (unsigned)time( NULL ) );

   cout<< (unsigned)time( NULL )<<endl;
   for (int i = 0; i < n; ++i) {
      r[i] = rand()%100;
      //cout << r[i] << endl;
   }
   return r;
}

int main() {
  int n=10,SUTUN1=3,SUTUN2=4,SUTUN3=40;
	int *as = SayiUret(n);

  string hoca;
  cout<<"Ders Sorumlusu: ";
  //cin>>hoca;
  getline(cin,hoca);

  int *fn = SayiUret(n);
	
  as[2] = 21;
	cout<<setw(SUTUN1)<<"SN"
      <<setw(SUTUN2)<<"AS"
      <<setw(SUTUN2)<<"FN"
      <<setw(SUTUN3)<<"DS"
      <<endl;
	for(int i=0;i<n;i++){
		cout<<setw(SUTUN1)<<i
        <<setw(SUTUN2)<<as[i]
        <<setw(SUTUN2)<<fn[i]
        <<setw(SUTUN3)<<hoca
        <<endl;
	}
  cout<<&as[0]<<endl
      <<&fn[0]<<endl;
  return 0;
}