#include <cstdio>
constexpr int MaxN = 5e2 + 5;
int n;
int q;
int p[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        char c = '\0';
        for (; !(c == 'c' || c == 'q');)
        {
            c = getchar();
        }
        if (c == 'c')
        {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            p[x][y] = v;
        }
        else if (c == 'q')
        {
            int sx, sy, tx, ty;
            scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
            int max, min;
            min = 0x3f3f3f3f;
            max = -0x3f3f3f3f;
            for (int j = sx; j <= tx; j++)
            {
                for (int k = sy; k <= ty; k++)
                {
                    min = p[j][k] < min ? p[j][k] : min;
                    max = p[j][k] > max ? p[j][k] : max;
                }
            }
            printf("%d %d\n", max, min);
        }
    }
    return 0;
}