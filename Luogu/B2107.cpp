#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, m;
int p[MaxN][MaxN];
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
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            printf("%d%c", p[j][i], j == 1 ? '\n' : ' ');
        }
    }
    return 0;
}