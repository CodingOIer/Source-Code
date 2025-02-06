#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e6 + 5;
constexpr long long Mod = 998'244'353;
int n;
long long p[MaxN];
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
int main()
{
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + n + 1);
    long long answer = 1;
    for (int i = 1; i <= n; i++)
    {
        answer = answer * gcd(i - 1, p[i]) % Mod;
    }
    printf("%lld\n", answer);
    return 0;
}
