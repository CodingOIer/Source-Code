#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 1e5 + 5;
constexpr int MaxM = 5e5 + 5;
int n, m;
int index;
int normal;
int low[MaxN];
int road[MaxN];
int vis_cnt[MaxN];
bool vis[MaxN];
bool split[MaxN];
std::vector<int> link[MaxN];
std::map<int, int> map;
inline int hash(int x)
{
    if (map[x] == 0)
    {
        n++;
        map[x] = n;
    }
    return map[x];
}
void dfs(int x, int f)
{
    vis[x] = true;
    index++;
    low[x] = index;
    road[x] = index;
    int son = 0;
    for (auto next : link[x])
    {
        if (!vis[next])
        {
            son++;
            dfs(next, x);
            low[x] = std::min(low[x], low[next]);
            if (x != f && low[next] >= road[x] && !split[x])
            {
                split[x] = true;
            }
        }
        else if (next != f)
        {
            low[x] = std::min(low[x], road[next]);
        }
    }
    if (x == f && son >= 2 && !split[x])
    {
        split[x] = true;
    }
}
void dfsCnt(int x, int g, long long &c, long long &s)
{
    if (vis_cnt[x] == g)
    {
        return;
    }
    vis_cnt[x] = g;
    c++;
    for (auto next : link[x])
    {
        if (split[next] && vis_cnt[next] != g)
        {
            vis_cnt[next] = g;
            s++;
        }
        dfsCnt(next, g, c, s);
    }
}
void solve(int id)
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u = hash(u);
        v = hash(v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            index = 0;
            dfs(i, i);
        }
    }
    int need = 0;
    long long plan = 1;
    for (int i = 1; i <= n; i++)
    {
        if (vis_cnt[i] != 0 || split[i])
        {
            continue;
        }
        long long c, s;
        c = 0;
        s = 0;
        dfsCnt(i, i, c, s);
        if (s == 0)
        {
            need += 2;
            plan *= c * (c - 1) / 2;
        }
        else if (s == 1)
        {
            need += 1;
            plan *= c;
        }
    }
    printf("Case %d: %d %lld\n", id, need, plan);
}
inline void clear()
{
    for (int i = 1; i <= n; i++)
    {
        low[i] = 0;
        road[i] = 0;
        vis[i] = false;
        vis_cnt[i] = false;
        split[i] = false;
        link[i].clear();
    }
    map.clear();
    n = 0;
    m = 0;
}
int main()
{
    for (int i = 1;; i++)
    {
        scanf("%d", &m);
        if (m == 0)
        {
            break;
        }
        solve(i);
        clear();
    }
    return 0;
}