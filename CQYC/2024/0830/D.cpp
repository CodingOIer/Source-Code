#include <cstdio>
constexpr int MaxN = 1e6 + 5;
constexpr long long Mod = 1e9 + 7;
int n;
int a[MaxN];
int b[MaxN];
int c[MaxN];
int w[MaxN];
long long solve(int al, int ar, int bl, int br)
{
    if (al == ar)
    {
        return 1;
    }
    if (a[al + 1] == b[br - 1])
    {
        return 2 * solve(al + 1, ar, bl, br - 1);
    }
    else
    {
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        w[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    printf("%lld\n", solve(1, n, 1, n));
    return 0;
}