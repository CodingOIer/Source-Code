#include <cstdio>
constexpr int MaxN = 5e5 + 5;
int n, q;
long long p[MaxN];
long long s[MaxN];
long long aft(long long x, long long y)
{
    return s[x + y - 1] - s[x - 1];
}
inline void solve()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        s[i] = s[i - 1] + p[(i - 1) % n + 1];
    }
    for (int i = 1; i <= q; i++)
    {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        long long answer = 0;
        long long cl = (l + n - 1) / n;
        answer += aft((cl + (l - 1) % n - 1) % n + 1, n - ((l - 1) % n + 1) + 1);
        long long cr = (r + n - 1) / n;
        answer += aft(cr, (r - 1) % n + 1);
        answer += (cr - cl - 1) * s[n];
        printf("%lld\n", answer);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
