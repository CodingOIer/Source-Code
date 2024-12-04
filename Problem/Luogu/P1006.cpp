#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e1 + 5;
int n, m;
int p[MaxN][MaxN];
int dp[MaxN][MaxN][MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= m; y1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                int y2 = (x1 + y1) - x2;
                if (!(1 <= y2 && y2 <= m))
                {
                    continue;
                }
                int pre = std::max({
                    dp[x1 - 1][y1][x2][y2],
                    dp[x1][y1 - 1][x2][y2],
                    dp[x1][y1][x2 - 1][y2],
                    dp[x1][y1][x2][y2 - 1],
                    dp[x1 - 1][y1][x2 - 1][y2],
                    dp[x1 - 1][y1][x2][y2 - 1],
                    dp[x1][y1 - 1][x2 - 1][y2],
                    dp[x1][y1 - 1][x2][y2 - 1],
                });
                dp[x1][y1][x2][y2] = pre + ((x1 == 1 && y1 == 1) || (x1 == n && y1 == m) ? p[x1][y1]
                                            : x1 == x2 && y1 == y2                       ? -0x3f3f3f3f
                                                                                         : p[x1][y1] + p[x2][y2]);
            }
        }
    }
    printf("%d\n", dp[n][m][n][m]);
    return 0;
}
