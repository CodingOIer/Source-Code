#include <cstdio>
#include <vector>
constexpr int MaxN = 1e4 + 5;
int n, m;
bool vis[100000000];
std::vector<int> len[MaxN];
std::vector<int> link[MaxN];
void dfs(int x, int fa, int depth)
{
    vis[depth] = true;
    for (int i = 0; i < int(link[x].size()); i++)
    {
        if (link[x][i] == fa)
        {
            continue;
        }
        dfs(link[x][i], x, depth + len[x][i]);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        len[u].push_back(w);
        len[v].push_back(w);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 0, 0);
    }
    for (int j = 1; j <= m; j++)
    {
        int x;
        scanf("%d", &x);
        printf("%s\n", vis[x] ? "AYE" : "NAY");
    }
    return 0;
}