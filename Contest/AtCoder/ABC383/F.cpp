#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e2 + 5;
constexpr int MaxX = 5e4 + 5;
int n, x;
long long k;
long long dp[MaxN][MaxX];
std::vector<std::tuple<long long, long long>> itm[MaxN];
int main()
{
    scanf("%d%d%lld", &n, &x, &k);
    for (int i = 1; i <= n; i++)
    {
        int p, u, c;
        scanf("%d%d%d", &p, &u, &c);
        itm[c].push_back({p, u});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
        }
        for (const auto &[p, u] : itm[i])
        {
            for (int j = x; j >= 1; j--)
            {
                dp[i][j] = std::max({dp[i][j], j >= p ? dp[i][j - p] + u : -1, j >= p ? dp[i - 1][j - p] + u + k : -1});
            }
        }
    }
    printf("%lld\n", dp[n][x]);
    return 0;
}
