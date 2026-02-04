#include <iostream>

long long A[100000];
long long B[100000];

int main() {
    long long N;
    std::cin >> N;
    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if (N > 0) {
        B[0] = A[0];
        for (int i = 1; i < N; i++) {
            B[i] = B[i - 1] + A[i];
        }
    }

    for (long long i = 0; i < N; i++) {
        std::cout << B[i] << " ";
    }
    return 0;
}