#include <algorithm>
#include <csetjmp>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 8e4 + 5;
int idx;
int n, m, s;
int in[MaxN];
int all[MaxN];
int block[MaxN];
int color[MaxN];
int answer[MaxN];
bool vis[MaxN];
std::queue<int> queue;
std::vector<int> dfn;
std::vector<int> cnt[MaxN];
std::vector<int> link[MaxN];
std::vector<int> rev_link[MaxN];
std::vector<int> new_link[MaxN];
std::vector<int> new_cnt[MaxN];
std::vector<int> repair[MaxN];
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
inline int calc(int x, int r)
{
    int res = 0;
    for (; x > 0;)
    {
        res += x;
        x = x * r / 10;
    }
    return res;
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
        repair[u].push_back(int(r * 10));
    }
    scanf("%d", &s);
    dfn.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        dfs1(i);
    }
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
        for (int j = 0; j < link[i].size(); j++)
        {
            int u = i;
            int v = link[i][j];
            if (color[u] == color[v])
            {
                block[color[u]] += calc(cnt[i][j], repair[i][j]);
                continue;
            }
            new_link[color[u]].push_back(color[v]);
            in[color[v]]++;
            new_cnt[color[u]].push_back(cnt[i][j]);
        }
    }
    s = color[s];
    std::vector<int> l;
    for (int i = 1; i <= idx; i++)
    {
        if (in[i] == 0)
        {
            queue.push(i);
        }
    }
    for (; !queue.empty();)
    {
        l.push_back(queue.front());
        int u = queue.front();
        queue.pop();
        for (auto v : link[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                queue.push(v);
            }
        }
    }
    memset(answer, -0x3f3f3f3f, sizeof(answer));
    answer[s] = block[s];
    for (auto u : l)
    {
        for (int i = 0; i < new_link[u].size(); i++)
        {
            int v = new_link[u][i];
            answer[v] = std::max(answer[v], answer[u] + new_cnt[u][i] + block[v]);
        }
    }
    int max = 0;
    for (int i = 1; i <= idx; i++)
    {
        max = std::max(max, answer[i]);
    }
    printf("%d\n", max);
    return 0;
}