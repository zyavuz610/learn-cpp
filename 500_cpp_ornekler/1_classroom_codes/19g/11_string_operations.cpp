#include <iostream>
using namespace std;

string temizle(string s){
  int boy = s.length();
  if(s[boy-1] == ','){
    return s.substr(0,boy-1);
  }
  return s;
}

int main() {
  string s;
  cout<<"İsim:";
  getline(cin,s);
  cout<<"isim:"<<s<<endl;
  s.replace(0,10,"ord. prof. ");
  cout<<"yeni isim: "<<s<<endl;
  /*
kullanıcıdan bir string al

"prof. dr. mustafa ulutaş"


"ord. prof. mustafa ulutaş"

getline(cin,str)

*/

/*


  cout<<temizle("korkma")<<endl;
  string str1 = "Merhaba";
  string str2,str3;
  cout<<"Adınız: ";
  cin>>str2;
  str3 = str1 + " " + str2;
  cout << str3<<endl;
  cout<<"Boy:"<<str2.size()<<endl;
  cout<<"Uzunluk:"<<str2.length()<<endl;
  cout<<"Kapasite:"<<str2.capacity()<<endl;

  */
}