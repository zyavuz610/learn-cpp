#include<iostream>
using namespace std;

//-----------------------------------------------------------------
// class decleration
class CitizenID{
    public:
        CitizenID(string _id = "100000001");
        void setFamilyID(string _id);
        string getCitizenID();
    private:
        string familyID;
};
//-----------------------------------------------------------------
CitizenID::CitizenID(string _id){
    familyID = _id;
}

void CitizenID::setFamilyID(string _id){
    familyID = _id;
}

string CitizenID::getCitizenID(){
    short int t[11];
    for(int i=0;i<9;i++){
        t[i] = familyID[i] - '0';
    }
    t[9] = (    7*(t[0]+t[2]+t[4]+t[6]+t[8])
                -(t[1]+t[3]+t[5]+t[7])         )%10;
    int sum = 0;
    for(int i=0;i<10;i++){
        sum += t[i];
    }
    t[10] = sum % 10;
    char rt[11];
    for(int i=0;i<11;i++){
        rt[i] = t[i] + '0';
    }
    return string(rt);
}

int main(){
    CitizenID tc,tc2("123456789");
    cout<<"TCKN of Atatürk: "<<tc.getCitizenID()<<endl;
    cout<<"TCKN 2: "<< tc2.getCitizenID() <<endl;
    return 0;
}
