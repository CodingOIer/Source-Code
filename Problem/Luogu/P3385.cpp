#include <cstdio>
#include <vector>
const int MaxN = 2e3 + 5;
const int MaxM = 6e3 + 5;
int t;
int n, m;
int dis[MaxN];
std::vector<std::pair<std::pair<int, int>, int>> link;
void init()
{
    link.clear();
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 0x3f3f3f3f;
    }
}
void solve()
{
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= m; i++)
    {
        int w, u, v;
        scanf("%d%d%d", &u, &v, &w);
        if (w >= 0)
        {
            link.push_back({{u, v}, w});
            link.push_back({{v, u}, w});
        }
        else
        {
            link.push_back({{u, v}, w});
        }
    }
    dis[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        bool change = false;
        for (auto x : link)
        {
            int w, u, v;
            u = x.first.first;
            v = x.first.second;
            w = x.second;
            if (dis[u] != 0x3f3f3f3f && dis[v] > dis[u] + w)
            {
                change = true;
                dis[v] = dis[u] + w;
            }
        }
        if (!change)
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}