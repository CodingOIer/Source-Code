#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, m;
int answer[MaxN];
bool vis[MaxN];
std::vector<int> g[MaxN];
void dfsSet(int u, int f)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    answer[u] = f;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfsSet(v, u);
    }
}
std::tuple<bool, int, bool> dfs(int u, int f)
{
    if (vis[u])
    {
        answer[u] = f;
        return {true, u, false};
    }
    vis[u] = true;
    bool suc = false;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        auto [found, c, pass] = dfs(v, u);
        if (found)
        {
            if (c == u)
            {
                pass = true;
            }
            if (f == 0)
            {
                suc = true;
                break;
            }
            if (pass)
            {
                answer[f] = u;
            }
            if (!pass)
            {
                answer[u] = f;
            }
            for (const auto &v : g[u])
            {
                if (v == f)
                {
                    continue;
                }
                dfsSet(v, u);
            }
            return {found, c, pass};
        }
    }
    vis[u] = false;
    if (f == 0 && suc)
    {
        vis[u] = true;
        for (const auto &v : g[u])
        {
            if (v == f)
            {
                continue;
            }
            dfsSet(v, u);
        }
        return {true, 0, false};
    }
    return {false, 0, false};
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            const auto &[res, _a, _b] = dfs(i, 0);
            if (!res)
            {
                printf("NIE\n");
                return 0;
            }
        }
    }
    printf("TAK\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}