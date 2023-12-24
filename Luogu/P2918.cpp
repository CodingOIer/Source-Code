#include <cstdio>
#include <cstring>
#define min(a, b) (a < b ? a : b)
const int MaxN = 1e2 + 5;
const int MaxH = 5e4 + 5;
int n, h;
int val[MaxN];
int cost[MaxN];
int dp[MaxN][MaxH];
int main()
{
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &val[i], &cost[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            if (j >= cost[i])
            {
                int num = j / cost[i];
                dp[i][j] = min(dp[i - 1][j], num * val[i] + dp[i - 1][j - num * cost[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[n][h]);
    return 0;
}