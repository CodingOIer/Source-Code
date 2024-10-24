#include <cstdio>
constexpr int MaxN = 5e6 + 5;
constexpr long long Mod = 998244353;
int t, n;
long long answer;
long long fac[MaxN];
inline long long read()
{
    char c;
    long long res = 0;
    for (;;)
    {
        c = getchar();
        if ('0' <= c && c <= '9')
        {
            res = c - '0';
            break;
        }
    }
    for (;;)
    {
        c = getchar();
        if (!('0' <= c && c <= '9'))
        {
            break;
        }
        res = res * 10 + (c - '0');
    }
    return res;
}
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y % 2 == 1)
        {
            res *= x;
            res %= Mod;
        }
        x *= x;
        x %= Mod;
        y /= 2;
    }
    return res;
}
long long inv(long long x)
{
    return fsp(x, Mod - 2);
}
long long C(long long x, long long y)
{
    return fac[x] * inv(fac[y]) % Mod * inv(fac[x - y]) % Mod;
}
int main()
{
    t = read();
    n = read();
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= Mod;
    }
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        x = read();
        y = read();
        answer ^= C(x, y);
    }
    printf("%lld\n", answer);
    return 0;
}