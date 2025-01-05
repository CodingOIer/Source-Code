#include <cstdio>
constexpr int MaxN = 5e3 + 5;
constexpr long long Mod = 998'244'353;
int n;
int p[MaxN];
long long dp[MaxN];
long long sum[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            sum[j] = dp[j] + (j != 0 ? sum[j - 1] : 0);
            sum[j] %= Mod;
        }
        int l, r;
        l = 0;
        r = n + 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (p[j] > p[i])
            {
                l = j;
                break;
            }
        }
        for (int j = i + 1; j <= n; j++)
        {
            if (p[j] > p[i])
            {
                r = j;
                break;
            }
        }
        for (int j = l + 1; j <= r - 1; j++)
        {
            dp[j] += (sum[j - 1] - (l != 0 ? sum[l - 1] : 0) + Mod) % Mod;
            dp[j] %= Mod;
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}