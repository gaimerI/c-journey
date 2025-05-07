#include <stdio.h>

int main() {
  float b = 20.99;
  
  printf("Six decimals: %f\n", b);
  printf("One decimal: %.1f\n", b); // Rounds to 21.0
  printf("Two decimals: %.2f\n", b);
  printf("Three decimals: %.3f\n", b);
}
