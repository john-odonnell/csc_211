#include <iostream>
void mystery(int& b, int c, int& a) {
   a ++;
   b --;
   c += a;
}

int main() {
   int a = 5;
   int b = 10;
   int c = 15;
   mystery(c, a, b);
   std::cout << a << ' ' << b << ' ' << c << "\n";
   return 0;
}