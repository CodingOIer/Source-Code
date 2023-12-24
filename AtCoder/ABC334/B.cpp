#include <cstdio>
long long a, m, l, r;
long long abs(const long long &__x)
{
    return __x > 0 ? __x : -__x;
}
int main()
{
    scanf("%lld%lld%lld%lld", &a, &m, &l, &r);
    long long tmp = l;
    if (a > l)
    {
        l = a - abs(a - l) / m * m;
    }
    else
    {
        l = a + abs(a - l) / m * m;
    }
    if (tmp > l)
    {
        l += m;
    }
    tmp = r;
    if (a > r)
    {
        r = a - abs(a - r) / m * m;
    }
    else
    {
        r = a + abs(a - r) / m * m;
    }
    if (tmp < r)
    {
        r -= m;
    }
    printf("%lld\n", (r - l) / m + 1);
    return 0;
}