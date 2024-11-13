#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 2e5 + 5;
class node
{
  public:
    int x;
    node *left, *right;
    node()
    {
        x = 0;
        left = nullptr;
        right = nullptr;
    }
};
int n, m;
int cnt_id;
int id[MaxN];
int fa[MaxN];
int who[MaxN];
int son[MaxN];
int top[MaxN];
int size[MaxN];
int depth[MaxN];
int color[MaxN];
bool happy[MaxN];
node *version[MaxN];
std::vector<int> lk[MaxN];
void dfs_info(int u, int f)
{
    size[u] = 1;
    fa[u] = f;
    depth[u] = depth[f] + 1;
    for (auto v : lk[u])
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
    cnt_id++;
    id[u] = cnt_id;
    top[u] = tp;
    if (son[u] != 0)
    {
        dfs_split(son[u], tp);
    }
    for (auto v : lk[u])
    {
        if (v == fa[u] || v == son[u])
        {
            continue;
        }
        dfs_split(v, v);
    }
}
void build(node *c, int s, int t)
{
    if (s == t)
    {
        return;
    }
    c->left = new node;
    c->right = new node;
    int mid = (s + t) / 2;
    build(c->left, s, mid);
    build(c->right, mid + 1, t);
}
void insert(node *b, node *c, int s, int t, int w)
{
    if (s == t)
    {
        c->x = b->x + 1;
        return;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        c->right = b->right;
        c->left = new node;
        insert(b->left, c->left, s, mid, w);
    }
    else
    {
        c->left = b->left;
        c->right = new node;
        insert(b->right, c->right, mid + 1, t, w);
    }
}
int query(node *b, node *c, int s, int t, int w)
{
    if (s == t)
    {
        return c->x - b->x;
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        return query(b->left, c->left, s, mid, w);
    }
    else
    {
        return query(b->right, c->right, mid + 1, t, w);
    }
}
bool query(int x, int y, int w)
{
    int r = 0;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        r += query(version[who[id[top[x]] - 1]], version[x], 0, n, w);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    r += query(version[who[id[x] - 1]], version[y], 0, n, w);
    return r > 0;
}
int solve()
{
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &color[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        lk[u].push_back(v);
        lk[v].push_back(u);
    }
    dfs_info(1, 0);
    dfs_split(1, 1);
    for (int i = 1; i <= n; i++)
    {
        who[id[i]] = i;
    }
    version[0] = new node;
    build(version[0], 0, n);
    for (int i = 1; i <= n; i++)
    {
        version[who[i]] = new node;
        insert(version[who[i - 1]], version[who[i]], 0, n, color[who[i]]);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        happy[i] = query(u, v, w);
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%s\n", happy[i] ? "Find" : "NotFind");
    }
    return 0;
}
int main()
{
    n = -1;
    for (; scanf("%d", &n);)
    {
        if (n == -1)
        {
            break;
        }
        solve();
        cnt_id = 0;
        memset(id, 0, sizeof(id));
        memset(fa, 0, sizeof(fa));
        memset(who, 0, sizeof(who));
        memset(son, 0, sizeof(son));
        memset(top, 0, sizeof(top));
        memset(size, 0, sizeof(size));
        memset(depth, 0, sizeof(depth));
        memset(color, 0, sizeof(color));
        memset(happy, false, sizeof(happy));
        memset(version, 0, sizeof(version));
        for (int i = 1; i <= n; i++)
        {
            lk[i].clear();
        }
        n = -1;
    }
    return 0;
}