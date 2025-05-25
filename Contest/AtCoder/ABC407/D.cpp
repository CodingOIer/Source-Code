#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e1 + 5;
int h, w;
bool vis[MaxN][MaxN];
long long answer;
long long p[MaxN][MaxN];
void check()
{
    long long temp = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (!vis[i][j])
            {
                temp ^= p[i][j];
            }
        }
    }
    answer = std::max(answer, temp);
}
void dfs(int x, int y)
{
    if (y > w)
    {
        dfs(x + 1, 1);
        return;
    }
    if (x > h)
    {
        check();
        return;
    }
    if (vis[x][y])
    {
        dfs(x, y + 1);
        return;
    }
    dfs(x, y + 1);
    vis[x][y] = true;
    if (!vis[x][y + 1] && y + 1 <= w)
    {
        vis[x][y + 1] = true;
        dfs(x, y + 1);
        vis[x][y + 1] = false;
    }
    if (!vis[x + 1][y] && x + 1 <= h)
    {
        vis[x + 1][y] = true;
        dfs(x, y + 1);
        vis[x + 1][y] = false;
    }
    vis[x][y] = false;
}
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            scanf("%lld", &p[i][j]);
        }
    }
    dfs(1, 1);
    printf("%lld\n", answer);
    return 0;
}