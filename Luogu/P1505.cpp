#include <algorithm>
#include <cstdio>
#include <map>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int tree1[MaxN * 4];
int tree2[MaxN * 4];
int tree3[MaxN * 4];
int lazy1[MaxN * 4];
int lazy2[MaxN * 4];
int lazy3[MaxN * 4];
inline void downstream1(int c, int s, int t)
{
    int mid = (s + t) / 2;
    tree1[c * 2] += (mid - s + 1) * lazy1[c];
    tree1[c * 2 + 1] += (t - s) * lazy1[c];
    lazy1[c * 2] += lazy1[c];
    lazy1[c * 2 + 1] += lazy1[c];
    lazy1[c] = 0;
}
inline void downstream2(int c, int s, int t)
{
    int mid = (s + t) / 2;
    tree2[c * 2] += lazy2[c];
    tree2[c * 2 + 1] += lazy2[c];
    lazy2[c * 2] += lazy2[c];
    lazy2[c * 2 + 1] += lazy2[c];
    lazy2[c] = 0;
}
inline void downstream3(int c, int s, int t)
{
    int mid = (s + t) / 2;
    tree3[c * 2] += lazy3[c];
    tree3[c * 2 + 1] += lazy3[c];
    lazy3[c * 2] += lazy3[c];
    lazy3[c * 2 + 1] += lazy3[c];
    lazy3[c] = 0;
}
void change1(int c, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        tree1[c] += (t - s + 1) * val;
        lazy1[c] += val;
        return;
    }
    downstream1(c, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change1(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change1(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree1[c] = tree1[c * 2] + tree1[c * 2 + 1];
}
void change2(int c, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        tree2[c] += val;
        lazy2[c] += val;
    }
    downstream2(c, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change2(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change2(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree2[c] = std::max(tree2[c * 2], tree2[c * 2 + 1]);
}
void change3(int c, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        tree3[c] += val;
        lazy3[c] += val;
    }
    downstream3(c, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change3(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change3(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree3[c] = std::min(tree3[c * 2], tree3[c * 2 + 1]);
}
int query1(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree1[c];
    }
    downstream1(c, s, t);
    int mid = (s + t) / 2;
    int response = 0;
    if (l <= mid)
    {
        response += query1(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        response += query1(c * 2 + 1, mid + 1, t, l, r);
    }
    return response;
}
int query2(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree2[c];
    }
    downstream2(c, s, t);
    int mid = (s + t) / 2;
    int response = -0x7f7f7f7f;
    if (l <= mid)
    {
        response = std::max(response, query2(c * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        response = std::max(response, query2(c * 2 + 1, mid + 1, t, l, r));
    }
    return response;
}
int query3(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree3[c];
    }
    downstream3(c, s, t);
    int mid = (s + t) / 2;
    int response = 0x7f7f7f7f;
    if (l <= mid)
    {
        response = std::max(response, query3(c * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        response = std::max(response, query3(c * 2 + 1, mid + 1, t, l, r));
    }
    return response;
}
void change(int c, int s, int t, int l, int r, int val)
{
    change1(c, s, t, l, r, val);
    change2(c, s, t, l, r, val);
    change3(c, s, t, l, r, val);
}
int n, m;
int index;
int id[MaxN];
int fa[MaxN];
int top[MaxN];
int son[MaxN];
int size[MaxN];
int depth[MaxN];
std::map<std::tuple<int, int>, int> ln;
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
            son[u] = size[v];
        }
        size[u] += size[v];
    }
}
void dfs_split(int u, int tp)
{
    index++;
    id[u] = index;
    top[u] = tp;
    if (son[u] != 0)
    {
        ln[{u, son[u]}] = index + 1;
        ln[{son[u], u}] = index + 1;
        dfs_split(son[u], tp);
    }
    for (auto [v, _] : link[u])
    {
        if (v == fa[u])
        {
            continue;
        }
        ln[{u, v}] = index + 1;
        ln[{v, u}] = index + 1;
        dfs_split(v, v);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
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
                change(1, 1, n, ln[{u, v}], ln[{u, v}], w);
            }
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
    }
    return 0;
}