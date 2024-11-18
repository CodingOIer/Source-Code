#include <cstdio>
constexpr long long Mod = 998'244'353;
long long n;
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
inline void solve()
{
    scanf("%lld", &n);
    printf("%lld\n", n * (n + 1) % Mod * (2 * n + 1) % Mod * fsp(6, Mod - 2) % Mod);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
