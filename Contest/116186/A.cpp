#include <algorithm>
#include <cstdio>
int t;
long long gcd(long long x, long long y)
{
    for (;;)
    {
        if (x == y)
        {
            return x;
        }
        else if (x > y)
        {
            x -= y;
        }
        else
        {
            y -= x;
        }
    }
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        long long g = gcd(a, b);
        a /= g;
        b /= g;
        long long min = std::min(a, b);
        long long step = (c + min - 1) / min;
        printf("%lld\n", b * step + a * step);
    }
    return 0;
}