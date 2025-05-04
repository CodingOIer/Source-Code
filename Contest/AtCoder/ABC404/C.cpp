#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
bool vis[MaxN];
std::vector<int> g[MaxN];
void dfs(int u)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (const auto &v : g[u])
    {
        dfs(v);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    if (n != m)
    {
        printf("No\n");
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (int(g[i].size()) % 2 != 0 || !vis[i])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}