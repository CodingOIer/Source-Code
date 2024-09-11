#include <algorithm>
#include <cstdio>
const int MaxN = 2e5 + 5;
int n, q;
int p[MaxN];
long long sum[MaxN];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + p[i];
    }
    for (int i = 1; i <= q; i++)
    {
        long long x;
        scanf("%lld", &x);
        int answer = (std::upper_bound(sum + 1, sum + 1 + n, x) - sum) - 1;
        printf("%d\n", answer);
    }
    return 0;
}