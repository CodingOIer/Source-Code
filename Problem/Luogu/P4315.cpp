#include <algorithm>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
constexpr int Unknown = 2e9;
int n;
int idx;
int id[MaxN];
int fa[MaxN];
int top[MaxN];
int son[MaxN];
int size[MaxN];
int temp[MaxN];
int value[MaxN];
int depth[MaxN];
int tree[MaxN * 4];
int lazy_add[MaxN * 4];
int lazy_cover[MaxN * 4];
char op[25];
std::vector<std::tuple<int, int>> g[MaxN];
std::vector<std::tuple<int, int>> links;
void dfs1(int u, int f)
{
    fa[u] = f;
    size[u] = 1;
    depth[u] = depth[f] + 1;
    for (auto [v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        value[v] = w;
        dfs1(v, u);
        if (size[v] > size[son[u]])
        {
            son[u] = v;
        }
        size[u] += size[v];
    }
}
void dfs2(int u, int t)
{
    id[u] = ++idx;
    top[u] = t;
    if (son[u] != 0)
    {
        dfs2(son[u], t);
    }
    for (auto [v, w] : g[u])
    {
        if (v == son[u] || v == fa[u])
        {
            continue;
        }
        dfs2(v, v);
    }
}
void build(int c, int s, int t)
{
    if (s == t)
    {
        tree[c] = temp[s];
        lazy_cover[c] = Unknown;
        return;
    }
    lazy_cover[c] = Unknown;
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
inline void downstream(int c)
{
    if (lazy_cover[c] != Unknown)
    {
        tree[c * 2] = lazy_cover[c];
        tree[c * 2 + 1] = lazy_cover[c];
        lazy_add[c * 2] = 0;
        lazy_add[c * 2 + 1] = 0;
        lazy_cover[c * 2] = lazy_cover[c];
        lazy_cover[c * 2 + 1] = lazy_cover[c];
        lazy_cover[c] = Unknown;
    }
    if (lazy_add[c] != 0)
    {
        tree[c * 2] += lazy_add[c];
        tree[c * 2 + 1] += lazy_add[c];
        lazy_add[c * 2] += lazy_add[c];
        lazy_add[c * 2 + 1] += lazy_add[c];
        lazy_add[c] = 0;
    }
}
inline void change_add(int c, int s, int t, int l, int r, int val)
{
    if (l > r)
    {
        return;
    }
    downstream(c);
    if (l <= s && t <= r)
    {
        tree[c] += val;
        lazy_add[c] += val;
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change_add(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change_add(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
inline void change_cover(int c, int s, int t, int l, int r, int val)
{
    if (l > r)
    {
        return;
    }
    downstream(c);
    if (l <= s && t <= r)
    {
        tree[c] = val;
        lazy_cover[c] = val;
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change_cover(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change_cover(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
inline int query(int c, int s, int t, int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    downstream(c);
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    int mid = (s + t) / 2;
    int res = 0;
    if (l <= mid)
    {
        res = std::max(res, query(c * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        res = std::max(res, query(c * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
inline void add(int x, int y, int val)
{
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        change_add(1, 1, n, id[top[x]], id[x], val);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    change_add(1, 1, n, id[x] + 1, id[y], val);
}
inline void cover(int x, int y, int val)
{
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        change_cover(1, 1, n, id[top[x]], id[x], val);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    change_cover(1, 1, n, id[x] + 1, id[y], val);
}
inline int query(int x, int y)
{
    int res = 0;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        res = std::max(res, query(1, 1, n, id[top[x]], id[x]));
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    res = std::max(res, query(1, 1, n, id[x] + 1, id[y]));
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({u, v});
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs1(1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
    {
        temp[id[i]] = value[i];
    }
    build(1, 1, n);
    for (;;)
    {
        scanf("%s", op);
        if (strcmp(op, "Stop") == 0)
        {
            break;
        }
        else if (strcmp(op, "Change") == 0)
        {
            int k, val;
            scanf("%d%d", &k, &val);
            cover(std::get<0>(links[k - 1]), std::get<1>(links[k - 1]), val);
        }
        else if (strcmp(op, "Cover") == 0)
        {
            int u, v, val;
            scanf("%d%d%d", &u, &v, &val);
            cover(u, v, val);
        }
        else if (strcmp(op, "Add") == 0)
        {
            int u, v, val;
            scanf("%d%d%d", &u, &v, &val);
            add(u, v, val);
        }
        else if (strcmp(op, "Max") == 0)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", query(u, v));
        }
    }
    return 0;
}