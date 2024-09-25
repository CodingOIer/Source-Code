#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e2 + 5;
int n, m, q;
int p[MaxN][MaxN];
bool available[MaxN];
std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>, std::greater<>> queue;
void update(int k)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = std::min(p[i][j], p[i][k] + p[k][j]);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        queue.push({x, i});
    }
    memset(p, 0x3f, sizeof(p));
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u++;
        v++;
        p[u][v] = w;
        p[v][u] = w;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int u, v, cur;
        scanf("%d%d%d", &u, &v, &cur);
        u++;
        v++;
        for (; !queue.empty() && std::get<0>(queue.top()) <= cur;)
        {
            available[std::get<1>(queue.top())] = true;
            update(std::get<1>(queue.top()));
            queue.pop();
        }
        printf("%d\n", !available[u] || !available[v] || p[u][v] == 0x3f3f3f3f ? -1 : p[u][v]);
    }
    return 0;
}