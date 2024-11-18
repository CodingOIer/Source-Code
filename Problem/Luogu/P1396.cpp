#include <algorithm>
#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e4 + 5;
int n, m, s, t;
int fd[MaxN];
std::vector<std::tuple<int, int>> g[MaxN];
std::vector<std::tuple<int, int, int>> links;
inline int find(int u)
{
    return fd[u] == u ? u : fd[u] = find(fd[u]);
}
int dfs(int u, int f, int t)
{
    if (u == t)
    {
        return 0;
    }
    for (auto [v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        int res = dfs(v, u, t);
        if (res != -1)
        {
            return std::max(res, w);
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        links.push_back({w, u, v});
    }
    std::iota(fd + 1, fd + 1 + n, 1);
    std::sort(links.begin(), links.end());
    for (auto [w, u, v] : links)
    {
        if (find(u) != find(v))
        {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            fd[find(v)] = find(u);
        }
    }
    printf("%d\n", dfs(s, 0, t));
    return 0;
}
