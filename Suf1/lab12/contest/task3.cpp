#include <iostream>
#include <vector>

int main() {
    int k;
    std::cin >> k;

    std::vector<int> queries(k);
    int max_n = 0;

    for (int i = 0; i < k; ++i) {
        std::cin >> queries[i];
        if (queries[i] > max_n)
            max_n = queries[i];
    }

    std::vector<int> digit_sum(max_n + 1, 0);
    std::vector<long long> pref(max_n + 1, 0);

    for (int i = 1; i <= max_n; ++i) {
        digit_sum[i] = digit_sum[i / 10] + (i % 10);
        pref[i] = pref[i - 1] + digit_sum[i];
    }

    for (int i = 0; i < k; ++i) {
        std::cout << pref[queries[i]] << '\n';
    }

    return 0;
}