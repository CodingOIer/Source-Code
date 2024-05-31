#include <algorithm>
#include <cstdio>
constexpr int MaxN = 3e5 + 5;
int n, x;
long long p[MaxN];
long long dp[MaxN][3];
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = std::max(dp[i - 1][0] + p[i], 0ll);
        dp[i][1] = std::max(dp[i - 1][1] + x * p[i], dp[i][0]);
        dp[i][2] = std::max(dp[i - 1][2] + p[i], dp[i][1]);
        answer = std::max(answer, dp[i][2]);
    }
    printf("%lld\n", answer);
    return 0;
}