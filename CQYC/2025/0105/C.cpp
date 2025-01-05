#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e3 + 5;
int n, m;
int a[MaxN];
int b[MaxN];
long long dp[MaxN][MaxN];
long long best[MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    memset(best, 0x3f, sizeof(best));
    best[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i, m); j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[j][k] = best[j][k];
                if (j >= 1)
                {
                    dp[j][k] = std::min(dp[j][k], best[j - 1][k] + a[i]);
                }
                if (k >= 1)
                {
                    dp[j][k] = std::min(dp[j][k], best[j][k - 1] + b[i]);
                }
                if (j >= 1 && k >= 1)
                {
                    dp[j][k] = std::min(dp[j][k], best[j - 1][k - 1] + a[i] + b[i]);
                }
            }
        }
        for (int j = 0; j <= std::min(i, m); j++)
        {
            for (int k = 0; k <= j; k++)
            {
                best[j][k] = std::min(best[j][k], dp[j][k]);
            }
        }
    }
    printf("%lld\n", best[m][m]);
    return 0;
}
