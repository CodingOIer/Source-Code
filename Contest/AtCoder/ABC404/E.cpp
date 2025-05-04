#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e3 + 5;
int n;
int answer;
int a[MaxN];
int vis[MaxN];
int dp[MaxN];
int calc(std::vector<int> v)
{
    int c = v.size();
    for (int i = 0; i <= c; i++)
    {
        dp[i] = 0x3f3f3f3f;
    }
    dp[c] = 0;
    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j >= std::max(0, i - v[i - 1]); j--)
        {
            dp[j] = std::min(dp[j], dp[i] + 1);
        }
    }
    return dp[0];
}
int main()
{
    scanf("%d", &n);
    n--;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &vis[i]);
    }
    std::vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(a[i]);
        if (vis[i] == 1)
        {
            answer += calc(v);
            v.clear();
        }
    }
    printf("%d\n", answer);
    return 0;
}