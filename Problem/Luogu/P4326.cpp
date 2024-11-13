#include <cstdio>
constexpr double pi = 3.14159265358979323846264338327950288419716939937;
double r;
int main()
{
    scanf("%lf", &r);
    printf("%.8lf\n", r * r * pi);
    printf("%.8lf\n", r * r * 2);
    return 0;
}