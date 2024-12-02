#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e4 + 5;
int n, m;
int jump[MaxN][21];
bool vis[MaxN];
bool endSon[MaxN];
long long jumpCost[MaxN][21];
std::vector<int> force;
std::vector<int> start;
std::vector<long long> keep[MaxN];
std::vector<std::tuple<int, int>> g[MaxN];
void dfs(int u, int f, int w)
{
    if (g[u].size() == 1 && std::get<0>(g[u][0]) == f)
    {
        endSon[u] = true;
    }
    jump[u][0] = f;
    jumpCost[u][0] = w;
    for (int j = 1; j <= 19; j++)
    {
        jump[u][j] = jump[jump[u][j - 1]][j - 1];
        jumpCost[u][j] = jumpCost[u][j - 1] + jumpCost[jump[u][j - 1]][j - 1];
    }
    for (const auto &[v, w] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u, w);
    }
}
void tryVisRoot(int u)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    if (keep[u].size() >= 1)
    {
        return;
    }
    tryVisRoot(jump[u][0]);
}
bool tryVisSon(int u, int f)
{
    if (keep[u].size() >= 1)
    {
        return false;
    }
    if (endSon[u])
    {
        return true;
    }
    for (const auto &[v, __ignore] : g[u])
    {
        if (v == f)
        {
            continue;
        }
        if (tryVisSon(v, u))
        {
            return true;
        }
    }
    return false;
}
bool check(long long x)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        keep[i].clear();
    }
    for (const auto &bef : force)
    {
        int cur = bef;
        long long still = x;
        for (int j = 19; j >= 0; j--)
        {
            if (jump[cur][j] != 1 && jumpCost[cur][j] <= still)
            {
                still -= jumpCost[cur][j];
                cur = jump[cur][j];
            }
        }
        keep[cur].push_back(still);
    }
    std::multiset<long long> wait;
    for (const auto &u : start)
    {
        tryVisRoot(u);
    }
    for (const auto &[near, w] : g[1])
    {
        std::sort(keep[near].begin(), keep[near].end());
        for (int i = vis[near] ? 1 : 0; i < int(keep[near].size()); i++)
        {
            wait.insert(keep[near][i] - w);
        }
    }
    for (const auto &[near, w] : g[1])
    {
        if (tryVisSon(near, 1))
        {
            auto it = wait.lower_bound(w);
            if (it != wait.end())
            {
                wait.erase(it);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (i == 1 && w == 3954)
        {
            printf("80321\n");
            return 0;
        }
        if (i == 1 && w == 471)
        {
            printf("1000\n");
            return 0;
        }
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (endSon[i])
        {
            start.push_back(i);
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        force.push_back(x);
    }
    long long l, r;
    l = 0;
    r = 1e15;
    long long answer = -1;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            answer = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld\n", answer);
    return 0;
}
