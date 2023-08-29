/*
For n = 2, the output should be
shapeArea(n) = 5;
For n = 3, the output should be
shapeArea(n) = 13.

verilen n için yıldız sayısı

n=1
    *

n=2
    *
   ***
    *

n=3
    *
   ***
  *****
   ***
    *

n=4
    *
   ***
  *****
 *******
  *****
   ***
    *

n=

*/

int shapeArea(int n) {
    //return ((2*n-1)*(2*n-1)) - 4*(n*n-n)/2;
    return (2*n*(n-1))+1; // sadeleşmiş hali
}