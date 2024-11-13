#include <cstdio>
#include <queue>
#include <vector>
constexpr int MaxN = 1.5e3 + 5;
int n, m;
int in[MaxN];
int dp[MaxN];
std::queue<int> queue;
std::vector<int> len[MaxN];
std::vector<int> link[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        len[u].push_back(w);
        link[u].push_back(v);
        in[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -0x3f3f3f3f;
        if (in[i] == 0)
        {
            dp[i] = 0;
            queue.push(i);
        }
    }
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        for (int j = 0; j < int(link[u].size()); j++)
        {
            in[link[u][j]]--;
            dp[link[u][j]] = std::max(dp[link[u][j]], dp[u] + len[u][j]);
            if (in[link[u][j]] == 0)
            {
                queue.push(link[u][j]);
            }
        }
    }
    printf("%d\n", dp[n] - dp[1]);
    return 0;
}