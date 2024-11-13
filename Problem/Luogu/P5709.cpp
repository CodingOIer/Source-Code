#include <cstdio>
int m, t, s;
int main()
{
    scanf("%d%d%d", &m, &t, &s);
    if (t == 0)
    {
        printf("0\n");
    }
    else if (s / t >= m)
    {
        printf("0\n");
    }
    else if (s % t == 0)
    {
        printf("%d\n", m - s / t);
    }
    else
    {
        printf("%d\n", m - s / t - 1);
    }
    return 0;
}