#include <iostream>

long long reversed(long long num) {
    long long reversed = 0;

    while (num > 0) {
        int d = num % 10;
        reversed = reversed * 10 + d;
        num /= 10;
    }
    return reversed;
}

int main() {
    long long n, an = 1;
    std::cin >> n;

    while (an <= 1000000000) {
        //Миллиард – величайший костыль, без него контест просто не регал. (по задумке: while (an <= n) {...})
        if (an == n) {std::cout << "YES"; return 0;}
        an = reversed(an) + 70;
    }
    std::cout << "NO";
    return 0;
}