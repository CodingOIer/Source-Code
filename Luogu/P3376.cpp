#include <cstdio>
#include <queue>
#include <vector>
const int MaxN = 2e2 + 5;
const int MaxM = 2e5 + 5;
class edge
{
  public:
    int to;
    long long use;
    long long flow;
    edge(int x, long long y)
    {
        to = x;
        use = 0;
        flow = y;
    }
    edge()
    {
        to = 0;
        use = 0;
        flow = 0;
    }
};
int n, m, s, t;
int depth[MaxN];
std::vector<edge> link[MaxN];
long long solve()
{
    std::queue<int> bfs;
    bfs.push(s);
    depth[s] = 1;
    for (; !bfs.empty();)
    {
        int now = bfs.front();
        bfs.pop();
        for (edge to : link[now])
        {
            if (depth[to.to] == 0)
            {
                depth[to.to] = depth[now] + 1;
                bfs.push(to.to);
            }
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
        link[u].push_back(edge{v, w});
    }
    long long answer = solve();
    printf("%lld\n", answer);
    return 0;
}