#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
const int MaxN = 3e3 + 5;
const int MaxM = 1e4 + 5;
int n, m;
bool vis[MaxN];
long long h[MaxN];
long long dis[MaxN];
std::priority_queue<std::pair<int, int>> queue;
std::vector<std::pair<int, int>> link[MaxN];
std::vector<std::pair<std::pair<int, int>, int>> links;
std::vector<std::pair<std::pair<int, int>, int>> temp_links;
void Dijkstra(int x)
{
    for (; !queue.empty();)
    {
        queue.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        dis[i] = 0x3f3f3f3f3f3f3f3f;
    }
    queue.push({0, x});
    for (; !queue.empty();)
    {
        auto tmp = queue.top();
        queue.pop();
        int id, len;
        id = tmp.second;
        len = tmp.first;
        len = -len;
        if (vis[id])
        {
            continue;
        }
        dis[id] = len;
        vis[id] = true;
        for (auto to : link[id])
        {
            if (vis[to.first])
            {
                continue;
            }
            queue.push({-len - to.second, to.first});
        }
    }
}
int main()
{
    memset(h, 0x3f, sizeof(h));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({{u, v}, w});
    }
    for (int i = 1; i <= n; i++)
    {
        links.push_back({{0, i}, 0});
    }
    bool error = true;
    h[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        bool change = false;
        for (auto road : links)
        {
            int u, v, w;
            u = road.first.first;
            v = road.first.second;
            w = road.second;
            if (h[v] > h[u] + w)
            {
                h[v] = h[u] + w;
                change = true;
            }
        }
        if (!change)
        {
            error = false;
            break;
        }
    }
    if (error)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        links.pop_back();
    }
    for (int i = 0; i <= m - 1; i++)
    {
        links[i].second = links[i].second + h[links[i].first.first] - h[links[i].first.second];
        link[links[i].first.first].push_back({links[i].first.second, links[i].second});
    }
    for (int i = 1; i <= n; i++)
    {
        Dijkstra(i);
        long long sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] != 0x3f3f3f3f3f3f3f3f)
            {
                dis[j] = dis[j] + h[j] - h[i];
            }
        }
        for (int j = 1; j <= n; j++)
        {
            sum += (dis[j] == 0x3f3f3f3f3f3f3f3f ? 1e9 * j : dis[j] * j);
        }
        printf("%lld\n", sum);
    }
    return 0;
}