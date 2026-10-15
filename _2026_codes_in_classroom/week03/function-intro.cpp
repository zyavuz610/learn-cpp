#include <iostream>

using namespace std;

void greeting(string name="Person",
              string msg = "Hi",
              string ch="...");

int main(){
  string name;
  cout << "Hello, what is your name?";
  getline(cin,name);

  greeting(name, "Hello", "!");
  greeting(name, "Hello");
  greeting(name);
  greeting();
  return 0;
}

void greeting(string name,
              string pre_str,
              string post_char) {
  if (name[0] >= 'a' && name[0] <= 'z'){
    name[0] -= ('a' - 'A');
  }
  cout << pre_str << " "
       << name
       << post_char << endl;
}