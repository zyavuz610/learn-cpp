#include <iostream>
using namespace std;

void notOrtalama();

int main() {
    // 1 boyutlu dinamik bir dizi
    int *p;
    int n=5;
    p = new int[n];

    // erişim
    p[3] = 23;
	*p = 35; // p[1] = 35 yapar
    for(int i=0;i<n;i++){
        cout<<i<<":"<<p[i]<<endl;
    }
    cout<<"-------------------------------------"<<endl;
    // öğrenci not ortalaması örneği
    notOrtalama();
  return 0;
}

void notOrtalama(){
    int n;
    cout<<"n:";
    cin>>n;
    double toplam=0;
    double *notlar = new double[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" > ";
        cin>>notlar[i];
        toplam+=notlar[i];
    }
    cout<<"ort:"<<toplam/n<<endl;
}
