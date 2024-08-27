#include <cstdio>
constexpr int MaxN = 5e2 + 5;
int n, m, k;
int board[MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (k == 1)
    {
        printf("-1\n");
        return 0;
    }
    else if (k == 2)
    {
        if (n == 1)
        {
            for (int i = 1; i <= m; i++)
            {
                printf("1 %d\n", i);
            }
        }
        else if (m == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d 1\n", i);
            }
        }
        else
        {
            printf("-1\n");
        }
        return 0;
    }
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
        }
        start ^= 3;
    }
    return 0;
}