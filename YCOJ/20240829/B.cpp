#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e2 + 5;
int idx;
int n, m, q;
int p[MaxN];
int fi[MaxN];
int id[MaxN];
int fa[MaxN];
int son[MaxN];
int top[MaxN];
int dis[MaxN];
int size[MaxN];
int depth[MaxN];
int st[28][MaxN];
std::vector<int> dfn;
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
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    tree[c] = merge(tree[c * 2], tree[c * 2 + 1]);
}
void change(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        if (std::get<2>(tree[c]) >= 1)
        {
            std::get<0>(tree[c]) = std::max(1, std::get<0>(tree[c]) - 1);
            std::get<1>(tree[c]) = std::max(1, std::get<1>(tree[c]) - 1);
            std::get<2>(tree[c]) = std::max(0, std::get<2>(tree[c]) - 1);
            return;
        }
        int mid = (s + t) / 2;
        change(c * 2, s, mid, l, r);
        change(c * 2 + 1, mid + 1, t, l, r);
        tree[c] = merge(tree[c * 2], tree[c * 2 + 1]);
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r);
    }
    tree[c] = merge(tree[c * 2], tree[c * 2 + 1]);
}
std::tuple<int, int, int> query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    int mid = (s + t) / 2;
    if (l <= mid && r > mid)
    {
        return merge(tree[c * 2], tree[c * 2 + 1]);
    }
    else if (l <= mid)
    {
        return tree[c * 2];
    }
    else
    {
        return tree[c * 2 + 1];
    }
}
void dfs(int u, int f)
{
    fa[u] = f;
    dfn.push_back(u);
    for (auto v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
        dfn.push_back(u);
    }
}
int tin(int x, int y)
{
    return fi[x] < fi[y] ? x : y;
}
int LCA(int x, int y)
{
    int l, r;
    l = fi[x];
    r = fi[y];
    if (l > r)
    {
        std::swap(l, r);
    }
    int k = log2(r - l + 1);
    return tin(st[k][l], st[k][r - (1 << k) + 1]);
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int u = 1; u <= n - 1; u++)
    {
        int v;
        scanf("%d", &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfs_info(1, 0);
    dfs_split(1, 0);
    dfn.push_back(0);
    dfs(1, 1);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        if (fi[dfn[i]] == 0)
        {
            fi[dfn[i]] = i;
        }
        st[0][i] = dfn[i];
    }
    for (int j = 1; j < 28; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= 2 * n - 1; i++)
        {
            st[j][i] = tin(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
    build(1, 1, m);
    for (int i = 1; i <= q; i++)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            change(1, 1, m, l, r);
        }
        else if (op == 2)
        {
            int x, y;
            std::tie(x, y, std::ignore) = query(1, 1, m, l, r);
            printf("%d\n", LCA(x, y));
        }
    }
    return 0;
}