#include <iostream>

int del_count(long long num) {
    if (num <= 0) return 0;

    int c = 0;
    for (long long i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            c += (i == num / i) ? 1 : 2;
        }
    }
    return c;
}

int main() {
    long long a, b;
    std::cin >> a >> b;

    long long max_num = 0;
    int max_divs = 0;

    for (long long i = a; i <= b; i++) {
        if (max_divs <= del_count(i)) {
            if (max_divs == del_count(i) && max_num < i) {max_num = i;}
            else {max_num = i; max_divs = del_count(i);}
        }
    }
    std::cout << max_num << " " << max_divs<< '\n';
}