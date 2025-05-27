#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n, m;
int s, t;
int cnt[MaxN];
int id[MaxN][MaxN];
long long answer;
std::vector<std::tuple<int, long long>> g[MaxN];
std::vector<std::tuple<int, long long>>::iterator cur[MaxN];
void addEdge(int u, int v, long long w)
{
    id[u][v] = g[u].size();
    id[v][u] = g[v].size();
    g[u].push_back({v, w});
    g[v].push_back({u, 0});
}
void bfs()
{
    for (int i = 1; i <= n; i++)
    {
        cur[i] = g[i].begin();
    }
    memset(cnt, 0, sizeof(cnt));
    std::queue<int> queue;
    cnt[s] = 1;
    queue.push(s);
    for (; !queue.empty();)
    {
        auto u = queue.front();
        queue.pop();
        for (const auto &[v, w] : g[u])
        {
            if (w == 0 || cnt[v] != 0)
            {
                continue;
            }
            cnt[v] = cnt[u] + 1;
            queue.push(v);
        }
    }
}
long long push(int u, long long flow)
{
    if (u == t || flow == 0)
    {
        return flow;
    }
    for (auto &it = cur[u]; it != g[u].end(); it++)
    {
        auto &[v, w] = *it;
        if (cnt[u] + 1 != cnt[v] || w == 0)
        {
            continue;
        }
        long long put = push(v, std::min(flow, w));
        if (put != 0)
        {
            w -= put;
            std::get<1>(g[v][id[v][u]]) += put;
            return put;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    for (;;)
    {
        bfs();
        if (cnt[t] == 0)
        {
            break;
        }
        answer += push(s, 1e10);
    }
    printf("%lld\n", answer);
    return 0;
}