#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n;
int va, vb, vc;
int a[MaxN];
int b[MaxN];
int c[MaxN];
long long dp[2][MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &va, &vb, &vc);
    n = va + vb + vc;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for (int i = 0; i <= va; i++)
    {
        for (int j = 0; j <= vb; j++)
        {
            for (int k = 0; k <= vc; k++)
            {
                dp[i & 1][j][k] = -0x3f3f3f3f;
                if (i == 0 && j == 0 && k == 0)
                {
                    dp[i & 1][j][k] = 0;
                    continue;
                }
                if (i >= 1)
                {
                    dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k] + a[i + j + k]);
                }
                if (j >= 1)
                {
                    dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[i & 1][j - 1][k] + b[i + j + k]);
                }
                if (k >= 1)
                {
                    dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[i & 1][j][k - 1] + c[i + j + k]);
                }
            }
        }
    }
    printf("%lld\n", dp[va & 1][vb][vc]);
    return 0;
}
