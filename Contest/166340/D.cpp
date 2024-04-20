#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    printf("%lld\n", p[1] + p[n]);
    return 0;
}