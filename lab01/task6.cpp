#include <iostream>

int main() {
    long long n;
    int eta;
    std::cin >> n >> eta;
    long long poln = (n - 1) / eta;
    long long nepoln = n - poln * eta;
    long long t = n + eta * (poln * (poln - 1) / 2) + poln * nepoln;

    std::cout << t << std::endl;

    return 0;
}