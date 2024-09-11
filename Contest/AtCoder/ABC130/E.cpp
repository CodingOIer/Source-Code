#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MaxN = 2e3 + 5;
const int MaxM = 1e3 + 5;
int n, m;
int s[MaxN], t[MaxN];
int dp[MaxM][MaxM];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i] == t[j])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            dp[i][j] %= mod;
        }
    }
    printf("%d\n", dp[n][m] % mod);
    return 0;
}
