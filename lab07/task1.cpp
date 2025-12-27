#include <iostream>

long long A[100000];
long long B[100000];

int main() {
    long long N;
    std::cin >> N;
    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (long long i = 0; i < N; i++) {
        B[i] = A[i] * A[i] + 2 * A[i] - 1;
    }

    for (long long i = 0; i < N; i++) {
        std::cout << B[i] << " ";
    }
    return 0;
}