#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, m;
char s[MaxN][MaxN];
bool vis[MaxN][MaxN];
void dfs(int x, int y)
{
    if (vis[x][y] || s[x][y] != '*')
    {
        return;
    }
    vis[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] || s[i][j] == '.')
            {
                continue;
            }
            answer++;
            dfs(i, j);
        }
    }
    printf("%d\n", answer);
    return 0;
}
