#include <stdio.h>

/*
CUSTOM TYPES
*/
typedef struct { // custom Vec2 type!
  double x, y;
} Vec2;

/*
MACROS
*/

#define DEG2RAD(angle) ((angle) * 0.01745329251)
#define RAD2DEG(rad) ((rad) * 57.2957795131)

/*
FUNCTION DECLARATIONS
*/

unsigned short rng_function(unsigned short input);
Vec2 vec2_define(double x, double y);
Vec2 vec2_add(Vec2 a, Vec2 b);
Vec2 vec2_sub(Vec2 a, Vec2 b);
double vec2_length(Vec2 v);
Vec2 vec2_normalize(Vec2 v);
void rng_seed(unsigned short seed);
int rng_bool();
unsigned short rng_range(unsigned short min, unsigned short max);
double square_root(double number);
double clamp(double val, double min, double max);
double lerp(double a, double b, double t);

/*
GLOBAL CONSTANTS
*/

unsigned short currentRNG;

/*
FUNCTION BODIES
*/

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
    return -1;
  }
  if (number == 0 || number == 1) {
    return number;
  }
  double guess = number / 2.0;
  double epsilon = 0.00001;
  while ((guess * guess - number) > epsilon || (number - guess * guess) > epsilon) {
    guess = (guess + number / guess) / 2.0;
  }
  return guess;
}

double clamp(double val, double min, double max) {
  if (val < min) return min;
  if (val > max) return max;
  return val;
}

double lerp(double a, double b, double t) {
  return a + (b - a) * t;
}

Vec2 vec2_define(double x, double y) {
  Vec2 v;
  v.x = x;
  v.y = y;
  return v;
}

Vec2 vec2_add(Vec2 a, Vec2 b) {
  return (Vec2){a.x + b.x, a.y + b.y};
}

Vec2 vec2_sub(Vec2 a, Vec2 b) {
  return (Vec2){a.x - b.x, a.y - b.y};
}

double vec2_length(Vec2 v) {
  return square_root(v.x * v.x + v.y * v.y);
}

Vec2 vec2_normalize(Vec2 v) {
  double len = vec2_length(v);
  if (len == 0) return (Vec2){0, 0};
  return (Vec2){v.x / len, v.y / len};
}

Vec2 vec2_scale(Vec2 v, double s) {
    return (Vec2){v.x * s, v.y * s};
}

double vec2_dot(Vec2 a, Vec2 b) {
    return a.x * b.x + a.y * b.y;
}

Vec2 vec2_lerp(Vec2 a, Vec2 b, double t) {
    return (Vec2){
        lerp(a.x, b.x, t),
        lerp(a.y, b.y, t)
    };
}

Vec2 vec2_perpendicular(Vec2 v) {
    return (Vec2){-v.y, v.x};
}

/*
MAIN
*/

int main() {
    // Test vec2_define, vec2_add, vec2_sub
    Vec2 v1 = vec2_define(3.0, 4.0);
    Vec2 v2 = vec2_define(1.0, 2.0);
    Vec2 sum = vec2_add(v1, v2);
    Vec2 diff = vec2_sub(v1, v2);

    printf("v1 = (%.2f, %.2f)\n", v1.x, v1.y);
    printf("v2 = (%.2f, %.2f)\n", v2.x, v2.y);
    printf("Sum = (%.2f, %.2f)\n", sum.x, sum.y);
    printf("Diff = (%.2f, %.2f)\n", diff.x, diff.y);

    // Test vec2_length and vec2_normalize
    double length = vec2_length(v1);
    Vec2 norm = vec2_normalize(v1);
    printf("Length of v1 = %.4f\n", length);
    printf("Normalized v1 = (%.4f, %.4f)\n", norm.x, norm.y);

    // Test RNG
    rng_seed(12345);
    printf("Random booleans: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rng_bool());
    }
    printf("\n");

    printf("Random numbers in range [10, 20]: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rng_range(10, 20));
    }
    printf("\n");

    // Test square_root
    double num = 25.0;
    printf("Square root of %.2f = %.4f\n", num, square_root(num));

    // Test clamp and lerp
    printf("Clamp 15 in [0, 10]: %.2f\n", clamp(15, 0, 10));
    printf("Lerp between 0 and 100 at t=0.25: %.2f\n", lerp(0, 100, 0.25));

    return 0;
}
