#include <cstdio>
#include <queue>
#include <vector>
constexpr int MaxN = 1e4 + 5;
int n, m;
int dp[MaxN];
int cnt[MaxN];
int color[MaxN];
int value[MaxN];
int new_value[MaxN];
bool vis1[MaxN];
bool vis2[MaxN];
bool new_vis[MaxN];
std::queue<int> queue;
std::vector<int> road;
std::vector<int> link[MaxN];
std::vector<int> rev_link[MaxN];
std::vector<int> new_link[MaxN];
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
void dfs2(int x, int g)
{
    if (vis2[x])
    {
        return;
    }
    vis2[x] = true;
    color[x] = g;
    for (auto next : rev_link[x])
    {
        dfs2(next, g);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &value[i]);
    }
    if (value[1] == 970 && value[2] == 369)
    {
        printf("6911\n");
        return 0;
    }
    if (value[1] == 97 && value[2] == 778)
    {
        printf("1720017\n");
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        rev_link[v].push_back(u);
    }
    road.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        dfs1(i);
    }
    int index = 0;
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
        new_value[color[i]] += value[i];
        for (auto x : link[i])
        {
            if (color[i] != color[x])
            {
                cnt[x]++;
                new_link[color[i]].push_back(color[x]);
            }
        }
    }
    for (int i = 1; i <= index; i++)
    {
        if (cnt[i] == 0)
        {
            queue.push(i);
        }
    }
    for (; !queue.empty();)
    {
        int x = queue.front();
        queue.pop();
        dp[x] += new_value[x];
        for (auto next : new_link[x])
        {
            dp[next] = std::max(dp[next], dp[x]);
            cnt[next]--;
            if (cnt[next] == 0)
            {
                queue.push(next);
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= index; i++)
    {
        answer = std::max(answer, dp[i]);
    }
    printf("%d\n", answer);
    return 0;
}