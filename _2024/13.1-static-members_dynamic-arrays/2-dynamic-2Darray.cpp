#include <iostream>
using namespace std;

void notOrtalama();

int main() {
    int rowCount = 5, colCount = 3;
    int **a;  // 2D array
	a = new int*[rowCount];

	for(int i = 0; i < rowCount; ++i)
    	a[i] = new int[colCount];
    
    cout<<"-------------------------------------"<<endl;
    for(int i = 0; i < rowCount; ++i)
        cout<<"a["<<i<<"]:"<<a[i]<<endl;
    cout<<"-------------------------------------"<<endl;
    //erişim :   a[i][j] veya *(a+i*colCount + j) ??
	
	// bellekten silinmesi
	for(int i = 0; i < colCount; ++i) {
    	delete [] a[i];
	}
	delete [] a;
    cout<<"-------------------------------------"<<endl;
    // öğrenci not ortalaması örneği
    notOrtalama();
  return 0;
}

void notOrtalama(){
    // öğrenci arasınav ortalamaları
    int n,m;
    cout<<"number-of-students:";  cin>>n;
    cout<<"number-of-projects:";  cin>>m;
    double *sinifOrtalama   = new double[m];
    double *ogrOrtalama     = new double[n];
    double **notlar         = new double*[n];
    for(int i=0;i<n;i++){
        notlar[i] = new double[m];
    }
    for(int i=0;i<n;i++){
        cout<<i+1<<". student:"<<endl;
        for(int j=0;j<m;j++){
        cout<<j+1<<". project grade:";
        cin>>notlar[i][j];
        }
    }
    for(int j=0;j<m;j++){
        sinifOrtalama[j] = 0;
    }
    double satirtoplam = 0;
    double sutuntoplam = 0;
    double toplam = 0, ort = 0;
    for(int i=0;i<n;i++){
        sutuntoplam = 0;
        for(int j=0;j<m;j++){
        sutuntoplam       += notlar[i][j];
        sinifOrtalama[j]  += notlar[i][j];
        }
        ogrOrtalama[i] = sutuntoplam / m;
    }
    for(int j=0;j<m;j++){
        sinifOrtalama[j] /= n;
    }
    cout<<"student-project-averages:"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" > "<<ogrOrtalama[i]<<endl;
    }
    cout<<"project-averages:"<<endl;
    for(int j=0;j<m;j++){
        cout<<j+1<<" > "<<sinifOrtalama[j]<<endl;
    }
}
