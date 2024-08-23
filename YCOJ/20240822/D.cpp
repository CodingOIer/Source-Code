#include <cstdio>
constexpr int MaxN = 1e7 + 5;
constexpr long long Mod = 998'244'353;
long long n, k;
long long fact[MaxN];
inline long long fsp(long long x, long long y)
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
inline long long inv(long long x)
{
    return fsp(x, Mod - 2);
}
inline long long A(long long n, long long m)
{
    return fact[n] * inv(fact[n - m]) % Mod;
}
inline long long C(long long n, long long m)
{
    return A(n, m) * inv(A(m, m)) % Mod;
}
int main()
{
    scanf("%lld%lld", &n, &k);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= Mod;
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer += fsp(i, k) * C(n, i) % Mod * fact[i - 1] % Mod * fsp(n, n - i) % Mod;
        answer %= Mod;
    }
    printf("%lld\n", answer);
    return 0;
}