#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <utility>
#include <vector>
constexpr int MaxN = 1e3 + 5;
int idx;
int n, m;
int answer;
int id[MaxN];
int cnt[MaxN];
int cur[MaxN];
int rev[MaxN][MaxN];
bool col[MaxN];
bool vis[MaxN];
std::queue<int> queue;
std::vector<int> l;
std::vector<int> r;
std::vector<int> link[MaxN];
std::vector<int> lk[MaxN];
std::vector<int> sti[MaxN];
std::map<std::pair<int, int>, bool> map;
void split(int u, bool c = true)
{
    if (vis[u])
    {
        return;
    }
    col[u] = c;
    vis[u] = true;
    if (c)
    {
        l.push_back(u);
    }
    else
    {
        r.push_back(u);
    }
    for (auto v : link[u])
    {
        split(v, !c);
    }
}
inline int newNode()
{
    idx++;
    return idx;
}
inline void addEdge(int u, int v, int m)
{
    lk[u].push_back(v);
    sti[u].push_back(m);
    rev[v][u] = lk[u].size() - 1;
}
inline void add(int u, int v, int m)
{
    addEdge(u, v, m);
    addEdge(v, u, 0);
}
inline void bfs(int s)
{
    cnt[s] = 1;
    queue.push(s);
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        for (int j = 0; j < lk[u].size(); j++)
        {
            if (cnt[lk[u][j]] == 0 && sti[u][j] > 0)
            {
                cnt[lk[u][j]] = cnt[u] + 1;
                queue.push(lk[u][j]);
            }
        }
    }
}
int dfs(int u, int f, int t)
{
    if (u == t || f == 0)
    {
        return f;
    }
    for (int &i = cur[u]; i < lk[u].size(); i++)
    {
        int v = lk[u][i];
        if (cnt[u] + 1 != cnt[v])
        {
            continue;
        }
        int push = std::min(f, sti[u][i]);
        push = dfs(v, push, t);
        if (push != 0)
        {
            sti[u][i] -= push;
            sti[v][rev[u][v]] += push;
            return push;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x++;
        y++;
        map[{x, y}] = true;
        map[{y, x}] = true;
        link[x].push_back(y);
        link[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (link[i].size() == 0 || vis[i])
        {
            continue;
        }
        split(i);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            answer++;
        }
    }
    int s = newNode();
    int t = newNode();
    for (int i = 1; i <= n; i++)
    {
        id[i] = newNode();
    }
    for (auto u : l)
    {
        add(s, id[u], 1);
        for (auto v : r)
        {
            if (map[{u, v}])
            {
                add(id[u], id[v], 1);
            }
        }
    }
    for (auto v : r)
    {
        add(id[v], t, 1);
    }
    for (;;)
    {
        memset(cnt, 0, sizeof(cnt));
        bfs(s);
        if (cnt[t] == 0)
        {
            break;
        }
        memset(cur, 0, sizeof(cur));
        answer += dfs(s, 0x7f7f7f7f, t);
    }
    printf("%d\n", answer);
    return 0;
}