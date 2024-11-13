#include <cstdio>
constexpr long long Mod = 6'662'333;
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
        x *= x;
        x %= Mod;
        y >>= 1;
    }
    return res;
}
int main()
{
    scanf("%lld", &n);
    printf("%lld\n", fsp(2, n - 1));
    return 0;
}