#include <cstdio>
#include <queue>
#include <tuple>
constexpr int MaxN = 1e3 + 5;
int h, w, d;
char s[MaxN][MaxN];
bool vis[MaxN][MaxN];
std::queue<std::tuple<int, int>> queue;
int main()
{
    scanf("%d%d%d", &h, &w, &d);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (s[i][j] == 'H')
            {
                queue.push({i, j});
            }
        }
    }
    queue.push({-1, -1});
    int dis = 0;
    for (; !queue.empty() && dis <= d;)
    {
        auto [x, y] = queue.front();
        queue.pop();
        if (x == -1 && y == -1)
        {
            dis++;
            queue.push({-1, -1});
            continue;
        }
        if (s[x][y] != '.' && s[x][y] != 'H')
        {
            continue;
        }
        if (vis[x][y])
        {
            continue;
        }
        vis[x][y] = true;
        queue.push({x - 1, y});
        queue.push({x + 1, y});
        queue.push({x, y - 1});
        queue.push({x, y + 1});
    }
    int answer = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (vis[i][j])
            {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
