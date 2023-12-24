#include <cmath>
#include <cstdio>
double p;
double a, b, c;
int main()
{
    scanf("%lf%lf%lf", &a, &b, &c);
    p = (a + b + c) / 2;
    printf("%.1lf\n", sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}