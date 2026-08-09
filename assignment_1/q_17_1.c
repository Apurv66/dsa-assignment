#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a = 36, b = 24;
    printf("gcd = %d\n", gcd(a, b));
    return 0;
}