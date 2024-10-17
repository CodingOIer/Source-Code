#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e2 + 5;
int n;
int fa[MaxN];
int pre[MaxN];
int depth[MaxN];
int jump[20][MaxN];
int ref[MaxN][MaxN];
bool vis[MaxN];
bool map[MaxN][MaxN];
long long dis[MaxN];
std::vector<int> tree[MaxN];
std::vector<std::tuple<int, int>> g[MaxN];
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
    jump[0][u] = f;
    for (int i = 1; i < 12; i++)
    {
        jump[i][u] = jump[i - 1][jump[i - 1][u]];
    }
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
    if (depth[x] <= depth[y])
    {
        std::swap(x, y);
    }
    for (int i = 11; i >= 0; i--)
    {
        if (depth[jump[i][x]] >= depth[y])
        {
            x = jump[i][x];
        }
    }
    for (int i = 11; i >= 0; i--)
    {
        if (jump[i][x] != jump[i][y])
        {
            x = jump[i][x];
            y = jump[i][y];
        }
    }
    if (x != y)
    {
        x = jump[0][x];
        y = jump[0][y];
    }
    return x;
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
            ref[u][v] = w;
            ref[v][u] = w;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(jump, false, sizeof(jump));
        for (int i = 1; i <= n; i++)
        {
            tree[i].clear();
        }
        Dijkstra(i);
        memset(map, false, sizeof(map));
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            map[pre[j]][j] = true;
            map[j][pre[j]] = true;
            tree[pre[j]].push_back(j);
            tree[j].push_back(pre[j]);
        }
        dfs(i, 0);
        long long answer = 0x3f3f3f3f3f3f3f3f;
        for (int j = 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (j == k || map[j][k] || ref[j][k] == 0 || LCA(j, k) != i)
                {
                    continue;
                }
                answer = std::min(answer, 1ll * dis[j] + dis[k] + ref[j][k]);
            }
        }
        printf("%lld ", answer == 0x3f3f3f3f3f3f3f3f ? -1 : answer);
    }
    printf("\n");
    return 0;
}