#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
const int MaxN = 2e5 + 5;
int n, m;
int a[MaxN];
int b[MaxN];
int vis[MaxN];
std::map<int, std::map<int, bool>> map;
std::vector<int> link[MaxN];
void dfs(int x, int fa, int len)
{
    if (vis[x] != 0)
    {
        if ((len - vis[x]) % 2 == 1)
        {
            printf("No\n");
            exit(0);
        }
        return;
    }
    vis[x] = len;
    for (int next : link[x])
    {
        if (next == fa)
        {
            continue;
        }
        dfs(next, x, len + 1);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (!map[a[i]][b[i]])
        {
            map[a[i]][b[i]] = true;
            link[a[i]].push_back(b[i]);
            link[b[i]].push_back(a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, -1, 1);
        }
    }
    printf("Yes\n");
    return 0;
}