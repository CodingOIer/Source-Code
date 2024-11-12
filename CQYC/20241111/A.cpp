#include <cstdio>
constexpr int MaxN = 5e3 + 5;
constexpr long long Mod = 998'244'353;
int n, m, k;
int su[MaxN][MaxN];
char s[MaxN][MaxN];
long long pw[MaxN * MaxN];
long long f[MaxN][MaxN];
inline int sum(int sx, int sy, int ex, int ey)
{
    return su[ex][ey] - su[sx - 1][ey] - su[ex][sy - 1] + su[sx - 1][sy - 1];
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = 'U';
        }
    }
    pw[0] = 1;
    for (int i = 1; i <= n * m; i++)
    {
        pw[i] = pw[i - 1] * 3;
        pw[i] = pw[i] >= Mod ? pw[i] - Mod : pw[i];
        pw[i] = pw[i] >= Mod ? pw[i] - Mod : pw[i];
    }
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        char ch;
        scanf("%d%d", &x, &y);
        scanf(" ");
        scanf("%c", &ch);
        s[x][y] = ch;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            su[i][j] = su[i - 1][j] + su[i][j - 1] - su[i - 1][j - 1] + (s[i][j] == 'U' ? 1 : 0);
        }
    }
    f[n][m] = s[n][m] == 'U' ? 3 : 1;
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            if (i == n && j == m)
            {
                continue;
            }
            if (s[i][j] == 'D')
            {
                f[i][j] += pw[sum(i, j + 1, i, m)] * f[i + 1][j];
            }
            else if (s[i][j] == 'R')
            {
                f[i][j] += pw[sum(i + 1, j, n, j)] * f[i][j + 1];
            }
            else if (s[i][j] == 'X')
            {
                f[i][j] += pw[sum(i, j + 1, i, m)] * f[i + 1][j];
                f[i][j] += pw[sum(i + 1, j, n, j)] * f[i][j + 1];
            }
            else if (s[i][j] == 'U')
            {
                // D
                f[i][j] += pw[sum(i, j + 1, i, m)] * f[i + 1][j];
                // R
                f[i][j] += pw[sum(i + 1, j, n, j)] * f[i][j + 1];
                // X
                f[i][j] += pw[sum(i, j + 1, i, m)] * f[i + 1][j];
                f[i][j] += pw[sum(i + 1, j, n, j)] * f[i][j + 1];
            }
            f[i][j] %= Mod;
        }
    }
    printf("%lld\n", f[1][1]);
    return 0;
}