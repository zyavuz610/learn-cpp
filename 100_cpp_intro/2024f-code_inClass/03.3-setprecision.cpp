#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    double d = 20.3343;
    cout<<"fixed oncesi: "<<d<<endl;
    cout<<fixed;
    cout<<"fixed sonrasi: "<<d<<endl;
    cout<<defaultfloat;
    cout<<"fixed pasif edildi: "<<d<<endl;
    //cout<<fixed;
    cout<<setprecision(3);
    cout<<"setprecision(2) sonrasi: "<<d<<endl<<endl;

    for(int i=0;i<30;i++){
        cout<< ((i+1)%10);
    }
    cout<<endl;
    cout<<setw(8)<<"abc";
    cout<<setw(8)<<d;
    cout<<setw(8)<<d;
    return 0;
}