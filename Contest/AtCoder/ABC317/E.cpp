#include <cstdio>
#include <queue>
const int MaxN = 2e3 + 5;
class str
{
  public:
    int x;
    int y;
    int len;
};
int h, w;
int go_x, go_y;
int end_x, end_y;
char s[MaxN][MaxN];
bool vis[MaxN][MaxN];
std::queue<str> bfs;
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", (s[i] + 1));
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (s[i][j] == 'S')
            {
                go_x = i;
                go_y = j;
            }
            if (s[i][j] == 'G')
            {
                end_x = i;
                end_y = j;
            }
            if (s[i][j] == '#')
            {
                vis[i][j] = true;
            }
            if (s[i][j] == '<')
            {
                vis[i][j] = true;
                for (int k = j - 1; k >= 1; k--)
                {
                    if (s[i][k] != '.')
                    {
                        break;
                    }
                    vis[i][k] = true;
                }
            }
            if (s[i][j] == '>')
            {
                vis[i][j] = true;
                for (int k = j + 1; k <= w; k++)
                {
                    if (s[i][k] != '.')
                    {
                        break;
                    }
                    vis[i][k] = true;
                }
            }
            if (s[i][j] == '^')
            {
                vis[i][j] = true;
                for (int k = i - 1; k >= 1; k--)
                {
                    if (s[k][j] != '.')
                    {
                        break;
                    }
                    vis[k][j] = true;
                }
            }
            if (s[i][j] == 'v')
            {
                vis[i][j] = true;
                for (int k = i + 1; k <= h; k++)
                {
                    if (s[k][j] != '.')
                    {
                        break;
                    }
                    vis[k][j] = true;
                }
            }
        }
    }
    str t;
    t.x = go_x;
    t.y = go_y;
    t.len = 0;
    bfs.push(t);
    vis[t.x][t.y] = true;
    // for (int i = 1; i <= h; i++)
    // {
    //     for (int j = 1; j <= w; j++)
    //     {
    //         printf("%d", vis[i][j]);
    //     }
    //     printf("\n");
    // }
    for (; !bfs.empty();)
    {
        t = bfs.front();
        bfs.pop();
        if (t.x == end_x && t.y == end_y)
        {
            printf("%d\n", t.len);
            return 0;
        }
        if (!vis[t.x - 1][t.y] && t.x != 1 && !vis[t.x - 1][t.y])
        {
            str k;
            k.x = t.x - 1;
            k.y = t.y;
            k.len = t.len + 1;
            bfs.push(k);
            vis[k.x][k.y] = true;
        }
        if (!vis[t.x + 1][t.y] && t.x != h && !vis[t.x + 1][t.y])
        {
            str k;
            k.x = t.x + 1;
            k.y = t.y;
            k.len = t.len + 1;
            bfs.push(k);
            vis[k.x][k.y] = true;
        }
        if (!vis[t.x][t.y - 1] && t.y != 1 && !vis[t.x][t.y - 1])
        {
            str k;
            k.x = t.x;
            k.y = t.y - 1;
            k.len = t.len + 1;
            bfs.push(k);
            vis[k.x][k.y] = true;
        }
        if (!vis[t.x][t.y + 1] && t.y != w && !vis[t.x][t.y + 1])
        {
            str k;
            k.x = t.x;
            k.y = t.y + 1;
            k.len = t.len + 1;
            bfs.push(k);
            vis[k.x][k.y] = true;
        }
    }
    printf("-1\n");
    return 0;
}