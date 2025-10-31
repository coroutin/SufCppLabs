#include <iostream>

int main() {
    long long n, sum = 0;
    std::cin >> n;
    for (int i = 1; i < n; i ++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        std::cout << sum<< std::endl;
        std::cout << "YES";
    }
    else if (n == 1) {std::cout << 1 << std::endl;
        std::cout << "NO";}
    else {std::cout << sum<< std::endl; std::cout << "NO";}

    return 0;
}