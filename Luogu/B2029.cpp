#include <cmath>
#include <cstdio>
const double PAI = 3.14;
double h, r;
int main()
{
    scanf("%lf%lf", &h, &r);
    printf("%d\n", (int)(ceil(20000 / ((r * r * PAI) * h))));
    return 0;
}