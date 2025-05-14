#include <algorithm>
#include <cstdio>
#include <map>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e4 + 5;
int n, m;
int k[MaxN];
int size[MaxN];
bool vis[MaxN];
std::vector<int> vk;
std::vector<std::tuple<int, int>> g[MaxN];
std::map<int, bool> answer;
void calcSize(int u, int f)
{
    if (vis[u] && f != 0)
    {
        return;
    }
    size[u] = 1;
    for (const auto &[v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        calcSize(v, u);
        size[u] += size[v];
    }
}
int findRoot(int u, int f, int sizeAll, int &root, int &best)
{
    if (vis[u])
    {
        return -1;
    }
    int most = sizeAll - size[u];
    for (const auto &[v, w] : g[u])
    {
        most = std::max(most, size[v]);
    }
    if (most < best)
    {
        root = u;
        best = most;
    }
    for (const auto &[v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        int res = findRoot(v, u, sizeAll, root, best);
        if (res != -1)
        {
            return res;
        }
    }
    return -1;
}
const std::vector<int> calcDis(int u, int f)
{
    if (vis[u])
    {
        return {};
    }
    std::vector<int> res = {0};
    for (const auto &[v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        for (const auto &val : calcDis(v, u))
        {
            res.push_back(val + w);
        }
    }
    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end());
    return res;
}
void solve(int u)
{
    vis[u] = true;
    calcSize(u, 0);
    std::map<int, bool> have;
    have[0] = true;
    for (const auto &[v, w] : g[u])
    {
        auto ve = calcDis(v, u);
        for (const auto &target : vk)
        {
            for (const auto &val : ve)
            {
                int c = target - (val + w);
                if (c >= 0 && have[c])
                {
                    answer[target] = true;
                }
            }
        }
        for (const auto &val : ve)
        {
            have[val + w] = true;
        }
    }
    for (const auto &[v, w] : g[u])
    {
        int root, best;
        root = -1;
        best = 0x3f3f3f3f;
        findRoot(v, u, size[v], root, best);
        if (root != -1)
        {
            solve(root);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &k[i]);
        vk.push_back(k[i]);
    }
    calcSize(1, 0);
    int root, best;
    root = 0;
    best = 0x3f3f3f3f;
    findRoot(1, 0, size[1], root, best);
    solve(root);
    for (int i = 1; i <= m; i++)
    {
        printf("%s\n", answer[k[i]] ? "AYE" : "NAY");
    }
    return 0;
}