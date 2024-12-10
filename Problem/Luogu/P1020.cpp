#include <algorithm>
#include <cstdio>
#include <set>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
std::set<int> sk;
int tree[MaxN * 4];
int lazy[MaxN * 4];
void downstream(int c)
{
    if (lazy[c] != 0)
    {
        lazy[c * 2] = std::max(lazy[c * 2], lazy[c]);
        tree[c * 2] = std::max(tree[c * 2], lazy[c]);
        lazy[c * 2 + 1] = std::max(lazy[c * 2 + 1], lazy[c]);
        tree[c * 2 + 1] = std::max(tree[c * 2 + 1], lazy[c]);
        lazy[c] = 0;
    }
}
void change(int c, int s, int t, int l, int r, int val)
{
    if (l <= s && t <= r)
    {
        tree[c] = std::max(tree[c], val);
        lazy[c] = std::max(lazy[c], val);
        return;
    }
    downstream(c);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[c] = std::max(tree[c * 2], tree[c * 2 + 1]);
}
int query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    downstream(c);
    int res = 0;
    int mid = (s + t) / 2;
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

    for (; scanf("%d", &p[n + 1]) != EOF;)
    {
        n++;
    }
    for (int i = 1; i <= n; i++)
    {
        change(1, 1, 5e4, 1, p[i], query(1, 1, 5e4, p[i], p[i]) + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        auto it = sk.lower_bound(p[i]);
        if (it == sk.end())
        {
            sk.insert(p[i]);
            continue;
        }
        sk.erase(it);
        sk.insert(p[i]);
    }
    printf("%d\n", query(1, 1, 5e4, 1, 5e4));
    printf("%zu\n", sk.size());
    return 0;
}
