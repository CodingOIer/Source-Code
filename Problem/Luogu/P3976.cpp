#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 5e4 + 5;
class node
{
  public:
    int lazy;
    int min, max;
    int left_max;
    int right_max;
    node()
    {
        lazy = 0;
        min = 0x3f3f3f3f;
        max = -0x3f3f3f3f;
        left_max = 0;
        right_max = 0;
    }
    friend node operator+(const node &__x, const node &__y)
    {
        node res;
        res.min = std::min(__x.min, __y.min);
        res.max = std::max(__x.max, __y.max);
        res.left_max = std::max({__y.max - __x.min, __x.left_max, __y.left_max});
        res.right_max = std::max({__x.max - __y.min, __x.right_max, __y.right_max});
        return res;
    }
    void operator+=(const node &__y)
    {
        (*this) = (*this) + __y;
    }
};
int n, q;
int id_cnt;
int id[MaxN];
int fat[MaxN];
int top[MaxN];
int son[MaxN];
int size[MaxN];
int depth[MaxN];
int value[MaxN];
int tree_value[MaxN];
node tree[MaxN * 4];
std::vector<int> link[MaxN];
void dfsInformation(int root, int fa = 1, int dep = 1)
{
    size[root] = 1;
    fat[root] = fa;
    depth[root] = dep;
    for (int next : link[root])
    {
        if (next == fa)
        {
            continue;
        }
        dfsInformation(next, root, dep + 1);
        size[root] += size[next];
        if (size[next] > size[son[root]])
        {
            son[root] = next;
        }
    }
}
void dfsSplit(int root, int now_top = 1)
{
    id_cnt++;
    id[root] = id_cnt;
    tree_value[id[root]] = value[root];
    top[root] = now_top;
    if (son[root] != 0)
    {
        dfsSplit(son[root], now_top);
    }
    for (int next : link[root])
    {
        if (next == fat[root] || next == son[root])
        {
            continue;
        }
        dfsSplit(next, next);
    }
}
void build(int root, int s, int t)
{
    if (s == t)
    {
        tree[root].min = tree_value[s];
        tree[root].max = tree_value[s];
        tree[root].left_max = 0;
        tree[root].right_max = 0;
        return;
    }
    int mid = (s + t) / 2;
    build(root * 2, s, mid);
    build(root * 2 + 1, mid + 1, t);
    tree[root] = tree[root * 2] + tree[root * 2 + 1];
}
void pushDown(int root)
{
    if (tree[root].lazy != 0)
    {
        tree[root * 2].lazy += tree[root].lazy;
        tree[root * 2 + 1].lazy += tree[root].lazy;
        tree[root * 2].min += tree[root].lazy;
        tree[root * 2].max += tree[root].lazy;
        tree[root * 2 + 1].min += tree[root].lazy;
        tree[root * 2 + 1].max += tree[root].lazy;
        tree[root].lazy = 0;
    }
}
void change(int root, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        tree[root].lazy += val;
        tree[root].min += val;
        tree[root].max += val;
        return;
    }
    pushDown(root);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(root * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change(root * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[root] = tree[root * 2] + tree[root * 2 + 1];
}
node query(int root, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[root];
    }
    pushDown(root);
    node res;
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        res = res + query(root * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res = res + query(root * 2 + 1, mid + 1, t, l, r);
    }
    return res;
}
int LCA(int x, int y)
{
    for (; top[x] != top[y];)
    {
        if (depth[x] < depth[y])
        {
            std::swap(x, y);
        }
        x = fat[top[x]];
    }
    return depth[x] < depth[y] ? x : y;
}
int calc(int x, int y)
{
    node l, r;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] > depth[top[y]])
        {
            l = query(1, 1, n, id[top[x]], id[x]) + l;
            x = fat[top[x]];
        }
        else
        {
            r = query(1, 1, n, id[top[y]], id[y]) + r;
            y = fat[top[y]];
        }
    }
    int max = LCA(x, y);
    if (x != max)
    {
        l = query(1, 1, n, id[max], id[x]) + l;
    }
    else
    {
        r = query(1, 1, n, id[max], id[y]) + r;
    }
    return std::max({l.right_max, r.left_max, r.max - l.min});
}
void update(int x, int y, int v)
{
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        change(1, 1, n, id[top[x]], id[x], v);
        x = fat[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    change(1, 1, n, id[x], id[y], v);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &value[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    dfsInformation(1);
    dfsSplit(1);
    build(1, 1, n);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        printf("%d\n", calc(a, b));
        update(a, b, v);
    }
    return 0;
}