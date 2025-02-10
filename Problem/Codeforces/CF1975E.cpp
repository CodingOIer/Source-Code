#include <cstdio>
#include <map>
#include <set>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, q;
int fa[MaxN];
int color[MaxN];
int value[MaxN];
std::set<int> set;
std::map<int, int> map;
std::vector<int> g[MaxN];
void dfs(int u, int f)
{
    fa[u] = f;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
    }
}
void reversal(int u)
{
    map[value[u]]--;
    map[value[fa[u]]]--;
    if (value[u] == 1)
    {
        set.erase(u);
    }
    if (value[fa[u]] == 1)
    {
        set.erase(fa[u]);
    }
    if (color[u] == 0)
    {
        value[fa[u]]++;
        value[u]--;
        color[u] = 1;
    }
    else
    {
        value[fa[u]]--;
        value[u]++;
        color[u] = 0;
    }
    map[value[u]]++;
    map[value[fa[u]]]++;
    if (value[u] == 1)
    {
        set.insert(u);
    }
    if (value[fa[u]] == 1)
    {
        set.insert(fa[u]);
    }
}
void solve()
{
    set.clear();
    map.clear();
    scanf("%d%d", &n, &q);
    value[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        value[i] = 0;
        scanf("%d", &color[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    map[0] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
        {
            color[i] = 0;
            reversal(i);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int u;
        scanf("%d", &u);
        reversal(u);
        if ((map[-1] == 1 && map[1] == 1) ||
            (map[-1] == 2 && map[1] == 2 && (color[*set.begin()] == 1 ^ color[*++set.begin()] == 1) &&
             (fa[*set.begin()] == *++set.begin() || fa[*++set.begin()] == *set.begin())))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
