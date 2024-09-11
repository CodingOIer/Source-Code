#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n, m, k;
int cp[MaxN][MaxN];
int hp[MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++)
    {
        int x, y, h, c;
        scanf("%d%d%d%d", &x, &y, &h, &c);
        if (hp[x][y] > h || hp[x][y] == 0)
        {
            hp[x][y] = h;
            cp[x][y] = c;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d%c", cp[i][j], j == m ? '\n' : ' ');
        }
    }
    return 0;
}