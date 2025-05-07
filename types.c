#include <stdio.h>
#include <stdbool.h>

int main() {
  int a = 15;
  float b = 20.99;
  double c = 63.7953;
  char d = 'a'; // Chars can also use numeric ASCII values, like 65 for 'a'
  // Strings are arrays of chars
  bool f = true; // Booleans are not built in, they require stdbool.h
  int g[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Array, all of same type
  
  printf("Integer: %d\n", a);
  printf("Float: %f\n", b);
  printf("Double: %lf\n", c);
  printf("Char: %c\n", d);
  printf("Bool: %d\n", f); // Booleans are processed as 0 or 1
  printf("Array: %d\n", g); // This actually fails, due to the array having many ints
  printf("Array item: %d\n", g[0]); // Array items are called with an index
}
