#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 3e3 + 5;
class node
{
  public:
    int to, w;
    node(int x, int y)
    {
        to = x;
        w = y;
    }
};
int n, m;
int h[MaxN];
int dis[MaxN];
bool vis[MaxN];
std::vector<node> link[MaxN];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
void Dijkstra(int r)
{
    dis[r] = 0;
    queue.push({0, r});
    for (; !queue.empty();)
    {
        int u = queue.top().second;
        queue.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto l : link[u])
        {
            if (dis[u] + l.w < dis[l.to])
            {
                dis[l.to] = dis[u] + l.w;
                queue.push({dis[l.to], l.to});
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        link[u].push_back(node(v, w));
    }
    for (int i = 1; i <= n; i++)
    {
        link[0].push_back(node(i, 0));
    }
    bool invalid = true;
    memset(h, 0x3f, sizeof(h));
    for (int i = 1; i <= n - 1; i++)
    {
        bool change = false;
        for (int j = 1; j <= n; j++)
        {
            for (auto l : link[j])
            {
                if (h[j] + l.w < h[l.to])
                {
                    change = true;
                    h[l.to] = h[j] + l.w;
                }
            }
        }
        if (!change)
        {
            invalid = false;
            break;
        }
    }
    if (invalid)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto &l : link[i])
        {
            l.w += h[i] - h[l.to];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, false, sizeof(vis));
        Dijkstra(i);
        long long answer = 0;
        for (int j = 1; j <= n; j++)
        {
            answer += j * (dis[j] == 0x3f3f3f3f ? 1e9 : dis[j] + h[j] - h[i]);
        }
        printf("%lld\n", answer);
    }
    return 0;
}