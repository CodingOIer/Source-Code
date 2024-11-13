#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2e5 + 5;
int n;
int ans;
int p[MaxN];
int dp[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(p[i], dp[i - 1] + p[i]);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}