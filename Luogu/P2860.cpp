#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 5e3 + 5;
int n, m;
int index;
int answer;
int fa[MaxN];
int low[MaxN];
int dfn[MaxN];
int color[MaxN];
bool vis1[MaxN];
bool vis2[MaxN];
bool split[MaxN];
std::vector<int> link[MaxN];
std::vector<int> new_link[MaxN];
std::map<std::pair<int, int>, bool> map1;
std::map<std::pair<int, int>, bool> map2;
void dfs1(int x, int f)
{
    fa[x] = f;
    vis1[x] = true;
    index++;
    dfn[x] = index;
    low[x] = index;
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
            if (low[next] > dfn[x] && !split[next])
            {
                answer++;
                split[next] = true;
            }
        }
        else
        {
            low[x] = std::min(low[x], dfn[next]);
        }
    }
}
void dfs2(int x, int c)
{
    if (vis2[x])
    {
        return;
    }
    vis2[x] = true;
    color[x] = c;
    for (auto next : link[x])
    {
        if (map1[{x, next}])
        {
            continue;
        }
        dfs2(next, c);
    }
}
int dfs3(int x, int f)
{
    if (new_link[x].size() == 1 && new_link[x][0] == f)
    {
        return 1;
    }
    int res = 0;
    for (auto next : new_link[x])
    {
        if (next == f)
        {
            continue;
        }
        res += dfs3(next, x);
    }
    return res;
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
    dfs1(1, 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (split[i])
        {
            map1[{i, fa[i]}] = true;
            map1[{fa[i], i}] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis2[i])
        {
            cnt++;
            dfs2(i, cnt);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto next : link[i])
        {
            int u, v;
            u = color[i];
            v = color[next];
            if (u == v || map2[{u, v}])
            {
                continue;
            }
            map2[{u, v}] = true;
            map2[{v, u}] = true;
            new_link[u].push_back(v);
            new_link[v].push_back(u);
        }
    }
    int answer = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (new_link[i].size() != 1)
        {
            answer = dfs3(i, 0);
            break;
        }
    }
    printf("%d\n", (answer + 1) / 2);
    return 0;
}