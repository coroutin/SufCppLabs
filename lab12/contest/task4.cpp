#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        total += a[i];
    }

    if (total % 2 != 0) {
        std::cout << 0;
        return 0;
    }

    long long half = total / 2;
    long long left = 0;
    int answer = 0;

    for (int i = 0; i < n - 1; ++i) {
        left += a[i];
        if (left == half) {
            ++answer;
        }
    }

    std::cout << answer;
    return 0;
}