#include <cstdio>
constexpr int MaxN = 5e2 + 5;
constexpr long long Mod = 1e9 + 7;
int n, p, m;
long long a[MaxN][MaxN];
long long b[MaxN][MaxN];
long long c[MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &n, &p, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            scanf("%lld", &a[i][j]);
        }
    }
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &b[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= p; k++)
        {
            for (int j = 1; j <= m; j++)
            {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= Mod;
                c[i][j] += Mod;
                c[i][j] %= Mod;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%lld ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}