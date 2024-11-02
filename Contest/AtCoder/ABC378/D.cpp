#include <cstdio>
constexpr int MaxN = 1e1 + 5;
int h, w, k;
int answer;
char s[MaxN][MaxN];
bool vis[MaxN][MaxN];
void dfs(int x, int y, int now)
{
    if (vis[x][y] || s[x][y] != '.')
    {
        return;
    }
    if (now == k + 1)
    {
        answer++;
        return;
    }
    vis[x][y] = true;
    dfs(x - 1, y, now + 1);
    dfs(x + 1, y, now + 1);
    dfs(x, y - 1, now + 1);
    dfs(x, y + 1, now + 1);
    vis[x][y] = false;
}
int main()
{
    scanf("%d%d%d", &h, &w, &k);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dfs(i, j, 1);
        }
    }
    printf("%d\n", answer);
    return 0;
}