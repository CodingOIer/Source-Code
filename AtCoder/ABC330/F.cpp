#include <cstdio>
const int MaxN = 2e5 + 5;
int n;
long long k;
long long x[MaxN];
long long y[MaxN];
int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    return 0;
}