#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
constexpr int MaxN = 2e2 + 5;
constexpr int E = 1e6;
int n, m, s, t;
int answer;
int cnt[MaxN];
int last[MaxN];
int rev[MaxN][MaxN];
std::queue<int> queue;
std::vector<int> max[MaxN];
std::vector<int> use[MaxN];
std::vector<int> link[MaxN];
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
            if (cnt[v] == 0 && use[u][i] < max[u][i])
            {
                cnt[v] = cnt[u] + 1;
                queue.push(v);
            }
        }
    }
}
int dfs(int u, int f)
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
            int push = std::min(f, max[u][i] - use[u][i]);
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
void add(int u, int v, int l)
{
    link[u].push_back(v);
    link[v].push_back(u);
    max[u].push_back(l);
    max[v].push_back(l);
    use[u].push_back(0);
    use[v].push_back(l);
    rev[u][v] = link[v].size() - 1;
    rev[v][u] = link[u].size() - 1;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= n; i++)
    {
        add(i, n + i, i == s || i == t ? E : 1);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(n + u, v, E);
        add(n + v, u, E);
    }
    for (;;)
    {
        memset(cnt, 0, sizeof(cnt));
        bfs();
        if (cnt[t] == 0)
        {
            break;
        }
        memset(last, 0, sizeof(last));
        answer += dfs(s, E);
    }
    printf("%d\n", answer);
    return 0;
}