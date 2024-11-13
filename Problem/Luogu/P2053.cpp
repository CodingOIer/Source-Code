#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 2e3 + 5;
int n, m;
int s, t;
int idx;
int p[MaxN][MaxN];
int dis[MaxN];
int car[MaxN];
int rev[MaxN][MaxN];
int last[MaxN];
int answer;
int answer_cost;
bool vis[MaxN];
std::queue<int> queue;
std::vector<int> max[MaxN];
std::vector<int> use[MaxN];
std::vector<int> cost[MaxN];
std::vector<int> link[MaxN];
inline void addOnce(int x, int y, int w, int u, int c)
{
    link[x].push_back(y);
    max[x].push_back(w);
    use[x].push_back(u);
    cost[x].push_back(c);
    rev[y][x] = link[x].size() - 1;
}
inline void addEdge(int x, int y, int w, int c)
{
    addOnce(x, y, w, 0, c);
    addOnce(y, x, w, w, -c);
}
inline int newPoint()
{
    idx++;
    return idx;
}
inline void calc()
{
    queue.push(s);
    dis[s] = 0;
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
            if (push > 0)
            {
                use[u][i] += push;
                use[v][rev[u][v]] -= push;
                answer_cost += cost[u][i] * push;
                return push;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    s = newPoint();
    t = newPoint();
    for (int i = 1; i <= n; i++)
    {
        car[i] = newPoint();
        addEdge(s, car[i], 1, 0);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                int now = newPoint();
                addEdge(car[i], now, 1, p[j][i] * i);
                addEdge(now, t, 1, 0);
            }
        }
    }
    for (;;)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, false, sizeof(vis));
        calc();
        if (dis[t] == 0x3f3f3f3f)
        {
            break;
        }
        memset(vis, false, sizeof(vis));
        answer += dfs(s, 1e8);
    }
    printf("%lf\n", double(answer_cost) / n);
    return 0;
}