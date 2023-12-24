#include <cstdio>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <vector>
const int MaxN = 25e2 + 5;
long long u, v;
long long start;
long long answer;
long long number;
long long n, m, k;
long long ans[MaxN];
long long value[MaxN];
bool vis[MaxN];
bool can_visit[MaxN][MaxN];
std::mt19937 rnd(88888888);
std::vector<long long> can[MaxN];
std::vector<long long> links[MaxN];
void Dijkstra(long long x)
{
    memset(vis, 0, sizeof(vis));
    memset(ans, 0x3f3f3f3f, sizeof(ans));
    std::priority_queue<std::pair<long long, long long>> queue;
    vis[x] = true;
    queue.push({0, x});
    for (; !queue.empty();)
    {
        long long len, now;
        len = -queue.top().first;
        now = queue.top().second;
        queue.pop();
        ans[now] = len;
        for (int i = 0; i < (int)(links[now].size()); i++)
        {
            long long y;
            y = links[now][i];
            if (len + 1 < ans[y] && !vis[y])
            {
                vis[y] = true;
                queue.push({-len - 1, y});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != x && ans[i] <= k + 1)
        {
            can[x].push_back(i);
            can_visit[x][i] = true;
        }
    }
    return;
}
inline void update(int a, int b, int c, int d)
{
    if (can_visit[1][a] && can_visit[a][b] && can_visit[b][c] && can_visit[c][d] && can_visit[d][1] && a != b &&
        a != c && a != d && b != c && b != d && c != d)
    {
        answer = std::max(answer, value[a] + value[b] + value[c] + value[d]);
    }
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 2; i <= n; i++)
    {
        scanf("%lld", &value[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &u, &v);
        links[u].push_back(v);
        links[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        Dijkstra(i);
    }
    start = clock();
    for (; (double)(clock() - start) / CLOCKS_PER_SEC <= 1.985;)
    {
        int a, b, c, d;
        a = can[1][rnd() % (can[1].size())];
        b = can[a][rnd() % (can[a].size())];
        c = can[b][rnd() % (can[b].size())];
        d = can[c][rnd() % (can[c].size())];
        update(a, b, c, d);
        number++;
    }
    printf("%lld %lld\n\n", answer, number);
    return 0;
}