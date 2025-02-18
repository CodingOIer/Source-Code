#include <algorithm>
#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n, m;
int *p[MaxN];
int dp[MaxN];
int pa[MaxN];
int size[MaxN];
int value[MaxN];
bool end[MaxN];
std::vector<int> g[MaxN];
std::vector<std::tuple<int, int, int>> links;
int getId(int x, int y)
{
    return m * (x - 1) + y;
}
int find(int u)
{
    return pa[u] == u ? u : pa[u] = find(pa[u]);
}
std::tuple<int, int> back(int u)
{
    return {(u - 1) / m + 1, (u - 1) % m + 1};
}
void dfsInit(int u, int f)
{
    size[u] = 0;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfsInit(v, u);
        size[u] += size[v];
    }
    if (size[u] == 0)
    {
        size[u] = 1;
    }
}
void dfs(int u, int f, int want)
{
    if (end[u])
    {
        dp[u] = want <= p[std::get<0>(back(u))][std::get<1>(back(u))] ? want - 1 : 0x3f3f3f3f;
        return;
    }
    int ls, rs;
    ls = rs = 0;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u, want);
        ls = rs;
        rs = v;
    }
    dp[u] = 0x3f3f3f3f;
    if (ls != 0 && dp[ls] <= value[u])
    {
        dp[u] = std::min(dp[u], dp[ls] - (size[u] - size[ls]));
    }
    if (rs != 0 && dp[rs] <= value[u])
    {
        dp[u] = std::min(dp[u], dp[rs] - (size[u] - size[rs]));
    }
}
bool check(int root, int want)
{
    dfs(root, 0, want);
    return dp[root] <= 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 5; i++)
    {
        p[i] = new int[m + 5];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
            value[getId(i, j)] = -1;
            if (i == 1 || i == n || j == 1 || j == m)
            {
                end[getId(i, j)] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j + 1 <= m)
            {
                links.push_back({std::min(p[i][j], p[i][j + 1]), getId(i, j), getId(i, j + 1)});
            }
            if (i + 1 <= n)
            {
                links.push_back({std::min(p[i][j], p[i + 1][j]), getId(i, j), getId(i + 1, j)});
            }
        }
    }
    std::iota(pa + 1, pa + 1 + n * m, 1);
    std::sort(links.begin(), links.end(), [](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) {
        return std::get<0>(x) > std::get<0>(y);
    });
    int k = n * m;
    for (const auto &[w, u, v] : links)
    {
        if (find(u) == find(v))
        {
            continue;
        }
        k++;
        pa[k] = k;
        value[k] = w;
        g[find(u)].push_back(k);
        g[k].push_back(find(u));
        g[find(v)].push_back(k);
        g[k].push_back(find(v));
        pa[find(u)] = k;
        pa[find(v)] = k;
    }
    int l, r;
    l = 1;
    r = 2e5;
    int res = 1;
    dfsInit(k, 0);
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (check(k, mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
