#include <cstdio>
#include <queue>
#include <tuple>
constexpr int MaxN = 1e3 + 5;
int n, m;
char s[MaxN][MaxN];
std::queue<std::tuple<int, int, char>> queue;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == 'E')
            {
                s[i][j] = '.';
                queue.push({i, j, 'E'});
            }
        }
    }
    for (; !queue.empty();)
    {
        const auto [x, y, ch] = queue.front();
        queue.pop();
        if (s[x][y] != '.')
        {
            continue;
        }
        s[x][y] = ch;
        queue.push({x - 1, y, 'v'});
        queue.push({x + 1, y, '^'});
        queue.push({x, y + 1, '<'});
        queue.push({x, y - 1, '>'});
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%s\n", s[i] + 1);
    }
    return 0;
}