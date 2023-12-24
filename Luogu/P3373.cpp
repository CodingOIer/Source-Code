#include <cstdio>
const int MaxN = 1e5 + 5;
long long op;
long long n, m;
long long l, r, c;
long long p[MaxN];
long long d[4 * MaxN];
long long lazy[4 * MaxN];
void build(long long s, long long t, long long k)
{
    if (s == t)
    {
        d[k] = p[s];
        return;
    }
    long long mid;
    mid = (s + t) / 2;
    build(s, mid, 2 * k);
    build(mid + 1, t, 2 * k + 1);
    d[k] = d[2 * k] + d[2 * k + 1];
    return;
}
void times(long long s, long long t, long long l, long long r, long long k, long long c)
{
}
void add(long long s, long long t, long long l, long long r, long long k, long long c)
{
    if (l <= s && t <= r)
    {
        d[k] += (t - s + 1) * c;
        lazy[k] += c;
        return;
    }
    long long mid;
    mid = (s + t) / 2;
    if (lazy[k] != 0)
    {
        d[2 * k] += (mid - s + 1) * lazy[k];
        d[2 * k + 1] += (t - mid) * lazy[k];
        lazy[2 * k] += lazy[k];
        lazy[2 * k + 1] += lazy[k];
        lazy[k] = 0;
    }
    if (l <= mid)
    {
        add(s, mid, l, r, 2 * k, c);
    }
    if (r >= mid + 1)
    {
        add(mid + 1, t, l, r, 2 * k + 1, c);
    }
    d[k] = d[2 * k] + d[2 * k + 1];
}
long long sum(long long s, long long t, long long l, long long r, long long k)
{
    if (l <= s && t <= r)
    {
        return d[k];
    }
    long long mid;
    mid = (s + t) / 2;
    if (lazy[k] != 0)
    {
        d[2 * k] += (mid - s + 1) * lazy[k];
        d[2 * k + 1] += (t - mid) * lazy[k];
        lazy[2 * k] += lazy[k];
        lazy[2 * k + 1] += lazy[k];
        lazy[k] = 0;
    }
    long long res;
    res = 0;
    if (l <= mid)
    {
        res += sum(s, mid, l, r, 2 * k);
    }
    if (r >= mid + 1)
    {
        res += sum(mid + 1, t, l, r, 2 * k + 1);
    }
    return res;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    build(1, n, 1);
    for (long long i = 1; i <= m; i++)
    {
        scanf("%lld", &op);
        if (op == 1)
        {
            scanf("%lld%lld%lld", &l, &r, &c);
            add(1, n, l, r, 1, c);
        }
        else if (op == 2)
        {
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", sum(1, n, l, r, 1));
        }
    }
    return 0;
}