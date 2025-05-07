#include <stdio.h>

int main() {
  int a = 15;
  float b = 20.99;
  double c = 63.7953;
  char d = 'a';
  
  printf("Integer: %lu bytes\n", sizeof(a));
  printf("Float: %lu bytes\n", sizeof(b));
  printf("Double: %lu bytes\n", sizeof(c));
  printf("Char: %lu bytes\n", sizeof(d));
}
