#include <cstdio>
#include <math.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int h = (n/3600);
    int m = ((n - h*3600) / 60);
    int s = (n % 60);
    printf("%02d:%02d:%02d", h, m ,s);
}