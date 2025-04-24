#include <algorithm>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n;
int atLeast;
int dis[MaxN][MaxN];
std::vector<int> g[MaxN];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int u = 1; u <= n; u++)
    {
        for (const auto &v : g[u])
        {
            dis[u][v] = 1;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
std::tuple<int, int> find()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] >= 3 && dis[i][j] % 2 == 1)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
void addEdge(int u, int v)
{
    dis[u][v] = 1;
    dis[v][u] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = std::min(dis[i][j], dis[i][v] + 1 + dis[u][j]);
            dis[i][j] = std::min(dis[i][j], dis[i][u] + 1 + dis[v][j]);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    atLeast = 1;
    int cnt = 0;
    init();
    for (;;)
    {
        auto res = find();
        if (res == std::tuple<int, int>{-1, -1})
        {
            break;
        }
        cnt++;
        addEdge(std::get<0>(res), std::get<1>(res));
    }
    init();
    if (cnt % 2 == 1)
    {
        printf("First\n");
        fflush(stdout);
    }
    if (cnt % 2 == 0)
    {
        printf("Second\n");
        fflush(stdout);
        int u, v;
        scanf("%d%d", &u, &v);
        if (u == -1 && v == -1)
        {
            return 0;
        }
        addEdge(u, v);
    }
    for (;;)
    {
        auto res = find();
        printf("%d %d\n", std::get<0>(res), std::get<1>(res));
        addEdge(std::get<0>(res), std::get<1>(res));
        fflush(stdout);
        int u, v;
        scanf("%d%d", &u, &v);
        if (u == -1 && v == -1)
        {
            return 0;
        }
        addEdge(u, v);
    }
    return 0;
}