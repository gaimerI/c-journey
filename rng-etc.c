#include <stdio.h>

unsigned short rng_function(unsigned short input);
void rng_seed(unsigned short seed);
int rng_bool();
unsigned short rng_range(unsigned short min, unsigned short max);
double square_root(double number);

unsigned short currentRNG;

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

void rng_seed(unsigned short seed) {
  currentRNG = seed;
}

int rng_bool() {
    currentRNG = rng_function(currentRNG);
    return currentRNG & 1;
}

unsigned short rng_range(unsigned short min, unsigned short max) {
    unsigned short rand = rng_function(currentRNG);
    currentRNG = rand;
    return min + (rand % (max - min + 1));
}

double square_root(double number) {
  if (number < 0) {
    return -1; // Return -1 for negative numbers (sqrt is not defined)
  }
  if (number == 0 || number == 1) {
    return number; // The square root of 0 is 0, and the square root of 1 is 1
  }
  double guess = number / 2.0; // Initial guess
  double epsilon = 0.00001; // Precision level
  while ((guess * guess - number) > epsilon || (number - guess * guess) > epsilon) {
    guess = (guess + number / guess) / 2.0; // Update guess using Newton's method
  }
  return guess;
}
