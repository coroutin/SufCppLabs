#include <iostream>

int main() {
    long long a, b, sum = 0;
    std::cin >> a >> b;
    if (a > b) {long long c = a; a = b; b = c;}
    for (int i = a; i <= b; i++) {
        if (i % 3 == 0 && (i % 10 == 2 || i % 10 == 4 || i % 10 == 8)) {sum += i;}
    }
    std::cout << sum;
    return 0;
}