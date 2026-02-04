#include <iostream>

int main()
{
    int k;
    std::cin >> k;
    if ((k % 10 == 5)||((k % 100 - k % 10) / 10 == 5)||((k % 1000 - k % 100) / 100 == 5)) {std::cout << "1";}
    else {std::cout << "0";}
    return 0;
}