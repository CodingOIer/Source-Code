#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 1e6 + 5;
constexpr long long Mod = 1e9 + 7;
int n, k;
long long p[MaxN];
long long mul[MaxN];
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res = res * x % Mod;
        }
        y >>= 1;
        x = x * x % Mod;
    }
    return res;
}
long long inv(long long x)
{
    return fsp(x, Mod - 2);
}
long long A(long long n, long long m)
{
    return m == 0 ? 1 : mul[n] * inv(mul[n - m]) % Mod;
}
long long C(long long n, long long m)
{
    return A(n, m) * inv(A(m, m)) % Mod;
}
int main()
{
    scanf("%d%d", &n, &k);
    k = n - k;
    mul[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        mul[i] = mul[i - 1] * i % Mod;
    }
    long long answer = 0;
    answer += p[1] * C(n - 2, k - 2) % Mod;
    answer += (p[1] - p[2] + Mod) * C(n - 2, k - 1) % Mod;
    for (int i = 2; i <= n; i++)
    {
        answer += p[i] * C(n - 3, k - 3) % Mod;
        answer += (p[i] - p[i + 1] + Mod) * C(n - 3, k - 2) % Mod;
    }
    answer %= Mod;
    printf("%lld\n", answer * inv(C(n - 1, k - 1)) % Mod);
    return 0;
}
