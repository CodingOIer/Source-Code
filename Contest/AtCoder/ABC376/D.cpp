#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m;
bool vis[MaxN];
std::vector<int> g[MaxN];
std::queue<std::tuple<int, int>> queue;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    queue.push({1, 0});
    for (; !queue.empty();)
    {
        auto [u, w] = queue.front();
        queue.pop();
        if (u == 1 && w != 0)
        {
            printf("%d\n", w);
            return 0;
        }
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto v : g[u])
        {
            if (!vis[v] || v == 1)
            {
                queue.push({v, w + 1});
            }
        }
    }
    printf("-1\n");
    return 0;
}