#include <cstdio>
#include <utility>
constexpr int MaxN = 1e2 + 5;
int n, q;
int p[MaxN][MaxN][MaxN];
int s[MaxN][MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                scanf("%d", &p[i][j][k]);
                s[i][j][k] = s[i][j - 1][k] + s[i][j][k - 1] + p[i][j][k] - s[i][j - 1][k - 1];
            }
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int sx, ex, sy, ey, sz, ez;
        scanf("%d%d%d%d%d%d", &sx, &ex, &sy, &ey, &sz, &ez);
        if (sx > ex)
        {
            std::swap(sx, ex);
        }
        if (sy > ey)
        {
            std::swap(sy, ey);
        }
        if (sz > ez)
        {
            std::swap(sz, ez);
        }
        int answer = 0;
        for (int x = sx; x <= ex; x++)
        {
            answer += s[x][ey][ez] - s[x][sy - 1][ez] - s[x][ey][sz - 1] + s[x][sy - 1][sz - 1];
        }
        printf("%d\n", answer);
    }
    return 0;
}