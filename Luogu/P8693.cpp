#include <cstdio>
#include <queue>
#include <tuple>
constexpr int MaxN = 3e2 + 5;
int n, k;
char s[MaxN][MaxN];
bool vis[MaxN][MaxN];
std::priority_queue<std::tuple<int, int, int, int, bool>> queue;
inline bool check(int x, int y, int size)
{
    int l = (size - 1) / 2;
    if (!(x - l >= 1 && y - l >= 1 && x + l <= n && y + l <= n))
    {
        return false;
    }
    for (int i = x - l; i <= x + l; i++)
    {
        for (int j = y - l; j <= y + l; j++)
        {
            if (s[i][j] == '*')
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
    queue.push({0, 3, 3, 5, false});
    for (; !queue.empty();)
    {
        auto [cost, x, y, size, vip] = queue.top();
        cost = -cost;
        if (cost == k)
        {
            size -= 2;
        }
        if (cost == 2 * k)
        {
            size -= 2;
        }
        queue.pop();
        if (!check(x, y, size) || (vis[x][y] && !vip))
        {
            continue;
        }
        vis[x][y] = true;
        // printf("On {%d, %d}, size is %d, cost is %d\n", x, y, size, cost);
        if (x == n - 2 && y == n - 2)
        {
            printf("%d\n", cost);
            break;
        }
        queue.push({-(cost + 1), x + 1, y, size, false});
        queue.push({-(cost + 1), x - 1, y, size, false});
        queue.push({-(cost + 1), x, y + 1, size, false});
        queue.push({-(cost + 1), x, y - 1, size, false});
        if (cost < k)
        {
            queue.push({-k, x, y, size, true});
        }
        else if (cost < 2 * k)
        {
            queue.push({-2 * k, x, y, size, true});
        }
    }
    return 0;
}