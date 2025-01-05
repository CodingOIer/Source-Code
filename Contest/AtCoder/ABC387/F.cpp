#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 3e3 + 5;
constexpr long long Mod = 998'244'353;
int n, m;
int p[MaxN];
int in[MaxN];
int gid[MaxN];
bool vis[MaxN];
bool use[MaxN][MaxN];
long long dp[MaxN][MaxN];
std::queue<int> queue;
std::vector<int> back;
std::vector<int> g[MaxN];
std::vector<int> rg[MaxN];
std::vector<int> ng[MaxN];
std::vector<int> rng[MaxN];
void dfs1(int u)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (const auto &v : g[u])
    {
        dfs1(v);
    }
    back.push_back(u);
}
void dfs2(int u, int color)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (const auto &v : rg[u])
    {
        dfs2(v, color);
    }
    gid[u] = color;
}
void calc(int u)
{
    for (int i = 1; i <= m; i++)
    {
        dp[u][i] = 1;
    }
    for (const auto &v : ng[u])
    {
        long long prefix = 0;
        for (int i = 1; i <= m; i++)
        {
            prefix += dp[v][i];
            prefix %= Mod;
            dp[u][i] = dp[u][i] * prefix % Mod;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        if (p[i] == i)
        {
            continue;
        }
        int u, v;
        u = p[i];
        v = i;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    int color = 0;
    std::reverse(back.begin(), back.end());
    for (const auto &u : back)
    {
        if (!vis[u])
        {
            dfs2(u, ++color);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int u = gid[i];
        for (const auto &ov : g[i])
        {
            int v = gid[ov];
            if (use[u][v])
            {
                continue;
            }
            use[u][v] = true;
            if (u != v)
            {
                ng[u].push_back(v);
                rng[v].push_back(u);
                in[u]++;
            }
        }
    }
    n = color;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            queue.push(i);
        }
    }
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        calc(u);
        for (const auto &v : rng[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                queue.push(v);
            }
        }
    }
    long long answer = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!rng[i].empty())
        {
            continue;
        }
        long long temp = 0;
        for (int j = 1; j <= m; j++)
        {
            temp += dp[i][j];
            temp %= Mod;
        }
        answer = answer * temp % Mod;
    }
    printf("%lld\n", answer);
    return 0;
}
