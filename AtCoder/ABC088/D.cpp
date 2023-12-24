#include <bits/stdc++.h>
using namespace std;
struct str
{
    int x, y;
    int len;
};
const int inf = 0x3f3f3f3f;
const int MaxN = 55;
int h, w;
int ans;
int black;
int vis[MaxN][MaxN];
char tmp[MaxN];
char s[MaxN][MaxN];
queue<str> bfs;
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", tmp);
        for (int j = 0; j < w; j++)
        {
            s[i][j + 1] = tmp[j];
            if (s[i][j + 1] == '#')
            {
                black++;
            }
        }
    }
    str t;
    t.x = 1;
    t.y = 1;
    t.len = 1;
    bfs.push(t);
    for (; !bfs.empty();)
    {
        t = bfs.front();
        bfs.pop();
        if (vis[t.x][t.y] || s[t.x][t.y] == '#' || !(1 <= t.x && t.x <= h && 1 <= t.y && t.y <= w))
        {
            continue;
        }
        if (t.x == h && t.y == w)
        {
            ans = t.len;
            break;
        }
        vis[t.x][t.y] = 1;
        t.len++;
        t.x += 1;
        if (vis[t.x][t.y] == 0 && s[t.x][t.y] != '#')
        {
            bfs.push(t);
        }
        t.x -= 2;
        if (vis[t.x][t.y] == 0 && s[t.x][t.y] != '#')
        {
            bfs.push(t);
        }
        t.x += 1;
        t.y += 1;
        if (vis[t.x][t.y] == 0 && s[t.x][t.y] != '#')
        {
            bfs.push(t);
        }
        t.y -= 2;
        if (vis[t.x][t.y] == 0 && s[t.x][t.y] != '#')
        {
            bfs.push(t);
        }
    }
    printf("%d\n", ans == 0 ? -1 : h * w - ans - black);
    return 0;
}