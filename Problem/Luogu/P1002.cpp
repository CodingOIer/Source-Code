#include <cstdio>
#include <cstdlib>
#include <vector>
constexpr int PXY = 50;
constexpr int MaxN = 1e2 + 5;
int n, m;
int cannotX, cannotY;
bool cannotVis[MaxN][MaxN];
long long dp[MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d", &cannotX, &cannotY);
    for (const auto &px : std::vector<int>{-2, -1, 1, 2})
    {
        for (const auto &py : std::vector<int>{-2, -1, 1, 2})
        {
            if (abs(px) + abs(py) == 3)
            {
                cannotVis[cannotX + px + PXY][cannotY + py + PXY] = true;
            }
        }
    }
    cannotVis[cannotX + PXY][cannotY + PXY] = true;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (cannotVis[i + PXY][j + PXY])
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                continue;
            }
            dp[i][j] = (i == 0 ? 0 : dp[i - 1][j]) + (j == 0 ? 0 : dp[i][j - 1]);
        }
    }
    printf("%lld\n", dp[n][m]);
    return 0;
}
