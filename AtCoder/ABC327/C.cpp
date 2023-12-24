#include <cstdio>
#include <cstring>
const int MaxN = 15;
int n = 9;
int p[MaxN][MaxN];
bool vis[MaxN];
bool checkLine(int x)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (vis[p[x][i]] == true)
        {
            return false;
        }
        vis[p[x][i]] = true;
    }
    return true;
}
bool checkLie(int x)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (vis[p[i][x]] == true)
        {
            return false;
        }
        vis[p[i][x]] = true;
    }
    return true;
}
bool checkBlock(int x, int y)
{
    memset(vis, 0, sizeof(vis));
    for (int i = x; i <= x + 2; i++)
    {
        for (int j = y; j <= y + 2; j++)
        {
            if (vis[p[i][j]] == true)
            {
                return false;
            }
            vis[p[i][j]] = true;
        }
    }
    return true;
}
int main()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!checkLine(i) || !checkLie(i))
        {
            printf("No\n");
            return 0;
        }
    }
    if (!checkBlock(1, 1) || !checkBlock(4, 1) || !checkBlock(7, 1) || !checkBlock(1, 4) || !checkBlock(4, 4) ||
        !checkBlock(7, 4) || !checkBlock(1, 7) || !checkBlock(4, 7) || !checkBlock(7, 7))
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}