#include <stdio.h>

int main() {
  int x = 5, y = 6, z = 50; // Declare multiple variables of the same type at once w/ different values
  printf("%d", x + y + z);
  x =  y = z = 50; // Declare multiple variables of the same type at once w/ same value
  printf("\n%d", x + y + z);
}
