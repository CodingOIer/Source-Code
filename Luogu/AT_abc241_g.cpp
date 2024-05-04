#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <utility>
#include <vector>
constexpr int MaxN = 5e3 + 5;
int idx;
int n, m, s, t;
int id[MaxN];
int cnt[MaxN];
int rev[MaxN][MaxN];
int last[MaxN];
int beat[MaxN];
int was_beat[MaxN];
std::queue<int> queue;
std::vector<int> use[MaxN];
std::vector<int> max[MaxN];
std::vector<int> link[MaxN];
std::map<std::pair<int, int>, bool> map;
inline void init()
{
    idx = 0;
    for (int i = 0; i < MaxN; i++)
    {
        use[i].clear();
        max[i].clear();
        link[i].clear();
    }
}
inline void add(int u, int v, int m, int k)
{
    use[u].push_back(k);
    max[u].push_back(m);
    link[u].push_back(v);
    rev[v][u] = link[u].size() - 1;
}
inline void add(int u, int v, int m)
{
    add(u, v, m, 0);
    add(v, u, m, m);
}
inline int new_node()
{
    idx++;
    return idx;
}
void bfs()
{
    queue.push(s);
    cnt[s] = 1;
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        for (int i = 0; i < int(link[u].size()); i++)
        {
            int v = link[u][i];
            if (cnt[v] == 0 && max[u][i] - use[u][i] > 0)
            {
                cnt[v] = cnt[u] + 1;
                queue.push(v);
            }
        }
    }
}
int dfs(int u, int f)
{
    if (u == t || f == 0)
    {
        return f;
    }
    for (int i = last[u]; i < int(link[u].size()); i++)
    {
        last[u] = i;
        int v = link[u][i];
        if (cnt[u] + 1 == cnt[v])
        {
            int push = std::min(f, max[u][i] - use[u][i]);
            push = dfs(v, push);
            if (push > 0)
            {
                use[u][i] += push;
                use[v][rev[u][v]] -= push;
                return push;
            }
        }
    }
    return 0;
}
inline int Dinic()
{
    int res = 0;
    for (;;)
    {
        memset(cnt, 0, sizeof(cnt));
        bfs();
        if (cnt[t] == 0)
        {
            break;
        }
        memset(last, 0, sizeof(last));
        res += dfs(s, 1e9);
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
        beat[u]++;
        was_beat[v]++;
        map[{u, v}] = true;
        map[{v, u}] = true;
    }
    for (int x = 1; x <= n; x++)
    {
        init();
        s = new_node();
        t = new_node();
        int mx = (n - 1) - was_beat[x];
        for (int i = 1; i <= n; i++)
        {
            id[i] = new_node();
            if (i == x)
            {
                continue;
            }
            for (int j = i + 1; j <= n; j++)
            {
                if (j != x && !map[{i, j}])
                {
                    int contest = new_node();
                    add(s, contest, 1);
                    add(contest, id[i], 1);
                    add(contest, id[j], 1);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
            {
                continue;
            }
            add(s, id[i], beat[i]);
            add(id[i], t, mx - 1);
        }
        if (Dinic() + mx == n * (n - 1) / 2)
        {
            printf("%d ", x);
        }
    }
    return 0;
}