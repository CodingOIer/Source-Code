#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e4 + 5;
int n, m;
int k[MaxN];
int size[MaxN];
bool vis[MaxN];
bool answer[MaxN];
std::vector<std::tuple<int, int>> res;
std::vector<std::tuple<int, int>> g[MaxN];
void calcSize(int u, int f)
{
    if (vis[u])
    {
        return;
    }
    size[u] = 1;
    for (const auto &[v, w] : g[u])
    {
        if (v == f || vis[v])
        {
            continue;
        }
        calcSize(v, u);
        size[u] += size[v];
    }
}
void findRoot(int u, int f, int sizeAll, int &root, int &best)
{
    if (vis[u])
    {
        return;
    }
    int most = sizeAll - size[u];
    for (const auto &[v, w] : g[u])
    {
        if (v == f || vis[v])
        {
            continue;
        }
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
        findRoot(v, u, sizeAll, root, best);
    }
}
void calcDis(int u, int f, int root, int dis)
{
    if (vis[u])
    {
        return;
    }
    res.push_back({dis, root});
    for (const auto &[v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        calcDis(v, u, root, dis + w);
    }
}
void solve(int u)
{
    vis[u] = true;
    for (const auto &[v, w] : g[u])
    {
        calcDis(v, u, v, w);
    }
    res.push_back({0, -1});
    std::sort(res.begin(), res.end());
    for (int i = 1; i <= m; i++)
    {
        if (answer[i])
        {
            continue;
        }
        auto itl = res.begin();
        auto itr = res.end();
        itr--;
        for (; itl < itr;)
        {
            int c = std::get<0>(*itl) + std::get<0>(*itr);
            if (c < k[i])
            {
                itl++;
            }
            else if (c > k[i])
            {
                itr--;
            }
            else if (c == k[i])
            {
                if (std::get<1>(*itl) == std::get<1>(*itr))
                {
                    auto cp = itl;
                    cp++;
                    if (std::get<0>(*cp) == std::get<0>(*itl))
                    {
                        itl++;
                    }
                    else
                    {
                        itr--;
                    }
                }
                else
                {
                    answer[i] = true;
                    break;
                }
            }
        }
    }
    res.clear();
    for (const auto &[v, w] : g[u])
    {
        if (vis[v])
        {
            continue;
        }
        calcSize(v, u);
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
    }
    calcSize(1, 0);
    int root, best;
    root = 0;
    best = 0x3f3f3f3f;
    findRoot(1, 0, size[1], root, best);
    solve(root);
    for (int i = 1; i <= m; i++)
    {
        printf("%s\n", answer[i] ? "AYE" : "NAY");
    }
    return 0;
}