#include <algorithm>
#include <cstdio>
#include <vector>
const int MaxN = 5e4 + 5;
const int MaxK = 1e5 + 5;
int n, k;
int id_cnt;
int id[MaxN];
int fa[MaxN];
int son[MaxN];
int top[MaxN];
int size[MaxN];
int depth[MaxN];
int query_u[MaxK];
int query_v[MaxK];
std::vector<int> link[MaxN];
int tree[4 * MaxN];
int lazy[4 * MaxN];
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
int query(int root, int s, int t, int l, int r)
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
int queryRouteSum(int x, int y)
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
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    dfsInformation(1, 0, 1);
    dfsSplit(1, 0, 1);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &query_u[i], &query_v[i]);
        changeRouteValue(query_u[i], query_v[i], 1);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer = std::max(answer, queryRouteSum(i, i));
    }
    printf("%d\n", answer);
    return 0;
}