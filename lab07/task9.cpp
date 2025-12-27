#include <iostream>

long long A[50];

int main() {
    long long N, product = 1;
    int index = 0;
    std::cin >> N;

    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        if (A[i] < 0 && abs(A[i]) % 10 == 3) {
            index = i;
        }
    }

    if (index == 0 || index == N - 1) {
        std::cout << "NO";
        return 0;
    }

    for (int i = index + 1; i < N; i++) {
        product *= A[i];
    }

    std::cout << product;
    return 0;
}