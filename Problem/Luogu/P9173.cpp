#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e3 + 5;
int n, m;
int a[MaxN];
int b[MaxN];
int dp[MaxN][MaxN];
inline int next_one(int x)
{
    return x % 2 == 1 ? x + 2 : x + 1;
}
inline int next_two(int x)
{
    return x % 2 == 0 ? x + 2 : x + 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            dp[i][j] = std::min(i > 0 ? a[i] == 1 ? next_one(dp[i - 1][j]) : next_two(dp[i - 1][j]) : 0x3f3f3f3f,
                                j > 0 ? b[j] == 1 ? next_one(dp[i][j - 1]) : next_two(dp[i][j - 1]) : 0x3f3f3f3f);
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}