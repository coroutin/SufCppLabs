#include <iostream>

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    if ((x>0)||(y>0)||(z>0)) {std::cout << "1" << '\n';}    //a
    else {std::cout << "0" << '\n';}
    if ((x==y)&&(x==z)) {std::cout << "1" << '\n';}    //б
    else {std::cout << "0" << '\n';}
    if (((x==y)&&(x!=z))||((x==z)&&(x!=y))||((y==z)&&(x!=y))) {std::cout << "1" << '\n';}     //в
    else {std::cout << "0" << '\n';}
    return 0;
}