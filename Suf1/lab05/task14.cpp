#include <iostream>

int max_digit(long long n) {

    if (n == 0) return 0;

    int max_dig = 0;

    while (n > 0) {
        int dig = n % 10;
        if (dig > max_dig) {
            max_dig = dig;
        }
        n /= 10;
    }

    return max_dig;
}


int max_digit(long long n, int &pos_mx) {

    if (n == 0) {
        pos_mx = 1;
        return 0;
    }

    int max_dig = -1;
    int max_pos_end = 0;
    int total_digs = 0;

    long long temp = n;
    while (temp > 0) {
        total_digs++;
        int dig = temp % 10;

        if (dig > max_dig) {
            max_dig = dig;
            max_pos_end = total_digs;
        }

        temp /= 10;
    }

    pos_mx = total_digs - max_pos_end + 1;

    return max_dig;
}

void max_digit(long long n, int &mx, int &pos_mx) {
    mx = max_digit(n, pos_mx);
}

int main() {
    long long n = 3562;

    std::cout << max_digit(n) << std::endl;

    int pos;
    std::cout << max_digit(n, pos) << " " << pos << std::endl;

    int mx, pos2;
    max_digit(n, mx, pos2);
    std::cout << mx << " " << pos2 << std::endl;

    return 0;
}