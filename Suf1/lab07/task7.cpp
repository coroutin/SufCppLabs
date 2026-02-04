#include <iostream>

long long A[100000];

int main() {
    long long N;
    int index = 0;
    std::cin >> N;

    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (long long i = 0; i < N; i++) {
        if (index % 2 == 0 && A[i] < 0) {A[i] += index;}
        index++;
    }

    for (long long i = 0; i < N; i++) {
        std::cout << A[i] << ' ';
    }

    return 0;
}