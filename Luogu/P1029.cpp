#include <cstdio>
long long p, q;
long long plan;
long long times;
long long gcd(long long x, long long y)
{
    for (;;)
    {
        if (x == 0)
        {
            return y;
        }
        else if (x == y || y == 0)
        {
            return x;
        }
        else if (x > y)
        {
            x %= y;
        }
        else if (x < y)
        {
            y %= x;
        }
    }
}
int main()
{
    scanf("%lld%lld", &p, &q);
    times = p * q;
    for (long long x = 1; x * x <= times; x++)
    {
        long long y;
        y = times / x;
        if (gcd(x, y) == p && x * y / gcd(x, y) == q && times % x == 0)
        {
            plan += x != y ? 2 : 1;
        }
    }
    printf("%lld\n", plan);
    return 0;
}