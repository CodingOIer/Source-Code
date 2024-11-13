#include <cstring>
#include <queue>
#include <string>
#include <tuple>
extern "C" bool move_to(char position);
void dfs(int x, int y, int vis[][505])
{
    if (move_to('W') && !vis[x - 1][y])
    {
        x--;
        vis[x][y] = true;
        dfs(x, y, vis);
        move_to('S');
        x++;
    }
    if (move_to('S') && !vis[x + 1][y])
    {
        x++;
        vis[x][y] = true;
        dfs(x, y, vis);
        move_to('W');
        x--;
    }
    if (move_to('A') && !vis[x][y - 1])
    {
        y--;
        vis[x][y] = true;
        dfs(x, y, vis);
        move_to('D');
        y++;
    }
    if (move_to('D') && !vis[x][y + 1])
    {
        y++;
        vis[x][y] = true;
        dfs(x, y, vis);
        move_to('A');
        y--;
    }
}
extern "C" std::string find_out_map(int x, int y, int n)
{
    int vis[505][505];
    memset(vis, false, sizeof(vis));
    dfs(x, y, vis);
    std::string res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }
}