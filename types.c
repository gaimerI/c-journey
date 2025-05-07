#include <stdio.h>

int main() {
  int a = 15;
  float b = 20.99;
  double c = 63.7953;
  char d = 'a'; // Chars can also use numeric ASCII values, like 65 for 'a'
  // Strings are arrays of chars
  
  printf("Integer: %d\n", a);
  printf("Float: %f\n", b);
  printf("Double: %lf\n", c);
  printf("Char: %c\n", d);
}
