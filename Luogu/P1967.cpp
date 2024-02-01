/**
 * @Author: CodingOIer redefinition0726@163.com
 * @Date: 2024-02-01 16:54:33
 * @LastEditors: CodingOIer redefinition0726@163.com
 * @LastEditTime: 2024-02-01 17:23:04
 * @FilePath: \Source-Code\Luogu\P1967.cpp
 * @
 * @Copyright (c) 2024 by CodingOIer, All Rights Reserved.
 */
#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e4 + 5;
constexpr int MaxM = 5e4 + 5;
class node
{
  public:
    int from, to, max;
    node(int x, int y, int z)
    {
        from = x;
        to = y;
        max = z;
    }
};
int cnt;
int n, m, q;
int f[MaxN];
int id[MaxN];
int fa[MaxN];
int max[MaxN];
int son[MaxN];
int top[MaxN];
int size[MaxN];
int depth[MaxN];
int son_max[MaxN];
int tree[MaxN * 4];
std::vector<int> way[MaxN];
std::vector<int> link[MaxN];
std::vector<node> vector;
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
}
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
void merge(int x, int y)
{
    f[find(y)] = find(x);
}
void dfsInformation(int x, int fat, int dep)
{
    fa[x] = fat;
    size[x] = 1;
    depth[x] = dep;
    for (int i = 0; i < int(link[x].size()); i++)
    {
        int len = way[x][i];
        int next = link[x][i];
        if (next == fat)
        {
            continue;
        }
        dfsInformation(next, x, dep + 1);
        if (size[next] > size[son[x]])
        {
            son[x] = next;
            son_max[x] = len;
        }
    }
}
void dfsSplit(int x, int tp, int len)
{
    if (x == 0)
    {
        return;
    }
    top[x] = tp;
    cnt++;
    id[x] = cnt;
    max[id[x]] = len;
    dfsSplit(son[x], tp, son_max[x]);
    for (int i = 0; i < int(link[x].size()); i++)
    {
        int next = link[x][i];
        int len = way[x][i];
        if (next == fa[x] || next == son[x])
        {
            continue;
        }
        dfsSplit(next, x, len);
    }
}
void build(int cur, int s, int t)
{
    if (s == t)
    {
        tree[cur] = max[s];
        return;
    }
    int mid = (s + t) / 2;
    build(cur * 2, s, mid);
    build(cur * 2 + 1, mid + 1, t);
    tree[cur] = std::min(tree[cur * 2], tree[cur * 2 + 1]);
}
int query(int cur, int s, int t, int l, int r)
{
    if (l > r)
    {
        return 0x3f3f3f3f;
    }
    if (l <= s && t <= r)
    {
        return tree[cur];
    }
    int mid = (s + t) / 2;
    int res = 0x3f3f3f3f;
    if (s <= mid)
    {
        res = std::min(res, query(cur * 2, s, mid, l, r));
    }
    if (t > mid)
    {
        res = std::min(res, query(cur * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
int queryRoute(int x, int y)
{
    int res = 0x3f3f3f3f;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        res = std::min(res, query(1, 1, n, id[top[x]], id[x]));
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    res = std::min(res, query(1, 1, n, id[x] + 1, id[y]));
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        vector.push_back(node(u, v, w));
    }
    std::sort(vector.begin(), vector.end(), [](const node &__x, const node &__y) { return __x.max > __y.max; });
    for (node x : vector)
    {
        if (find(x.from) == find(x.to))
        {
            continue;
        }
        merge(x.from, x.to);
        link[x.from].push_back(x.to);
        way[x.from].push_back(x.max);
        link[x.to].push_back(x.from);
        way[x.to].push_back(x.max);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", queryRoute(u, v));
    }
    return 0;
}