#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
int p[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    int k = 0;
    int x, y;
    x = 1;
    y = 1;
    char to = 'L';
    for (int i = 0; i <= n + 1; i++)
    {
        p[0][i] = -1;
        p[i][0] = -1;
        p[n + 1][i] = -1;
        p[i][n + 1] = -1;
    }
    for (int i = 1; i <= n * n; i++)
    {
        p[x][y] = ++k;
        if (to == 'L' && p[x][y + 1] != 0)
        {
            to = 'J';
        }
        if (to == 'J' && p[x + 1][y] != 0)
        {
            to = 'H';
        }
        if (to == 'H' && p[x][y - 1] != 0)
        {
            to = 'K';
        }
        if (to == 'K' && p[x - 1][y] != 0)
        {
            to = 'L';
        }
        if (to == 'L')
        {
            y++;
        }
        if (to == 'J')
        {
            x++;
        }
        if (to == 'H')
        {
            y--;
        }
        if (to == 'K')
        {
            x--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("% 3d", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
