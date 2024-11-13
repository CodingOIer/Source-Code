#include <cstdio>
#include <vector>
constexpr int MaxN = 4e5 + 5;
int n;
int answer;
bool back;
bool vis[MaxN];
std::vector<int> link[MaxN];
int dfs(int u, int f)
{
    if (vis[u])
    {
        back = true;
        return 0;
    }
    vis[u] = true;
    int size = 1;
    for (auto v : link[u])
    {
        if (v == f)
        {
            f = 0;
            continue;
        }
        size += dfs(v, u);
    }
    return size;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    for (int i = 1; i <= 400000; i++)
    {
        if (link[i].size() == 0)
        {
            continue;
        }
        back = false;
        int size = dfs(i, 0);
        if (back)
        {
            answer += size;
        }
        else
        {
            answer += size - 1;
        }
    }
    printf("%d\n", answer);
    return 0;
}