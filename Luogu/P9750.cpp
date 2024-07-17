#include <cmath>
#include <cstdio>
int t, m;
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
inline void print(int a, int b, bool end = true)
{
    int g = gcd(a, b);
    a /= g;
    b /= g;
    if (b < 0)
    {
        a = -a;
        b = -b;
    }
    if (b == 1)
    {
        printf("%d", a);
    }
    else
    {
        printf("%d/%d", a, b);
    }
    if (end)
    {
        printf("\n");
    }
}
inline int breakSqrt(int x)
{
    int res = 1;
    for (int i = 10000; i >= 1; i--)
    {
        if (x % (i * i) == 0)
        {
            return i;
        }
    }
    return -1;
}
inline void solve()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        printf("NO\n");
        return;
    }
    int op = 1;
    if (a < 0)
    {
        op = -1;
    }
    if (int(sqrt(delta)) * int(sqrt(delta)) == delta)
    {
        print(-b + op * int(sqrt(delta)), 2 * a);
    }
    else
    {
        if (b != 0)
        {
            print(-b, 2 * a, false);
            printf("%c", op == 1 ^ 2 * a < 0 ? '+' : '-');
        }
        else
        {
            if (!(op == 1 ^ 2 * a < 0))
            {
                printf("-");
            }
        }
        int k = breakSqrt(delta);
        delta /= k * k;
        int l = abs(2 * a);
        int g = gcd(k, l);
        k /= g;
        l /= g;
        if (k != 1)
        {
            printf("%d*", k);
        }
        printf("sqrt(%d)", delta);
        if (l != 1)
        {
            printf("/%d", l);
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}