// ~ 100

#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
constexpr int MaxN = 5e2 + 5;
int n, m, q;
int id[MaxN][MaxN];
char s[MaxN][MaxN];
bool vis[MaxN][MaxN];
bool cannot[MaxN][MaxN];
bool answer[MaxN * 3][MaxN][MaxN];
std::queue<std::tuple<int, int>> temp;
std::queue<std::tuple<int, int>> fire;
std::queue<std::tuple<int, int>> queue;
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    int sx, sy;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == 'v')
            {
                fire.push({i, j});
                cannot[i][j] = true;
            }
            else if (s[i][j] == '.')
            {
                queue.push({i, j});
            }
            else if (s[i][j] == '#')
            {
                sx = i;
                sy = j;
            }
        }
    }
    int most = -1;
    for (int k = 0;; k++)
    {
        queue.push({-1, -1});
        for (;;)
        {
            int x, y;
            std::tie(x, y) = queue.front();
            queue.pop();
            if (x == -1 && y == -1)
            {
                break;
            }
            if (cannot[x][y])
            {
                continue;
            }
            answer[k][x][y] = true;
            queue.push({x, y});
        }
        memset(vis, false, sizeof(vis));
        memset(id, false, sizeof(id));
        int idx = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!answer[k][i][j] || id[i][j] != 0)
                {
                    continue;
                }
                idx++;
                temp.push({i, j});
                for (; !temp.empty();)
                {
                    int x, y;
                    std::tie(x, y) = temp.front();
                    temp.pop();
                    if (!answer[k][x][y] || id[x][y] != 0)
                    {
                        continue;
                    }
                    id[x][y] = idx;
                    temp.push({x - 1, y});
                    temp.push({x + 1, y});
                    temp.push({x, y - 1});
                    temp.push({x, y + 1});
                }
            }
        }
        bool good = false;
        for (int cid = 1; cid <= idx; cid++)
        {
            temp.push({sx, sy});
            memset(vis, false, sizeof(vis));
            bool suc = true;
            for (; !temp.empty();)
            {
                int x, y;
                std::tie(x, y) = temp.front();
                temp.pop();
                if (vis[x][y] || id[x][y] == cid)
                {
                    continue;
                }
                if (x == 1 || x == n || y == 1 || y == m)
                {
                    suc = false;
                    break;
                }
                vis[x][y] = true;
                temp.push({x - 1, y});
                temp.push({x + 1, y});
                temp.push({x, y - 1});
                temp.push({x, y + 1});
                temp.push({x - 1, y - 1});
                temp.push({x + 1, y + 1});
                temp.push({x - 1, y + 1});
                temp.push({x + 1, y - 1});
            }
            for (; !temp.empty();)
            {
                temp.pop();
            }
            if (suc)
            {
                good = true;
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        if (id[i][j] == cid)
                        {
                            answer[k][i][j] = false;
                        }
                    }
                }
            }
        }
        if (!good)
        {
            goto end;
        }
        most++;
        fire.push({-1, -1});
        for (;;)
        {
            int x, y;
            std::tie(x, y) = fire.front();
            fire.pop();
            if (x == -1 && y == -1)
            {
                break;
            }
            if (!cannot[x - 1][y] && x - 1 >= 1)
            {
                cannot[x - 1][y] = true;
                fire.push({x - 1, y});
            }
            if (!cannot[x + 1][y] && x + 1 <= n)
            {
                cannot[x + 1][y] = true;
                fire.push({x + 1, y});
            }
            if (!cannot[x][y - 1] && y - 1 >= 1)
            {
                cannot[x][y - 1] = true;
                fire.push({x, y - 1});
            }
            if (!cannot[x][y + 1] && y + 1 <= m)
            {
                cannot[x][y + 1] = true;
                fire.push({x, y + 1});
            }
        }
    }
end:;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int l, r;
        l = 0;
        r = most;
        int res = -1;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (answer[mid][x][y])
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%d\n", res + 1);
    }
    return 0;
}