#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 7e2 + 5;
constexpr int MaxM = 5e5 + 5;
int n, m, k;
int p[MaxN][MaxN];
long long dis[MaxN][MaxN];
std::queue<std::tuple<long long, int, int>> queue;
std::vector<std::tuple<int, int>> w[MaxM];
std::vector<std::tuple<long long, int, int>> v[MaxM];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
            w[p[i][j]].push_back({i, j});
        }
    }
    v[0].push_back({0, 1, 1});
    for (int i = 1; i <= k; i++)
    {
        if (1ll * int(v[i - 1].size()) * int(w[i].size()) <= 1ll * n * m)
        {
            for (auto [x, y] : w[i])
            {
                long long best = 0x7f7f7f7f7f7f7f7f;
                for (auto [cost, px, py] : v[i - 1])
                {
                    best = std::min(best, cost + abs(x - px) + abs(y - py));
                }
                v[i].push_back({best, x, y});
            }
        }
        else
        {
            for (auto [cost, px, py] : v[i - 1])
            {
                queue.push({cost, px, py});
                dis[px][py] = cost;
            }
            memset(dis, 0x3f, sizeof(dis));
            for (; !queue.empty();)
            {
                auto [cost, x, y] = queue.front();
                queue.pop();
                if (cost > dis[x][y])
                {
                    continue;
                }
                if (1 < x && dis[x - 1][y] > cost + 1)
                {
                    dis[x - 1][y] = cost + 1;
                    queue.push({cost + 1, x - 1, y});
                }
                if (x < n && dis[x + 1][y] > cost + 1)
                {
                    dis[x + 1][y] = cost + 1;
                    queue.push({cost + 1, x + 1, y});
                }
                if (1 < y && dis[x][y - 1] > cost + 1)
                {
                    dis[x][y - 1] = cost + 1;
                    queue.push({cost + 1, x, y - 1});
                }
                if (y < m && dis[x][y + 1] > cost + 1)
                {
                    dis[x][y + 1] = cost + 1;
                    queue.push({cost + 1, x, y + 1});
                }
            }
            for (auto [x, y] : w[i])
            {
                v[i].push_back({dis[x][y], x, y});
            }
        }
    }
    std::sort(v[k].begin(), v[k].end());
    printf("%lld\n", std::get<0>(v[k][0]));
    return 0;
}
