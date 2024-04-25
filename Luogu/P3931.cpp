#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, r;
int dp[MaxN];
std::vector<std::pair<int, int>> link[MaxN];
void dfs(int u, int f)
{
    int update = 0;
    if (link[u].size() == 1 && link[u][0].first == f)
    {
        return;
    }
    for (auto k : link[u])
    {
        int v, l;
        v = k.first;
        l = k.second;
        if (v == f)
        {
            continue;
        }
        dp[v] = l;
        dfs(v, u);
        update += dp[v];
    }
    dp[u] = std::min(dp[u], update);
}
int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        link[u].push_back({v, w});
        link[v].push_back({u, w});
    }
    memset(dp, 0x3f, sizeof(dp));
    dfs(r, 0);
    printf("%d\n", dp[r]);
    return 0;
}