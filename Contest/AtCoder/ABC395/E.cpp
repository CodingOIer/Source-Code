#include <cstdio>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, m, k;
bool vis[2][MaxN];
std::vector<int> g[2][MaxN];
std::priority_queue<std::tuple<long long, int, bool>, std::vector<std::tuple<long long, int, bool>>, std::greater<>>
    queue;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[0][u].push_back(v);
        g[1][v].push_back(u);
    }
    queue.push({0, 1, false});
    for (; !queue.empty();)
    {
        auto [cost, u, type] = queue.top();
        queue.pop();
        if (u == n)
        {
            printf("%lld\n", cost);
            break;
        }
        if (vis[type][u])
        {
            continue;
        }
        vis[type][u] = true;
        for (const auto &v : g[type][u])
        {
            queue.push({cost + 1, v, type});
        }
        queue.push({cost + k, u, type ^ true});
    }
    return 0;
}
