#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e1 + 5;
int n;
int p[MaxN][MaxN];
int dp[MaxN][MaxN][MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (;;)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 0 && y == 0 && z == 0)
        {
            break;
        }
        p[x][y] = z;
    }
    dp[1][1][1][1] = p[1][1];
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= n; y1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                int y2 = (x1 + y1) - x2;
                if (!(1 <= y2 && y2 <= n))
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
                dp[x1][y1][x2][y2] = pre + (x1 == x2 && y1 == y2 ? p[x1][y1] : p[x1][y1] + p[x2][y2]);
            }
        }
    }
    printf("%d\n", dp[n][n][n][n]);
    return 0;
}
