#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 5e3 + 5;
int n, m, s, t;
int answer;
int answer_cost;
int dis[MaxN];
int rev[MaxN][MaxN];
int last[MaxN];
bool vis[MaxN];
std::vector<int> use[MaxN];
std::vector<int> max[MaxN];
std::vector<int> cost[MaxN];
std::vector<int> link[MaxN];
std::queue<int> queue;
void Dijkstra()
{
    dis[s] = 0;
    queue.push(s);
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        vis[u] = false;
        for (int i = 0; i < link[u].size(); i++)
        {
            int v = link[u][i];
            if (dis[u] + cost[u][i] < dis[v] && max[u][i] - use[u][i] > 0)
            {
                dis[v] = dis[u] + cost[u][i];
                if (!vis[v])
                {
                    queue.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}
int dfs(int u, int f)
{
    if (u == t || f == 0)
    {
        return f;
    }
    vis[u] = true;
    for (int i = last[u]; i < link[u].size(); i++)
    {
        last[u] = i;
        int v = link[u][i];
        if (!vis[v] && dis[u] + cost[u][i] == dis[v] && max[u][i] - use[u][i] > 0)
        {
            int push = std::min(f, max[u][i] - use[u][i]);
            push = dfs(v, push);
            if (push != 0)
            {
                answer_cost += push * cost[u][i];
                use[u][i] += push;
                use[v][rev[u][v]] -= push;
                return push;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w, c;
        scanf("%d%d%d%d", &u, &v, &w, &c);
        use[u].push_back(0);
        max[u].push_back(w);
        cost[u].push_back(c);
        link[u].push_back(v);
        use[v].push_back(w);
        max[v].push_back(w);
        cost[v].push_back(-c);
        link[v].push_back(u);
        rev[u][v] = link[v].size() - 1;
        rev[v][u] = link[u].size() - 1;
    }
    for (;;)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, false, sizeof(vis));
        Dijkstra();
        if (dis[t] == 0x3f3f3f3f)
        {
            break;
        }
        memset(vis, false, sizeof(vis));
        memset(last, 0, sizeof(last));
        answer += dfs(s, 1e9);
    }
    printf("%d %d\n", answer, answer_cost);
    return 0;
}