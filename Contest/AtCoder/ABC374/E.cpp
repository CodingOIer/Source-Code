#include <algorithm>
#include <cstdio>
#include <utility>
constexpr int MaxN = 1e2 + 5;
int n, x;
long long a[MaxN];
long long b[MaxN];
long long p[MaxN];
long long q[MaxN];
inline long long check(long long x)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        long long best = 0x7f7f7f7f;
        for (long long j = (x + a[i] - 1) / a[i]; j >= std::max(0ll, (x + a[i] - 1) / a[i] - int(1e5)); j--)
        {
            best = std::min(best, p[i] * j + (x - a[i] * j <= 0 ? 0 : (x - a[i] * j + b[i] - 1) / b[i] * q[i]));
        }
        std::swap(a[i], b[i]);
        std::swap(p[i], q[i]);
        for (long long j = (x + a[i] - 1) / a[i]; j >= std::max(0ll, (x + a[i] - 1) / a[i] - int(1e5)); j--)
        {
            best = std::min(best, p[i] * j + (x - a[i] * j <= 0 ? 0 : (x - a[i] * j + b[i] - 1) / b[i] * q[i]));
        }
        std::swap(a[i], b[i]);
        std::swap(p[i], q[i]);
        res += best;
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld%lld", &a[i], &p[i], &b[i], &q[i]);
        if (1.0 * b[i] / q[i] > 1.0 * a[i] / p[i])
        {
            std::swap(a[i], b[i]);
            std::swap(p[i], q[i]);
        }
    }
    long long l, r;
    l = 0;
    r = 1e9;
    long long res = 0;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        if (check(mid) <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld\n", res);
    return 0;
}