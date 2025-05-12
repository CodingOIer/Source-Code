#include <cmath>
#include <cstdio>
#include <deque>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e3 + 5;
int n, m;
int allow;
int dis[MaxN];
int cnt[MaxN];
bool vis[MaxN];
std::deque<int> queue;
std::vector<std::tuple<int, int>> g[MaxN];
void init()
{
    allow = 0;
    for (; !queue.empty();)
    {
        queue.pop_back();
    }
}
void push(int x)
{
    if (queue.empty() || x > dis[queue.front()] + allow)
    {
        queue.push_back(x);
    }
    else
    {
        queue.push_front(x);
    }
}
void check()
{
    if (queue.empty())
    {
        return;
    }
    if (dis[queue.front()] > dis[queue.back()])
    {
        int x, y;
        x = queue.front();
        queue.pop_front();
        y = queue.back();
        queue.pop_back();
        queue.push_back(x);
        queue.push_front(y);
    }
}
void solve()
{
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        cnt[i] = 0;
        vis[i] = false;
        dis[i] = 0x3f3f3f3f;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        if (w >= 0)
        {
            g[v].push_back({u, w});
        }
        allow += w;
    }
    allow = allow < 0 ? -0x3f3f3f3f : sqrt(allow);
    dis[1] = 0;
    push(1);
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop_front();
        check();
        vis[u] = false;
        for (const auto &[v, w] : g[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                {
                    printf("YES\n");
                    return;
                }
                if (!vis[v])
                {
                    push(v);
                    check();
                    vis[v] = true;
                }
            }
        }
    }
    printf("NO\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}