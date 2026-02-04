#include <iostream>

long long A[100000];

int main() {
    long long N;
    std::cin >> N;

    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (long long i = 0; i < N; i++) {
        if (A[i] % 2 == 0) {A[i] *= A[i];}
        else {A[i] *= 2;}
    }

    for (long long i = 0; i < N; i++) {
        std::cout << A[i] << ' ';
    }

    return 0;
}