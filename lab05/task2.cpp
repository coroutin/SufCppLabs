#include <iostream>

long long sum(long long num) {
    long long sum = 0;

    while (num > 0) {
        int d = num % 10;
        sum += d;
        num /= 10;
    }
    return sum;
}

int main() {
    long long num;
    bool yes = false;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> num;

        if (sum(num) > 5) {
            if (yes) {std::cout << " ";}
            std::cout << num;
            yes = true;
        }
    }
    if (!yes) {std::cout << "NO"; return 0;}
    return 0;
}