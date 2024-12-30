#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
long long m;
long long p[MaxN];
long long calc(long long x)
{
    long long res = 0;
    for (int i = 1; i <= 2 * x; i++)
    {
        res += (p[i] + p[2 * x - i + 1]) % m;
    }
    for (int i = 2 * x + 1; i <= 2 * n; i++)
    {
        res += (p[i] + p[2 * n - i + 1]) % m;
    }
    return m;
}
int main()
{
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + 2 * n);
    int l, r;
    l = 1;
    r = n;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
    }
    return 0;
}
