#include <cstdio>
int n, a, b;
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    if (n > a * b)
    {
        printf("%d\n", -1);
        return 0;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            printf("%d%c",
                   b % 2 == 1 ? (b * (i - 1) + j <= n ? b * (i - 1) + j : 0)
                              : (i % 2 == 1 ? (b * (i - 1) + j <= n ? b * (i - 1) + j : 0)
                                            : (b * (i - 1) + (b - j + 1) <= n ? b * (i - 1) + (b - j + 1) : 0)),
                   j == b ? '\n' : ' ');
        }
    }
    return 0;
}