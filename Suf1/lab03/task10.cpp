#include <iostream>

int main() {
    int n;
    int sum = 0;
    bool even = false;
    bool cont = true;

    while (std::cin >> n && cont) {
        int odin = n % 10;
        int desat = n / 10 % 10;

        if (n % 2 == 0) {
            sum += n;
            even = true;
        }

        cont = (desat <= odin);
    }

    if (even) {std::cout << sum;}
    else {std::cout << "NO";}

    return 0;
}