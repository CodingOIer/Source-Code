#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 4e3 + 5;
int n, m;
long long dp[MaxN];
std::vector<std::tuple<int, int>> g[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        g[i].push_back({i + 1, 0});
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        long long s;
        scanf("%d%d%lld", &l, &r, &s);
        s -= r - l + 1;
        if (s > 0)
        {
            g[l - 1].push_back({r, s});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -0x7f7f7f7f'7f7f7f7f;
    }
    for (int i = 0; i <= n; i++)
    {
        if (dp[i] == -0x7f7f7f7f'7f7f7f7f)
        {
            continue;
        }
        for (const auto &[to, w] : g[i])
        {
            dp[to] = std::max(dp[to], dp[i] + w);
        }
    }
    if (dp[n] == -0x7f7f7f7f'7f7f7f7f)
    {
        printf("-1\n");
        return 0;
    }
    printf("%lld\n", dp[n] + n);
    return 0;
}