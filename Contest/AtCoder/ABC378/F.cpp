#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int in[MaxN];
bool vis[MaxN];
std::vector<int> g[MaxN];
int dfs(int u)
{
    if (vis[u])
    {
        return 0;
    }
    if (in[u] == 2)
    {
        return 1;
    }
    else if (in[u] == 3)
    {
        vis[u] = true;
        int res = 0;
        for (auto v : g[u])
        {
            res += dfs(v);
        }
        return res;
    }
    else
    {
        return 0;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 3)
        {
            long long cnt = dfs(i);
            answer += cnt * (cnt - 1) / 2;
        }
    }
    printf("%lld\n", answer);
    return 0;
}