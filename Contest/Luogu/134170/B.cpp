#include <cstdio>
int t;
long long x, a, b;
long long solve()
{
    if (x == 0)
    {
        return -b;
    }
    if (a == 0)
    {
        return -b;
    }
    if (b == 0)
    {
        return x;
    }
    long long next = a * x - b;
    if (next == 0)
    {
        return -b;
    }
    else if (next < 0)
    {
        return next;
    }
    else if (next >= x)
    {
        return x;
    }
    else
    {
        long long add = x - next;
        long long need = x / add;
        if (x - need * add == 0)
        {
            return -b;
        }
        else if (x - need * add < 0)
        {
            return x - need * add;
        }
        else
        {
            return x - (need + 1) * add;
        }
    }
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld%lld%lld", &x, &a, &b);
        long long next = x * a - b;
        if (next >= x)
        {
            printf("%lld\n", x);
            continue;
        }
        long long l = x;
        x = x * a - b;
        long long res = -0x3f3f3f3f3f3f3f3f;
        for (int u = 1; u <= 1e6; u++)
        {
            if (x < 0 || l == x)
            {
                res = x;
                break;
            }
            l = x;
            x = x * a - b;
        }
        if (res == -0x3f3f3f3f3f3f3f3f)
        {
            res = solve();
        }
        printf("%lld\n", res);
    }
    return 0;
}