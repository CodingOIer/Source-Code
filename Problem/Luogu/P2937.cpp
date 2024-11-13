#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int h, w;
int answer[MaxN][MaxN];
char s[MaxN][MaxN];
bool f[MaxN][MaxN];
bool vis[MaxN][MaxN];
std::queue<std::tuple<int, int, int>> queue;
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", s[i] + 1);
    }
    std::vector<std::tuple<int, int>> v;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (s[i][j] == 'C')
            {
                v.push_back({i, j});
            }
            if (s[i][j] == '*')
            {
                f[i][j] = true;
            }
        }
    }
    int sx, sy;
    int ex, ey;
    std::tie(sx, sy) = v[0];
    std::tie(ex, ey) = v[1];
    queue.push({sx, sy, -1});
    for (; !queue.empty();)
    {
        int x, y, l;
        std::tie(x, y, l) = queue.front();
    }
    return 0;
}