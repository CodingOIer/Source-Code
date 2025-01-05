#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
long long Mod;
long long dp[MaxN];
long long frac[MaxN];
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res = res * x % Mod;
        }
        x = x * x % Mod;
        y >>= 1;
    }
    return res;
}
long long inv(long long x)
{
    return fsp(x, Mod - 2);
}
long long A(long long n, long long m)
{
    return frac[n] * inv(frac[n - m]) % Mod;
}
long long C(long long n, long long m)
{
    return A(n, m) * inv(A(m, m)) % Mod;
}
int main()
{
    scanf("%d%lld", &n, &Mod);
    frac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        frac[i] = frac[i - 1] * i % Mod;
    }
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
    }
    return 0;
}
