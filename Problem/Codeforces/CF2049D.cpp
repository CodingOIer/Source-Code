#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e2 + 5;
int n, m;
long long k;
long long p[MaxN][MaxN];
long long prefix[MaxN][MaxN];
long long dp[MaxN][MaxN][MaxN];
void solve()
{
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &p[i][j]);
        }
    }
    long long answer = 0x3f3f3f3f'3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefix[i][j] = 0x3f3f3f3f'3f3f3f3f;
        }
        for (int c = 0; c <= m - 1; c++)
        {
            dp[i][c][0] = 0x3f3f3f3f'3f3f3f3f;
            for (int j = 1; j <= m; j++)
            {
                if (i == 1 && j == 1)
                {
                    dp[i][c][j] = p[i][(j + c - 1) % m + 1];
                    continue;
                }
                dp[i][c][j] = std::min(dp[i][c][j - 1] + p[i][(j + c - 1) % m + 1],
                                       i == 1 ? 0x3f3f3f3f'3f3f3f3f : prefix[i - 1][j] + p[i][(j + c - 1) % m + 1]);
            }
            for (int j = 1; j <= m; j++)
            {
                dp[i][c][j] += c * k;
                prefix[i][j] = std::min(prefix[i][j], dp[i][c][j]);
                if (i == n && j == m)
                {
                    answer = std::min(answer, dp[i][c][j]);
                }
            }
        }
    }
    printf("%lld\n", answer);
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
