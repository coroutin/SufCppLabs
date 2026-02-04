#include <iostream>

long long A[100000];
long long B[100000];

int main() {
    long long N;
    int index = 0;
    std::cin >> N;
    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (long long i = 0; i < N; i++) {
        if (A[i] % 7 == 0) {index = i;}
    }

    if (index != 0) {std::cout << index << std::endl;}
    else {std::cout << "NO" << std::endl;}
    return 0;
}