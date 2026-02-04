#include <iostream>

long long A[100000];

int main() {
    long long N;
    std::cin >> N;
    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (long long i = 0; i < N; i++) {
        if (A[i] % 3 == 0) {
            std::cout << "true" << ' ';
        }
        else {std::cout << "false" << ' ';}
    }
    return 0;
}