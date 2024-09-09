#include <cstdio>
#include <random>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 1e3 + 5;
constexpr int RandomCount = 5; // Count for random check
int n, Mod;
int a[MaxN][MaxN];
int b[MaxN][MaxN];
int c[MaxN][MaxN];
int x[MaxN];
int y[MaxN];
int z[MaxN];
int r[MaxN];
void solve()
{
    scanf("%d", &Mod);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    for (int _ = 1; _ <= RandomCount; _++)
    {
        for (int i = 1; i <= n; i++)
        {
            r[i] = (long long)(rnd()) % Mod;
        }
        for (int i = 1; i <= n; i++)
        {
            x[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                x[i] += 1ll * b[i][j] * r[j] % Mod;
                x[i] %= Mod;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            y[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                y[i] += 1ll * a[i][j] * x[j] % Mod;
                y[i] %= Mod;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            z[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                z[i] += 1ll * c[i][j] * r[j] % Mod;
                z[i] %= Mod;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (y[i] != z[i])
            {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}