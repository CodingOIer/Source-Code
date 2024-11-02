#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, m;
long long r[MaxN];
long long q[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &r[i], &q[i]);
        q[i] += r[i];
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        long long t, d;
        scanf("%lld%lld", &t, &d);
        long long back = d;
        d %= r[t];
        printf("%lld\n", back + (q[t] - d) % r[t]);
    }
    return 0;
}