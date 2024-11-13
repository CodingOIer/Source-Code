#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

constexpr int MaxN = 1e5 + 5;
int n, m;
int dis[MaxN];
int pre[MaxN];
bool vis[MaxN];
std::vector<int> link[MaxN];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
void Dijkstra(int u)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[u] = 0;
    memset(vis, false, sizeof(vis));
    queue.push({0, u});
    for (; !queue.empty();)
    {
        auto [_, u] = queue.top();
        queue.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto v : link[u])
        {
            if (dis[u] + 1 < dis[v])
            {
                pre[v] = u;
                dis[v] = dis[u] + 1;
                queue.push({dis[v], v});
            }
        }
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
        link[v].push_back(u);
    }
    Dijkstra(1);
    for (int i = 2; i <= n; i++)
    {
        if (pre[i] == 0)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    for (int i = 2; i <= n; i++)
    {
        printf("%d\n", pre[i]);
    }
    return 0;
}