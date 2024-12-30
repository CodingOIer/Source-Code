#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e3 + 5;
constexpr long long Mod = 998'244'353;
int n, m;
long long f[MaxN][MaxN];
long long g[MaxN][MaxN];
long long su[MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        f[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
            {
                g[i][j] = f[i][j - i];
                f[i][j] = f[i][j - i];
            }
            su[i][j] = (su[i - 1][j] + g[i][j]) % Mod;
            f[i][j] = (f[i][j] + (su[i - 1][j] - su[std::max(0, i - 1 - m)][j] + Mod)) % Mod;
        }
        printf("%lld\n", g[i][n]);
    }
    return 0;
}
