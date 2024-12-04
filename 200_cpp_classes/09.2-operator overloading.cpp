/*
# Operator Overloading
## Neden Gerekli?
   * bilinen operatörklerin nesneler için de çalışmasını sağlamak için kullanılır
   * Örn; Complex c1,c2;
   * c1 = c1 + c2;  
   * saat bilgilerinin farkının için operator overloading gerekli
   * benzer şekilde
      * komplex sayı toplanması
      * saat karşılaştırma
      * alan farkı vb..
   * operator anahtar kelimesi kullanılır
   * şu operatorler aşırı yüklenemz
      .   ::   ?:   sizeof
   * şu operatörler aşırı yüklenebilir
   * +, -, ++, *, /, <<, (), [], vd...
//------------------------------------------------------------   
aşırı yükleme, member funk. ya da friend func olarak tanımlanabilir
operatör AŞIRI YÜKLEME - friend funcion vs. member function
member func.
   "s1 + s2" ifadesi "s1.operator+(s2)" haline dönüşür. 
   Bu şu demek, fonk. ilk objenin alt fonk. olarak çağrılır.
friend func.
   * ancak s1 + s2 de ilk operand obje değilse problem oluşur.
   * 10 + s1, ya da s1 + 10 ifadeleri hata verir
   * s1 + 10 ifadesi aşırı yükleme ile düzeltilebilir
   * ancak yine de private elamanlara erişecek şekilde friend func. tanımlanarak problem çözülür,
   * aşağıda <<, >> kısmında örnek mevcut, bakınız...
   
*/

