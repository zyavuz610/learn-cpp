#include <iostream>
using namespace std;

int len(char *a){
    int i=0;
    while(a[i] != '\0') i++;
    return i;
}
int sum(int *a,int n){
    int s=0;
    for(int i=0;i<n;i++){
        s += a[i];
    }
    return s;
}
int find(int *a, int n,int e){
    for(int i=0;i<n;i++){
        if(a[i] == e){
            return i;
        }
    }
    return -1;
}
void upper(char *a){
    while(*a != '\0'){
        if(*a >= 'a' && *a <= 'z')
           *a -= ('a' - 'A'); 
         a++;
    }
}

int main(){
    char a[] = "zafer";
    cout<<a<<":"<<len(a)<<endl;
    upper(a);
    cout<<a<<":"<<len(a)<<endl;
    int a2[] = {10,20,30,40,50};
    cout<<"Toplam:"<<sum(a2,2)<<endl;
    cout<<"Eleman Yeri:"<<find(a2,5,420)<<endl;
    return 0;
}