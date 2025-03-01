#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, x;
long long u[MaxN];
long long d[MaxN];
long long check(long long k)
{
    long long result = 0;
    long long pl, pr;
    pl = 0;
    pr = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        long long cost = u[i] + d[i] - k;
        result += cost;
        long long cl = std::max(0ll, u[i] - cost);
        long long cr = std::min(k, u[i]);
        if (cr < pl - x || pr + x < cl)
        {
            return -1;
        }
        cl = std::max(cl, pl - x);
        cr = std::min(cr, pr + x);
        pl = cl;
        pr = cr;
    }
    return result;
}
int main()
{
    scanf("%d%d", &n, &x);
    long long l, r;
    l = 0;
    r = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &u[i], &d[i]);
        r = std::min(r, u[i] + d[i]);
    }
    long long result = 0;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        if (check(mid) == -1)
        {
            r = mid - 1;
        }
        else
        {
            result = mid;
            l = mid + 1;
        }
    }
    printf("%lld\n", check(result));
    return 0;
}
