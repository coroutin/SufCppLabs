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

    int answer = 0;
    for (int i = 1; i <= 100000; ++i) {
        if (cnt[i] > answer) {
            answer = cnt[i];
        }
    }

    std::cout << answer;
    return 0;
}
