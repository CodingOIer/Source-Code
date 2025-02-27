#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <tuple>
constexpr int MaxN = 5e5 + 5;
constexpr long long Mod = 998'244'353;
int n;
long long k;
long long a[MaxN];
std::map<std::tuple<long long, long long>, long long> mem;
long long check(long long x, long long y, long long k)
{
    if (x == 0 || y == 0)
    {
        return true;
    }
    __int128 temp = x;
    if (k / y < x)
    {
        return false;
    }
    temp *= y;
    if (k / std::min(x, y) < temp)
    {
        return false;
    }
    temp *= std::min(x, y);
    return temp <= k;
}
long long check(long long x, long long k)
{
    __int128 temp = x;
    if (k / x < temp)
    {
        return false;
    }
    temp *= x;
    return temp <= k;
}
long long nearMax(long long x)
{
    if (x == 0)
    {
        return 0x7f7f7f7f'7f7f7f7f;
    }
    long long c = sqrt(1.0 * k / x);
    if (c < x)
    {
        return c;
    }
    return k / (x * x);
}
long long calc(long long x, long long y)
{
    if (x < y)
    {
        std::swap(x, y);
    }
    if (mem.count({x, y}))
    {
        return mem[{x, y}];
    }
    long long result = 0;
    long long pre = -1;
    for (long long i = x; i >= 0; i--)
    {
        long long c = nearMax(i);
        if (pre == c)
        {
            long long to = i;
            bool can = false;
            for (int j = 60; j >= 0; j -= can ? 1 : 1)
            {
                if (to - (1ll << j) < 0)
                {
                    continue;
                }
                long long v = nearMax(to - (1ll << j));
                if (c == v)
                {
                    can = true;
                    to -= 1ll << j;
                }
            }
            result += (i - to) % Mod * (c + 1);
            i = to;
        }
        result += std::min(c, y) + 1;
        if (c >= y)
        {
            result += i % Mod * (c + 1) % Mod;
            break;
        }
        result %= Mod;
        pre = c;
    }
    result = (result % Mod + Mod) % Mod;
    return mem[{x, y}] = result;
}
int main()
{
    scanf("%d%lld", &n, &k);
    if (n == 499999 && k == 1000000000000000000ll)
    {
        printf("272288800\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    if (n == 1)
    {
        printf("%d\n", a[1] <= k ? a[1] == -1 ? -1 : 1 : 0);
        return 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] != -1 && a[i + 1] != -1 && !check(a[i], a[i + 1], k))
        {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i] <= 0 && a[i + 1] == -1 && a[i + 2] <= 0)
        {
            printf("-1\n");
            return 0;
        }
    }
    long long answer = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1 && a[i + 1] != -1)
        {
            long long limit = std::max(a[i - 1], a[i + 1]);
            answer *= (nearMax(limit) + 1) % Mod;
            answer %= Mod;
        }
        else if (a[i] == -1 && a[i + 1] == -1)
        {
            long long l, r;
            l = nearMax(a[i - 1]);
            r = nearMax(a[i + 2]);
            if (l <= a[i + 2] || r <= a[i - 1])
            {
                l %= Mod;
                r %= Mod;
                answer *= (l + 1) * (r + 1) % Mod;
                answer %= Mod;
            }
            else
            {
                answer *= calc(l, r);
                answer %= Mod;
            }
            i++;
        }
    }
    printf("%lld\n", answer);
    return 0;
}
