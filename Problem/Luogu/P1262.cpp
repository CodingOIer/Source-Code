#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <utility>
#include <vector>
constexpr int MaxN = 3e3 + 5;
int n, r, m;
int p[MaxN];
int in[MaxN];
int col[MaxN];
int cost[MaxN];
int minId[MaxN];
bool get[MaxN];
bool vis[MaxN];
std::queue<int> queue;
std::vector<int> dfn;
std::vector<int> link[MaxN];
std::vector<int> rev_link[MaxN];
std::vector<int> new_link[MaxN];
std::map<std::pair<int, int>, bool> map;
void dfs1(int u)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (auto v : link[u])
    {
        dfs1(v);
    }
    dfn.push_back(u);
}
void dfs2(int u, int c)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    col[u] = c;
    for (auto v : rev_link[u])
    {
        dfs2(v, c);
    }
}
int main()
{
    scanf("%d", &n);
    scanf("%d", &r);
    memset(p, 0x3f3f3f3f, sizeof(p));
    for (int i = 1; i <= r; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x] = y;
    }
    scanf("%d", &m);
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
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    memset(vis, false, sizeof(vis));
    int idx = 0;
    for (int i = n; i >= 1; i--)
    {
        if (!vis[dfn[i]])
        {
            idx++;
            dfs2(dfn[i], idx);
        }
    }
    memset(cost, 0x3f3f3f3f, sizeof(cost));
    memset(minId, 0x3f3f3f3f, sizeof(minId));
    for (int i = 1; i <= n; i++)
    {
        if (p[i] < cost[col[i]] && p[i] != -1)
        {
            cost[col[i]] = p[i];
        }
        minId[col[i]] = std::min(minId[col[i]], i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto v : link[i])
        {
            int u = col[i];
            v = col[v];
            if (!map[{u, v}] && u != v)
            {
                map[{u, v}] = true;
                new_link[u].push_back(v);
                in[v]++;
            }
        }
    }
    for (int i = 1; i <= idx; i++)
    {
        if (in[i] == 0)
        {
            queue.push(i);
        }
    }
    int all_cost = 0;
    int min_id = 0x3f3f3f3f;
    bool accept = true;
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        if (!get[u])
        {
            if (cost[u] != 0x3f3f3f3f)
            {
                all_cost += cost[u];
                get[u] = true;
            }
            else
            {
                accept = false;
                min_id = std::min(min_id, minId[u]);
            }
        }
        for (auto v : new_link[u])
        {
            get[v] = get[u];
            in[v]--;
            if (in[v] == 0)
            {
                queue.push(v);
            }
        }
    }
    if (accept)
    {
        printf("YES\n");
        printf("%d\n", all_cost);
    }
    else
    {
        printf("NO\n");
        printf("%d\n", min_id);
    }
    return 0;
}