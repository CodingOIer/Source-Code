#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e2 + 5;
int n, m;
int idx;
int fa[MaxN];
int dfn[MaxN];
int low[MaxN];
bool vis[MaxN];
bool split[MaxN];
std::vector<int> link[MaxN];
std::vector<std::pair<int, int>> answer;
void dfs(int u, int f)
{
    fa[u] = f;
    idx++;
    dfn[u] = idx;
    low[u] = idx;
    vis[u] = true;
    bool vis_fa = false;
    for (auto v : link[u])
    {
        if (v == f && !vis_fa)
        {
            vis_fa = true;
            continue;
        }
        if (!vis[v])
        {
            dfs(v, u);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                split[v] = true;
            }
        }
        else
        {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (split[i])
        {
            if (i < fa[i])
            {
                answer.push_back({i, fa[i]});
            }
            else
            {
                answer.push_back({fa[i], i});
            }
        }
    }
    std::sort(answer.begin(), answer.end());
    for (auto x : answer)
    {
        printf("%d %d\n", x.first, x.second);
    }
    return 0;
}