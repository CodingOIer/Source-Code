#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e6 + 5;
constexpr long long Diff = 754324754324754324;
int n, m;
long long p[MaxN];
long long tree[MaxN * 4];
long long lazy_add[MaxN * 4];
long long lazy_change[MaxN * 4];
void build(int c, int s, int t)
{
    lazy_change[c] = Diff;
    if (s == t)
    {
        tree[c] = p[s];
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
void downstreamChange(int c)
{
    if (lazy_change[c] != Diff)
    {
        tree[c * 2] = lazy_change[c];
        tree[c * 2 + 1] = lazy_change[c];
        lazy_change[c * 2] = lazy_change[c];
        lazy_change[c * 2 + 1] = lazy_change[c];
        lazy_add[c * 2] = 0;
        lazy_add[c * 2 + 1] = 0;
        lazy_change[c] = Diff;
    }
}
void downstreamAdd(int c)
{
    if (lazy_add[c] != 0)
    {
        tree[c * 2] += lazy_add[c];
        if (lazy_change[c * 2] != Diff)
        {
            lazy_change[c * 2] += lazy_add[c];
        }
        else
        {
            lazy_add[c * 2] += lazy_add[c];
        }
        tree[c * 2 + 1] += lazy_add[c];
        if (lazy_change[c * 2 + 1] != Diff)
        {
            lazy_change[c * 2 + 1] += lazy_add[c];
        }
        else
        {
            lazy_add[c * 2 + 1] += lazy_add[c];
        }
        lazy_add[c] = 0;
    }
}
void downstream(int c)
{
    downstreamChange(c);
    downstreamAdd(c);
}
void change(int c, int s, int t, int l, int r, long long v)
{
    if (l <= s && t <= r)
    {
        tree[c] = v;
        lazy_add[c] = 0;
        lazy_change[c] = v;
        return;
    }
    downstream(c);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r, v);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r, v);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
void add(int c, int s, int t, int l, int r, long long v)
{
    if (l <= s && t <= r)
    {
        tree[c] += v;
        if (lazy_change[c] != Diff)
        {
            lazy_change[c] += v;
        }
        else
        {
            lazy_add[c] += v;
        }
        return;
    }
    downstream(c);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        add(c * 2, s, mid, l, r, v);
    }
    if (r > mid)
    {
        add(c * 2 + 1, mid + 1, t, l, r, v);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
long long query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    downstream(c);
    int mid = (s + t) / 2;
    long long res = -0x7f7f7f7f7f7f7f7f;
    if (l <= mid)
    {
        res = std::max(res, query(c * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        res = std::max(res, query(c * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            long long v;
            scanf("%lld", &v);
            change(1, 1, n, l, r, v);
        }
        else if (op == 2)
        {
            long long v;
            scanf("%lld", &v);
            add(1, 1, n, l, r, v);
        }
        else if (op == 3)
        {
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}