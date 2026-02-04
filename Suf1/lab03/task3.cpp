#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int k = 0;
    int p = -1;
    int m = 9;
    while (n > 0) {
        int d = n % 10;
        if (d < m) {
            m = d;
            p = k;
        }
        n /= 10;
        k++;
    }
    std::cout << m << " " << p;
    return 0;
}