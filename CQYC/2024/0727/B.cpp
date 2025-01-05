#include <cstdio>
#include <cstring>
#include <deque>
#include <vector>
constexpr int MaxN = 7.5e4 + 5;
int n, m;
int p[MaxN];
int in[MaxN];
int dis[MaxN];
int vis[MaxN];
std::deque<int> queue;
std::vector<int> link[MaxN];
void Dijkstra(int root)
{
    queue.push_back(root);
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop_front();
        if (vis[u] == root)
        {
            continue;
        }
        vis[u] = root;
        for (auto v : link[u])
        {
            if (in[v])
            {
                if (dis[u] + 1 < dis[v])
                {
                    dis[v] = dis[u] + 1;
                    queue.push_back(v);
                }
            }
            else
            {
                if (dis[u] < dis[v])
                {
                    dis[v] = dis[u];
                    queue.push_front(v);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        in[i] = 1;
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[n] = 0;
    Dijkstra(n);
    int answer = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        dis[p[i]]--;
        answer += dis[p[i]];
        in[p[i]] = 0;
        Dijkstra(p[i]);
    }
    printf("%d\n", answer);
    return 0;
}