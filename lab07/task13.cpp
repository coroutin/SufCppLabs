#include <iostream>

const int MAX_N = 100;

int A[MAX_N];
int N;

void inv() {
    for (int i = 0; i < N; i++) A[i] = 9 - A[i];
}

void reverse() {
    for (int i = 0; i < N / 2; i++) {
        int tmp = A[i];
        A[i] = A[N - 1 - i];
        A[N - 1 - i] = tmp;
    }
}

void rsh(int k) {
    for (int i = N - 1; i >= k; i--) A[i] = A[i - k];
    for (int i = 0; i < k && i < N; i++) A[i] = 0;
}

void crsh(int k) {
    k %= N;
    if (k == 0) return;

    int tmp[MAX_N];
    for (int i = 0; i < N; i++) {
        tmp[(i + k) % N] = A[i];
    }
    for (int i = 0; i < N; i++) {
        A[i] = tmp[i];
    }
}

void lsh(int k) {
    for (int i = 0; i < N - k; i++) A[i] = A[i + k];
    for (int i = N - k; i < N; i++) A[i] = 0;
}

void clsh(int k) {
    k %= N;
    if (k == 0) return;

    int tmp[MAX_N];
    for (int i = 0; i < N; i++) {
        tmp[i] = A[(i + k) % N];
    }
    for (int i = 0; i < N; i++) {
        A[i] = tmp[i];
    }
}

void printArray() {
    for (int i = 0; i < N; i++) std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << "Введите размер массива: ";
    std::cin >> N;
    while (N <= 0 || N > MAX_N) {
        std::cout << "Неверный размер массива." << std::endl;
        std::cout << "Введите размер массива заново: ";
        std::cin >> N;
    }

    std::cout << "Введите элементы массива:" << std::endl;
    while (true) {
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }

        bool valid = true;
        for (int i = 0; i < N; i++) {
            if (A[i] < 0 || A[i] > 9) {
                valid = false;
                break;
            }
        }

        if (valid) break;
        else {
            std::cout << "Неверный элемент(ы) массива." << std::endl;
            std::cout << "Введите элементы массива заново:" << std::endl;
        }
    }

    std::cout << R"(        Команды:
1 - inv   Заменить все элементы на их дополнения до 9.
2 - reverse   Перевернуть массив.
3 - rsh k   Сдвинуть массив вправо на k элементов.
4 - crsh k   Циклический сдвиг вправо на k элементов.
5 - lsh k   Сдвинуть массив влево на k элементов.
6 - clsh k   Циклический сдвиг влево.
0 - exit   Выход)" << std::endl;
    std::cin.ignore();

    while (true) {
        std::cout << "Выберите команду: ";
        int cmd;
        int k;

        std::cin >> cmd;

        if (cmd >=3 && cmd <= 6) {
            std::cout << "Введите параметр k: ";
            std::cin >> k;
            while (k <= 0) {
                std::cout << "Неверный параметр." << std::endl;
                std::cout << "Введите параметр k заново: ";
                std::cin >> k;
            }
        }

        if (cmd == 0) {
            std::cout << "Досвидан dear юзер" << std::endl;
            break;
        }

        switch (cmd) {
            case 1: inv(); break;
            case 2: reverse(); break;
            case 3: rsh(k); break;
            case 4: crsh(k); break;
            case 5: lsh(k); break;
            case 6: clsh(k); break;
            default:
                std::cout << "Неверная команда." << std::endl;
                continue;
        }

        printArray();
    }

    return 0;
}