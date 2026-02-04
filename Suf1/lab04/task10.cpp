#include <iostream>

int digits_cnt(long long num) {
    if (num == 0) return 1;
    int cnt = 0;
    while (num > 0) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int get_first(long long num) {
    int min_d = 9;

    while (num > 0) {
        int d = num % 10;

        if (d != 0 && d < min_d) {
            min_d = d;
        }

        num /= 10;
    }

    return min_d;
}

int get_min(long long num) {
    if (num == 0) {return 0;}

    int min_d = 9;

    while (num > 0) {
        int d  = num % 10;

        if (d < min_d) {
            min_d = d;
        }

        num /= 10;
    }

    return min_d;
}

long long remove_digit (long long num, int remove_d) {
    long long res = 0, place = 1;
    bool removed = false;

    while (num > 0) {
        int d = num % 10;

        if (d == remove_d && !removed) {
            removed = true;
        }
        else {
            res += d * place;
            place *= 10;
        }

        num /= 10;
    }

    return res;
}

int main() {
    long long n;
    std::cin >> n;

    long long temp = n;

    long long m = 0;

    int dig_total = digits_cnt(temp);
    int dig_used = 0;

    int first = get_first(n);
    m = first;
    dig_used++;
    n = remove_digit(n, first);

    while (dig_used < dig_total) {
        int d = get_min(n);
        m = m * 10 + d;
        dig_used++;
        n = remove_digit(n, d);
    }

    std::cout << m;
    return 0;
}