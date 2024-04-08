#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 2e2 + 5;
constexpr long long MaxFlow = 1e18;
int n, m;
int s, t;
int cnt[MaxN];
int last[MaxN];
long long x;
long long answer;
std::queue<int> queue;
std::vector<int> link[MaxN];
std::vector<long long> max[MaxN];
std::vector<long long> use[MaxN];
std::pair<int, int> rev[MaxN][MaxN];
void bfs()
{
    queue.push(s);
    cnt[s] = 1;
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
    if (u == t || f == 0)
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
                auto temp = rev[u][v];
                use[temp.first][temp.second] -= push;
                return push;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d%lld", &n, &m, &x);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        link[u].push_back(v);
        link[v].push_back(u);
        max[u].push_back(w);
        max[v].push_back(w);
        use[u].push_back(0);
        use[v].push_back(w);
        int x, y;
        x = u;
        y = link[u].size() - 1;
        rev[v][u] = {x, y};
        x = v;
        y = link[v].size() - 1;
        rev[u][v] = {x, y};
    }
    s = 1;
    t = n;
    for (;;)
    {
        memset(cnt, 0, sizeof(cnt));
        bfs();
        if (cnt[t] == 0)
        {
            break;
        }
        memset(last, 0, sizeof(cnt));
        answer += dfs(s, MaxFlow);
    }
    if (answer == 0)
    {
        printf("Orz Ni Jinan Saint Cow!\n");
    }
    else
    {
        printf("%lld %lld\n", answer, x / answer + (x % answer != 0 ? 1 : 0));
    }
    return 0;
}