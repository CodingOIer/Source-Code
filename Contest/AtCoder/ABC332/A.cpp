#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, s, k;
long long sum;
long long x, y;
int main()
{
    scanf("%d%d%d", &n, &s, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x, &y);
        sum += x * y;
    }
    printf("%lld\n", (sum >= s ? 0 : k) + sum);
    return 0;
}