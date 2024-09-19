#include <cstdio>
double x, a, y, b;
int main()
{
    scanf("%lf%lf%lf%lf", &x, &a, &y, &b);
    printf("%.2lf\n", (x * a - y * b) / (a - b));
    return 0;
}