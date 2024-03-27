#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n, m;
int index;
int fa[MaxN];
int low[MaxN];
int road[MaxN];
bool vis1[MaxN];
bool vis2[MaxN];
bool split[MaxN];
std::vector<int> link[MaxN];
std::vector<int> group[MaxN];
std::map<std::pair<int, int>, bool> map;
void dfs1(int x, int f)
{
    fa[x] = f;
    vis1[x] = true;
    index++;
    low[x] = index;
    road[x] = index;
    bool vis_fa = false;
    for (auto next : link[x])
    {
        if (next == f)
        {
            if (!vis_fa)
            {
                vis_fa = true;
                continue;
            }
        }
        if (!vis1[next])
        {
            dfs1(next, x);
            low[x] = std::min(low[x], low[next]);
            if (low[next] > low[x])
            {
                split[next] = true;
            }
        }
        else
        {
            low[x] = std::min(low[x], road[next]);
        }
    }
}
void dfs2(int x, int g)
{
    if (vis2[x])
    {
        return;
    }
    vis2[x] = true;
    group[g].push_back(x);
    for (auto next : link[x])
    {
        if (!map[{x, next}])
        {
            dfs2(next, g);
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
    for (int i = 1; i <= n; i++)
    {
        if (!vis1[i])
        {
            dfs1(i, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (split[i])
        {
            map[{i, fa[i]}] = true;
            map[{fa[i], i}] = true;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis2[i])
        {
            cnt++;
            dfs2(i, cnt);
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d", int(group[i].size()));
        for (auto x : group[i])
        {
            printf(" %d", x);
        }
        printf("\n");
    }
    return 0;
}