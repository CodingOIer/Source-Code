#include <cstdio>
#include <map>
#include <queue>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, m;
int dp[2][MaxN];
int color[MaxN];
int value[MaxN];
int new_cnt[MaxN];
int new_rev_cnt[MaxN];
bool vis[2][MaxN];
bool vis1[MaxN];
bool vis2[MaxN];
std::queue<int> queue;
std::vector<int> road;
std::vector<int> link[MaxN];
std::vector<int> rev_link[MaxN];
std::vector<int> new_link[MaxN];
std::vector<int> new_rev_link[MaxN];
std::map<std::pair<int, int>, bool> map;
void dfs1(int x)
{
    if (vis1[x])
    {
        return;
    }
    vis1[x] = true;
    for (auto next : link[x])
    {
        dfs1(next);
    }
    road.push_back(x);
}
void dfs2(int x, int c)
{
    if (vis2[x])
    {
        return;
    }
    vis2[x] = true;
    color[x] = c;
    for (auto next : rev_link[x])
    {
        dfs2(next, c);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        rev_link[v].push_back(u);
    }
    road.push_back(0);
    int index = 0;
    for (int i = 1; i <= n; i++)
    {
        dfs1(i);
    }
    for (int i = n; i >= 1; i--)
    {
        if (!vis2[road[i]])
        {
            index++;
            dfs2(road[i], index);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        value[color[i]]++;
        for (auto next : link[i])
        {
            int u, v;
            u = color[i];
            v = color[next];
            if (map[{u, v}] || u == v)
            {
                continue;
            }
            map[{u, v}] = true;
            new_link[u].push_back(v);
            new_cnt[v]++;
            new_rev_link[v].push_back(u);
            new_rev_cnt[u]++;
        }
    }
    int s = color[1];
    vis[0][s] = true;
    vis[1][s] = true;
    for (int i = 1; i <= index; i++)
    {
        if (new_cnt[i] == 0)
        {
            queue.push(i);
        }
    }
    for (; !queue.empty();)
    {
        int x = queue.front();
        queue.pop();
        dp[0][x] += value[x];
        for (auto next : new_link[x])
        {
            new_cnt[next]--;
            if (vis[0][x])
            {
                vis[0][next] = true;
                dp[0][next] = std::max(dp[0][next], dp[0][x]);
            }
            if (new_cnt[next] == 0)
            {
                queue.push(next);
            }
        }
    }
    for (int i = 1; i <= index; i++)
    {
        if (new_rev_cnt[i] == 0)
        {
            queue.push(i);
        }
    }
    for (; !queue.empty();)
    {
        int x = queue.front();
        queue.pop();
        dp[1][x] += value[x];
        for (auto next : new_rev_link[x])
        {
            new_rev_cnt[next]--;
            if (vis[1][x] == true)
            {
                vis[1][next] = true;
                dp[1][next] = std::max(dp[1][next], dp[1][x]);
            }
            if (new_rev_cnt[next] == 0)
            {
                queue.push(next);
            }
        }
    }
    int answer = value[s];
    for (int i = 1; i <= index; i++)
    {
        for (auto x : new_rev_link[i])
        {
            if (vis[0][i] && vis[1][x])
            {
                answer = std::max(answer, dp[0][i] + dp[1][x] - value[s]);
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}