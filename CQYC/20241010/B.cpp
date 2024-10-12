#include <cstdio>
constexpr int MaxN = 2e3 + 5;
constexpr long long Mod = 1e9 + 7;
int n, q;
long long fact[MaxN];
long long sum[MaxN][MaxN];
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
long long C(long long n, long long m)
{
    return fact[n] * fsp(fact[n - m], Mod - 2) % Mod * fsp(fact[m], Mod - 2) % Mod;
}
int main()
{
    scanf("%d%d", &n, &q);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % Mod;
    }
    for (int c = 1; c <= n; c++)
    {
        for (int i = 1; i <= c; i++)
        {
            sum[c][i] = (sum[c][i - 1] + (fsp(2, c - i) * (i * i % Mod) % Mod * (c - i) % Mod * C(c, i))) % Mod;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%lld\n", (sum[c][b] - sum[c][a - 1] + Mod) % Mod);
    }
    return 0;
}
