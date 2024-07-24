#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <utility>
#include <vector>
std::mt19937_64 rnd(std::random_device{}());
constexpr int MaxN = 1e3 + 5;
int n, m;
int p[MaxN];
int f[MaxN];
int w[MaxN];
int pre[MaxN];
int dis[MaxN];
bool vis[MaxN];
unsigned long long sha[MaxN];
std::map<std::pair<int, int>, int> map;
std::vector<int> v1[MaxN];
std::vector<int> v2[MaxN];
std::vector<int> link[MaxN];
std::vector<int> answer;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx == fy)
    {
        return;
    }
    f[fy] = fx;
}
void Dijkstra(int u)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[u] = 0;
    memset(vis, false, sizeof(vis));
    queue.push({0, u});
    for (; !queue.empty();)
    {
        auto [_, u] = queue.top();
        queue.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto v : link[u])
        {
            if (dis[u] + 1 < dis[v])
            {
                pre[v] = u;
                dis[v] = dis[u] + 1;
                queue.push({dis[v], v});
            }
        }
    }
}
std::vector<std::pair<int, int>> rev(int u, int v)
{
    Dijkstra(u);
    std::vector<std::pair<int, int>> response;
    int x = v;
    for (; x != u;)
    {
        response.push_back({x, pre[x]});
        x = pre[x];
    }
    return response;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        sha[i] = rnd();
        scanf("%d", &p[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
        map[{u, v}] = i;
        map[{v, u}] = i;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        v1[find(i)].push_back(i);
        v2[find(i)].push_back(p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        unsigned long long sum1, sum2;
        sum1 = 0;
        sum2 = 0;
        for (auto x : v1[i])
        {
            sum1 += sha[x];
        }
        for (auto x : v2[i])
        {
            sum2 += sha[x];
        }
        if (sum1 != sum2)
        {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int w = i;
        for (; w <= n; w++)
        {
            if (p[w] == i)
            {
                break;
            }
        }
        auto response = rev(i, w);
        for (auto [u, v] : response)
        {
            std::swap(p[u], p[v]);
            answer.push_back(map[{u, v}]);
        }
        for (int i = int(response.size()) - 2; i >= 0; i--)
        {
            auto [u, v] = response[i];
            std::swap(p[u], p[v]);
            answer.push_back(map[{u, v}]);
        }
    }
    printf("%zu\n", answer.size());
    for (auto x : answer)
    {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}