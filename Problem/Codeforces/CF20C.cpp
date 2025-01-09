#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, m;
int pre[MaxN];
bool vis[MaxN];
long long dis[MaxN];
std::vector<std::tuple<long long, int>> g[MaxN];
std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>, std::greater<>> queue;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    queue.push({0, 1});
    dis[1] = 0;
    for (; !queue.empty();)
    {
        int u = std::get<1>(queue.top());
        queue.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (const auto &[v, w] : g[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pre[v] = u;
                queue.push({dis[v], v});
            }
        }
    }
    if (dis[n] == 0x3f3f3f3f'3f3f3f3f)
    {
        printf("-1\n");
    }
    else
    {
        int u = n;
        std::vector<int> temp;
        for (; u != 0;)
        {
            temp.push_back(u);
            u = pre[u];
        }
        std::reverse(temp.begin(), temp.end());
        for (const auto &val : temp)
        {
            printf("%d ", val);
        }
        printf("\n");
    }
    return 0;
}
