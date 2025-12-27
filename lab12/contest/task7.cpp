#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long cur = a[0];
    long long ans = a[0];

    for (int i = 1; i < n; ++i) {
        if ((a[i] % 2 + 2) % 2 != (a[i - 1] % 2 + 2) % 2) {
            cur = std::max(a[i], cur + a[i]);
        } else {
            cur = a[i];
        }
        ans = std::max(ans, cur);
    }

    std::cout << ans;
    return 0;
}