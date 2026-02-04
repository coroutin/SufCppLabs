#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cnt(100001, 0);

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    bool found = false;
    for (int i = 1; i <= 100000; ++i) {
        if (cnt[i] >= 3) {
            std::cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        std::cout << -1;
    }

    return 0;
}