#include <bits/stdc++.h>
using namespace std;
const int MaxN = 3e4 + 5;
const int MaxM = 3e1 + 5;
int n;
int money;
int v[MaxM];
int val[MaxM];
int dp[MaxM][MaxN];
int main()
{
    scanf("%d%d", &money, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &val[i]);
        val[i] *= v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= money; j++)
        {
            if (v[i] <= j)
            {

                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + val[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[n][money]);
    return 0;
}