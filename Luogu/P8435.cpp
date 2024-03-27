#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 5e2 + 5;
int n, m;
int index;
int dfn[MaxN];
int low[MaxN];
bool vis1[MaxN];
bool vis2[MaxN];
bool split[MaxN];
std::vector<int> link[MaxN];
std::vector<int> group[MaxN];
std::map<std::pair<int, int>, bool> map;
void dfs1(int x, int f)
{
    vis1[x] = true;
    index++;
    dfn[x] = index;
    low[x] = index;
    bool vis_fa = false;
    int son = 0;
    for (auto next : link[x])
    {
        if (next == f && !vis_fa)
        {
            vis_fa = true;
            continue;
        }
        if (!vis1[next])
        {
            son++;
            dfs1(next, x);
            low[x] = std::min(low[x], low[next]);
            if (x != f && low[next] >= dfn[x])
            {
                split[x] = true;
            }
        }
        else
        {
            low[x] = std::min(low[x], dfn[next]);
        }
    }
    if (x == f && son >= 2)
    {
        split[x] = true;
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
        if (split[next])
        {
            if (!map[{g, next}])
            {
                map[{g, next}] = true;
                group[g].push_back(next);
            }
        }
        else
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
    int index = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis2[i])
        {
            index++;
            dfs2(i, index);
        }
    }
    printf("%d\n", index);
    for (int i = 1; i <= index; i++)
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