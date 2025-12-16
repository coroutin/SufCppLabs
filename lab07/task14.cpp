#include <iostream>

int main() {
    const int MAX_SIZE = 100;
    int A[MAX_SIZE];
    int N;

    std::cout << "Введите количество элементов: ";
    std::cin >> N;
    while (N <= 0 || N > MAX_SIZE) {
        std::cout << "Неверно введено количество элементов массива" << std::endl;
        std::cout << "Введите количество элементов заново: ";
        std::cin >> N;
    }

    std::cout << "Элемент 1: ";
    std::cin >> A[0];
    std::cout << "Массив: " << A[0] << std::endl;

    for (int i = 1; i < N; i++) {
        std::cout << "Элемент " << i + 1 << ": ";
        int n;
        std::cin >> n;

        int pos = i;
        while (pos > 0 && n < A[pos - 1]) {
            A[pos] = A[pos - 1];
            pos--;
        }

        A[pos] = n;

        std::cout << "Массив: ";
        for (int j = 0; j <= i; j++) {
            std::cout << A[j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}