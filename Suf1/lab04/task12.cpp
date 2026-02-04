#include <iostream>

long long fibonacci(long long n) {
    if (n <= 1) {return n;}

    long long a = 0, b = 1;

    for (long long i = 2; i <= n; ++i) {
        long long temp = b;
        b += a;
        a = temp;
    }
    return b;
}

int main() {
    int k;
    std::cin >> k;

    int position = 0;
    int fib_numb = 1;

    while (position < k) {
        long long num = fibonacci(fib_numb);
        fib_numb++;

        long long temp = num;
        int dig_cnt = 0;

        while (temp > 0) {
            dig_cnt++;
            temp /= 10;
        }

        for (int i = dig_cnt - 1; i >= 0; i--) {
            position++;

            long long digit = num;
            for (int j = 0; j < i; j++) {
                digit /= 10;
            }
            digit %= 10;

            if (position == k) {
                std::cout << digit;
                return 0;
            }
        }
    }
    return 0;
}