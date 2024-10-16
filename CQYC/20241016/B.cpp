#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e2 + 5;
int n;
int fa[MaxN];
int pre[MaxN];
int depth[MaxN];
bool vis[MaxN];
long long dis[MaxN];
std::vector<int> tree[MaxN];
std::vector<std::tuple<int, int>> g[MaxN];
std::map<std::tuple<int, int>, int> ref;
std::map<std::tuple<int, int>, bool> map;
std::priority_queue<std::tuple<long long, int>, std::vector<std::tuple<long long, int>>, std::greater<>> queue;
inline void Dijkstra(int u)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    queue.push({0, u});
    dis[u] = 0;
    for (; !queue.empty();)
    {
        auto [l, u] = queue.top();
        queue.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto [v, w] : g[u])
        {
            if (dis[v] > dis[u] + w)
            {
                pre[v] = u;
                dis[v] = dis[u] + w;
                queue.push({dis[v], v});
            }
        }
    }
}
inline void dfs(int u, int f)
{
    fa[u] = f;
    depth[u] = depth[f] + 1;
    for (auto v : tree[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
    }
}
inline int LCA(int x, int y)
{
    for (;;)
    {
        if (x == y)
        {
            return x;
        }
        if (depth[x] >= depth[y])
        {
            x = fa[x];
        }
        else
        {
            y = fa[y];
        }
    }
}
int main()
{
    scanf("%*d%d", &n);
    for (int u = 1; u <= n; u++)
    {
        for (int v = u + 1; v <= n; v++)
        {
            int w;
            scanf("%d", &w);
            if (w == -1)
            {
                continue;
            }
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            ref[{u, v}] = w;
            ref[{v, u}] = w;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            tree[i].clear();
        }
        Dijkstra(i);
        map.clear();
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            map[{pre[j], j}] = true;
            map[{j, pre[j]}] = true;
            tree[pre[j]].push_back(j);
            tree[j].push_back(pre[j]);
        }
        dfs(i, 0);
        long long answer = 0x3f3f3f3f3f3f3f3f;
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k || map[{j, k}] || ref[{j, k}] == 0 || LCA(j, k) != i)
                {
                    continue;
                }
                answer = std::min(answer, 1ll * dis[j] + dis[k] + ref[{j, k}]);
            }
        }
        printf("%lld ", answer == 0x3f3f3f3f3f3f3f3f ? -1 : answer);
    }
    printf("\n");
    return 0;
}