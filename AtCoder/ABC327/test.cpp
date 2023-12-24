#include <cmath>
#include <cstdio>
double calc(double x, double y, double k)
{
    return x / y - 1200.0 / sqrt(k);
}
int main()
{
    printf("%.6lf %.6l", calc(100, 1, 1), calc(190, 1.9, 2));
    return 0;
}