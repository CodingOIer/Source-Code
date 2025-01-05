#include <cstdio>
#include <queue>
#include <tuple>
constexpr int MaxN = 1e3 + 5;
int h, w;
char s[MaxN][MaxN];
bool vis[2][MaxN][MaxN];
std::queue<std::tuple<bool, int, int, int>> queue;
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (s[i][j] == 'S')
            {
                queue.push({false, i, j, 0});
                queue.push({true, i, j, 0});
            }
        }
    }
    for (; !queue.empty();)
    {
        const auto &[type, x, y, answer] = queue.front();
        queue.pop();
        if (vis[type][x][y] || (s[x][y] != '.' && s[x][y] != 'S' && s[x][y] != 'G'))
        {
            continue;
        }
        if (s[x][y] == 'G')
        {
            printf("%d\n", answer);
            return 0;
        }
        vis[type][x][y] = true;
        if (type)
        {
            queue.push({false, x - 1, y, answer + 1});
            queue.push({false, x + 1, y, answer + 1});
        }
        else
        {
            queue.push({true, x, y - 1, answer + 1});
            queue.push({true, x, y + 1, answer + 1});
        }
    }
    printf("-1\n");
    return 0;
}
