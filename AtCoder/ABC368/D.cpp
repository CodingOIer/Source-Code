#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m, k;
int size[MaxN];
bool must[MaxN];
std::vector<int> g[MaxN];
bool dfs(int u, int f)
{
    size[u] = 1;
    bool res = must[u];
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        bool r = dfs(v, u);
        if (!r)
        {
            m -= size[v];
        }
        else
        {
            res = true;
            size[u] += size[v];
        }
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    m = n;
    int x;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &x);
        must[x] = true;
    }
    dfs(x, 0);
    printf("%d\n", m);
    return 0;
}