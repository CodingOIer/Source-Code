#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 5e3 + 5;
constexpr long long Mod = 998'244'353;
int n;
long long p[MaxN];
long long dp[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        p[i] = (p[i] % Mod + Mod) % Mod;
    }
    memcpy(dp, p, sizeof(dp));
    for (int i = 2; i <= n; i++)
    {
        long long s = 0;
        for (int j = n; j >= 1; j--)
        {
            long long cp = dp[j];
            dp[j] = p[j] * (s + dp[j] * (n - i - j + 2) % Mod) % Mod;
            s += cp;
            s %= Mod;
        }
    }
    printf("%lld ", dp[1]);
    std::reverse(p + 1, p + 1 + n);
    memcpy(dp, p, sizeof(dp));
    for (int i = 2; i <= n; i++)
    {
        long long s = 0;
        for (int j = n; j >= 1; j--)
        {
            long long cp = dp[j];
            dp[j] = p[j] * (s + dp[j] * (n - i - j + 2) % Mod) % Mod;
            s += cp;
            s %= Mod;
        }
    }
    printf("%lld\n", dp[1]);
    return 0;
}