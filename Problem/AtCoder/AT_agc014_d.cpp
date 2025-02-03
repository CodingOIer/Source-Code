#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n;
bool kill[MaxN];
std::vector<int> g[MaxN];
void dfs(int u, int f)
{
    int w = 0;
    for (const auto &v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
        if (!kill[v])
        {
            w = v;
        }
    }
    if (w != 0)
    {
        kill[u] = true;
        kill[w] = true;
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
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!kill[i])
        {
            printf("First\n");
            return 0;
        }
    }
    printf("Second\n");
    return 0;
}
