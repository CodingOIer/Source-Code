#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e3 + 5;
constexpr int MaxM = 1e2 + 5;
int n;
int dp[MaxN];
char s[MaxN][MaxM];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int best = 0;
        for (int j = 1; j <= i - 1; j++)
        {
            if (strstr(s[i] + 1, s[j] + 1) == s[i] + 1)
            {
                best = std::max(best, dp[j]);
            }
        }
        dp[i] = best + 1;
        answer = std::max(answer, dp[i]);
    }
    printf("%d\n", answer);
    return 0;
}