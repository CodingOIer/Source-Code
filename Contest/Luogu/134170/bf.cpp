#include <cstdio>
int t;
long long x, a, b;
int main()
{
    // freopen("std.in", "r", stdin);
    // freopen("bf.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld%lld%lld", &x, &a, &b);
        long long next = x * a - b;
        if (a == next)
        {
            long long add = x - next;
            if (x % add == 0)
            {
                printf("%lld\n", -b);
            }
            else
            {
                printf("%lld\n", x - add * (x / add + 1));
            }
        }
        if (next >= x)
        {
            printf("%lld\n", x);
            continue;
        }
        long long l = x;
        x = x * a - b;
        for (;;)
        {
            if (x < 0 || l == x)
            {
                printf("%lld\n", x);
                break;
            }
            l = x;
            x = x * a - b;
        }
    }
    return 0;
}