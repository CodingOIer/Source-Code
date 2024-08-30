#include <cstdio>
#include <sched.h>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e5 + 5;
constexpr long long Mod = 1e9 + 7;
int n;
std::vector<std::tuple<int, int>> g[MaxN];
std::tuple<int, long long> dfs(int u, int f)
{
    int pfi;
    long long fi;
    fi = 0;
    pfi = u;
    for (auto [v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        int x;
        long long y;
        std::tie(x, y) = dfs(v, u);
        y += w;
        if (y > fi)
        {
            pfi = x;
            fi = y;
        }
    }
    return {pfi, fi};
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    printf("%lld\n", std::get<1>(dfs(std::get<0>(dfs(1, 0)), 0)) % Mod * 500000004 % Mod);
    return 0;
}