#include <algorithm>
#include <cstdio>
constexpr int MaxN = 25;
int n;
int p[MaxN];
int k[MaxN];
int dp[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        p[x] = i;
    }
    int x;
    for (; scanf("%d", &x) == 1;)
    {
        k[x] = 1;
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &x);
            k[x] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = std::max({dp[i - 1][j], dp[i][j - 1], p[i] == k[j] ? dp[i - 1][j - 1] + 1 : -0x3f3f3f3f});
            }
        }
        printf("%d\n", dp[n][n]);
    }
    return 0;
}