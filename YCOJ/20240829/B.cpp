#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e2 + 5;
int idx;
int n, m, q;
int id[MaxN];
int fa[MaxN];
int son[MaxN];
int top[MaxN];
int dis[MaxN];
int size[MaxN];
int depth[MaxN];
std::vector<int> g[MaxN];
std::tuple<int, int, int> tree[MaxN * 4];
void dfs_info(int u, int f)
{
    fa[u] = f;
    size[u] = 1;
    depth[u] = depth[f] + 1;
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs_info(v, u);
        if (size[v] > size[son[u]])
        {
            son[u] = v;
        }
        size[u] += size[v];
    }
}
void dfs_split(int u, int t)
{
    idx++;
    id[u] = idx;
    top[u] = t;
    if (u != t)
    {
        dis[u] = dis[fa[u]] + 1;
    }
    if (son[u] != 0)
    {
        dfs_split(son[u], t);
    }
    for (auto v : g[u])
    {
        if (v == fa[u] || v == top[u])
        {
            continue;
        }
        dfs_split(v, v);
    }
}
std::tuple<int, int, int> merge(std::tuple<int, int, int> x, std::tuple<int, int, int> y)
{
    int n, m, l;
    int a, b, c;
    std::tie(n, m, l) = x;
    std::tie(a, b, c) = y;
    return {id[n] < id[a] ? n : a, id[m] > id[b] ? m : b, std::min(l, c)};
}
void build(int c, int s, int t)
{
    if (s == t)
    {
        tree[c] = {c, c, dis[s]};
        return;
    }
    int mid = (s + t) / 2;
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_info(1, 0);
    dfs_split(1, 0);
    return 0;
}