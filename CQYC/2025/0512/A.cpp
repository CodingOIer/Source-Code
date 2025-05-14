#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e4 + 5;
constexpr int MaxK = 1e1 + 5;
constexpr int MaxKP = (1 << 9) + 5;
int n, m, k;
int e, maxTime;
long long best[2][MaxKP];
long long dp[2][MaxN][MaxKP];
std::vector<int> event[MaxN][MaxK];
std::vector<std::tuple<int, int>> g[MaxN];
std::priority_queue<std::tuple<long long, int>, std::vector<std::tuple<long long, int>>, std::greater<>> queue;
std::vector<std::tuple<int, int>> waitForKill(int u, int begin)
{
    std::vector<std::tuple<int, int>> res;
    for (int i = 0; i < k; i++)
    {
        auto it = std::lower_bound(event[u][i].begin(), event[u][i].end(), begin);
        if (it != event[u][i].end())
        {
            res.push_back({*it, i});
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}
void solve(int u, int start)
{
    memset(dp[u], 0x3f, sizeof(dp[u]));
    memset(best[u], 0x3f, sizeof(best[u]));
    dp[u][start][0] = 0;
    for (int j = 0; j < 1 << k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            queue.push({dp[u][i][j], i});
        }
        for (; !queue.empty();)
        {
            const auto [cost, c] = queue.top();
            queue.pop();
            for (const auto &et : g[c])
            {
                const auto &[v, w] = et;
                if (dp[u][v][j] > cost + w)
                {
                    dp[u][v][j] = cost + w;
                    queue.push({dp[u][v][j], v});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            auto can = waitForKill(i, dp[u][i][j]);
            int status = j;
            for (const auto &[time, who] : can)
            {
                status |= 1 << who;
                dp[u][i][status] = std::min(dp[u][i][status], (long long)(time));
            }
        }
        for (int i = 1; i <= n; i++)
        {
            best[u][j] = std::min(best[u][j], dp[u][i][j]);
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    scanf("%d%d", &e, &maxTime);
    for (int i = 1; i <= e; i++)
    {
        int c, x, t;
        scanf("%d%d%d", &c, &x, &t);
        event[x][c - 1].push_back(t);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            std::sort(event[i][j].begin(), event[i][j].end());
        }
    }
    int x, y;
    scanf("%d%d", &x, &y);
    solve(0, x);
    solve(1, y);
    long long answer = 0x3f3f3f3f'3f3f3f3f;
    for (int i = 0; i < 1 << k; i++)
    {
        for (int j = 0; j < 1 << k; j++)
        {
            if ((i | j) == (1 << k) - 1)
            {
                answer = std::min(answer, std::max(best[0][i], best[1][j]));
            }
        }
    }
    if (answer > maxTime)
    {
        printf("-1\n");
    }
    else
    {
        printf("%lld\n", answer);
    }
    return 0;
}
