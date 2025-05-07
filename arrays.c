#include <stdio.h>

int main() {
  int list[5]; // defining an array by its size

  list[0] = 2;
  list[1] = 4;
  list[2] = 8;
  list[3] = 16;
  list[4] = 32;

  printf("Array items are:");
  
  int i;
  for(i = 0; i < 5; i++) {
    printf("  %d\n", list[i]);
  }

  printf("\nArray size is: %lu\n", (unsigned long) sizeof(list));

  int length = sizeof(list) / sizeof(list[0]);

  printf("But length of array is %d?", length);
}
