#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> p(n + 1);
    p[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        p[i] = p[i - 1] + x;
    }

    int k;
    std::cin >> k;

    while (k--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << p[r + 1] - p[l] << '\n';
    }

    return 0;
}