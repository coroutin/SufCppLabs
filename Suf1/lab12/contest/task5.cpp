#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::pmr::string s;
    std::cin >> s;

    std::vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int weight = s[i - 1] - 'a' + 1;
        pref[i] = pref[i - 1] + weight;
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << pref[r] - pref[l - 1] << '\n';
    }

    return 0;
}