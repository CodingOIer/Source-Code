#include <algorithm>
#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, m, q;
int fd[MaxN];
int up[MaxN];
int depth[MaxN];
int jump[13][MaxN];
int jump_min[13][MaxN];
std::vector<std::tuple<int, int>> g[MaxN];
std::vector<std::tuple<int, int, int>> links;
int find(int x)
{
    return fd[x] == x ? x : fd[x] = find(fd[x]);
}
inline void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx != fy)
    {
        fd[fx] = fy;
    }
}
void dfs(int u, int f, int l)
{
    up[u] = l;
    depth[u] = depth[f] + 1;
    jump[0][u] = f;
    jump_min[0][u] = l;
    for (int j = 1; j < 13; j++)
    {
        jump[j][u] = jump[j - 1][jump[j - 1][u]];
        jump_min[j][u] = std::min({jump_min[j - 1][u], jump_min[j - 1][jump[j - 1][u]], up[jump[j - 1][u]]});
    }
    for (auto [v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u, w);
    }
}
int LCA(int x, int y)
{
    int res = 0x7f7f7f7f;
    if (depth[x] < depth[y])
    {
        std::swap(x, y);
    }
    for (int j = 12; j >= 0; j--)
    {
        if (depth[jump[j][x]] >= depth[y])
        {
            res = std::min(res, jump_min[j][x]);
            x = jump[j][x];
        }
    }
    for (int j = 12; j >= 0; j--)
    {
        if (jump[j][x] != jump[j][y])
        {
            res = std::min(res, jump_min[j][x]);
            res = std::min(res, jump_min[j][y]);
            x = jump[j][x];
            y = jump[j][y];
        }
    }
    if (x != y)
    {
        res = std::min(res, jump_min[0][x]);
        res = std::min(res, jump_min[0][y]);
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({u, v, w});
    }
    std::sort(links.begin(), links.end(),
              [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) -> bool {
                  return std::get<2>(x) > std::get<2>(y);
              });
    std::iota(fd + 1, fd + 1 + n, 1);
    for (auto [u, v, w] : links)
    {
        if (find(u) == find(v))
        {
            continue;
        }
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (jump[0][i] != 0)
        {
            continue;
        }
        up[i] = 0x7f7f7f7f;
        for (int j = 0; j < 13; j++)
        {
            jump[j][i] = i;
            jump_min[j][i] = 0x7f7f7f7f;
        }
        depth[i] = 1;
        for (auto [v, w] : g[i])
        {
            dfs(v, i, w);
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", find(u) == find(v) ? LCA(u, v) : -1);
    }
    return 0;
}