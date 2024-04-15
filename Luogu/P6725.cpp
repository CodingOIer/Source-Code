#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
constexpr long long Mod = 1e9 + 7;
int n, k;
long long answer;
long long p[MaxN];
long long pw[MaxN];
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
        x *= x;
        x %= Mod;
        y /= 2;
    }
    return res;
}
long long C(long long x, long long y)
{
    return pw[x] * ksm(pw[x - y], Mod - 2) % Mod * ksm(pw[y], Mod - 2) % Mod;
}
int main()
{
    scanf("%d%d", &n, &k);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = pw[i - 1] * i;
        pw[i] %= Mod;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = k; i <= n; i++)
    {
        answer += C(i - 1, k - 1) * p[i];
        answer %= Mod;
    }
    printf("%lld\n", answer);
    return 0;
}