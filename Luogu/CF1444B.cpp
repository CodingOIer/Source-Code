#include <algorithm>
#include <cstdio>
constexpr int MaxN = 3e5 + 5;
constexpr long long Mod = 998'244'353;
long long fsp(long long x, long long y)
{
    long long response = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            response *= x;
            response %= Mod;
        }
        y >>= 1;
        x *= x;
        x %= Mod;
    }
    return response;
}
long long inv(long long x)
{
    return fsp(x, Mod - 2);
}
long long A(long long n, long long m)
{
    long long response = 1;
    for (int i = n; i >= n - m + 1; i--)
    {
        response *= i;
        response %= Mod;
    }
    return response;
}
long long C(long long n, long long m)
{
    return A(n, m) * inv(A(m, m)) % Mod;
}
int n;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%lld", &p[i]);
    }
    long long s1, s2;
    s1 = 0;
    s2 = 0;
    std::sort(p + 1, p + 1 + 2 * n);
    for (int i = 1; i <= n; i++)
    {
        s1 += p[i];
        s2 += p[n + i];
    }
    printf("%lld\n", (s2 - s1) % Mod * C(2 * n, n) % Mod);
    return 0;
}