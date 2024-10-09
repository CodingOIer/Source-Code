#include <algorithm>
#include <cstdio>
inline long long cnt(long long x)
{
    long long res = 0;
    for (; x != 1;)
    {
        res++;
        x /= 2;
    }
    return res;
}
long long calc(long long a, long long b, long long c)
{
    long long all = cnt(2 * (a + b + c) - 1);
    if ((a == 0 ? 1 : 0) + (b == 0 ? 1 : 0) + (c == 0 ? 1 : 0) >= 1)
    {
        return all;
    }
    long long x, y, z;
    x = std::max({a, b, c});
    z = std::min({a, b, c});
    y = a + b + c - x - z;
    return std::max(calc(std::max(x - (1ll << (all - 1)), 0ll), y, z) + 1, all);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", calc(a, b, c));
    }
    return 0;
}