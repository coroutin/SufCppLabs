#include <iostream>
#include <vector>

int main() {
    int n, c;
    std::cin >> n >> c;

    std::vector<int> cnt(100001, 0);

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        cnt[a]++;
    }

    long long answer = 0;

    for (int i = 1; i <= 100000; i++) {
        if (cnt[i] > 0) {
            answer += std::min(cnt[i], c);
        }
    }

    std::cout << answer;
    return 0;
}
