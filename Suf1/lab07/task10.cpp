#include <iostream>

int main() {
    long long sum = 0;
    int N;
    std::cin >> N;

    int A[1000];

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int k1, k2;
    std::cin >> k1 >> k2;

    int left = std::min(k1, k2);
    int right = std::max(k1, k2);

    int start = std::max(left, 0);
    int end = std::min(right, N - 1);

    if (start > end) {
        std::cout << "NO";
        return 0;
    }

    for (int i = start; i <= end; i++) {
        sum += A[i];
    }

    std::cout << sum;
    return 0;
}