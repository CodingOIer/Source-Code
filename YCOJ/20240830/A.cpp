#include <algorithm>
#include <cstdio>
constexpr int MaxN = 4e3 + 5;
constexpr int MaxM = 1e4 + 5;
constexpr long long Mod = 998'244'353;
int n, v;
int p[MaxN];
long long dp[MaxN][MaxM];
int main()
{
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = p[i]; j <= v; j++)
        {
            dp[i][j] = (dp[i - 1][j] * 2 + dp[i - 1][j - p[i]]);
            dp[i][j] %= Mod;
        }
        for (int j = 0; j <= std::min(v, p[i] - 1); j++)
        {
            dp[i][j] = dp[i - 1][j] * 2;
            dp[i][j] %= Mod;
        }
    }
    printf("%lld\n", dp[n][v]);
    return 0;
}