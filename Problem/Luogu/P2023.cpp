#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n, m;
long long Mod;
long long p[MaxN];
long long tree[MaxN * 4];
long long lazy1[MaxN * 4];
long long lazy2[MaxN * 4];
inline void build(int c, int s, int t)
{
    lazy1[c] = 1;
    lazy2[c] = 0;
    if (s == t)
    {
        tree[c] = p[s];
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
    tree[c] = (tree[c * 2] + tree[c * 2 + 1]) % Mod;
}
inline void downstream(int c, int s, int t)
{
    if (lazy1[c] != 1)
    {
        tree[c * 2] = tree[c * 2] * lazy1[c] % Mod;
        lazy1[c * 2] = lazy1[c * 2] * lazy1[c] % Mod;
        lazy2[c * 2] = lazy2[c * 2] * lazy1[c] % Mod;
        tree[c * 2 + 1] = tree[c * 2 + 1] * lazy1[c] % Mod;
        lazy1[c * 2 + 1] = lazy1[c * 2 + 1] * lazy1[c] % Mod;
        lazy2[c * 2 + 1] = lazy2[c * 2 + 1] * lazy1[c] % Mod;
        lazy1[c] = 1;
    }
    if (lazy2[c] != 0)
    {
        int mid = (s + t) / 2;
        tree[c * 2] = (tree[c * 2] + lazy2[c] * (mid - s + 1)) % Mod;
        lazy2[c * 2] += lazy2[c];
        tree[c * 2 + 1] = (tree[c * 2 + 1] + lazy2[c] * (t - mid)) % Mod;
        lazy2[c * 2 + 1] += lazy2[c];
        lazy2[c] = 0;
    }
}
void changeMulti(int c, int s, int t, int l, int r, long long val)
{
    if (l <= s && t <= r)
    {
        tree[c] = tree[c] * val % Mod;
        lazy1[c] = lazy1[c] * val % Mod;
        lazy2[c] = lazy2[c] * val % Mod;
        return;
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        changeMulti(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        changeMulti(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[c] = (tree[c * 2] + tree[c * 2 + 1]) % Mod;
}
void changeAdd(int c, int s, int t, int l, int r, long long val)
{
    if (l <= s && t <= r)
    {
        tree[c] = (tree[c] + (t - s + 1) * val) % Mod;
        lazy2[c] = (lazy2[c] + val) % Mod;
        return;
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        changeAdd(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        changeAdd(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[c] = (tree[c * 2] + tree[c * 2 + 1]) % Mod;
}
long long query(int c, int s, int t, int l, int r)
{
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    downstream(c, s, t);
    int mid = (s + t) / 2;
    long long res = 0;
    if (l <= mid)
    {
        res += query(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res += query(c * 2 + 1, mid + 1, t, l, r);
    }
    return res % Mod;
}
int main()
{
    scanf("%d%lld", &n, &Mod);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    build(1, 1, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            changeMulti(1, 1, n, l, r, val);
        }
        if (op == 2)
        {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            changeAdd(1, 1, n, l, r, val);
        }
        if (op == 3)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}
