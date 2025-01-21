#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
constexpr long long Mod = 1'000'000'007;
int n;
int a[MaxN];
int b[MaxN];
long long dp[2][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &b[i]);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] =
            (dp[0][i - 1] * (a[i] + b[i - 1]) % Mod + dp[1][i - 1] * (a[i] + std::max(b[i - 1] - 1, 0)) % Mod) % Mod;
        dp[1][i] = (dp[0][i - 1] * b[i] % Mod + dp[1][i - 1] * b[i] % Mod) % Mod;
    }
    printf("%lld\n", dp[0][n] + dp[1][n]);
    return 0;
}
