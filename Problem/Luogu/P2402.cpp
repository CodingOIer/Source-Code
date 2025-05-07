#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 2e3 + 5;
constexpr long long inf = 0x3f3f3f3f'3f3f3f3f;
int n, m;
int total;
int begin, end;
int ct[MaxN];
int id[MaxN];
int stop[MaxN];
long long cow;
long long c[MaxN];
long long p[MaxN];
long long w[MaxN][MaxN];
long long dis[MaxN][MaxN];
std::vector<int> g[MaxN];
std::vector<int>::iterator it[MaxN];
void reset()
{
    for (int i = 1; i <= total; i++)
    {
        g[i].clear();
        for (int j = 1; j <= total; j++)
        {
            w[i][j] = 0;
        }
    }
    begin = 1;
    end = 2;
    total = 2;
}
int node()
{
    return ++total;
}
void addEdge(int u, int v, long long c)
{
    g[u].push_back(v);
    g[v].push_back(u);
    w[u][v] += c;
}
void bfs()
{
    for (int i = 1; i <= total; i++)
    {
        it[i] = g[i].begin();
    }
    std::queue<int> queue;
    for (int i = 1; i <= total; i++)
    {
        ct[i] = -1;
    }
    ct[begin] = 1;
    queue.push(begin);
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        for (const auto v : g[u])
        {
            if (ct[v] == -1 && w[u][v] > 0)
            {
                ct[v] = ct[u] + 1;
                queue.push(v);
            }
        }
    }
}
long long tryPush(int u, long long flow)
{
    if (u == end || flow == 0)
    {
        return flow;
    }
    for (auto &c = it[u]; c != g[u].end(); c++)
    {
        int v = *c;
        if (ct[u] + 1 != ct[v])
        {
            continue;
        }
        long long push = std::min(w[u][v], flow);
        push = tryPush(v, push);
        if (push > 0)
        {
            w[u][v] -= push;
            w[v][u] += push;
            return push;
        }
    }
    return 0;
}
long long dinic()
{
    long long result = 0;
    for (;;)
    {
        bfs();
        if (ct[end] == -1)
        {
            break;
        }
        result += tryPush(begin, inf);
    }
    return result;
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &c[i], &p[i]);
        cow += c[i];
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        dis[u][v] = std::min(dis[u][v], w);
        dis[v][u] = std::min(dis[v][u], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    long long result = -1;
    long long l, r;
    l = 0;
    r = 2e17;
    for (; l <= r;)
    {
        long long mid = (l + r) / 2;
        reset();
        for (int i = 1; i <= n; i++)
        {
            id[i] = node();
            stop[i] = node();
            addEdge(begin, id[i], c[i]);
            addEdge(stop[i], end, p[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] <= mid)
                {
                    addEdge(id[i], stop[j], inf);
                }
            }
        }
        long long canCow = dinic();
        if (canCow >= cow)
        {
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld\n", result);
    return 0;
}
