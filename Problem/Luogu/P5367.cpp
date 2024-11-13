#include <cstdio>
constexpr int MaxN = 1e6 + 5;
constexpr long long Mod = 998244353;
int n;
int p[MaxN];
long long answer;
long long fac[MaxN];
long long tree[MaxN];
long long lowerBot(long long x)
{
    return x & -x;
}
void change(long long x, long long v)
{
    for (; x <= n; x += lowerBot(x))
    {
        tree[x] += v;
    }
}
long long query(long long x)
{
    long long res = 0;
    for (; x > 0; x -= lowerBot(x))
    {
        res += tree[x];
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        change(i, 1);
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % Mod;
    }
    fac[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        answer += fac[n - i] * (query(p[i] - 1)) % Mod;
        answer %= Mod;
        change(p[i], -1);
    }
    printf("%lld\n", answer + 1);
    return 0;
}