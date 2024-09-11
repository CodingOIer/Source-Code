#include <algorithm>
#include <cstdio>
constexpr int MaxN = 55;
int h, w, k;
int sx, sy;
long long p[MaxN][MaxN];
long long dp[MaxN * MaxN][MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &h, &w, &k);
    scanf("%d%d", &sx, &sy);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            scanf("%lld", &p[i][j]);
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[0][i][j] = -0x7f7f7f7f7f7f7f7f;
        }
    }
    dp[0][sx][sy] = 0;
    long long answer = k * p[sx][sy];
    for (int d = 1; d <= k && d <= h * w; d++)
    {
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                dp[d][i][j] = dp[d - 1][i][j];
                if (1 < i)
                {
                    dp[d][i][j] = std::max(dp[d][i][j], dp[d - 1][i - 1][j]);
                }
                if (1 < j)
                {
                    dp[d][i][j] = std::max(dp[d][i][j], dp[d - 1][i][j - 1]);
                }
                if (i < h)
                {
                    dp[d][i][j] = std::max(dp[d][i][j], dp[d - 1][i + 1][j]);
                }
                if (j < w)
                {
                    dp[d][i][j] = std::max(dp[d][i][j], dp[d - 1][i][j + 1]);
                }
                dp[d][i][j] += p[i][j];
                answer = std::max(answer, dp[d][i][j] + (k - d) * p[i][j]);
            }
        }
    }
    printf("%lld\n", answer);
    return 0;
}