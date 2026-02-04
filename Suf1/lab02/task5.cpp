#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;
    if ((n % 2) && (k % 2)) {std::cout << "1";}
    else if ((n % 2 == 0)&&(k % 2 == 0)) {std::cout << "1";}
    else {std::cout << "0";}
    return 0;
}