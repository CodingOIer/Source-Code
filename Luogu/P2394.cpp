#include <cstdio>
long double x;
int main()
{
    scanf("%15Lf", &x);
    printf("%.8Lf\n", x / 23);
    return 0;
}