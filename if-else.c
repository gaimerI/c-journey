#include <stdio.h>

int main() {
  const int x = 20;
  const int y = 15;

  if (x > y) {
    printf("x is greater than y");
  } else {
    // it isn't
  }
  
  int time = 20;
  (time < 18) ? printf("Good day.") : printf("Good evening."); // shorthand if-else, aka ternary
}
