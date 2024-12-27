#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
constexpr int MaxM = 1e6 + 5;
int n;
int p[MaxN];
int last[MaxM];
long long dp[MaxN];
long long sum[MaxN];
void solve()
{
    for (int i = 1; i <= 1e6; i++)
    {
        last[i] = 0;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (p[i] == p[i - 1] ? p[i] : 0);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (last[p[i]] != 0)
        {
            dp[i] = std::max(dp[i], dp[last[p[i]] + 1] + p[i] + (sum[i] - sum[last[p[i]] + 1]));
        }
        last[p[i]] = i;
    }
    printf("%lld\n", dp[n]);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
