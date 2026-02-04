#include <iostream>

const int MAX_SUM = 9 * 128;

int main() {
    int N;
    std::cin >> N;

    int half = N / 2;

    long long cnt[MAX_SUM + 1] = {0};

    for (int dig = 0; dig <= 9; dig++) {
        cnt[dig] = 1;
    }

    for (int len = 2; len <= half; len++) {
        long long new_cnt[MAX_SUM + 1] = {0};

        for (int sum = 0; sum <= 9 * (len - 1); sum++) {
            for (int dig = 0; dig <= 9; dig++) {
                new_cnt[sum + dig] += cnt[sum];
            }
        }

        for (int i = 0; i <= 9 * len; i++) {
            cnt[i] = new_cnt[i];
        }
    }

    long long res = 0;
    for (int sum = 0; sum <= 9 * half; sum++) {
        res += cnt[sum] * cnt[sum];
    }

    std::cout << res << std::endl;

    return 0;
}