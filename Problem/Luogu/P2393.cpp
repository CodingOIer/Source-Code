#include <cstdio>
int main()
{
    long double answer = 0;
    for (double x; scanf("%lf", &x) != EOF;)
    {
        answer += x * 1e6;
    }
    printf("%.5Lf\n", answer / 1e6);
    return 0;
}