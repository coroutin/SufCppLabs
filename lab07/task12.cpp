#include <iostream>

int main() {
    std::cout << "Введите чётную длину билета: ";
    int N;
    std::cin >> N;
    while (N <= 0 || N % 2 != 0) {
        std::cout << "Неверная длина билета. Введите длину билета заново ";
        std::cin >> N;
    }

    int half = N / 2;

    const int MAX_SUM = 9 * half;

    long long cnt[451] = {0};

    for (int digit = 0; digit <= 9; digit++) {
        cnt[digit] = 1;
    }

    for (int len = 2; len <= half; len++) {
        long long new_cnt[451] = {0};

        for (int old_sum = 0; old_sum <= 9 * (len - 1); old_sum++) {
            for (int digit = 0; digit <= 9; digit++) {
                int new_sum = old_sum + digit;
                new_cnt[new_sum] += cnt[old_sum];
            }
        }

        for (int sum = 0; sum <= 9 * len; sum++) {
            cnt[sum] = new_cnt[sum];
        }
    }

    long long result = 0;
    for (int sum = 0; sum <= MAX_SUM; sum++) {
        result += cnt[sum] * cnt[sum];
    }

    std::cout << "Для билетов длины: "<< N << ", существет: " << result << " счастливых билетов." << std::endl;

    return 0;
}