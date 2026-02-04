#include <algorithm>
#include <cmath>

int max_digit(long long n) {
    n = llabs(n);
    if (n == 0) return 0;

    int mx = 0;
    while (n > 0) {
        mx = std::max(mx, (int)(n % 10));
        n /= 10;
    }
    return mx;
}


int max_digit(long long n, int &pos_mx) {
    n = llabs(n);

    if (n == 0) {
        pos_mx = 1;
        return 0;
    }

    int mx = -1;
    int pos_from_start = 0;
    long long t = n;
    int total_digits = 0;

    while (t > 0) {
        total_digits++;
        t /= 10;
    }

    t = n;
    int current_pos = total_digits;

    while (t > 0) {
        int dig = t % 10;
        if (dig >= mx) {
            mx = dig;
            pos_from_start = current_pos;
        }
        t /= 10;
        current_pos--;
    }

    pos_mx = pos_from_start;
    return mx;
}

void max_digit(long long n, int &mx, int &pos_mx) {
    mx = max_digit(n, pos_mx);
}