#include <algorithm>
#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
long long dp[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0x7f7f7f7f7f7f7f;
        if (i >= 2)
        {
            dp[i] = std::min(dp[i], dp[i - 2] + (p[i] - p[i - 1]));
        }
        if (i >= 3)
        {
            dp[i] = std::min(dp[i], dp[i - 3] + (p[i - 1] - p[i - 2]) + (p[i] - p[i - 1]));
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}
