#include <cstdio>
long long n, s, k;
long long gcd(long long x, long long y)
{
    for (;;)
    {
        if (x == 0 || x == y)
        {
            return y;
        }
        else if (y == 0)
        {
            return x;
        }
        else if (x > y)
        {
            x %= y;
        }
        else if (y > x)
        {
            y %= x;
        }
    }
}
void exGcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exGcd(b, a % b, y, x);
    y -= a / b * x;
}
inline void solve()
{
    scanf("%lld%lld%lld", &n, &s, &k);
    s = n - s;
    long long g = gcd(k, n);
    if (s % g != 0)
    {
        printf("-1\n");
        return;
    }
    n /= g;
    s /= g;
    k /= g;
    long long x, y;
    exGcd(k, n, x, y);
    x = x < 0 ? x + n : x;
    printf("%lld\n", s * x % n);
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