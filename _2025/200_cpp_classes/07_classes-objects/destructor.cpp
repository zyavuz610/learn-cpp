#include <iostream>
 
using namespace std;
class Line {
   public:
      void setLength( double len );
      double getLength( void );
      Line();   // This is the constructor declaration
      ~Line();  // This is the destructor: declaration
 /*
    bir sınıfın sadece bir adet yıkıcı methodu olabilir
    sınıftan türetilen nesne ömrü bittiğinde çalıştırılır,
    sınıfla ilgili çalıştırılacak en son method dur.

    Constructor (yapıcı metot) nesneyi kullanıma hazırlarken, destructor da nesneyi temizlemek ve kaynaklarını serbest bırakmak için kullanılır.
      Destructor'lar genellikle dinamik olarak ayrılmış bellekleri serbest bırakmak, dosyaları kapatmak veya diğer temizleme işlemlerini gerçekleştirmek için kullanılır.
 */
   private:
      double length;
};
 
// Member functions definitions including constructor
Line::Line(void) {
   cout << "Object is being created" << endl;
}
Line::~Line(void) {
   cout << "Object is being deleted" << endl;
}
void Line::setLength( double len ) {
   length = len;
}
double Line::getLength( void ) {
   return length;
}

// Main function for the program
int main() {
   Line line;
 
   // set line length
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   return 0;
}
