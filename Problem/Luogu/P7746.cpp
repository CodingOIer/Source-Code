#include <algorithm>
#include <cstdio>
#include <vector>
const int MaxN = 5e5 + 5;
int n, m;
int id_cnt;
int id[MaxN];
int fa[MaxN];
int son[MaxN];
int top[MaxN];
int size[MaxN];
int depth[MaxN];
int value[MaxN];
std::vector<int> link[MaxN];
long long tree[4 * MaxN];
long long lazy[4 * MaxN];
void build(int root, int s, int t)
{
    if (s == t)
    {
        tree[root] = 0;
        return;
    }
    int mid = (s + t) / 2;
    build(root * 2, s, mid);
    build(root * 2 + 1, mid + 1, t);
    tree[root] = (tree[root * 2] + tree[root * 2 + 1]);
}
void pushDown(int root, int s, int t)
{
    int mid = (s + t) / 2;
    if (lazy[root] != 0)
    {
        tree[root * 2] += lazy[root] * (mid - s + 1);
        tree[root * 2 + 1] += lazy[root] * (t - mid);
        lazy[root * 2] += lazy[root];
        lazy[root * 2 + 1] += lazy[root];
        lazy[root] = 0;
    }
}
void change(int root, int s, int t, int l, int r, int c)
{
    if (l <= s && t <= r)
    {
        tree[root] += c * (t - s + 1);
        lazy[root] += c;
        return;
    }
    pushDown(root, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(root * 2, s, mid, l, r, c);
    }
    if (r >= mid + 1)
    {
        change(root * 2 + 1, mid + 1, t, l, r, c);
    }
    tree[root] = tree[root * 2] + tree[root * 2 + 1];
}
long long query(int root, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[root];
    }
    pushDown(root, s, t);
    int mid = (s + t) / 2;
    int res = 0;
    if (l <= mid)
    {
        res += query(root * 2, s, mid, l, r);
    }
    if (r >= mid + 1)
    {
        res += query(root * 2 + 1, mid + 1, t, l, r);
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
long long queryRouteSum(int x, int y)
{
    long long res = 0;
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
        res += query(1, 1, n, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    res += query(1, 1, n, id[x], id[y]);
    return res;
}
void changeRouteValue(int x, int y, int c)
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
    change(1, 1, n, id[x], id[y], c);
}
void changeSonTreeSum(int x, int c)
{
    change(1, 1, n, id[x], id[x] + size[x] - 1, c);
}
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d", &value[1]);
    for (int i = 2; i <= n; i++)
    {
        int val, fa;
        scanf("%d%d", &val, &fa);
        value[i] = val;
        link[i].push_back(fa);
        link[fa].push_back(i);
    }
    dfsInformation(1, 0, 1);
    dfsSplit(1, 0, 1);
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        change(1, 1, n, id[i], id[i], value[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        char op = '\0';
        for (; op != 'p' && op != 'u';)
        {
            scanf("%c", &op);
        }
        if (op == 'p')
        {
            int x, y;
            scanf("%d%d", &x, &y);
            changeSonTreeSum(x, y);
            changeRouteValue(x, x, -y);
        }
        else if (op == 'u')
        {
            int x;
            scanf("%d", &x);
            printf("%lld\n", queryRouteSum(x, x));
        }
    }
    return 0;
}