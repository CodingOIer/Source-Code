#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, m;
int answer;
int p[MaxN][MaxN];
int best[MaxN][MaxN];
int calc(int x, int y)
{
    if (!(1 <= x && x <= n && 1 <= y && y <= m))
    {
        return 0;
    }
    if (best[x][y] != 0)
    {
        return best[x][y];
    }
    return best[x][y] =
               1 + std::max({p[x - 1][y] < p[x][y] ? calc(x - 1, y) : 0, p[x + 1][y] < p[x][y] ? calc(x + 1, y) : 0,
                             p[x][y - 1] < p[x][y] ? calc(x, y - 1) : 0, p[x][y + 1] < p[x][y] ? calc(x, y + 1) : 0});
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            answer = std::max(answer, calc(i, j));
        }
    }
    printf("%d\n", answer);
    return 0;
}