#include <cstdio>
#include <cmath>

int main() {
    int xa, ya, xb, yb;
    scanf("%d" "%d" "%d" "%d", &xa, &ya, &xb, &yb);
    if (abs(xa < 1000 and ya < 1000 and xb< 1000 and yb < 1000)) {
        double l = sqrt(pow((xb - xa), 2) + pow((yb - ya), 2));
        double xc = (xa + xb) * 0.5, yc = (ya + yb) * 0.5;
        printf("%.4lf\n%.4lf %.4lf", l, xc, yc);
    }
}