#include <stdio.h>

int gcd(int a, int b); // function prototype thingamajig

int main() {
    printf("GCD of 20 and 12 is: %d\n", gcd(20, 12));
    return 0;
}

int gcd(int a, int b) {
    int smaller = (a < b) ? a : b;
    int gcd = 1;

    for (int i = 1; i <= smaller; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}
