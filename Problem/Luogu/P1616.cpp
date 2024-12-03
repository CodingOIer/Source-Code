#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e7 + 5;
int n, m, c;
long long dp[MaxN];
long long cost[MaxN];
long long value[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    int c = 0;
    for (int i = 1; i <= m; i++)
    {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        for (;;)
        {
            c++;
            cost[c] = x;
            value[c] = y;
            if (x >= n)
            {
                break;
            }
            x *= 2;
            y *= 2;
        }
    }
    for (int i = 1; i <= c; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (cost[i] <= j)
            {
                dp[j] = std::max(dp[j], dp[j - cost[i]] + value[i]);
            }
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}
