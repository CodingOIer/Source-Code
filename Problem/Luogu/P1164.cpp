#include <cstdio>
constexpr int MaxN = 1e2 + 5;
constexpr int MaxM = 1e4 + 5;
int n, m;
int p[MaxN];
int dp[MaxN][MaxM];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j == p[i])
            {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else if (j > p[i])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - p[i]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}