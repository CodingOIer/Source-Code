#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <utility>
#include <vector>
constexpr int MaxN = 8e4 + 5;
int n, m, s;
int all[MaxN];
int block[MaxN];
int color[MaxN];
bool vis[MaxN];
std::queue<int> queue;
std::vector<int> dfn;
std::vector<int> cnt[MaxN];
std::vector<int> link[MaxN];
std::vector<int> rev_link[MaxN];
std::vector<int> new_cnt[MaxN];
std::vector<int> new_link[MaxN];
std::vector<double> repair[MaxN];
std::map<std::pair<int, int>, int> map;
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
    color[u] = c;
    for (auto v : rev_link[u])
    {
        dfs2(v, c);
    }
}
int calc(int x, double r)
{
    if (x == 0)
    {
        return 0;
    }
    return x + calc(int(x * r), r);
}
void bfs()
{
    queue.push(s);
    all[s] = block[s];
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        vis[u] = false;
        for (int i = 0; i < new_link[u].size(); i++)
        {
            int v = new_link[u][i];
            if (all[u] + map[{u, v}] + block[v] > all[v])
            {
                all[v] = all[u] + map[{u, v}] + block[v];
                if (!vis[v])
                {
                    queue.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        double r;
        scanf("%d%d%d%lf", &u, &v, &w, &r);
        link[u].push_back(v);
        rev_link[v].push_back(u);
        cnt[u].push_back(w);
        repair[u].push_back(r);
    }
    scanf("%d", &s);
    dfn.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        dfs1(i);
    }
    int idx = 0;
    memset(vis, false, sizeof(vis));
    for (int i = n; i >= 1; i--)
    {
        if (!vis[dfn[i]])
        {
            idx++;
            dfs2(dfn[i], idx);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < link[i].size(); i++)
        {
            int u = i;
            int v = link[i][j];
            if (color[u] == color[v])
            {
                block[color[u]] += calc(cnt[i][j], repair[i][j]);
                continue;
            }
            if (!map.count({u, v}))
            {
                new_link[color[u]].push_back(color[v]);
                new_link[color[v]].push_back(color[u]);
            }
            map[{u, v}] = std::max(map[{u, v}], cnt[i][j]);
            map[{v, u}] = map[{u, v}];
        }
    }
    memset(vis, false, sizeof(vis));
    bfs();
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer = std::max(answer, all[i]);
    }
    printf("%d\n", answer);
    return 0;
}