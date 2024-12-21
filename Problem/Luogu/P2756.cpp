#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n, m;
int cnt[MaxN];
int wasPair[MaxN];
int where[MaxN][MaxN];
bool vis[MaxN];
std::queue<int> queue;
std::vector<std::tuple<int, int, int>> g[MaxN];
std::vector<std::tuple<int, int, int>>::iterator cit[MaxN];
void addEdge(int u, int v, int w)
{
    where[u][v] = g[u].size();
    where[v][u] = g[v].size();
    g[u].push_back({v, 0, w});
    g[v].push_back({u, w, w});
}
void bfs(int s)
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        cnt[i] = 0x3f3f3f3f;
        cit[i] = g[i].begin();
    }
    cnt[s] = 0;
    queue.push(s);
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (const auto &[v, use, limit] : g[u])
        {
            if (use < limit && cnt[v] == 0x3f3f3f3f)
            {
                cnt[v] = cnt[u] + 1;
                queue.push(v);
            }
        }
    }
}
int tryPush(int u, int push, const int &t)
{
    if (u == t || push == 0)
    {
        return push;
    }
    for (auto &it = cit[u]; it != g[u].end(); it++)
    {
        auto [v, use, limit] = *it;
        if (cnt[u] + 1 == cnt[v])
        {
            int canPush = std::min(push, limit - use);
            canPush = tryPush(v, canPush, t);
            if (canPush != 0)
            {
                if (u <= m && m < v && v <= n - 2)
                {
                    wasPair[v] = u;
                }
                if (v <= m && m < u && u <= n - 2)
                {
                    wasPair[v] = 0;
                }
                std::get<1>(*it) += canPush;
                std::get<1>(g[v][where[v][u]]) -= canPush;
                return canPush;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &m, &n);
    int s, t;
    s = n + 1;
    t = n + 2;
    for (int i = 1; i <= m; i++)
    {
        addEdge(s, i, 1);
    }
    for (int i = m + 1; i <= n; i++)
    {
        addEdge(i, t, 1);
    }
    for (;;)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u == -1 && v == -1)
        {
            break;
        }
        addEdge(u, v, 1);
    }
    n += 2;
    int answer = 0;
    for (;;)
    {
        bfs(s);
        if (cnt[t] == 0x3f3f3f3f)
        {
            break;
        }
        int push = tryPush(s, 0x3f3f3f3f, t);
        answer += push;
    }
    printf("%d\n", answer);
    for (int i = m + 1; i <= n - 2; i++)
    {
        if (wasPair[i] != 0)
        {
            printf("%d %d\n", wasPair[i], i);
        }
    }
    return 0;
}
