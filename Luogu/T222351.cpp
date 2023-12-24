#include <cstdio>
int t;
long long a, b, c;
void solve()
{
    scanf("%lld%lld%lld", &a, &b, &c);
    long long res;
    long long l, r;
    l = 1;
    r = c + 1;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        if (a * c + b + mid < c * (c + 1) / 2)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld %lld\n", c + 1, l);
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}