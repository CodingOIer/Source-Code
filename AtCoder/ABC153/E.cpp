#include <algorithm>
#include <cstdio>
#include <cstring>
const int MaxN = 1e3 + 5;
const int MaxH = 1e4 + 5;
const int MaxVal = 1e5 + 4;
int h, n;
int max_v;
int answer;
int v[MaxN];
int val[MaxN];
int dp[MaxH + MaxVal];
int main()
{
    scanf("%d%d", &h, &n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &val[i], &v[i]);
        max_v = std::max(max_v, v[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = val[i]; j <= h + val[i] - 1; j++)
        {
            dp[j] = std::min(dp[j], dp[j - val[i]] + v[i]);
        }
    }
    answer = 0x3f3f3f3f;
    for (int i = h; i <= h + max_v - 1; i++)
    {
        answer = std::min(dp[i], answer);
    }
    printf("%d\n", answer);
    return 0;
}