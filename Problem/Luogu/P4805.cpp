#include <algorithm>
#include <cstdio>
constexpr int MaxN = 4e2 + 5;
int n;
long long p[MaxN];
long long dp[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    long long answer = 0;
    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l <= n - len + 1; l++)
        {
            int r = l + len - 1;
            if (l == r)
            {
                dp[l][r] = p[l];
                answer = std::max(answer, dp[l][r]);
                continue;
            }
            int curR = r + 1;
            long long prefixSum, suffixSum;
            prefixSum = 0;
            suffixSum = 0;
            dp[l][r] = -0x3f3f3f3f'3f3f3f3f;
            for (int curL = l; curL <= r; curL++)
            {
                prefixSum += p[curL];
                for (; suffixSum < prefixSum;)
                {
                    curR--;
                    suffixSum += p[curR];
                }
                if (curL >= curR)
                {
                    break;
                }
                if (prefixSum == suffixSum && dp[l][curL] == prefixSum && dp[curR][r] == suffixSum)
                {
                    dp[l][r] = std::max(dp[l][r], prefixSum + dp[curL + 1][curR - 1] + suffixSum);
                }
            }
            answer = std::max(answer, dp[l][r]);
        }
    }
    printf("%lld\n", answer);
    return 0;
}
