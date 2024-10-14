#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e2 + 5;
constexpr int MaxM = 1e5 + 5;
int n, m, q;
bool disabled[MaxM];
long long dis[MaxN][MaxN];
std::vector<long long> answer;
std::vector<std::tuple<int, int, int>> ask;
std::vector<std::tuple<int, int, int>> links;
inline void update(int k)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({u, v, w});
    }
    for (int i = 1; i <= q; i++)
    {
        int op, x, y;
        op = x = y = 0;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            disabled[x] = true;
        }
        else
        {
            scanf("%d%d", &x, &y);
        }
        ask.push_back({op, x, y});
    }
    std::reverse(ask.begin(), ask.end());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = 0x3f3f3f3f3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (!disabled[i])
        {
            auto [u, v, w] = links[i - 1];
            dis[u][v] = w;
            dis[v][u] = w;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        update(i);
    }
    for (auto [op, x, y] : ask)
    {
        if (op == 1)
        {
            auto [u, v, w] = links[x - 1];
            dis[u][v] = std::min(dis[u][v], 1ll * w);
            dis[v][u] = std::min(dis[v][u], 1ll * w);
            update(u);
            update(v);
        }
        else
        {
            answer.push_back(dis[x][y] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[x][y]);
        }
    }
    std::reverse(answer.begin(), answer.end());
    for (auto v : answer)
    {
        printf("%lld\n", v);
    }
    return 0;
}