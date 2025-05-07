#include <stdio.h>

int main() {
  int i = 0;

  while (i <= 10) { // repeats until i is greater than 10
    printf("%d\n", i);
    i++;
  }

  printf("\n");
  
  do { // repeats the loop at least once.
    printf("%d\n", i);
  } while (i < 10);
  
}
