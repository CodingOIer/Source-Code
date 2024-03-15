#include <algorithm>
#include <cstdio>
constexpr int MaxN = 25;
int n;
int floyd[MaxN][MaxN];
int main()
{
    for (int id = 1;; id++)
    {
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 20; j++)
            {
                floyd[i][j] = 0x3f3f3f3f;
            }
        }
        for (int i = 1; i <= 20; i++)
        {
            floyd[i][i] = 0;
        }
        if (scanf("%d", &n) != 1)
        {
            break;
        }
        for (int i = 1; i <= 19; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int x;
                scanf("%d", &x);
                floyd[i][x] = 1;
                floyd[x][i] = 1;
            }
            scanf("%d", &n);
        }
        for (int k = 1; k <= 20; k++)
        {
            for (int i = 1; i <= 20; i++)
            {
                for (int j = 1; j <= 20; j++)
                {
                    floyd[i][j] = std::min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                }
            }
        }
        printf("Test Set #%d\n", id);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%2d to %2d: %d\n", x, y, floyd[x][y]);
        }
        printf("\n");
    }
    return 0;
}