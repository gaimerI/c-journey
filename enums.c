#include <stdio.h>

enum levels { // enums for constants that don't change
  LOW = 1,
  MEDIUM, // 2
  HIGH // 3
}

int main() {
  enum level variable = MEDIUM;
  printf("%d", level);
}
