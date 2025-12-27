#include <iostream>

long long A[100000];

bool Prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}


int main() {
    long long N;
    std::cin >> N;
    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (long long i = 0; i < N; i++) {
        if (Prime(A[i])) {
            std::cout << A[i] << " ";
        }
    }
    return 0;
}