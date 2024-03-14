#include <cstdio>
int n, q;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            printf("-1\n");
            continue;
        }
        int res = 0;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                res = j;
                for (; x % j == 0;)
                {
                    x /= j;
                }
            }
        }
        if (x != 1)
        {
            res = x;
        }
        printf("%d\n", n / res - 1);
    }
    return 0;
}