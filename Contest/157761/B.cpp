#include <algorithm>
#include <cstdio>
int t;
inline long long abs(long long x)
{
    return x >= 0 ? x : -x;
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        long long p, q, r, s;
        scanf("%lld%lld%lld%lld", &p, &q, &r, &s);
        long long max = std::max({p, q, r, s});
        if (!(p + q + r + s - max > max))
        {
            printf("no\n");
            continue;
        }
        if (p == r && q == s)
        {
            printf("no\n");
            continue;
        }
        long long a, b, c;
        a = q;
        b = s;
        c = abs(p - r);
        max = std::max({a, b, c});
        if (a + b + c - max > max)
        {
            printf("yes\n");
            continue;
        }
        a = p;
        b = r;
        c = abs(q - s);
        max = std::max({a, b, c});
        if (a + b + c - max > max)
        {
            printf("yes\n");
            continue;
        }
        printf("no\n");
    }
    return 0;
}