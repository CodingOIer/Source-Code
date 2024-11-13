#include <cstdio>
constexpr int MaxN = 4e3 + 5;
int n;
long long mod;
long long answer;
long long dp[MaxN][MaxN];
int main()
{
    scanf("%d%lld", &n, &mod);
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i / 2 + (i % 2 == 1 ? 1 : 0); j++)
        {
            dp[i][j] = dp[i - 2][j - 1] * j + dp[i - 1][j] * j * 2;
            dp[i][j] %= mod;
        }
    }
    for (int i = 1; i <= n / 2 + (n % 2 == 1 ? 1 : 0); i++)
    {
        answer += dp[n][i];
        answer %= mod;
    }
    printf("%lld\n", answer);
    return 0;
}