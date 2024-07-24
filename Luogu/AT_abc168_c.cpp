#include <cmath>
#include <cstdio>
#include <cstdlib>
double a, b, h, w;
double l;
double x;
int main()
{
    scanf("%lf%lf%lf%lf", &a, &b, &h, &w);
    x = abs((h * 30 + w * 0.5) - (w * 6));
    printf("%.10lf\n", sqrt(a * a + b * b - 2 * a * b * cos(x * 3.14159265358979323846264338327950288 / 180)));
    return 0;
}