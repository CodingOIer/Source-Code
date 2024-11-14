#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e6 + 5;
constexpr long long Mod1 = 998'244'353;
constexpr long long Mod2 = 998'244'853;
constexpr long long Base1 = 137;
constexpr long long Base2 = 173;
int n;
char s[MaxN];
long long fsp(long long x, long long y, long long Mod = Mod1)
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
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int w = 0;
    long long shl1, shl2;
    long long shr1, shr2;
    shl1 = shl2 = shr1 = shr2 = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        shl1 = (shl1 + s[i] * fsp(Base1, i, Mod1)) % Mod1;
        shl2 = (shl2 + s[i] * fsp(Base2, i, Mod2)) % Mod2;
        shr1 = (shr1 * Base1 + s[n - i + 1] * Base1) % Mod1;
        shr2 = (shr2 * Base2 + s[n - i + 1] * Base2) % Mod2;
        if (shl1 == shr1 && shl2 == shr2)
        {
            w = i;
        }
    }
    printf("%s", s + 1);
    for (int i = w + 1; i <= n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}
