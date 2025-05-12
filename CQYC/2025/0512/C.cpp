#include <cstdio>
#include <cstring>
#include <deque>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n, m;
int l[MaxN];
int r[MaxN];
int dis[MaxN];
bool vis[MaxN];
std::deque<int> queue;
std::vector<std::tuple<int, int>> g[MaxN];
void addEdge(int u, int v, int w)
{
    g[u].push_back({v, w});
}
void push(int u)
{
    if (queue.empty() || dis[u] > dis[queue.front()])
    {
        queue.push_back(u);
    }
    else
    {
        queue.push_front(u);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        addEdge(i - 1, i, 1);
        addEdge(i, i - 1, 0);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        addEdge(l - 1, r, (r - l + 1) / 2);
        addEdge(r, l - 1, -(r - l + 1) / 2);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    queue.push_back(0);
    for (; !queue.empty();)
    {
        const auto u = queue.front();
        queue.pop_front();
        vis[u] = false;
        for (const auto &[v, w] : g[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    push(v);
                    vis[v] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%c", dis[i] - dis[i - 1] == 1 ? '1' : '0');
    }
    return 0;
}