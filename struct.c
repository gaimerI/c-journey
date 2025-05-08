#include <stdio.h>

struct words { // Structs are like JS classes and methods
  char greeting[30];
  char place[20];
};

int main() {
  struct words s1 = {"Hello", "World"}; // Strings cannot be put into a structure one by one without string copying

  printf("%s, %s", s1.greeting, s1.place);
}
