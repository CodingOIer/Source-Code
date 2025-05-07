// 100 =

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e3 + 5;
constexpr long long inf = 0x3f3f3f3f;
int n, k;
int c[MaxN][MaxN];
int dp[MaxN][MaxN];
int first[MaxN][15];
bool vis[10];
std::vector<int> v[MaxN];
void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        v[i].clear();
        char ch = getchar();
        for (; !std::isdigit(ch);)
        {
            ch = getchar();
        }
        for (; isdigit(ch);)
        {
            v[i].push_back(ch ^ 48);
            ch = getchar();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            vis[j] = false;
        }
        int ck = 0;
        for (int j = i; j <= n; j++)
        {
            for (const auto &val : v[j])
            {
                ck += !vis[val] ? 1 : 0;
                vis[val] = true;
            }
            c[i][j] = ck;
        }
    }
    memset(first, 0, sizeof(first));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            first[i][c[j][i]] = first[i][c[j][i]] == 0 ? j : first[i][c[j][i]];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        dp[0][i] = -inf;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= std::min(i, k); j++)
        {
            dp[i][j] = -inf;
            for (int w = 1; w <= 10; w++)
            {
                if (first[i][w] == 0)
                {
                    continue;
                }
                dp[i][j] = std::max(dp[i][j], dp[first[i][w] - 1][j - 1] + c[first[i][w]][i]);
            }
        }
    }
    printf("%d\n", dp[n][k]);
}
int main()
{
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
