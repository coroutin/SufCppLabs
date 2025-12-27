#include <iostream>

int main() {
    long long sum = 0;
    int N;
    std::cin >> N;

    int A[100000];

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        if (A[i] > 0 && A[i + 1] > 0) {
            std::cout << i << " " << i + 1;
            return 0;
        }
    }

    std::cout << "NO";
    return 0;
}