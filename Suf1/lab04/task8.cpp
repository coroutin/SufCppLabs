#include <iostream>

int main() {
    int k;
    std::cin >> k;

    int len = 1;
    int count = 9;
    int first = 1;


    while (k > len * count) {
        k -= len * count;
        len++;
        count *= 10;
        first *= 10;
    }

    std::string num = std::to_string(first + (k - 1) / len);
    std::cout << num[(k - 1) % len];
    return 0;
}