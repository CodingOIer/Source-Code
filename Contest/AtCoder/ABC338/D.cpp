/**
 * @file AtCoder\ABC338\D.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief AtCoder
 * @version 1.0
 * @date 2024-01-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
long long tree[MaxN * 4];
long long lazy[MaxN * 4];
void downstream(int cur, int s, int t)
{
    if (lazy[cur] != 0)
    {
        tree[cur * 2] += lazy[cur];
        tree[cur * 2 + 1] += lazy[cur];
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2 + 1] += lazy[cur];
        lazy[cur] = 0;
    }
}
void tree_change(int cur, int s, int t, int l, int r, long long val)
{
    if (l > r)
    {
        return;
    }
    if (l <= s && t <= r)
    {
        tree[cur] += val;
        lazy[cur] += val;
        return;
    }
    downstream(cur, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        tree_change(cur * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        tree_change(cur * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[cur] = std::min(tree[cur * 2], tree[cur * 2 + 1]);
}
long long query(int cur, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[cur];
    }
    downstream(cur, s, t);
    int mid = (s + t) / 2;
    long long res = 0x3f3f3f3f3f3f3f3f;
    if (l <= mid)
    {
        res = std::min(res, query(cur * 2, s, mid, l, r));
    }
    if (r > mid)
    {
        res = std::min(res, query(cur * 2 + 1, mid + 1, t, l, r));
    }
    return res;
}
void change(int l, int r, long long val)
{
    if (l <= r)
    {
        tree_change(1, 1, n, l, r - 1, val);
    }
    else
    {
        tree_change(1, 1, n, l, n, val);
        tree_change(1, 1, n, 1, r - 1, val);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 2; i <= m; i++)
    {
        int x, y;
        x = p[i - 1];
        y = p[i];
        if (x > y)
        {
            std::swap(x, y);
        }
        change(y, x, y - x);
        change(x, y, n - (y - x));
    }
    printf("%lld\n", query(1, 1, n, 1, n));
    return 0;
}