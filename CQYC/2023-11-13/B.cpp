#include <cstdio>
#include <cstring>
const int MaxN = 1e3 + 5;
const long long Mod = 1e18 + 31;
int n;
char s[MaxN];
long long hash_sum[MaxN];
long long ksm(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y % 2 == 1)
        {
            res *= x;
            res %= Mod;
        }
        y /= 2;
        x *= x;
        x %= Mod;
    }
    return res;
}
long long getHash(int l, int r)
{
    return (hash_sum[r] - hash_sum[l - 1] * ksm(131, r - l + 1) + Mod) % Mod;
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        hash_sum[i] = hash_sum[i - 1] * 131 + s[i];
    }
    printf("%lld %lld\n", getHash(1, 3), getHash(4, 6));
    return 0;
}