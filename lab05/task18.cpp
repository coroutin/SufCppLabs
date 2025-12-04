int zero_digits_count(long long n) {
    int cnt = 0;
    int pos = 0;

    while (n > 0) {
        if (pos % 2 == 0 && (n & 1) == 1) {
            cnt++;
        }
        n >>= 1;
        pos++;
    }
    return cnt;
}