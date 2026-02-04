#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    int m;
    std::cin >> m;

    std::vector<int> pref(n, 0);

    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1];
        if (s[i] == s[i - 1]) {
            pref[i]++;
        }
    }

    while (m--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << pref[r - 1] - pref[l - 1] << '\n';
    }

    return 0;
}