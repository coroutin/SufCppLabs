#include <math.h>
#include <iostream>

int main() {
    int a, x;
    scanf("%d %d", &a, &x);
    long long y = abs(pow(x, 5) + abs(a * x - pow(x,3)) - a) + a * pow(x, 2) + pow(a, 8);
    printf("%lld", y);
}