#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::pmr::string s;
    std::cin >> s;

    std::vector<int> numbers;
    int current = 0;

    for (char c : s) {
        if (c == '+') {
            numbers.push_back(current);
            current = 0;
        } else {
            current = current * 10 + (c - '0');
        }
    }
    numbers.push_back(current);

    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) std::cout << '+';
        std::cout << numbers[i];
    }

    return 0;
}