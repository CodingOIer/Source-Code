#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e5 + 5;
int n;
long long p[MaxN];
long long px[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    long long prefix = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix += px[i];
        p[i] += prefix;
        int most = std::min(p[i], 0ll + n - i);
        px[i + 1]++;
        px[i + most + 1]--;
        p[i] -= most;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", p[i]);
    }
    printf("\n");
    return 0;
}
