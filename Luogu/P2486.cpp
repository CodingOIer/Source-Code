#include <cstdio>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, m;
int idx;
int p[MaxN];
int id[MaxN];
int fa[MaxN];
int top[MaxN];
int son[MaxN];
int size[MaxN];
int temp[MaxN];
int depth[MaxN];
int tree[MaxN * 4];
int lazy[MaxN * 4];
int tree_l[MaxN * 4];
int tree_r[MaxN * 4];
char op[15];
std::vector<int> g[MaxN];
void dfs1(int u, int f)
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
    for (auto v : g[u])
    {
        if (v == fa[u] || v == son[u])
        {
            continue;
        }
        dfs2(v, v);
    }
}
inline void upstream(int c)
{
    tree[c] = tree[c * 2] + tree[c * 2 + 1] - (tree_r[c * 2] == tree_l[c * 2 + 1] ? 1 : 0);
    tree_l[c] = tree_l[c * 2];
    tree_r[c] = tree_r[c * 2 + 1];
}
inline void downstream(int c)
{
    if (lazy[c] != 0)
    {
        tree[c * 2] = 1;
        tree[c * 2 + 1] = 1;
        tree_l[c * 2] = lazy[c];
        tree_r[c * 2] = lazy[c];
        tree_l[c * 2 + 1] = lazy[c];
        tree_r[c * 2 + 1] = lazy[c];
        lazy[c * 2] = lazy[c];
        lazy[c * 2 + 1] = lazy[c];
        lazy[c] = 0;
    }
}
void build(int c, int s, int t)
{
    if (s == t)
    {
        tree[c] = 1;
        tree_l[c] = temp[s];
        tree_r[c] = temp[s];
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    upstream(c);
}
void change(int c, int s, int t, int l, int r, int val)
{
    downstream(c);
    if (l <= s && t <= r)
    {
        tree[c] = 1;
        tree_l[c] = val;
        tree_r[c] = val;
        lazy[c] = val;
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r, val);
    }
    upstream(c);
}
std::tuple<int, int, int> query(int c, int s, int t, int l, int r)
{
    downstream(c);
    if (l <= s && t <= r)
    {
        return {tree[c], tree_l[c], tree_r[c]};
    }
    int mid = (s + t) / 2;
    if (l <= mid && r > mid)
    {
        auto [lt, ll, lr] = query(c * 2, s, mid, l, r);
        auto [rt, rl, rr] = query(c * 2 + 1, mid + 1, t, l, r);
        return {lt + rt - (lr == rl ? 1 : 0), ll, rr};
    }
    else if (l <= mid)
    {
        return query(c * 2, s, mid, l, r);
    }
    else
    {
        return query(c * 2 + 1, mid + 1, t, l, r);
    }
}
inline void change(int x, int y, int val)
{
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        change(1, 1, n, id[top[x]], id[x], val);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    change(1, 1, n, id[x], id[y], val);
}
inline int query(int x, int y)
{
    int ll, rr;
    ll = -1;
    rr = -1;
    int res = 0;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] > depth[top[y]])
        {
            auto [w, r, l] = query(1, 1, n, id[top[x]], id[x]);
            res += w - (ll != -1 && ll == l ? 1 : 0);
            ll = r;
            x = fa[top[x]];
        }
        else
        {
            auto [w, l, r] = query(1, 1, n, id[top[y]], id[y]);
            res += w - (rr != -1 && rr == r ? 1 : 0);
            rr = l;
            y = fa[top[y]];
        }
    }
    if (id[x] == id[y])
    {
        return res - (ll != -1 && rr != -1 && ll == rr ? 1 : 0);
    }
    else if (id[x] > id[y])
    {
        auto [w, r, l] = query(1, 1, n, id[y], id[x]);
        return res - (ll != -1 && ll == l ? 1 : 0) + w - (rr != -1 && rr == r ? 1 : 0);
    }
    else
    {
        auto [w, l, r] = query(1, 1, n, id[x], id[y]);
        return res - (ll != -1 && ll == l ? 1 : 0) + w - (rr != -1 && rr == r ? 1 : 0);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
    {
        temp[id[i]] = p[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", op);
        if (strcmp(op, "C") == 0)
        {
            int u, v, x;
            scanf("%d%d%d", &u, &v, &x);
            change(u, v, x);
        }
        else if (strcmp(op, "Q") == 0)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", query(u, v));
        }
    }
    return 0;
}