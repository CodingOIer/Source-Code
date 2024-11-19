#include <algorithm>
#include <cstdio>
long long n, k;
long long sum(long long x, long long y)
{
    return (x + y) * (y - x + 1) / 2;
}
inline void solve()
{
    scanf("%lld%lld", &n, &k);
    long long l, r;
    l = k;
    r = k + n - 1;
    long long answer = 0x7f7f7f7f7f7f7f7f;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        long long re = sum(k, mid) - sum(mid + 1, n + k - 1);
        answer = std::min(answer, re < 0 ? -re : re);
        if (re < 0)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld\n", answer);
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
