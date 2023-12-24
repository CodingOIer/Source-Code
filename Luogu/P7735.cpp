#include <algorithm>
#include <cstdio>
#include <cstring>
#include <random>
#include <vector>
constexpr int MaxN = 1e5 + 5;
class node
{
  public:
    int lazy;
    int answer;
    int left_color;
    int right_color;
    node()
    {
        lazy = 0;
        answer = 0;
        left_color = 0;
        right_color = 0;
    }
    friend node operator+(const node &__x, const node &__y)
    {
        node res;
        res.left_color = __x.left_color;
        res.right_color = __y.right_color;
        res.answer = __x.answer + __y.answer + (__x.right_color == __y.left_color ? 1 : 0);
        return res;
    }
    void operator+=(const node &__x)
    {
        (*this) = (*this) + __x;
    }
};
int t;
int n, q;
int id_cnt;
int id[MaxN];
int fat[MaxN];
int top[MaxN];
int son[MaxN];
int size[MaxN];
int depth[MaxN];
node tree[MaxN * 4];
std::vector<int> link[MaxN];
std::mt19937 rnd(std::random_device{}());
void init()
{
    for (int i = 1; i <= n; i++)
    {
        link[i].clear();
    }
    id_cnt = 0;
    memset(son, 0, sizeof(son));
}
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
        tree[root].answer = 0;
        int tmp = 0;
        for (; tmp == 0;)
        {
            tmp = rnd();
        }
        tree[root].left_color = tmp;
        tree[root].right_color = tmp;
        return;
    }
    int mid = (s + t) / 2;
    build(root * 2, s, mid);
    build(root * 2 + 1, mid + 1, t);
    tree[root] = tree[root * 2] + tree[root * 2 + 1];
}
void pushDown(int root, int s, int t)
{
    if (tree[root].lazy != 0)
    {
        int mid = (s + t) / 2;
        tree[root * 2].lazy = tree[root].lazy;
        tree[root * 2].answer = mid - s;
        tree[root * 2].left_color = tree[root].lazy;
        tree[root * 2].right_color = tree[root].lazy;
        tree[root * 2 + 1].answer = t - mid - 1;
        tree[root * 2 + 1].lazy = tree[root].lazy;
        tree[root * 2 + 1].left_color = tree[root].lazy;
        tree[root * 2 + 1].right_color = tree[root].lazy;
    }
}
void change(int root, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        tree[root].lazy = val;
        tree[root].answer = t - s;
        tree[root].left_color = val;
        tree[root].right_color = val;
        return;
    }
    pushDown(root, s, t);
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
    pushDown(root, s, t);
    int mid = (s + t) / 2;
    node left, right;
    if (l <= mid)
    {
        left = query(root * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        right = query(root * 2 + 1, mid + 1, t, l, r);
    }
    if (left.left_color != 0 && right.left_color != 0)
    {
        return left + right;
    }
    else if (left.left_color != 0)
    {
        return left;
    }
    else if (right.left_color != 0)
    {
        return right;
    }
}
void changeOnRoute(int x, int y)
{
    int tmp = 0;
    for (; tmp == 0;)
    {
        tmp = rnd();
    }
    node res;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        change(1, 1, n, id[top[x]], id[x], tmp);
        x = fat[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    change(1, 1, n, id[x], id[y], tmp);
}
int queryOnRoute(int x, int y)
{
    int res = 0;
    for (; top[x] != top[y];)
    {
        if (depth[top[x]] < depth[top[y]])
        {
            std::swap(x, y);
        }
        node tmp = query(1, 1, n, id[top[x]], id[x]);
        res += tmp.answer;
        if (tmp.left_color == query(1, 1, n, id[fat[top[x]]], id[fat[top[x]]]).right_color)
        {
            res++;
        }
        x = fat[top[x]];
    }
    if (depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    res += query(1, 1, n, id[x], id[y]).answer;
    return res;
}
void solve()
{
    init();
    scanf("%d%d", &n, &q);
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
    for (int i = 1; i <= q; i++)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            changeOnRoute(x, y);
        }
        else if (op == 2)
        {
            printf("%d\n", queryOnRoute(x, y));
        }
    }
    return;
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}