#include <cstdio>
#include <vector>
constexpr int MaxN = 2e4 + 5;
int n, m;
int index;
int answer;
int low[MaxN];
int road[MaxN];
bool vis[MaxN];
bool split[MaxN];
std::vector<int> link[MaxN];
void dfs(int x, int f)
{
    vis[x] = true;
    index++;
    low[x] = index;
    road[x] = index;
    int son = 0;
    for (auto next : link[x])
    {
        if (!vis[next])
        {
            son++;
            dfs(next, x);
            low[x] = std::min(low[x], low[next]);
            if (x != f && low[next] >= road[x] && !split[x])
            {
                answer++;
                split[x] = true;
            }
        }
        else if (next != f)
        {
            low[x] = std::min(low[x], road[next]);
        }
    }
    if (x == f && son >= 2 && !split[x])
    {
        answer++;
        split[x] = true;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            index = 0;
            dfs(i, i);
        }
    }
    printf("%d\n", answer);
    for (int i = 1; i <= n; i++)
    {
        if (split[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}