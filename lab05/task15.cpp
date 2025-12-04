void min_odd_digit(long long n, int &mn, int &pos_mn) {
    mn = -1;
    pos_mn = -1;

    long long t = n;
    int len = 0;
    while (t > 0) {
        len++;
        t /= 10;
    }

    int pos_from_right = 1;
    while (n > 0) {
        int d = n % 10;

        if (d % 2 == 1) {
            int left_pos = len - pos_from_right + 1;
            if (mn == -1 || d < mn || (d == mn && left_pos < pos_mn)) {
                mn = d;
                pos_mn = left_pos;
            }
        }

        n /= 10;
        pos_from_right++;
    }
}