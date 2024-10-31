#include <iostream>
using namespace std;

class Zaman {
    public:
        void setTime(int h,int m,int s){
            saat = h;
            dakika = m;
            saniye = s;
        }
        void setTime(string s){
            int start=0,stop=0;
            for(int i=start;i<s.length();i++){
                if(s[i] == ':'){
                    stop = i;
                    break;
                }
            }
            saat = atoi(s.substr(start,stop-start).c_str());
            start = stop + 1;
            for(int i=stop+1;i<s.length();i++){
                if(s[i] == ':'){
                    stop=i;
                    break;
                }
            }
            dakika = atoi(s.substr(start,stop-start).c_str());
            saniye = atoi(s.substr(stop+1,s.length()-stop-1).c_str());
        }
        void print(){
            if (saat<10) cout<<"0";
            cout<<saat<<":";
            if (dakika<10) cout<<"0";
            cout<<dakika<<":";
            if (saniye<10) cout<<"0";
            cout<<saniye<<endl;
        }
        void incrementSecond(int n){
            saniye += n;
            dakika += saniye/60;
            saniye = saniye%60;
            /*
            saniye += n;
            if(saniye >= 60){
                dakika++;
                saniye %= 60;
            }
            */
        }
    private:
        int saat;
        int dakika;
        int saniye;
};

int main(){
    Zaman t1;
    //t1.setTime(10,20,33);
    t1.setTime("09:01:59");
    cout<<"Önce: ";
    t1.print();
    t1.incrementSecond(2);
    cout<<"Sonra: ";
    t1.print();
    return 0;
}