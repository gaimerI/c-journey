#include <stdio.h>

int main() {
  int number = 15; // Integer type

  float decimal; // Declare variable without setting
  decimal = 12.96;

  char letter = 'a'; // Single character, single quotes

  printf("My favourite number is %d", number);
  printf("\nDecimals permitted, it is %f", decimal);
  printf("\nFor favourite letter, it's %c", letter);
  printf("\n");
  printf("I can use multiple variables here, like %d and %f.", number, decimal);
  print("\nIt is also possible to use format specifiers w/o variables: %d", 15);
}
