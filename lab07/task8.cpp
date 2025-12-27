#include <iostream>

long long A[50];

int main() {
    long long N, Ao, B, product = 1;
    bool find = false;
    std::cin >> N;

    for (long long i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cin >> Ao >> B;

    for (long long i = 0; i < N; i++) {
        if (A[i] >= Ao && A[i] <= B) {find = true; product *= A[i];}
    }

    if (!find) {std::cout << "NO" << std::endl;} else {std::cout << product << std::endl;}

    return 0;
}