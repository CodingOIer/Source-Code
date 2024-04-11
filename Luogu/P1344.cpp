#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 35;
constexpr int E = 1001;
int n, m;
int cnt[MaxN];
int last[MaxN];
int rev[MaxN][MaxN];
long long answer;
std::queue<int> queue;
std::vector<int> max[MaxN];
std::vector<long long> use[MaxN];
std::vector<long long> link[MaxN];
void bfs()
{
    queue.push(1);
    cnt[1] = 1;
    for (; !queue.empty();)
    {
        int u = queue.front();
        queue.pop();
        for (int i = 0; i < int(link[u].size()); i++)
        {
            int v = link[u][i];
            if (cnt[v] == 0 && max[u][i] - use[u][i] > 0)
            {
                cnt[v] = cnt[u] + 1;
                queue.push(v);
            }
        }
    }
}
long long dfs(int u, long long f)
{
    if (u == n || f == 0)
    {
        return f;
    }
    for (int i = last[u]; i < int(link[u].size()); i++)
    {
        last[u] = i;
        int v = link[u][i];
        if (cnt[u] + 1 == cnt[v])
        {
            long long push = std::min(f, max[u][i] - use[u][i]);
            push = dfs(v, push);
            if (push > 0)
            {
                use[u][i] += push;
                use[v][rev[u][v]] -= push;
                return push;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        w = w * E + 1;
        link[u].push_back(v);
        link[v].push_back(u);
        max[u].push_back(w);
        max[v].push_back(w);
        use[u].push_back(0);
        use[v].push_back(w);
        rev[u][v] = link[v].size() - 1;
        rev[v][u] = link[u].size() - 1;
    }
    for (;;)
    {
        memset(cnt, 0, sizeof(cnt));
        bfs();
        if (cnt[n] == 0)
        {
            break;
        }
        memset(last, 0, sizeof(last));
        answer += dfs(1, 1e18);
    }
    printf("%lld %lld\n", answer / E, answer % E);
    return 0;
}