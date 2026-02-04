#include <iostream>

int main() {
    long long m, m1, n, n1;
    std::cin >> m >> n;
    m1 = abs(m);
    n1 = n;

    while (n1 != 0) {
        long long kami = m1 % n1;
        m1 = n1;
        n1 = kami;
    }
    long long contestFaeces1 = m / m1;
    long long contestFaeces2 = n / m1;
    std::cout << contestFaeces1 << " " << contestFaeces2;
}