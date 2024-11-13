#include <cstdio>
constexpr int MaxN = 5e3 + 5;
constexpr int Mod = 10000;
int n, k;
int dp[MaxN][MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= k; j++)
        {
            sum += dp[i - 1][j];
            sum %= Mod;
            dp[i][j] = sum;
            if (j - i + 1 >= 0)
            {
                sum -= dp[i - 1][j - i + 1];
                sum += Mod;
                sum %= Mod;
            }
        }
    }
    printf("%d\n", dp[n][k]);
    return 0;
}