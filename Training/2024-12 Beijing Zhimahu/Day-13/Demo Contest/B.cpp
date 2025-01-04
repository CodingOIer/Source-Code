#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n, b;
long long a;
long long p[MaxN];
int main()
{
    scanf("%d%lld%d", &n, &a, &b);
    long long best = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        best = std::max(best, p[i]);
    }
    printf("%lld\n", best + a);
    return 0;
}
