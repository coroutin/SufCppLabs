#include <iostream>

int main() {
    int n = 0;
    scanf("%d", &n);
    int m = n % 10;
    int f = (m * 1000 + n) * 2;
    printf("%d", f);
}