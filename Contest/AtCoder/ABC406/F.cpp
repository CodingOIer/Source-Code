#include <cstdio>
#include <cstdlib>
#include <vector>
constexpr int MaxN = 3e5 + 5;
int n, q;
int u[MaxN];
int v[MaxN];
int id[MaxN];
int fa[MaxN];
int top[MaxN];
int son[MaxN];
int size[MaxN];
int tree[MaxN];
std::vector<int> g[MaxN];
void dfsInit(int u, int f)
{
    fa[u] = f;
    size[u] = 1;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfsInit(v, u);
        size[u] += size[v];
        if (size[v] > size[son[u]])
        {
            son[u] = v;
        }
    }
}
void dfsSplit(int u, int tp, int &index)
{
    top[u] = tp;
    id[u] = ++index;
    if (son[u] != 0)
    {
        dfsSplit(son[u], tp, index);
    }
    for (const auto &v : g[u])
    {
        if (v == fa[u] || v == son[u])
        {
            continue;
        }
        dfsSplit(v, v, index);
    }
}
void tChange(int x, int val)
{
    for (; x <= n; x += x & -x)
    {
        tree[x] += val;
    }
}
int tQuery(int x)
{
    int res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
int tQuery(int l, int r)
{
    return tQuery(r) - tQuery(l - 1);
}
void change(int u, int val = 1)
{
    tChange(id[u], val);
}
int query(int u)
{
    return tQuery(id[u], id[u] + size[u] - 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &u[i], &v[i]);
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    dfsInit(1, 0);
    int _ = 0;
    dfsSplit(1, 1, _);
    int all = n;
    for (int i = 1; i <= n; i++)
    {
        change(i);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, w;
            scanf("%d%d", &x, &w);
            change(x, w);
            all += w;
        }
        else if (op == 2)
        {
            int x;
            scanf("%d", &x);
            if (fa[u[x]] == v[x])
            {
                x = u[x];
            }
            else
            {
                x = v[x];
            }
            int a, b;
            a = query(x);
            b = all - a;
            printf("%d\n", abs(a - b));
        }
    }
    return 0;
}