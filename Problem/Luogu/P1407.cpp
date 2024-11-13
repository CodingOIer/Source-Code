#include <cstdio>
#include <map>
#include <string>
#include <vector>
constexpr int MaxN = 8e3 + 5;
int cnt;
int n, m;
int color[MaxN];
char tu[MaxN][15];
char tv[MaxN][15];
char ttu[15];
char ttv[15];
bool vis1[MaxN];
bool vis2[MaxN];
std::vector<int> road;
std::vector<int> link[MaxN];
std::vector<int> rev_link[MaxN];
std::map<std::string, int> map;
inline int hash(std::string s)
{
    if (map[s] != 0)
    {
        return map[s];
    }
    cnt++;
    map[s] = cnt;
    return map[s];
}
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
    road.push_back(x);
}
void dfs2(int x, int c)
{
    if (vis2[x])
    {
        return;
    }
    vis2[x] = true;
    color[x] = c;
    for (auto next : rev_link[x])
    {
        dfs2(next, c);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s %s", tu[i], tv[i]);
        int u, v;
        u = hash(tu[i]);
        v = hash(tv[i]);
        link[v].push_back(u);
        rev_link[u].push_back(v);
    }
    scanf("%d", &m);
    for (int j = 1; j <= m; j++)
    {
        scanf("%s %s", ttu, ttv);
        int u, v;
        u = hash(ttu);
        v = hash(ttv);
        link[u].push_back(v);
        rev_link[v].push_back(u);
    }
    road.push_back(0);
    for (int i = 1; i <= cnt; i++)
    {
        dfs1(i);
    }
    int group = 0;
    for (int i = cnt; i >= 1; i--)
    {
        if (!vis2[road[i]])
        {
            group++;
            dfs2(road[i], group);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%s\n", color[hash(tu[i])] == color[hash(tv[i])] ? "Unsafe" : "Safe");
    }
    return 0;
}