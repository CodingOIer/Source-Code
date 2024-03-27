#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 1e4 + 5;
int n, m;
int out[MaxN];
int size[MaxN];
int color[MaxN];
bool vis1[MaxN];
bool vis2[MaxN];
std::vector<int> dfn;
std::vector<int> link[MaxN];
std::vector<int> rev_link[MaxN];
std::map<std::pair<int, int>, bool> map;
void dfs1(int x)
{
    if (vis1[x])
    {
        return;
    }
    vis1[x] = true;
    for (auto next : link[x])
    {
        dfs1(next);
    }
    dfn.push_back(x);
}
void dfs2(int x, int c)
{
    if (vis2[x])
    {
        return;
    }
    vis2[x] = true;
    size[c]++;
    color[x] = c;
    for (auto next : rev_link[x])
    {
        dfs2(next, c);
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
        rev_link[v].push_back(u);
    }
    dfn.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis1[i])
        {
            dfs1(i);
        }
    }
    int index = 0;
    for (int i = n; i >= 1; i--)
    {
        if (!vis2[dfn[i]])
        {
            index++;
            dfs2(dfn[i], index);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto next : link[i])
        {
            int u, v;
            u = color[i];
            v = color[next];
            if (map[{u, v}] || u == v)
            {
                continue;
            }
            map[{u, v}] = true;
            out[u]++;
        }
    }
    int answer = 0;
    for (int i = 1; i <= index; i++)
    {
        if (out[i] == 0)
        {
            if (answer != 0)
            {
                printf("0\n");
                return 0;
            }
            answer = size[i];
        }
    }
    printf("%d\n", answer);
    return 0;
}