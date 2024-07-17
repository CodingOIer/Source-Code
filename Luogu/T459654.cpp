#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
constexpr int MaxN = 1e3 + 5;
int n, m;
int u[MaxN];
int v[MaxN];
int c[MaxN];
int f[MaxN];
int len[MaxN];
bool vis[MaxN];
std::vector<int> link[MaxN];
std::vector<int> cost[MaxN];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
void Dijkstra(int minCost)
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        len[i] = 0x7f7f7f7f;
        link[i].clear();
        cost[i].clear();
    }
    for (; !queue.empty();)
    {
        queue.pop();
    }
    for (int i = 1; i <= m; i++)
    {
        if (f[i] >= minCost)
        {
            link[u[i]].push_back(v[i]);
            link[v[i]].push_back(u[i]);
            cost[u[i]].push_back(c[i]);
            cost[v[i]].push_back(c[i]);
        }
    }
    len[1] = 0;
    queue.push({0, 1});
    for (; !queue.empty();)
    {
        auto k = queue.top();
        queue.pop();
        int u, l;
        u = k.second;
        l = k.first;
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int j = 0; j < link[u].size(); j++)
        {
            int v, c;
            v = link[u][j];
            c = cost[u][j];
            if (l + c < len[v])
            {
                len[v] = l + c;
                queue.push({len[v], v});
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d", &u[i], &v[i], &c[i], &f[i]);
    }
    int answer = -0x7f7f7f7f;
    for (int i = 1; i <= m; i++)
    {
        Dijkstra(f[i]);
        if (len[n] != 0x7f7f7f7f)
        {
            double k = double(f[i]) / double(len[n]);
            answer = std::max(answer, int(k * 1e6));
        }
    }
    printf("%d\n", answer);
    return 0;
}