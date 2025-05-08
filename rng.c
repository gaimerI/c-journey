#include <stdio.h>

unsigned short rng_function(unsigned short input);

unsigned short currentRNG;

int main() {
  currentRNG = 0;
  
  int i;

  for(i = 0; i <=5; i++) {
    printf("%hu\n", currentRNG);
    currentRNG = rng_function(currentRNG);
  }
}

unsigned short rng_function(unsigned short input) {
  if (input == 0x560A) input = 0;
  unsigned short s0 = (unsigned char) input << 8;
  s0 = s0 ^ input;
  short s1 = (s0 >> 1) ^ 0xFf80;
  if ((s0 & 1) == 0) {
    if (s1 == 0xAA55) input = 0; else input = s1 ^ 0x1FF4;
  } else {
    input = s1 ^ 0x8180;
  }
  return (unsigned short) input;
}
