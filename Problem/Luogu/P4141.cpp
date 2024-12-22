#include <cstdio>
constexpr int MaxN = 2e3 + 5;
int n, m;
int f[MaxN];
int p[MaxN];
int dp[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (j >= p[i])
            {
                dp[j] += dp[j - p[i]];
            }
            dp[j] %= 10;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        f[0] = 1;
        for (int j = 1; j <= m; j++)
        {
            f[j] = dp[j];
        }
        for (int j = 1; j <= m; j++)
        {
            if (j >= p[i])
            {
                f[j] -= f[j - p[i]];
            }
            f[j] = (f[j] + 10) % 10;
        }
        for (int j = 1; j <= m; j++)
        {
            printf("%d", f[j]);
        }
        printf("\n");
    }
    return 0;
}
