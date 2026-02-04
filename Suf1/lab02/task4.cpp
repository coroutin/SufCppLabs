#include <iostream>

int main()
{
    int y;
    std::cin >> y;
    if (((y % 4 == 0)&&(y % 100 != 0))||(y % 400 == 0)) {
        std::cout << "1";
    }
    else {std::cout << "0";}
    return 0;
}