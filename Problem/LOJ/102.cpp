#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 4e2 + 5;
int n, m;
int s, t;
int cnt[MaxN];
bool vis[MaxN];
long long cost;
long long answer;
long long dis[MaxN];
std::vector<std::tuple<int, long long, long long, int>> g[MaxN];
std::vector<std::tuple<int, long long, long long, int>>::iterator cur[MaxN];
void addEdge(int u, int v, long long w, long long c)
{
    int cu = g[u].size();
    int cv = g[v].size();
    g[u].push_back({v, w, c, cv});
    g[v].push_back({u, 0, -c, cu});
}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        cur[i] = g[i].begin();
    }
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    memset(dis, 0x3f, sizeof(dis));
    std::queue<int> queue;
    cnt[s] = 1;
    dis[s] = 0;
    queue.push(s);
    vis[s] = true;
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        vis[u] = false;
        for (const auto &[v, w, c, rev] : g[u])
        {
            if (w == 0 || dis[u] + c >= dis[v])
            {
                continue;
            }
            dis[v] = dis[u] + c;
            cnt[v] = cnt[u] + 1;
            if (!vis[v])
            {
                queue.push(v);
                vis[v] = true;
            }
        }
    }
}
std::tuple<long long, long long> push(int u, long long flow)
{
    if (u == t || flow == 0)
    {
        return {flow, 0};
    }
    for (auto &it = cur[u]; it != g[u].end(); it++)
    {
        auto &[v, w, c, rev] = *it;
        if (cnt[u] + 1 != cnt[v] || dis[u] + c != dis[v] || w == 0)
        {
            continue;
        }
        auto [put, cost] = push(v, std::min(flow, w));
        if (put != 0)
        {
            w -= put;
            std::get<1>(g[v][rev]) += put;
            return {put, cost + put * c};
        }
    }
    return {0, 0};
}
int main()
{
    scanf("%d%d", &n, &m);
    s = 1;
    t = n;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w, c;
        scanf("%d%d%d%d", &u, &v, &w, &c);
        addEdge(u, v, w, c);
    }
    for (;;)
    {
        init();
        if (cnt[t] == 0)
        {
            break;
        }
        auto [x, y] = push(s, 1e10);
        answer += x;
        cost += y;
    }
    printf("%lld %lld\n", answer, cost);
    return 0;
}
