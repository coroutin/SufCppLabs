#include <iostream>

int main() {
    long a, b, c, d, x;
    std::cin >> a >> b >> c >> d >> x;
    if (((-100000 <= a)&&(a <= 100000)) and ((-100000 <= b)&&(b <= 100000)) and ((-100000 <= c)&&(c <= 100000)) and ((-100000 <= d)&&(d <= 100000)) and ((-100000 <= x)&&(x <= 100000))) {
        if ((a <= x)&&(x <= b)&&(not((c <= x)&&(x <= d)))) {printf("1");}
        else {printf("0");}
    }
}