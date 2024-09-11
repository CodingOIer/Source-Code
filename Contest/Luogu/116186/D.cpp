#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 5e3 + 5;
int n, m;
int p[MaxN];
int fa[MaxN];
int res[MaxN];
std::vector<int> son[MaxN];
std::vector<int> link[MaxN];
int f(int u, int d, int w)
{
    if (d == w)
    {
        return p[u];
    }
    int res = 0;
    for (int v : link[u])
    {
        if (v == fa[u])
        {
            continue;
        }
        res += f(v, d + 1, w);
    }
    return res;
}
int calc(int u)
{
    int max = 0;
    for (int i = 0; i <= n; i++)
    {
        max = std::max(max, f(u, 0, i));
    }
    return max;
}
int dfs(int u)
{
    int res = calc(u);
    for (int v : link[u])
    {
        if (v == fa[u])
        {
            continue;
        }
        res += dfs(v);
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &fa[i]);
        link[i].push_back(fa[i]);
        link[fa[i]].push_back(i);
        son[fa[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, w, y;
        scanf("%d%d%d", &x, &w, &y);
        p[x] += w;
        printf("%d\n", dfs(y));
    }
    return 0;
}