#include <cstdio>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
long long f[MaxN];
std::vector<std::tuple<int, long long>> g[MaxN];
std::vector<std::tuple<int, long long>> r[MaxN];
void dfs(int u, long long to)
{
    if (f[u] != 0x7f7f7f7f7f7f7f7f)
    {
        return;
    }
    f[u] = to;
    for (auto [v, w] : g[u])
    {
        dfs(v, to + w);
    }
    for (auto [v, w] : r[u])
    {
        dfs(v, to - w);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        r[v].push_back({u, w});
    }
    memset(f, 0x7f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0x7f7f7f7f7f7f7f7f)
        {
            dfs(i, 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", f[i]);
    }
    printf("\n");
    return 0;
}