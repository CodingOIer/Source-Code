#include <algorithm>
#include <cstdio>
#include <vector>
const int MaxN = 1e5 + 5;
const int MaxM = 3e5 + 5;
class road
{
  public:
    int u, v, w;
    friend bool operator<(const road &a, const road &b)
    {
        return a.w < b.w;
    }
    road()
    {
    }
    road(int x, int y, int z)
    {
        u = x;
        v = y;
        w = z;
    }
};
int n, m, q;
int id_cnt;
int f[MaxN];
int id[MaxN];
int fa[MaxN];
int son[MaxN];
int top[MaxN];
int size[MaxN];
int depth[MaxN];
int value[MaxN];
int tree[4 * MaxN];
int lazy[4 * MaxN];
road p[MaxN];
std::vector<int> link[MaxN];
std::vector<road> need;
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
void pushDown(int root, int s, int t)
{
    if (lazy[root] != 0)
    {
        int mid = (s + t) / 2;
        tree[2 * root] += lazy[root];
        tree[2 * root + 1] += lazy[root];
        lazy[2 * root] += lazy[root];
        lazy[2 * root + 1] += lazy[root];
        lazy[root] = 0;
    }
}
void change(int root, int s, int t, int l, int r, int c)
{
    if (l <= s && t <= r)
    {
        tree[root] += c;
        lazy[root] += c;
        return;
    }
    pushDown(root, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(2 * root, s, mid, l, r, c);
    }
    if (r >= mid + 1)
    {
        change(2 * root + 1, mid + 1, t, l, r, c);
    }
    tree[root] = std::max(tree[2 * root], tree[2 * root + 1]);
}
int query(int root, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[root];
    }
    pushDown(root, s, t);
    int res = -1e9;
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        res = std::max(res, query(2 * root, s, mid, l, r));
    }
    if (r >= mid + 1)
    {
        res = std::max(res, query(2 * root + 1, mid + 1, t, l, r));
    }
    return res;
}
void dfsInformation(int root, int fat, int deep)
{
    fa[root] = fat;
    size[root] = 1;
    depth[root] = deep;
    for (int next : link[root])
    {
        if (next == fat)
        {
            continue;
        }
        dfsInformation(next, root, deep + 1);
        size[root] += size[next];
        if (size[next] > size[son[root]])
        {
            son[root] = next;
        }
    }
    return;
}
void dfsSplit(int root, int fat, int top_root)
{
    id_cnt++;
    id[root] = id_cnt;
    top[root] = top_root;
    if (son[root] == 0)
    {
        return;
    }
    dfsSplit(son[root], root, top_root);
    for (int next : link[root])
    {
        if (next == fat || next == son[root])
        {
            continue;
        }
        dfsSplit(next, root, next);
    }
}
void changeOnTree(int x, int y, int c)
{
    for (;;)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        if (top[x] == top[y])
        {
            break;
        }
        change(1, 1, n, id[top[x]], id[x], c);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    if (x != y)
    {
        change(1, 1, n, id[x], id[y] - 1, c);
    }
}
int queryOnTree(int x, int y)
{
    int res = 0;
    for (;;)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        if (top[x] == top[y])
        {
            break;
        }
        res = std::max(res, query(1, 1, n, id[top[x]], id[x]));
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    if (x != y)
    {
        res = std::max(res, query(1, 1, n, id[x], id[y] - 1));
    }
    return res;
}
int main()
{
    freopen("nav.in", "r", stdin);
    freopen("nav.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &p[i].u, &p[i].v, &p[i].w);
    }
    std::sort(p + 1, p + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        if (find(p[i].u) == find(p[i].v))
        {
            continue;
        }
        f[find(p[i].v)] = find(p[i].u);
        link[p[i].u].push_back(p[i].v);
        link[p[i].v].push_back(p[i].u);
        need.push_back(p[i]);
    }
    int root = 1;
    dfsInformation(1, 0, 1);
    dfsSplit(1, 0, 1);
    for (road x : need)
    {
        changeOnTree(x.u, x.v, x.w);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", queryOnTree(u, v));
    }
    return 0;
}