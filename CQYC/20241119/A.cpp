#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e7 + 5;
constexpr long long Mod = 998'244'353;
constexpr long double Pai = 3.1415926535897932384626433832795;
long long n, m, k;
long long f[MaxN];
long long g[MaxN];
long long s[MaxN];
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res *= x;
            res %= Mod;
        }
        y >>= 1;
        x *= x;
        x %= Mod;
    }
    return res;
}
long long frac(long long x, long long y)
{
    return x * fsp(y, Mod - 2) % Mod;
}
long long sum(long long x, long long y)
{
    return (x + y) * (y - x + 1) / 2 % Mod;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    long long l, r;
    l = 0;
    r = m;
    long long can = 0;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        if (2 * n * Pai * mid <= 4 * n * m)
        {
            can = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    long long base = frac(1, 2 * m) % Mod * sum(1, can) * 2 % Mod;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 2 * i * base % Mod;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = (g[i - 1] + f[i]) % Mod;
    }
    long long answer1 = 0;
    for (int i = 2; i <= n; i++)
    {
        answer1 += g[i - 1] * 2 * m % Mod;
        answer1 %= Mod;
    }
    k = can;
    long long plan = sum(1, k);
    for (int i = 1; i <= n; i++)
    {
        answer1 += plan * i * 2 % Mod;
        answer1 %= Mod;
    }
    printf("%lld ", answer1);
    long long still = 2 * m - 2 * can - 1 % Mod;
    long long answer2 = 0;
    for (int i = 1; i <= n; i++)
    {
        answer2 += ((2 * can + 1) % Mod * sum(1, i - 1) + i * still % Mod * (i - 1) + sum(1, i - 1) * still % Mod) %
                   Mod * 2 * m % Mod;
        answer2 += (2 * i * still) % Mod * m % Mod;
        answer2 %= Mod;
    }
    answer2 += sum(1, n) * m * 2 % Mod;
    answer2 %= Mod;
    printf("%lld\n", answer2);
    return 0;
}
