#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        long long s, t;
        scanf("%lld%lld", &s, &t);
        p[i + 1] += p[i] / s * t;
    }
    printf("%lld\n", p[n]);
    return 0;
}