#include <iostream>
//in cpp, numbers are int and floating points are double by default
int main(){

   //implicit tc(automatic by complier)
   int a = 5;
   float b = 10.5;
   double c = a * b;//integer value 'a' is auto promoted to double (5.0)
   std::cout << "c = " << c << '\n';

   char letter = 'A';
   int asciiValue = letter;//'A' is auto converted to is ASCII integer value
   std::cout << "ASCII = " << asciiValue << '\n';

   //explicit tc(manual casting)
   int x = 10, y = 3;
   double z = static_cast<double>(x) / y;//it forces explicit conversion. We can use C-style (doble)x/y too.
   std::cout <<"Division: " << z << '\n';

   char ch = 'a';
   std::cout << (int)ch + ch << '\n';//'a' is explicitly converted to its ASCII value

    return 0;
}