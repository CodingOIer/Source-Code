#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int tree_sum[MaxN * 4];
int tree_max[MaxN * 4];
int tree_min[MaxN * 4];
bool lazy[MaxN * 4];
void downstream(int c)
{
    if (lazy[c])
    {
        int max, min;

        tree_sum[c * 2] = -tree_sum[c * 2];
        max = tree_max[c * 2];
        min = tree_min[c * 2];
        tree_max[c * 2] = -min;
        tree_min[c * 2] = -max;

        tree_sum[c * 2 + 1] = -tree_sum[c * 2 + 1];
        max = tree_max[c * 2 + 1];
        min = tree_min[c * 2 + 1];
        tree_max[c * 2 + 1] = -min;
        tree_min[c * 2 + 1] = -max;

        lazy[c * 2] ^= true;
        lazy[c * 2 + 1] ^= true;
        lazy[c] = false;
    }
}
void change(int c, int s, int t, int l, int r)
{
    if (l > r)
    {
        return;
    }
    if (l <= s && t <= r)
    {
        tree_sum[c] = -tree_sum[c];
        int max, min;
        max = tree_max[c];
        min = tree_min[c];
        tree_max[c] = -min;
        tree_min[c] = -max;
        lazy[c] ^= true;
        return;
    }
    downstream(c);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r);
    }
    tree_sum[c] = tree_sum[c * 2] + tree_sum[c * 2 + 1];
    tree_max[c] = std::max(tree_max[c * 2], tree_max[c * 2 + 1]);
    tree_min[c] = std::min(tree_min[c * 2], tree_min[c * 2 + 1]);
}
void change_single(int c, int s, int t, int w, int val)
{
    if (s == t)
    {
        tree_sum[c] = val;
        tree_max[c] = val;
        tree_min[c] = val;
        return;
    }
    downstream(c);
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change_single(c * 2, s, mid, w, val);
    }
    else
    {
        change_single(c * 2 + 1, mid + 1, t, w, val);
    }
    tree_sum[c] = tree_sum[c * 2] + tree_sum[c * 2 + 1];
    tree_max[c] = std::max(tree_max[c * 2], tree_max[c * 2 + 1]);
    tree_min[c] = std::min(tree_min[c * 2], tree_min[c * 2 + 1]);
}
std::tuple<int, int, int> query(int c, int s, int t, int l, int r)
{
    if (l > r)
    {
        return {0, -0x7f7f7f7f, 0x7f7f7f7f};
    }
    if (l <= s && t <= r)
    {
        return {tree_sum[c], tree_max[c], tree_min[c]};
    }
    downstream(c);
    int mid = (s + t) / 2;
    int x, y, z;
    x = 0;
    y = -0x7f7f7f7f;
    z = 0x7f7f7f7f;
    if (l <= mid)
    {
        auto [kx, ky, kz] = query(c * 2, s, mid, l, r);
        x += kx;
        y = std::max(y, ky);
        z = std::min(z, kz);
    }
    if (r > mid)
    {
        auto [kx, ky, kz] = query(c * 2 + 1, mid + 1, t, l, r);
        x += kx;
        y = std::max(y, ky);
        z = std::min(z, kz);
    }
    return {x, y, z};
}
int n, m;
int idx;
int id[MaxN];
int fa[MaxN];
int top[MaxN];
int son[MaxN];
int size[MaxN];
int depth[MaxN];
std::map<std::tuple<int, int>, int> ln;
std::vector<std::tuple<int, int>> input;
std::vector<std::tuple<int, int>> link[MaxN];
void dfs_info(int u, int f)
{
    fa[u] = f;
    size[u] = 1;
    depth[u] = depth[fa[u]] + 1;
    for (auto [v, _] : link[u])
    {
        if (v == fa[u])
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
void dfs_split(int u, int tp)
{
    idx++;
    id[u] = idx;
    top[u] = tp;
    if (son[u] != 0)
    {
        ln[{u, son[u]}] = idx + 1;
        ln[{son[u], u}] = idx + 1;
        dfs_split(son[u], tp);
    }
    for (auto [v, _] : link[u])
    {
        if (v == fa[u] || v == son[u])
        {
            continue;
        }
        ln[{u, v}] = idx + 1;
        ln[{v, u}] = idx + 1;
        dfs_split(v, v);
    }
}
void change(int x, int y)
{
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        change(1, 1, n, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    change(1, 1, n, id[x] + 1, id[y]);
}
std::tuple<int, int, int> query(int x, int y)
{
    int a, b, c;
    a = 0;
    b = -0x7f7f7f7f;
    c = 0x7f7f7f7f;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        auto [kx, ky, kz] = query(1, 1, n, id[top[x]], id[x]);
        a += kx;
        b = std::max(b, ky);
        c = std::min(c, kz);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    auto [kx, ky, kz] = query(1, 1, n, id[x] + 1, id[y]);
    a += kx;
    b = std::max(b, ky);
    c = std::min(c, kz);
    return {a, b, c};
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u++;
        v++;
        input.push_back({u, v});
        link[u].push_back({v, w});
        link[v].push_back({u, w});
    }
    dfs_info(1, 0);
    dfs_split(1, 1);
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, w] : link[u])
        {
            if (u < v)
            {
                change_single(1, 1, n, ln[{u, v}], w);
            }
        }
    }
    char opt[15];
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", opt);
        if (strcmp(opt, "C") == 0)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            auto [u, v] = input[x - 1];
            change_single(1, 1, n, ln[{u, v}], y);
        }
        else if (strcmp(opt, "N") == 0)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u++;
            v++;
            change(u, v);
        }
        else
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u++;
            v++;
            auto [x, y, z] = query(u, v);
            if (strcmp(opt, "SUM") == 0)
            {
                printf("%d\n", x);
            }
            else if (strcmp(opt, "MAX") == 0)
            {
                printf("%d\n", y);
            }
            else if (strcmp(opt, "MIN") == 0)
            {
                printf("%d\n", z);
            }
        }
    }
    return 0;
}