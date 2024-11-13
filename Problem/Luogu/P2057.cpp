#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e2 + 5;
int n, m;
int p[MaxN];
int cnt[MaxN];
int edgeId[MaxN][MaxN];
std::vector<std::tuple<int, int, int>> g[MaxN];
std::vector<std::tuple<int, int, int>>::iterator ref[MaxN];
inline void addEdge(int u, int v, int w)
{
    g[u].push_back({v, 0, w});
    edgeId[u][v] = g[u].size() - 1;
    g[v].push_back({u, w, w});
    edgeId[v][u] = g[v].size() - 1;
}
inline void init(int begin)
{
    for (int i = 1; i <= n + 2; i++)
    {
        ref[i] = g[i].begin();
    }
    memset(cnt, 0x3f, sizeof(cnt));
    std::queue<int> queue;
    queue.push(begin);
    cnt[begin] = 1;
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        for (auto [v, use, most] : g[u])
        {
            if (use == most || cnt[v] != 0x3f3f3f3f)
            {
                continue;
            }
            cnt[v] = cnt[u] + 1;
            queue.push(v);
        }
    }
}
inline int tryPush(int u, int flow)
{
    if (u == n + 2 || flow == 0)
    {
        return flow;
    }
    for (; ref[u] != g[u].end();)
    {
        auto [v, use, most] = *ref[u];
        if (cnt[u] + 1 == cnt[v])
        {
            int push = std::min(flow, most - use);
            push = tryPush(v, push);
            if (push > 0)
            {
                std::get<1>(g[u][edgeId[u][v]]) += push;
                std::get<1>(g[v][edgeId[v][u]]) -= push;
                return push;
            }
        }
        ref[u]++;
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        if (p[i] == 0)
        {
            addEdge(n + 1, i, 1);
        }
        else
        {
            addEdge(i, n + 2, 1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v, 1);
        addEdge(v, u, 1);
    }
    int answer = 0;
    for (;;)
    {
        init(n + 1);
        int push = tryPush(n + 1, 0x3f3f3f3);
        if (push == 0)
        {
            break;
        }
        answer += push;
    }
    printf("%d\n", answer);
    return 0;
}