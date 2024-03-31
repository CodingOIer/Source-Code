#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e6 + 5;
constexpr long long Diff = 754324754324754234;
int n, q;
long long tree[MaxN * 4];
long long lazy_add[MaxN * 4];
long long lazy_set[MaxN * 4];
void downstream(int c, int s, int t)
{
    long long add = lazy_add[c];
    long long set = lazy_set[c];
    if (add != 0)
    {
        tree[c * 2] += add;
        tree[c * 2 + 1] += add;
        lazy_add[c * 2] += add;
        lazy_add[c * 2 + 1] += add;
    }
    if (set != Diff)
    {
        tree[c * 2] = set;
        tree[c * 2 + 1] = set;
        lazy_set[c * 2] = set;
        lazy_set[c * 2 + 1] = set;
    }
    lazy_add[c] = 0;
    lazy_set[c] = Diff;
}
void changeAdd(int c, int s, int t, int l, int r, long long v)
{
    if (l <= s && t <= r)
    {
        tree[c] += v;
        lazy_add[c] += v;
        return;
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        changeAdd(c * 2, s, mid, l, r, v);
    }
    if (r > mid)
    {
        changeAdd(c * 2 + 1, mid + 1, t, l, r, v);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
void changeSet(int c, int s, int t, int l, int r, long long v)
{
    if (l <= s && t <= r)
    {
        tree[c] = v;
        lazy_set[c] = v;
        return;
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        changeSet(c * 2, s, mid, l, r, v);
    }
    if (r > mid)
    {
        changeSet(c * 2 + 1, mid + 1, t, l, r, v);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
long long query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    if (r <= mid)
    {
        return query(c * 2, s, mid, l, r);
    }
    if (l > mid)
    {
        return query(c * 2 + 1, mid + 1, t, l, r);
    }
    return std::max(query(c * 2, s, mid, l, r), query(c * 2 + 1, mid + 1, t, l, r));
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);
        changeSet(1, 1, n, i, i, x);
    }
    for (int i = 1; i <= 4 * n; i++)
    {
        lazy_set[i] = Diff;
    }
    for (int i = 1; i <= q; i++)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            long long x;
            scanf("%lld", &x);
            changeSet(1, 1, n, l, r, x);
        }
        else if (op == 2)
        {
            long long x;
            scanf("%lld", &x);
            changeAdd(1, 1, n, l, r, x);
        }
        else
        {
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}
