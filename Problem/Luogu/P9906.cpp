#include <cstdio>
constexpr int MaxN = 5e3 + 5;
constexpr long long Mod = 1e9 + 7;
int n, m;
long long answer;
long long dp[MaxN][MaxN];
long long sum[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    dp[2][n - 1] = 2;
    for (int i = 3; i <= n; i++)
    {
        sum[n - 1] = dp[i - 1][n - 1];
        for (int j = n - 2; j >= 1; j--)
        {
            sum[j] = dp[i - 1][j] + sum[j + 2];
            sum[j] %= Mod;
        }
        for (int j = n - 2; j >= 1; j--)
        {
            dp[i][j] = sum[j + 1];
            if (i + j <= n)
            {
                dp[i][j] += sum[i + j - 1];
            }
            dp[i][j] %= Mod;
        }
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            answer += dp[i][j] * (m - i + 1);
            answer %= Mod;
        }
    }
    printf("%lld\n", answer);
    return 0;
}