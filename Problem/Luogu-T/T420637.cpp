/**
 * @file Luogu\T420637.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief Luogu
 * @version 1.0
 * @date 2024-01-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cstdio>
constexpr int MaxN = 2e6 + 5;
constexpr int Mod = 1e9 + 7;
int t;
long long p[MaxN];
long long fac[MaxN];
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
long long C(long long n, long long m)
{
    return fac[n] * inv(fac[m]) % Mod * inv(fac[n - m]) % Mod;
}
int main()
{
    scanf("%d", &t);
    fac[0] = 1;
    for (int i = 1; i <= 2e6; i++)
    {
        fac[i] = fac[i - 1] * i % Mod;
    }
    for (int i = 1; i <= t; i++)
    {
        long long n;
        scanf("%lld", &n);
        printf("%lld\n", C(2 * n, n));
    }
    return 0;
}