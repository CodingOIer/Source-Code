#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
constexpr long long Mod = 1e9 + 7;
int n;
long long p[MaxN];
long long diff[MaxN];
long long answer[MaxN];
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
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[pre] == p[i])
        {
            long long k = fsp(2, i - pre + 1);
            diff[i] = diff[pre - 1] + (k - 1) + (k - 1) * (diff[pre - 1] + (fsp(2, pre - 1) - 1));
            diff[i] %= Mod;
        }
        else
        {
            diff[i] = diff[i - 1] * 2 + (fsp(2, i - 1) - 1) + 1;
            diff[i] %= Mod;
            pre = i;
        }
        answer[i] = answer[pre - 1] + fsp(2, pre - 1) * (fsp(2, i - pre + 1) - 1) % Mod * (p[i] - 1) % Mod -
                    diff[pre - 1] * (fsp(2, i - pre + 1) - 1) % Mod;
        answer[i] += Mod;
        answer[i] %= Mod;
    }
    printf("%lld\n", answer[n]);
    return 0;
}