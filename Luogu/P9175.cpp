#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
class rim
{
  public:
    int to;
    int v, s;
    long long c;
    rim()
    {
        v = 0;
        s = 0;
        c = 0;
        to = 0;
    }
};
class node
{
  public:
    long long x;
    node *left, *right;
    node()
    {
        x = 0;
        left = nullptr;
        right = nullptr;
    }
};
int n;
int q;
int sl;
int cnt;
int id[MaxN];
int fa[MaxN];
int st[21][MaxN * 2];
int top[MaxN];
int son[MaxN];
int lg2[MaxN * 2];
int dis[MaxN * 2];
int size[MaxN];
int first[MaxN];
int depth[MaxN];
int tree_min_s[MaxN * 4];
node *root[MaxN];
std::vector<int> road;
std::vector<rim> link[MaxN];
void build(node *cur, int s, int t)
{
    if (s == t)
    {
        return;
    }
    int mid = (s + t) / 2;
    cur->left = new node;
    cur->right = new node;
    build(cur->left, s, mid);
    build(cur->right, mid + 1, t);
}
void change(node *cur, node *last, int s, int t, int w, long long val)
{
    if (s == t)
    {
        cur->x = val;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        cur->right = last->right;
        cur->left = new node;
        change(cur->left, last->left, s, mid, w, val);
    }
    else
    {
        cur->left = last->left;
        cur->right = new node;
        change(cur->right, last->right, mid + 1, t, w, val);
    }
    cur->x = cur->left->x + cur->right->x;
}
long long query(node *cur, node *last, int s, int t, int w)
{
    if (s == t)
    {
        return cur->x - last->x;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        return query(cur->left, last->left, s, mid, w);
    }
    else
    {
        return cur->left->x - last->left->x + query(cur->right, last->right, mid + 1, t, w);
    }
}
void change(int c, int s, int t, int w, int val)
{
    if (s == t)
    {
        tree_min_s[c] = val;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        change(c * 2, s, mid, w, val);
    }
    else
    {
        change(c * 2 + 1, mid + 1, t, w, val);
    }
    tree_min_s[c] = std::min(tree_min_s[c * 2], tree_min_s[c * 2 + 1]);
}
int query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree_min_s[c];
    }
    int mid = (s + t) / 2;
    int res = 0x3f3f3f3f;
    if (l <= mid)
    {
        res = std::min(res, query(c * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        res = std::min(res, query(c * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
inline void change(int x, int y, int w, long long val)
{
    change(root[x], root[y], 1, n, w, val);
}
void dfsInfo(int x, int f)
{
    fa[x] = f;
    size[x] = 1;
    depth[x] = depth[f] + 1;
    for (auto next : link[x])
    {
        int to = next.to;
        if (to == f)
        {
            continue;
        }
        dfsInfo(to, x);
        if (size[to] > size[son[x]])
        {
            son[x] = to;
        }
        size[x] += size[to];
    }
}
void dfsSplit(int x, int tp)
{
    if (x == 0)
    {
        return;
    }
    cnt++;
    id[x] = cnt;
    top[x] = tp;
    dfsSplit(son[x], tp);
    for (auto next : link[x])
    {
        int to = next.to;
        if (to == fa[x] || to == son[x])
        {
            continue;
        }
        dfsSplit(to, to);
    }
}
void dfs(int x, int fa)
{
    for (auto next : link[x])
    {
        if (next.to == fa)
        {
            continue;
        }
        road.push_back(x);
        change(1, 1, n, id[x], next.s);
        change(next.to, x, next.v, next.c);
        dfs(next.to, x);
    }
    road.push_back(x);
}
inline int query(int x, int y)
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
    res = std::min(res, query(1, 1, n, id[x], id[y]));
    return res;
}
inline int get(int x)
{
    return std::lower_bound(dis + 1, dis + 1 + sl, x) - dis;
}
inline int max(int x, int y)
{
    return first[x] < first[y] ? x : y;
}
inline int LCA(int x, int y)
{
    if (first[x] > first[y])
    {
        std::swap(x, y);
    }
    int len = first[y] - first[x];
    len = lg2[len];
    return max(st[len][first[x]], st[len][first[y] - (1 << len) + 1]);
}
inline long long check(int x, int y, int lca, int k)
{
    int need = get(k);
    return query(root[x], root[lca], 1, n, need) + query(root[y], root[lca], 1, n, need);
}
int main()
{
    scanf("%d", &n);
    int scnt = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, v, c, s;
        scanf("%d%d%d%d%d", &x, &y, &v, &c, &s);
        rim temp;
        temp.to = y;
        temp.v = v;
        temp.s = s;
        temp.c = c;
        link[x].push_back(temp);
        temp.to = x;
        link[y].push_back(temp);
        scnt++;
        dis[scnt] = v;
        // dis[scnt] = s;
    }
    std::sort(dis + 1, dis + 1 + scnt);
    sl = std::unique(dis + 1, dis + 1 + scnt) - dis - 1;
    for (int i = 1; i <= n; i++)
    {
        for (auto &x : link[i])
        {
            x.v = get(x.v);
            // x.s = get(x.s);
        }
    }
    dfsInfo(1, 0);
    dfsSplit(1, 1);
    for (int i = 1; i <= n; i++)
    {
        root[i] = new node;
    }
    build(root[1], 1, n);
    dfs(1, 0);
    for (int i = 1; i <= n * 2; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        st[0][i] = road[i - 1];
        if (first[road[i - 1]] != 0)
        {
            continue;
        }
        first[road[i - 1]] = i;
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= 2 * n - 1; i++)
        {
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1)) - 1]);
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        long long want;
        scanf("%d%d%lld", &x, &y, &want);
        int l, r;
        l = 1;
        r = 0x3f3f3f3f;
        int lca = LCA(x, y);
        if (x != lca)
        {
            r = std::min(r, query(fa[x], lca));
        }
        if (y != lca)
        {
            r = std::min(r, query(fa[y], lca));
        }
        int res = -1;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (check(x, y, lca, mid) <= want)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}